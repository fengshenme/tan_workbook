#include <stdio.h>

int main(int argc, char const *argv[])
{

    char a = 0x12;
    char b = 0x34;
    char c = 0x56;
    char d = 0x78;
    int i = 0;       //所有位置0
    i = a << 24;     //先用a填充i的最高8位
    i |= b << 16;    //再用b填充i的次高8位
    i |= c << 8;     //再用c填充i的次低8位
    i |= d;          //最后用d填充i的最低8位
    printf("%#x\n", i); //输出12345678

    int j = i;
    // 0001 0010
    char a1 = j >> 24;
    char b1 = 0x00 | j >> 16;
    char c1 = 0x00 | j >> 8;
    char d1 = 0x00 | j ;

    printf("%#x,%#x,%#x,%#x", a1, b1, c1, d1);

    return 0;
}
