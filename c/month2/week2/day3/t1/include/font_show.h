#ifndef __FONTCH_H__
#define __FONTCH_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>


/**
 * @brief 初始化字体库
 * 
 * @return int 
 */
int Init_Font(void);
/**
 * @brief 关闭字体库
 * 
 */
void UnInit_Font(void);
/**
 * @brief 清空区域
 * 
 * @param X x轴从0开始起始位置
 * @param Y y轴从0开始起始位置
 * @param width 宽
 * @param height 高
 * @param color 背景颜色
 * @return int 
 */
int Clean_Area(int X, int Y, int width, int height, unsigned long color);
/**
 * @brief 中文显示
 * 
 * @param x 
 * @param y 
 * @param color 
 * @param ch 
 * @param size 
 * @return int 
 */
int Draw_TextX(unsigned int x, unsigned int y, unsigned long color, const unsigned char ch[], int size);
/**
 * @brief 英文显示
 * 
 * @param x 
 * @param y 
 * @param color 
 * @param ch 
 * @param size 
 * @return int 
 */
int Draw_ASCIIX(unsigned int x, unsigned int y, unsigned long color, const unsigned char ch[], int size);

/**
 * @brief 显示字符
 * 
 * @param x 
 * @param y 
 * @param string 要显示的字符串
 * @param color 
 * @param size 
 * @return int 
 */
int Display_characterX(unsigned int x, unsigned int y, unsigned char *string, unsigned int color, int size);

int utf8ToUnicodeChar(unsigned char *ch, int *unicode);

int utf8ToUnicode(unsigned char *utf8_str,
                  unsigned short *unicode_str,
                  int unicode_str_size);

int gb2312ToUtf8(char *ptDestText,
                 int nDestLength,
                 char *ptSrcText,
                 int nSrcLength);

int utf8ToGb2312(char *gb2312_str,
                 int len_gb2312,
                 char *utf8_str,
                 int len_utf8);

#endif