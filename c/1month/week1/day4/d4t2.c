#include <stdio.h>


int main(int argc, char const *argv[])
{   
    char a ;
    printf("输入一个字符:");
    scanf("%c", &a);while (getchar() != '\n')
    {}
    
    printf("DEC: %d\n", a); // 十进制
    printf("HEX: 0x%X\n", a); // 16进制
    printf("OCT: 0%dO\n", a);  // 8进制

    return 0;
}
