// 编写一个函数，计算 1+2+3+4+…+n 的值
#include <stdio.h>

int sum(int n);

int main(int argc, char const *argv[])
{   
    int n;
    scanf("%d",&n);while (getchar()!='\n');
    
    printf("%d\n",sum(n));
    return 0;
}

int sum(int n)
{
    return n*(((float)n+1)/2);
}
