#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <linux/input.h>

//映射显存
unsigned int *FB; //全局变量

int open_file(char *path);
//获取点击的x,y坐标轴
void getxy(int lcd_fd, int *x_tmp, int *y_tmp);
//映射显存
void mem_map(int lcd_fd);
void show_pic_full(char *path);
//显示颜色
void show_color(unsigned int color, int x_start, int y_start, int w, int h);

int main(int argc, char const *argv[])
{
    // 1.打开触摸屏文件
    int ts_fd; // 触摸屏设备文件描述符
    int lcd_fd;  //lcd设备文件描述符
    ts_fd = open_file("/dev/input/event0");
    lcd_fd = open_file("/dev/fb0");

    /*
获得如下数据：
type:0x3 code:0x0 value:379		触摸屏x坐标：379
type:0x3 code:0x1 value:293		触摸屏y坐标：293
type:0x1 code:0x14a value:1		触摸屏按下
type:0x0 code:0x0 value:0		//分隔符
type:0x1 code:0x14a value:0		触摸屏松开
type:0x0 code:0x0 value:0		//分隔符
};
    */
    // 2.读取触摸屏数据
    int x_tmp = 0, y_tmp = 0;
     // 2.映射显存/dev/input/event0
    mem_map(lcd_fd);
    while (1)
    {
        getxy(ts_fd, &x_tmp, &y_tmp);
        printf("(%d, %d)\n", x_tmp, y_tmp);
        if(x_tmp <= 400 && x_tmp > 0)
        {
            show_color(0xFFFFFF, 0, 0, 800, 480);
        }
        else if(x_tmp <= 800 && x_tmp > 400)
        {
            show_pic_full("image/10.ebm");
        }
    }

    // 3.关闭触摸屏文件
    close(lcd_fd);
    close(ts_fd);

    return 0;
}

//获取点击x,y坐标轴
void getxy(int ts_fd,  int *x, int *y)
{
    struct input_event touch_data;
    bzero(&touch_data, sizeof(touch_data));
    read(ts_fd, &touch_data, sizeof(touch_data));
    if (touch_data.type == EV_ABS)
    {
        if (touch_data.code == ABS_X)
            *x = touch_data.value;
        if (touch_data.code == ABS_Y)
            *y = touch_data.value;
        if (*x != 0 && *y != 0)
        {
            *x = (*x) * 800 / 1024;
            *y = (*y) * 480 / 600;
        }
    }
    if (touch_data.type == EV_KEY && touch_data.code == BTN_TOUCH && touch_data.value == EV_SYN)
    {
        *x = 0;
        *y = 0;
    }
}

//打开linux 的linux文件
int open_file(char *path)
{
    int lcd_fd;                    //定义变量
    lcd_fd = open(path, O_RDWR); //打开文件
    if (lcd_fd == -1)              //判断lcd_fd是否等于-1,等于（打开失败）
    {
        perror("open lcd failed"); //打开失败输出open failed
        return 1;
    }
    return lcd_fd;
}

//显示图片
void show_pic_full(char *path)
{
    int img_fi;
    img_fi = open_file(path);
    // 3.读取源文件到,显存，显示颜色
    read(img_fi, FB, 800 * 480 * 4);
    close(img_fi);
}
//显示颜色
void show_color(unsigned int color, int x_start, int y_start, int w, int h)
{
    int x, y;
    for (y = y_start; y < y_start + h; y++)
        for (x = x_start; x < x_start + w; x++)
            *(FB + x + 800 * y) = color;
}


//  2.映射显存
void mem_map(int lcd_fd)
{
    FB = mmap(NULL,                   // 指定映射的地址（一般填NULL，由系统随机分配）
              800 * 480 * 4,          // 内存的大小（开发板屏幕4*800*480字节）
              PROT_READ | PROT_WRITE, // 保护权限（PROT_READ|PROT_WRITE）
              MAP_SHARED,             // 共享的	MAP_SHARED
              lcd_fd,                 // 映射的文件描述符
              0);                     // 映射后偏移量（一般填0，不偏移）
    if (FB == MAP_FAILED)
        perror("mem map fialed\n");
    return;
}