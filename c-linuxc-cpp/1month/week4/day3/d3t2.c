#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/mman.h>

/*多种颜色循环切换，间隔一秒*/

int main()
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
    unsigned int *FB;
    FB = mmap(NULL,                   // 指定映射的地址（一般填NULL，由系统随机分配）
              800 * 480 * 4,          // 内存的大小（开发板屏幕4*800*480字节）
              PROT_READ | PROT_WRITE, // 保护权限（PROT_READ|PROT_WRITE）
              MAP_SHARED,             // 共享的	MAP_SHARED
              lcd_fd,                 // 映射的文件描述符
              0);                     // 映射后偏移量（一般填0，不偏移）

    // 2.操作显存，显示颜色
    // unsigned int color_red = 0x00FF0000;
    int  j;
    // 定义循环颜色
    unsigned int color[7] = {0x00C00000, 0x00FF0000, 0x00FFC000, 0x00FFFF00, 0x0092D050, 0x0000B05, 0x00FFFFFF};
    while (1)
    {
        // for(7次)
        // for(800*480次)
        for (size_t i = 0; i < 7; i++)
        {
            for (j = 0; j < 480 * 800; j++)
            {
                *(FB + j) = color[i];
            }
            sleep(1);
            //  usleep(1000*1000);
        }
    }

    // 3.取消映射并关闭LCD
    munmap(FB, 800 * 480 * 4);
    close(lcd_fd); //关闭文件

    return 0;
}
