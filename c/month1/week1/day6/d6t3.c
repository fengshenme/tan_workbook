#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a = 12;
    int b = ++a;
    b++;

    // a 13 b 13 b 14   a 14 b 15
    // 1: 13 2: 15 3: 14 b: 15
    printf("1:%d\n", a++);
    printf("2:%d\n", ++b);
    printf("3:%d\n", a);
    printf("4:%d\n", b);

    return 0;
}
