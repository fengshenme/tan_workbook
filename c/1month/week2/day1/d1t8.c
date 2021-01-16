#include <stdio.h>

// 实验5 题3
/**
 * 
 * 用变量 a 给出下面的定义 
 * a) 一个整型数 
 * int a;
 * b) 一个指向整型数的指针 
    int b = 2;
    int *a = &b;
    printf("%d\n", *a)
 * c) 一个指向指针的的指针，它指向的指针是指向一个整型
    int c = 3;
    int *e = &c;
    int *a = e;
    printf("%d\n", *a);
 * d) 一个有 10 个整型数的数组 
      int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
 * e) 一个有 10 个指针的数组，该指针是指向一个整型数的 
    int b[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *a[10];
    for (size_t i = 0; i < 10; i++)
    {
        a[i] = &b[i];
        printf("%d\n", *a[i]);
    }
 * f) 一个指向有 10 个整型数数组的指针 
    int b[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *a = &b[0];
    for (size_t i = 0; i < 10; i++)
        printf("%d\n", a[i]);
 * g) 一个指向函数的指针，该函数有一个整型参数并返回一个整型数\
 * int (*p) (int) ; 
 * h) 一个有 10 个指针的数组，该指针指向一个函数，该函数有一个整型参数并返回一个整型数
 * int (*a[10])(int);
*/
// odd and even numbe 返回1是偶数返回0是奇数
int odd_even(int num)
{
    return num%2 ? 0 : 1;
}
int main(int argc, char const *argv[])
{
    int (*p) (int) ;
    int d;
    scanf("%d",&d);while(getchar() != '\n');
    p = odd_even;
    if (p(d))
    {
        printf("偶数\n");
    }
    else
    {
       printf("奇数\n");
    }
    
    int (*a[10])(int);
    int i;
    for ( i = 0; i < 10; i++)
    {
        a[i] = odd_even;
        if (a[i](i))
        {
            printf("%d ",i);
            printf("偶数 \n");
        }
        else
        {
            printf("%d ",i);
            printf("奇数\n");
        }
    }
    
    return 0;
}















