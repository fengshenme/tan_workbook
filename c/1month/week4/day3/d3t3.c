#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/mman.h>


//映射显存
unsigned int *FB; //全局变量

void show_color(unsigned int color, int x_start, int y_start, int w, int h);
int open_lcd(char *lcd_path);
void mem_map(int lcd_fd);


/*多种颜色分层显示*/
int main()
{
    // 1.打开lcd文件
     int lcd_fd;// 设备文件描述符
    lcd_fd = open_lcd("/dev/fb0");
    // 2.映射显存
    mem_map(lcd_fd);
    // 3.操作显存，显示颜色 定义循环颜色
    unsigned int color[5] = {0x00FFFFFF, 0x00000000, 0x00FF0000, 0x00009200, 0x000000FB};

    show_color(color[0], 0, 0, 800, 480);
    for (size_t i = 0; i < 4; i++)
        show_color(color[i + 1], 200 + i * 50, 40 + i * 50, 400 - i * 100, 400 - i * 100);
    // 4.取消映射并关闭LCD
    munmap(FB, 800 * 480 * 4);
    close(lcd_fd); //关闭文件1

    return 0;
}

void show_color(unsigned int color, int x_start, int y_start, int w, int h)
{
    int x, y;
    for (y = y_start; y < y_start + h; y++)
        for (x = x_start; x < x_start + w; x++)
            *(FB + x + 800 * y) = color;
}

//打开linux 的linux文件
int open_lcd(char *lcd_path)
{
    int lcd_fd;                      //定义变量
    lcd_fd = open(lcd_path, O_RDWR); //打开LCD文件
    if (lcd_fd == -1)                //判断lcd_fd是否等于-1,等于（打开失败）
    {
        perror("open lcd failed"); //打开失败输出open failed
        return 1;
    }
    return lcd_fd;
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
        return ;
}