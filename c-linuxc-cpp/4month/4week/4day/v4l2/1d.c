#include <stdio.h>
#include <linux/videodev2.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/ioctl.h>
#include <sys/mman.h>

#define W 800
#define H 480

int main(int argc, char const *argv[])
{
    // 1.打开摄像头的驱动
    int camerafd = open("/dev/video7", O_RDWR);

    // 2.设置摄像头采集画面的格式(画面宽，高，画面的格式等等)
    struct v4l2_format myfmt;
    bzero(&myfmt, sizeof(myfmt));
    myfmt.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;

    myfmt.fmt.pix.width = W;
    myfmt.fmt.pix.height = H;
    myfmt.fmt.pix.pixelformat = V4L2_PIX_FMT_YUYV;
    myfmt.fmt.pix.field = V4L2_FIELD_NONE;
    // 设置摄像头的采集格式
    int ret = ioctl(camerafd, VIDIOC_S_FMT, &myfmt);

    // 3.跟摄像头的驱动申请缓冲块
    struct v4l2_requestbuffers myvbuf;
    memset(&myvbuf, 0, sizeof(myvbuf));
    int nbuf = 6;
    myvbuf.count = nbuf;
    myvbuf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    myvbuf.memory = V4L2_MEMORY_MMAP;
    
    ioctl(&camerafd, VIDIOC_REQBUFS, &myvbuf);

    // 4.分配刚才你申请的缓冲块
    struct v4l2_buffer v4buf[nbuf];
    int length[nbuf];

    unsigned char *start[nbuf];
    int i;
    for ( i = 0; i < nbuf; i++)
    {
        memset(&v4buf[i], 0, sizeof(v4buf[i]));
        v4buf[i].type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
        v4buf[i].memory = V4L2_MEMORY_MMAP;
        v4buf[i].index = i;
        ioctl(camerafd, VIDIOC_QUERYBUF, &v4buf[i]);

        length[i] = v4buf[i].length;
        //立马把分配的缓冲块做个映射
        start[i] = mmap(NULL, v4buf[i].length, PROT_READ | PROT_WRITE, MAP_SHARED, camerafd, v4buf[i].m.offset);

        ioctl(camerafd, VIDIOC_QBUF, &v4buf[i]);
    }
    
    memset(&v4buf, 0, sizeof(v4buf));
    



    return 0;
}
