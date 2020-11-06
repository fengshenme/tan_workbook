#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

// 显示德国国旗？
/******************主函数***********************/
int main(int argc, char const *argv[])
{
    // 打开LCD文件。”/dev/fb0”
    int lcd_fd;
    lcd_fd = open("/dev/fb0", O_RDWR);
    if (lcd_fd == -1)
    {
        perror("open lcd failed");
        return 1;
    }
    // 2.德国国旗三个颜色由上到下黑0x00000000 红0x00FF0000 黄0x00FFFF00
    // unsigned int color = 0x00FF0000;
    unsigned int colors[384000] = {[0 ... 128000] = 0x00000000, 
                    [128001 ... 256000] = 0x00FF0000, [256001 ... 383999] = 0x00FFFF00};
    
    // write(lcd_fd, &color, 4);
    write(lcd_fd, colors, 4 * 800 * 480);
    // 3.关闭LCD文件
    close(lcd_fd);

    return 0;
}