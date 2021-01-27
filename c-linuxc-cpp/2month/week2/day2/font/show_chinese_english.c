#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "libfont/font.h"



int main(int argc,const char **argv)
{
	// 初始化字体库
	Init_Font();
	
	// 清空区域
	Clean_Area(100, 100, 64*10, 64, 0xFFFFFF);
	
// int   Display_characterX(unsigned int x,          //x坐标起始点
                         // unsigned int y,          //y坐标起始点
						 // unsigned char *string,   //GB2312 中文字符串
						 // unsigned int color ,     //字体颜色值
						 // int size);               //字体放大倍数 1~8
	
	unsigned char * str = malloc(30);
	//  str = "GZ2039大家好！！！~";
	// unsigned char * str1 = "GZ2039大家好！！！~";

	// 显示中英文（1倍字体：16*16）
	Display_characterX(100, 100, "GZ2039大家好！！！~", 0xFF0000, 4);	// 64*64
	free(str);
	// 关闭字体库
	UnInit_Font();
}



