
#include "include/fontch.h"
#include "include/char_conversion.h"




int main(int argc, const char **argv)
{
    // 初始化字体库
    Init_Font();

    // 清空区域
    // Clean_Area(100, 100, 64 * 10, 64, 0xFFFFFF);
    Clean_Area(10, 10, 64 * 10, 64);

    // int   Display_characterX(unsigned int x,          //x坐标起始点
    // unsigned int y,          //y坐标起始点
    // unsigned char *string,   //GB2312 中文字符串
    // unsigned int color ,     //字体颜色值
    // int size);               //字体放大倍数 1~8

    char *str = malloc(30);
    char *tmp = malloc(30);
    strcpy(tmp, "确定 取消");
    utf8ToGb2312(str, sizeof(30), tmp, strlen(tmp));
     
    // unsigned char * str1 = "GZ2039大家好！！！~";

    // 显示中英文（1倍字体：16*16）
    Display_characterX(10, 10, (unsigned char *)str, 0xFF0000, 4); // 64*64
    free(str);
    free(tmp);
    // 关闭字体库
    UnInit_Font();
}

 
