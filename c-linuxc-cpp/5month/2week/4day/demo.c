#include <stdio.h>

#define MAX(a, b) (a > b ? a : b)

    union
    {
        int a;
        char b;
    } c;

int main(int argc, char const *argv[])
{
    int a = 9, b = 3;
    printf("%d\n", MAX(b, a));



    c.a = 0x12345678;

     printf("%#x\n", c.b);

    return 0;
}
