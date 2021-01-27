#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

// 显示德国国旗（思考一下意大利国旗可以如何显示)？
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
    int i, j, num = 0;
    unsigned int sum = 480*800;
    unsigned int *p = malloc(4*sum);

    
    // 循环显示三分之一黑
    for (j = 0; j < 480; j++)
    {
        for (i = 0; i < 800; i++)
        {
            if (j <= 160)
            {
                p[num] = 0x00000000;
            }
            if (320 > j && j > 160)
            {
                p[num] = 0x00FF0000;
            }

            if (j >= 320)
            {
                p[num] = 0x00FFFF00;
            }
            num++;
        }
    }
    // write(lcd_fd, &color, 4);
    write(lcd_fd, p, 4 * 800 * 480);
    // 3.关闭LCD文件
    close(lcd_fd);
    free(p);
    return 0;
}
