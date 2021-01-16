#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

// 意大利国旗可以如何显示)？
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
    // 2.意大利国旗三个颜色由上到下绿0x0000B050 白0x00FFFFFF 红0x00FF0000
    unsigned int colors[800*480];
    int i, j, num=0;
    // 循环显示
    for (i = 0; i < 480; i++)
    {
        for (j = 0; j < 800; j++)
        {

            if (j <= 266)
            {
                colors[num] = 0x0000B050;
            }
            if (532 > j && j > 266)
            {
                colors[num] = 0x00FFFFFF;
            }
            if (j >= 532)
            {
                colors[num] = 0x00FF0000;
            }
            num++;
        }
    }
    // write(lcd_fd, &color, 4);
    write(lcd_fd, colors, 4 * 800 * 480);
    // 3.关闭LCD文件
    close(lcd_fd);
    

    return 0;
}