#ifndef MYCAMERA_H
#define MYCAMERA_H

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
    void *start;  //缓冲块的首地址
    int somelength; //缓冲块的大小
};
class mycamera
{
public:
    mycamera();
    //初始化摄像头
    int camera_init();
    //启动摄像头捕捉画面
    int camera_capture();
    //摄像头的关闭
    int camera_uninit();


private:
    int camerafd;
    int lcdfd;
    int *lcdmem;
    //定义结构体数组存放4个缓冲块的信息
    struct bufattr array[4];
};

#endif // MYCAMERA_H
