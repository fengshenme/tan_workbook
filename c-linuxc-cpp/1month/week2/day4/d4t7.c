#include <stdio.h>

/**
 * unsigned long long的最大值:18446744073709551615 
 * n 120000
 * 编写一个函数 Fibonacci()，要求程序输出第 n 项斐波那契数，n 由用户输入。 斐波那契数列：1, 1, 2, 3, 5, 8, 13, 21,...
 *  1 0+1 1+1 1+2 2+3 3+5 5+8
*/
long long unsigned int Fibonacci(long long unsigned int n, long long unsigned int a, long long unsigned int b)
{

    if (n == 0)
        return 0;
    long long unsigned  int c = b;
    b = a + b;
    a = c;
    printf("%llu, ", b); //放在递归前是升序打印
    Fibonacci(--n, a, b);
    // printf("%d, ", b); // 放在递归后是降序打印
    if (n == 0)
        printf("\n%llu \n", b);

    return b;
}

int main(int argc, char const *argv[])
{
    long long unsigned  int a;
    scanf("%llu", &a);
    while (getchar() != '\n')
        ;
    Fibonacci(a, 1, 0);
    return 0;
}
