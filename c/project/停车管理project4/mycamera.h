#ifndef MYCAMERA_H
#define MYCAMERA_H

#include <QDate>
#include <QDebug>
#include <QMessageBox>
#include <QTime>

#include <fcntl.h>
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include <sys/ioctl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>

#include <linux/videodev2.h> //跟V4L2架构有关的头文件

#include "include/jerror.h"
#include "include/jpeglib.h"

//这款摄像头：最大支持640*480大小的画面
#define W 320
#define H 240

//自定义一个结构体存放每个缓冲块的首地址和大小
struct bufattr {
    void* start; //缓冲块的首地址z
    int somelength; //缓冲块的大小
};

class MyCamera {
public:
    MyCamera();
    //初始化摄像头
    int camera_init();
    //启动摄像头捕捉画面
    int camera_capture();
    //启动摄像头捕捉一幅画面
    int save_pic();
    //摄像头的关闭
    int camera_uninit();

private:
    int camerafd;
    int lcdfd;
    int* lcdmem;
    //定义结构体数组存放4个缓冲块的信息
    struct bufattr array[4];

    /**
   * @brief write_jpeg_file rgb数据保存为jpg图片
   * @param jpeg_file jpeg文件写入路径
   * @param rgb_buffer 传入的rgb数据
   * @param width 图片宽
   * @param height 图片高
   * @param quality 压缩率
   * @return
   */
    int write_jpeg_file(const char* jpeg_file, unsigned char* rgb_buffer,
        int width, int height, int quality);
};

#endif // MYCAMERA_H
