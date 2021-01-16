#include "mycamera.h"

mycamera::mycamera()
{

}

//封装一个函数把YUV转换成ARGB
int yuvtorgb(int y,int u,int v)
{
    int r,g,b; //正常的取值范围0--255之间
    unsigned int pix;
    r = 1164*(y-16)/1000 + 1596*(v-128)/1000;
    g = 1164*(y-16)/1000 + 813*(v-128)/1000 - 391*(u-128)/1000;
    b = 1164*(y-16)/1000 + 2018*(u-128)/1000;
    //修正运算结果
    if(r>255)
        r=255;
    if(g>255)
        g=255;
    if(b>255)
        b=255;
    if(r<0)
        r=0;
    if(g<0)
        g=0;
    if(b<0)
        b=0;
    //顺便做个好事，RGB-->ARGB
    pix=0x00<<24|r<<16|g<<8|b;  //左移和位或操作实现数据的拼接  ARGB
    return pix;
}

//封装函数把一帧画面YUV数据转换成ARGB
//yuvdata --》你要转换的YUV
//argbdata --》存放转换得到的ARGB
int allyuvtorgb(char *yuvdata,int *argbdata)
{
    /*
        分析：yuvdata[0]   Y1
              yuvdata[1]   U
              yuvdata[2]   Y2
              yuvdata[3]   V
        循环次数：画面大小W*H(640*480)，需要转换得到W*H个像素点
    */
    int i,j;
    for(i=0,j=0; i<W*H; i+=2,j+=4)
    {
        //每次循环得到两个像素点
        argbdata[i]=yuvtorgb(yuvdata[j], yuvdata[j+1], yuvdata[j+3]);
        argbdata[i+1]=yuvtorgb(yuvdata[j+2], yuvdata[j+1], yuvdata[j+3]);
    }
    return 0;
}

//摄像头的初始化
int mycamera::camera_init()
{
    int ret;
    int i;
    //打开摄像头的驱动
    camerafd=open("/dev/video7",O_RDWR);
    if(camerafd==-1)
    {
        perror("打开摄像头失败！\n");
        return -1;
    }

    //打开液晶屏的驱动
    lcdfd=open("/dev/fb0",O_RDWR);
    if(lcdfd==-1)
    {
        perror("打开lcd失败!\n");
        return -1;
    }

    //映射得到lcd的首地址
    lcdmem=(int *)mmap(NULL,800*480*4,PROT_READ|PROT_WRITE,MAP_SHARED,lcdfd,0);
    if(lcdmem==NULL)
    {
        perror("映射lcd失败!\n");
        return -1;
    }

    //定义结构体变量存放你想要设置的采集格式
    struct v4l2_format myfmt;
    bzero(&myfmt,sizeof(myfmt));
    myfmt.type=V4L2_BUF_TYPE_VIDEO_CAPTURE;
    myfmt.fmt.pix.width=W;
    myfmt.fmt.pix.height=H;
    myfmt.fmt.pix.pixelformat=V4L2_PIX_FMT_YUYV;  //YUV格式
    myfmt.fmt.pix.field=V4L2_FIELD_NONE;
    //设置摄像头的采集格式
    ret=ioctl(camerafd,VIDIOC_S_FMT,&myfmt);
    if(ret==-1)
    {
        perror("设置摄像头的采集格式失败!\n");
        return -1;
    }

    //跟摄像头的驱动申请缓冲块
    struct v4l2_requestbuffers mybuf;
    bzero(&mybuf,sizeof(mybuf));
    mybuf.count=4; //申请4个缓冲块
    mybuf.type=V4L2_BUF_TYPE_VIDEO_CAPTURE;
    mybuf.memory=V4L2_MEMORY_MMAP;
    ret=ioctl(camerafd,VIDIOC_REQBUFS,&mybuf);
    if(ret==-1)
    {
        perror("申请缓冲块失败!\n");
        return -1;
    }

    //分配刚才你申请的4个缓冲块
    struct v4l2_buffer buf;  //重复使用buf
    for(i=0; i<4; i++)
    {
        bzero(&buf,sizeof(buf));
        buf.index=i;  //缓冲块的索引
        buf.type=V4L2_BUF_TYPE_VIDEO_CAPTURE;
        buf.memory=V4L2_MEMORY_MMAP;
        //此代码执行成功，摄像头的驱动会自动把缓冲块的大小和偏移填充到length和offset
        ret=ioctl(camerafd, VIDIOC_QUERYBUF, &buf);
        if(ret==-1)
        {
            perror("分配缓冲块失败!\n");
            return -1;
        }

        //立马把分配的缓冲块做个映射
        array[i].somelength = buf.length;
        array[i].start = mmap(NULL, buf.length, PROT_READ|PROT_WRITE, MAP_SHARED, camerafd, buf.m.offset);
        if(array[i].start == NULL)
        {
            perror("映射缓冲块首地址失败!\n");
            return -1;
        }
        //顺便入个队
        ret=ioctl(camerafd,VIDIOC_QBUF,&buf);  //入队
        if(ret==-1)
        {
            perror("入队失败!\n");
            return -1;
        }
    }

    //启动摄像头采集
    enum v4l2_buf_type mytype;
    mytype=V4L2_BUF_TYPE_VIDEO_CAPTURE;
    ret=ioctl(camerafd,VIDIOC_STREAMON,&mytype);
    if(ret==-1)
    {
        perror("启动采集失败!\n");
        return -1;
    }
    return 0;
}
//摄像头捕捉画面
int mycamera::camera_capture()
{
    int i,j;
    int ret;
    //定义一个数组存放转换得到的一帧完整的ARGB数据
    int argbbuf[W*H];  //W*H
    //关键步骤，最麻烦的一步
    //让摄像头的画面出队(把画面数据从缓冲块中取出来)，入队循环进行，产生源源不断的视频流
    struct v4l2_buffer buf;
    for(i=0; i<4; i++)
    {
        bzero(&buf,sizeof(buf));
        buf.index=i;  //缓冲块的索引
        buf.type=V4L2_BUF_TYPE_VIDEO_CAPTURE;
        buf.memory=V4L2_MEMORY_MMAP;
        //画面出队,把画面从缓冲块中取出来
        ret=ioctl(camerafd,VIDIOC_DQBUF,&buf);  //出队
        if(ret==-1)
        {
            perror("出队失败!\n");
            return -1;
        }
        ret=ioctl(camerafd,VIDIOC_QBUF,&buf);  //入队
        if(ret==-1)
        {
            perror("入队失败!\n");
            return -1;
        }

        //把出队的画面数据在开发板的液晶屏上显示出来
        /*
            出队的画面数据在哪里？
               array[i].start这个首地址中就是画面数据(YUV)
            画面数据如何填充到液晶屏上显示呢？
               第一步：mmap()液晶屏首地址--》int *lcdmem=mmap() 学习过
               第二步：lcdmem+偏移=画面数据
            YUV格式的画面无法在液晶屏直接显示(原因是液晶屏支持的像素编码方式是ARGB)
            YUV数据如何转换成RGB、ARGB  --》已解决
        */
        allyuvtorgb((char *)(array[i].start),argbbuf);

        //把转换得到的ARGB数据填充液晶屏
        /*
        #include <string.h>
        void *memcpy(void *dest, const void *src, size_t n);

        图像第一行像素点： argbbuf[640*0]---argbbuf[640-1]
            填充lcd的对应位置：lcdmem+800*0---lcdmem+640-1
            memcpy(lcdmem,&argbbuf[0],640*4);
        图像第二行像素点： argbbuf[640*1]---argbbuf[640*2-1]
            填充lcd的对应位置：lcdmem+800*1---lcdmem+800+640-1
            memcpy(lcdmem+800,&argbbuf[640],640*4);
        图像第三行像素点： argbbuf[640*2]---argbbuf[640*3-1]
            填充lcd的对应位置：lcdmem+800*2---lcdmem+800*2+640-1
            。。。。。

            图像第480行像素点： argbbuf[640*479]---argbbuf[640*480-1]
                  */
                  for(j=0; j<H; j++)
                      memcpy(lcdmem+800*j+60, &argbbuf[W * j], W*4);
    }
    return 0;
}
//摄像头关闭
int mycamera::camera_uninit()
{
    int i;
    int ret;
    enum v4l2_buf_type mytype;
    mytype=V4L2_BUF_TYPE_VIDEO_CAPTURE;
    //关闭摄像头
    ret=ioctl(camerafd,VIDIOC_STREAMOFF,&mytype);
    if(ret==-1)
    {
        perror("关闭采集失败!\n");
        return -1;
    }
    //解除映射
    munmap(lcdmem,800*480*4);
    for(i=0; i<4; i++)
        munmap(array[i].start,array[i].somelength);
    //关闭文件描述符
    close(camerafd);
    close(lcdfd);
    return 0;
}
