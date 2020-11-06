#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a = -1;

    if(++a)
        printf("1:%d\n", a);
    else if(a++)
        printf("2:%d\n", a);
    else if(a++)
        printf("3:%d\n", a);
    else if(a++)
        printf("4:%d\n", a);
    else
        printf("5:%d\n", a);

    printf("a:%d\n", a); // 0 0 1 p3 2 
    return 0;
}