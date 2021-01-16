#include <stdio.h>

// #  编写一个函数，使其返回 2 个整型参数中的最大值 
int max_value(int a, int b)
{
    return a>b ? a : b ;
}

int main(int argc, char const *argv[])
{
    int a = 100, b=222;

    printf("%d\n", max_value(a, b));

    return 0;
}
