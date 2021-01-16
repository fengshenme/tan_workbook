#include <stdio.h>

// static int func_1(int a, int b);
extern int func_1(int a, int b);

int main(int argc, char const *argv[])
{
    int a = 5, b = 9;

    printf("%d \n", func_1(a, b));
    return 0;
}

//返回最小值
int func_2(int a, int b)
{
    return a > b ? b : a;
}
int func_3(void)
{
    printf("nisds;kksl\n");
    return 0 ;
}
