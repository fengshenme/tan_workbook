#ifndef __FONTCH_H__
#define __FONTCH_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int Init_Font(void);
void UnInit_Font(void);
int Create_LineEdit(int X, int Y, int width, int height);
int Clean_Area(int X, int Y, int width, int height);
int Draw_Text16(unsigned int x, unsigned int y, unsigned long color, const unsigned char ch[]);
int Draw_TextX(unsigned int x, unsigned int y, unsigned long color, const unsigned char ch[], int size);
int Draw_ASCII(unsigned int x, unsigned int y, unsigned long color, const unsigned char ch[]);
int Draw_ASCIIX(unsigned int x, unsigned int y, unsigned long color, const unsigned char ch[], int size);
int Display_character(unsigned int x, unsigned int y, unsigned char *string, unsigned int color);
int Display_characterX(unsigned int x, unsigned int y, unsigned char *string, unsigned int color, int size);

/**
 * @brief 编码转换
 * 
 * @param from_charset 
 * @param to_charset 
 * @param inbuf 
 * @param inlen 
 * @param outbuf 
 * @param outlen 
 * @return int 
 */
int code_convert(char *from_charset, char *to_charset, char *inbuf, size_t inlen,
		char *outbuf, size_t outlen) ;

/**
 * @brief utf-8转gb2312
 * 
 * @param inbuf 
 * @param inlen 
 * @param outbuf 
 * @param outlen 
 * @return int 
 */
int u2g(char *inbuf, size_t inlen, char *outbuf, size_t outlen);
/**
 * @brief gb2312转utf-8
 * 
 * @param inbuf 
 * @param inlen 
 * @param outbuf 
 * @param outlen 
 * @return int 
 */
int g2u(char *inbuf, size_t inlen, char *outbuf, size_t outlen);

#endif