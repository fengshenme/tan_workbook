#include <fcntl.h>
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <sys/mman.h>

#include <linux/videodev2.h> //跟V4L2架构有关的头文件


//粤嵌买的这款摄像头：最大支持640*480大小的画面
#define W 640
#define H 480

//自定义一个结构体存放每个缓冲块的首地址和大小
struct bufattr
{
    void *start;    //缓冲块的首地址
    int somelength; //缓冲块的大小
};

int show(int *argbbuf);

//封装一个函数把YUV转换成ARGB
int yuvtorgb(int y, int u, int v)
{
    unsigned int r, g, b;
    unsigned int pix;
    r = 1164 * (y - 16) / 1000 + 1596 * (v - 128) / 1000;
    g = 1164 * (y - 16) / 1000 + 813 * (v - 128) / 1000 - 391 * (u - 128) / 1000;
    b = 1164 * (y - 16) / 1000 + 2018 * (u - 128) / 1000;
    //顺便做个好事，RGB-->ARGB
    pix = 0x00 << 24 | r << 16 | g << 8 | b; //左移和位或操作实现数据的拼接  ARGB
    return pix;
}

//封装函数把一帧画面YUV数据转换成ARGB
//yuvdata --》你要转换的YUV
//argbdata --》存放转换得到的ARGB
int allyuvtorgb(char *yuvdata, int *argbdata)
{
    /*
		分析：yuvdata[0]   Y1
		      yuvdata[1]   U
			  yuvdata[2]   Y2
			  yuvdata[3]   V
	*/
    int i, j;
    for (i = 0, j = 0; i < W*H ; i += 2, j += 4)
    {
        argbdata[i] = yuvtorgb(yuvdata[j], yuvdata[j + 1], yuvdata[j + 3]);
        argbdata[i + 1] = yuvtorgb(yuvdata[j + 2], yuvdata[j + 1], yuvdata[j + 3]);
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    int camerafd;
    int ret;
    int i;
    //打开摄像头的驱动
    camerafd = open("/dev/video7", O_RDWR);
    if (camerafd == -1)
    {
        printf( "打开摄像头失败！\n");
        return -1;
    }
    printf("[%d] --- ", __LINE__);
    //定义结构体变量存放你想要设置的采集格式
    struct v4l2_format myfmt;
    bzero(&myfmt, sizeof(myfmt));
    myfmt.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    myfmt.fmt.pix.width = W;
    myfmt.fmt.pix.height = H;
    myfmt.fmt.pix.pixelformat = V4L2_PIX_FMT_YUYV; //YUV格式
    myfmt.fmt.pix.field = V4L2_FIELD_NONE;
    //设置摄像头的采集格式
    ret = ioctl(camerafd, VIDIOC_S_FMT, &myfmt);
    if (ret == -1)
    {
        perror("设置摄像头的采集格式失败!\n");
        return -1;
    }

    //跟摄像头的驱动申请缓冲块
    struct v4l2_requestbuffers mybuf;
    bzero(&mybuf, sizeof(mybuf));
    mybuf.count = 4; //申请4个缓冲块
    mybuf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    mybuf.memory = V4L2_MEMORY_MMAP;
    ret = ioctl(camerafd, VIDIOC_REQBUFS, &mybuf);
    if (ret == -1)
    {
        perror("申请缓冲块失败!\n");
        return -1;
    }

    //分配刚才你申请的4个缓冲块
    //定义结构体数组存放4个缓冲块的信息
    struct bufattr array[4];
    struct v4l2_buffer buf; //重复使用buf
    for (i = 0; i < 4; i++)
    {
        bzero(&buf, sizeof(buf));
        buf.index = i; //缓冲块的索引
        buf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
        buf.memory = V4L2_MEMORY_MMAP;
        //此代码执行成功，摄像头的驱动会自动把缓冲块的大小和偏移填充到length和offset
        ret = ioctl(camerafd, VIDIOC_QUERYBUF, &buf);
        if (ret == -1)
        {
            perror("分配缓冲块失败!\n");
            return -1;
        }

        //立马把分配的缓冲块做个映射
        array[i].somelength = buf.length;
        array[i].start = mmap(NULL, buf.length, PROT_READ | PROT_WRITE, MAP_SHARED, camerafd, buf.m.offset);
        if (array[i].start == NULL)
        {
            perror("映射缓冲块首地址失败!\n");
            return -1;
        }
        //顺便入个队
        ret = ioctl(camerafd, VIDIOC_QBUF, &buf); //入队
        if (ret == -1)
        {
            perror("入队失败!\n");
            return -1;
        }
    }
    printf("[%d] --- ", __LINE__);
    //启动摄像头采集
    enum v4l2_buf_type mytype;
    mytype = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    ret = ioctl(camerafd, VIDIOC_STREAMON, &mytype);
    if (ret == -1)
    {
        perror("启动采集失败!\n");
        return -1;
    }

    //定义一个数组存放转换得到的一帧完整的ARGB数据
    int argbbuf[W * H]; //W*H
    //关键步骤，最麻烦的一步
    //让摄像头的画面出队(把画面数据从缓冲块中取出来)，入队循环进行，产生源源不断的视频流
    while (1) //程序不要退出，摄像头不断的出队，入队画面数据
    {

        printf("[%d] --- %d ", __LINE__, argbbuf[100]);

        for (i = 0; i < 4; i++)
        {
            bzero(&buf, sizeof(buf));
            buf.index = i; //缓冲块的索引
            buf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
            buf.memory = V4L2_MEMORY_MMAP;
            //画面出队,把画面从缓冲块中取出来
            ret = ioctl(camerafd, VIDIOC_DQBUF, &buf); //出队
            if (ret == -1)
            {
                perror("出队失败!\n");
                return -1;
            }
            ret = ioctl(camerafd, VIDIOC_QBUF, &buf); //入队
            if (ret == -1)
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
            allyuvtorgb(array[i].start, argbbuf);
            

            show(argbbuf);
            //把转换得到的ARGB数据填充液晶屏
        }
    }
    for ( i = 0; i < 4; i++)
        munmap(array[i].start,  array[i].somelength);

    close(camerafd);
    
}

int show(int *argbbuf)
{
     // 1.打开并映射
    int lcd_fd;                        //定义变量
    lcd_fd = open("/dev/fb0", O_RDWR); //打开LCD文件
    if (lcd_fd == -1)                  //判断lcd_fd是否等于-1,等于（打开失败）
    {
        perror("open lcd failed"); //打开失败输出open failed
        return 1;
    }

    //映射显存
    // unsigned int *FB;
    unsigned long(*FB)[W];
    FB = mmap(NULL,                   // 指定映射的地址（一般填NULL，由系统随机分配）
              800 * 480 * 4,          // 内存的大小（开发板屏幕4*800*480字节）
              PROT_READ | PROT_WRITE, // 保护权限（PROT_READ|PROT_WRITE）
              MAP_SHARED,             // 共享的	MAP_SHARED
              lcd_fd,                 // 映射的文件描述符
              0);                     // 映射后偏移量（一般填0，不偏移）

    // 2.操作显存，显示颜色
    // unsigned int color_red = 0x00FF0000;
    int num = 0, i, j;
    printf("[%d] --- %d ", __LINE__, argbbuf[100]);
    // for(480次)
    // for(800次)
    for (j = 0; j < 480; j++)
    {
        for (i = 0; i < 640; i++)
        {
            if (j <= 160)
            {
                FB[j][i] = argbbuf[num];
            }
            num++;
        }
    }

    // 3.取消映射并关闭LCD
    // munmap	//取消映射
    munmap(FB, 800 * 480 * 4);
    close(lcd_fd); //关闭文件

    return 0;
}

