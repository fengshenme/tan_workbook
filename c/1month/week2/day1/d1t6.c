#include <stdio.h>

/**
 * 实验5 题1
 * 
*/
int main(int argc, char const *argv[])
{
    int a[3][5] = {{1, 2, 19, 4, 5}, {6, 7, 18, 9, 10}, {11, 22, 13, 14, 15}};

    printf("获取地址\n");
    // int *p = &a[2][0];
    printf("a[2][3]一种方法0x%lX\n", &a[2][3]);
    // printf("%d\n", p[3]);
    int *p = a;
    printf("a[2][0]二种1:0x%lX ,2:0x%lX\n",&a[2][0], p+10);

    printf("a[2][0]二种1:0x%lX ,2:0x%lX, 2:0x%lX\n",&a[2][0], p+10, a[2]);
    
    int (*k)[15] = &a;
    printf("a[0][0]3种0x%lX, 0x%lX, 0x%lX, 0x%lX\n",&a[0][0], &a[0], p, k[0]);
    printf("%d-%d-%d\n",*&a[2][3],*p+10,*p);

    return 0;
}
