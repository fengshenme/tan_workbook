#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>  


void play_a(int lcd_fd, unsigned int *color, int i,int sum);

// 3.多种颜色循环切换（间隔1秒）
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
    unsigned int sum = 480 * 800;
    // 定义循环颜色
    unsigned int color[7] = {0x00C00000, 0x00FF0000, 0x00FFC000, 0x00FFFF00, 0x0092D050, 0x0000B05, 0x00FFFFFF };
    while (1)
    {
        for (size_t i = 0; i < 7; i++)
        {
             play_a( lcd_fd, color, i, sum); // 第一回刷不完全,需要在补一次
             play_a( lcd_fd, color, i, sum);
            //  sleep(1);
             usleep(3000*1000);
        }
    }

    // 3.关闭LCD文件
    close(lcd_fd);

    return 0;
}
// 2.写入文件
void play_a(int lcd_fd, unsigned int *color, int i, int sum)
{
            unsigned int *p = malloc(4 * sum);
            int count = 0;
            for (size_t j = 0; j < sum; j++)
            {
                
                p[j] = color[i];
                //3kb就写入一次文件 这个显示屏线扫描3200字节
                if (255*3 <= sum-j && count == 255*3)
                {
                    
                    int flags = write(lcd_fd, &p[j-255*3], count*4);
                    if (flags == -1)
                    {
                        printf("write failed\n");
                        exit(0);
                    }
                    count = 0;
                }
                count ++;
                if(255*3 > sum-j &&  1 == sum - j)
                {
                    write(lcd_fd, &p[j-count], 4*count);
                }
                
            }

            free(p);
            lseek(lcd_fd, 0, SEEK_SET);
}