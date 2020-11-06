#include "../include/font_show.h"




int main(int argc, const char **argv)
{
    // 初始化字体库
    Init_Font();

    // 清空区域
    // Clean_Area(100, 100, 64 * 10, 64, 0xFFFFFF);
    // Clean_Area(10, 10, 16*2*5 , 32, 0xFFFFFF);

    // int   Display_characterX(unsigned int x,          //x坐标起始点
    // unsigned int y,          //y坐标起始点
    // unsigned char *string,   //GB2312 中文字符串
    // unsigned int color ,     //字体颜色值
    // int size);               //字体放大倍数 1~8

    char *str = malloc(200);
    char *tmp = malloc(200);
    strcpy(tmp, "选择图片排序方式: 时间 文件大小 文件创建时间");
    utf8ToGb2312(str, sizeof(200), tmp, strlen(tmp));
     
    // unsigned char * str1 = "GZ2039大家好！！！~";

    // 显示中英文（1倍字体：16*16）
    Display_characterX(10, 10, (unsigned char *)str, 0xFF0000, 2); // 64*64
    free(str);
    free(tmp);
    // 关闭字体库
    UnInit_Font();
}

 
