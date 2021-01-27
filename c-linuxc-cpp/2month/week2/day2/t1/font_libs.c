
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include "include/font_libs.h"


int LCD_fd;
unsigned long *fb_mem = NULL;

#define FB_SIZE 800 * 480 * 4

/**
 * @brief // 初始化字体库
 * 
 * @return int 
 */
int Init_Font(void);
/**
 * @brief 关闭字体库
 * 
 */
void UnInit_Font(void);
int Create_LineEdit(int X, int Y, int width, int height);
int Clean_Area(int X, int Y, int width, int height);
int Draw_Text16(unsigned int x, unsigned int y, unsigned long color, const unsigned char ch[]);
int Draw_TextX(unsigned int x, unsigned int y, unsigned long color, const unsigned char ch[], int size);
int Draw_ASCII(unsigned int x, unsigned int y, unsigned long color, const unsigned char ch[]);
int Draw_ASCIIX(unsigned int x, unsigned int y, unsigned long color, const unsigned char ch[], int size);
int Display_character(unsigned int x, unsigned int y, unsigned char *string, unsigned int color);
int Display_characterX(unsigned int x, unsigned int y, unsigned char *string, unsigned int color, int size);

int Init_Font(void)
{

    //申请LCD操作许可、
    LCD_fd = open("/dev/fb0", O_RDWR);
    if (LCD_fd == -1)
    {
        perror("Open LCD");
        return -1;
    }

    //显存映射
    fb_mem = (unsigned long *)mmap(NULL,                   //程序空间的映射地址 ， 不确定可以赋值NULL，由系统分配
                                   FB_SIZE,                //映射的内存的大小    LCD 800*480*4
                                   PROT_READ | PROT_WRITE, //映射区的保护操作           PROT_EXEC  Pages may be executed.
                                                           //                           PROT_READ  Pages may be read.
                                                           //                           PROT_WRITE Pages may be written.
                                                           //							PROT_NONE  Pages may not be accessed.
                                   MAP_SHARED,             //共享标志            MAP_SHARED     MAP_PRIVATE
                                   LCD_fd,                 //目标文件描述符 ----> 内存映射的目标文件
                                   0);                     //映射内存的偏移大小   默认从头开始，0

    if (fb_mem == MAP_FAILED)
    {
        perror("Mmap LCD");
        return -1;
    }

    //Show_Bmp(0,0,"logo.bmp");

    return 0;
}

void UnInit_Font(void)
{

    //撤销映射
    munmap(fb_mem,   //映射后的地址，通过mmap返回的值
           FB_SIZE); //映射的大小

    close(LCD_fd);
}


int Clean_Area(int X, int Y, int width, int height)
{
    int x, y;

    for (y = Y; y < Y + height; y++)
    {
        for (x = X; x < X + width; x++)
        {
            fb_mem[y * 800 + x] = 0xFFFFFFFF;
        }
    }
    return 0;
}


int Draw_TextX(unsigned int x, unsigned int y, unsigned long color, const unsigned char ch[], int size)
{
    unsigned short int i, j, k, m;
    unsigned char mask, buffer;
    for (i = 0; i < 16; i++)
    {
        mask = 0x80;        //掩码
        buffer = ch[i * 2]; //提取一行的第一个字节
        for (j = 0; j < 8; j++)
        {
            if (buffer & mask)
            {
                for (k = 0; k < size; k++)
                {
                    for (m = 0; m < size; m++)
                    {
                        fb_mem[(y + i * size + m) * 800 + (x + j * size + k)] = color;
                    }
                }
            }
            mask = mask >> 1;
        }
        mask = 0x80;
        buffer = ch[i * 2 + 1];
        for (j = 0; j < 8; j++)
        {
            if (buffer & mask)
            {
                for (k = 0; k < size; k++)
                {
                    for (m = 0; m < size; m++)
                    {
                        fb_mem[(y + i * size + m) * 800 + (x + (j + 8) * size + k)] = color;
                    }
                }
            }
            mask = mask >> 1;
        }
    }

    return 0;
}



int Draw_ASCIIX(unsigned int x, unsigned int y, unsigned long color, const unsigned char ch[], int size)
{
    unsigned short int i, j, k, m;
    unsigned char mask, buffer;

    for (i = 0; i < 16; i++)
    {
        mask = 0x80;
        buffer = ch[i];
        for (j = 0; j < 8; j++)
        {
            if (buffer & mask)
            {
                for (k = 0; k < size; k++)
                {
                    for (m = 0; m < size; m++)
                    {
                        fb_mem[(y + i * size + m) * 800 + (x + j * size + k)] = color;
                    }
                }
            }
            mask = mask >> 1;
        }
    }

    return 0;
}


int Display_characterX(unsigned int x, unsigned int y, unsigned char *string, unsigned int color, int size)
{
    int k, xx;
    unsigned char qh, wh;
    const unsigned char *mould;
    unsigned int length = strlen((const char *)string);

    for (k = 0, xx = x; k < length; k++)
    {
        if (string[k] & 0x80) //中文字符
        {
            qh = string[k] - 0xa0;     //区号
            wh = string[k + 1] - 0xa0; //位号
            mould = &__CHS[((qh - 1) * 94 + wh - 1) * 32];
            Draw_TextX(4 * size + xx, y, color, mould, size); //加4为了让每个中文之间有一定的间隙
            xx += 16 * size;                                  //当前的中文字模为32*32,每次显示下一个中文时横向偏移32个bit
            k++;                                              //加载下一个中文，两次++操作，偏移2个字节
        }
        else
        {
            mould = &__ASCII[string[k] * 16];
            Draw_ASCIIX(4 * size + xx, y, color, mould, size);
            xx += 8 * size; //当前的ASCII字模显示为8*16,每次显示下一个中文时横向偏移8个bit
        }
    }
    return 0;
}

