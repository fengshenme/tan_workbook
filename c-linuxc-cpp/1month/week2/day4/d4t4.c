#include <stdio.h>

int get_max(int a ,int b, int c)
{   
    int max = a>b ? a : b;

    return max > c ? max : c ;
}

/**
 * 3、 编写一个函数，使其返回 3 个整型参数中的最大值
 * 
*/
int main(int argc, char const *argv[])
{
    int a=9, b=10, c=987;
    printf("%d\n", get_max(a,b,c));   
    
    return 0;
}
