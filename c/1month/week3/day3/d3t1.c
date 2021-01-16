
#include <stdio.h>

int main(void)

{
    unsigned int a = 0x12345678;
    char *p = (char *)&a;
    // 打印出 78 为大端序 12 为小端序
    printf("0x%x\n", *p );

    return 0;
}