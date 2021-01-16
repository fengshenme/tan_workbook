#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

// 3.多种颜色循环切换（间隔1秒）
/******************主函数***********************/
int main(int argc, char const *argv[])
{

    // 2.德国国旗三个颜色由上到下绿0x0000B050 白0x00FFFFFF 红0x00FF0000
    unsigned int color[3] = {0x0000B05, 0x00FFFFFF, 0x00FF0000};
    int num = 800 * 480;
    for (size_t i = 0; i < 3; i++)
    {
        // 打开LCD文件。”/dev/fb0”
        int lcd_fd;
        lcd_fd = open("/dev/fb0", O_RDWR | O_TRUNC);
        if (lcd_fd == -1)
        {
            perror("open lcd failed");
            return 1;
        }
        unsigned int color[i];
        // 尝试使用循环，显示更多的位置，直至全屏
        for (size_t j = 0; j < num; j++)
        {
            write(lcd_fd, color[i], 4 * num);
        }
        // 3.关闭LCD文件
        close(lcd_fd);
        sleep(3);
    }
    

    return 0;
}