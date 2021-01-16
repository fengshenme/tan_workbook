#include <stdio.h>

int main(int argc, char const *argv[])
{
    // int a=4,b=3,*p,*q,*w;
    // p=&a;q=&b;w=p;q=NULL;
    // // *q=0;  // 两边类型不同, int * 与 int
    //  w=p;  // int * , int *
    //  *p=a;  // int * int * 这里赋值的是元素的地址 a相当于&a
    //  *p=*w; // 变量赋值给变量 int * , int *
    //  printf("%d \n", *p);
    /*
        2.指针也可以使用数组下标形式，访问数组元素。如下标为正数（如s[2]），从arr向后偏移2个位置, 负数（如s[-2]），从arr向前偏移2个位置
        题7
    */
     int x[8]={8,7,6,5,0,0},*s;
     s=x+3;
     printf("%d\n",s[2]);

     // 题8
     int a[10]={1,2,3,4,5,6,7,8,9,10},*p=&a[3],b;
     b=p[5];
     printf("%d\n",b);

    return 0;
}
