#include <stdio.h>
#include <math.h>

/**
  * 实验3  技术点强化
*/
void task0(void);
void task1(void);
void task2(void);
void task3(void);
void task4(void);
void task5(void);
void task6(void);

int main(int argc, char const *argv[])
{
    printf("================题1============= \n");
    task0();
    printf("================题2============= \n");
    task1();
    printf("================题3============= \n");
    task2();
    printf("================题4============= \n");
    task3();
    printf("================题5============= \n");
    task4();
    printf("================题6============= \n");
    task5();
    return 0;
}

/**
 * 实验3 技术点强化1
 * 编写一个程序，要求用相应的控制流语句往屏幕打印 26 个小写字母
 */
void task0(void)
{
    int i;
    for ( i = 65; i < 123; i++)
    {
        if ( i < 91 || i>96)
        {
            printf("%c ", i);
        }
    }
    printf("\n");

    
}

/** 
 * 技术点强化2
 * A-Z之间 的ascii编码  65-90
 * 编写一个程序，用户输入某个大写字母，产生一个金字塔图案。例如用户输入字母 E，则产生如下图案
     A
    ABA
   ABCBA
  ABCDCBA
 ABCDEDCBA
*/
void task1(void)
{
    char c ;
    int a;
    while (1)
    {
        printf("输入大写字符A-Z之间任意一个: ");
        scanf("%c", &c); while (getchar() != '\n');
        a = c;
        if (a > 64 && a < 91)
        {
            break ;
        } else
        {
            printf("输入字符无效! \n");
        }
    }
    
    for (size_t i = 0; i < 5; i++)
    {
        for (size_t k = i; k < 5; k++)
        {
            printf(" ");
        }// 69
        int j, l;
        for ( j = 0; j < i+1; j++)
        {
            printf("%c",a-4+j);
        }
        for ( l = j; l > 1 ; l--)
        {
            printf("%c",a+l-6);
        }
        
        printf("\n");
    }
    
}

/**
 * 题3
 * 编写一个程序，该程序读取输入直到遇到#字符，然后报告读取的空格数目、读取的换行符数目以及读取 的所有其他字符数目
*/
void task2(void)
{
    int space = 0;
    int lfb = 0;
    int elsb = 0;
    printf("输入键盘字符,按 # 退出 ");
    while (1)
    {
        char c ;
        int h;
        scanf("%c", &c);  //while (getchar() != '\n');
        h = c;
        switch (h)
        {
            case 35:
                printf("空格数目:%d 换行符数目: %d 其他字符数目 :%d \n", space, lfb, elsb);
                return 0;
            case 32:
                space++;
                break;
            case 10:
                lfb++;
                break;
            default:
                elsb++;
                break;
        }
        
    }
}

/**
 * 编写一个程序，接受一个整数输入，然后显示所有小于或等于该数的素数。
 * 
 * 思路1)：因此判断一个整数m是否是素数，只需把 m 被 2 ~ m-1 之间的每一个整数去除，如果都不能被整除，那么 m 就是一个素数。

    思路2)：另外判断方法还可以简化。m 不必被 2 ~ m-1 之间的每一个整数去除，只需被 2 ~  之间的每一个整数去除就可以了。如果 m 不能被 2 ~  间任一整数整除，m 必定是素数。例如判别 17 是是否为素数，只需使 17 被 2~4 之间的每一个整数去除，由于都不能整除，可以判定 17 是素数。

    原因：因为如果 m 能被 2 ~ m-1 之间任一整数整除，其二个因子必定有一个小于或等于 ，另一个大于或等于 。例如 16 能被 2、4、8 整除，16=2*8，2 小于 4，8 大于 4，16=4*4，4=√16，因此只需判定在 2~4 之间有无因子即可。

    # 编写一个程序，接受一个整数输入，然后显示所有小于或等于该数的素数。 编译需要加 -lm
    gcc d7t1.c -o a.out -Wall -lm
 * 
*/
void task3(void)
{
    unsigned int a;
    while (1)
    {
        printf("请输入大于2的数:");
        scanf("%u", &a); while (getchar() != '\n');
        if (a>2)
            break;
    }
    
    int i, j;
    for ( i = 2; i <= a; i++)
    {
        int b = (int) sqrt((double) i);
        // printf("%u\n",b);
        int c = 0;
        for ( j = 2; j <= b; j++)
        {
            if ( i%j == 0 )
            {
                c++;
                // printf("%d\n", i);
                break;
            }
        }
        if( !(c>0) ){
            printf("%u ", i);
        }
    }
}

/**
 * 输入一个华氏温度，要求输出摄氏温度。要求结果保留 2 位小数。 
 * 转换公式为：c = 5*(F-32)/9
 * 
 */ 
void task4(void)
{
    float a ;
    printf("输入华式温度:");
    scanf("%f", &a); while (getchar() != '\n');

    float b = 5*(a-32)/9;

    printf("摄氏温度:%.2f\n", b);
}

/**
 * 打印如下图案：
   *
  ***
 *****
*******
 *****
  ***
   *

*/
void task5(void)
{
    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = 4-i; j>1; j--)
        {
            printf(" ");
        }
        for (size_t k = 0; k <= i*2; k++)
        {
            printf("*");
        }
         printf("\n");
    }
    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = 0; j <= i; j++)
        {
            printf(" ");
        }
        for (size_t k = 5-i; k > i; k--)
        {
            printf("*");
        }
         printf("\n");

    }
}

/**
 * 将一个十进制数转换为十六进制数。比如输入 10，输出 0xA
 * 一.十进制转bai换十六进制
    若十进制数du23785转为十六进制，则用 23785/16=1486余............9, 1486/16=92余……zhi14, 92/16=5余………….12,
    5/16=0余……………..5，十六进制中，10对应为a、11对应为b、。。。。。。、15对应为f，再将余数倒写为5ce9,则十进制23785=十六进制5ce9。
    二.十六进制转换十进制
    十六进制数的第0位的权值为16的0次方，第1位的权值为16的1次方，第2位的权值为16的2次方。
    所以，在第N（N从0开始）位上，如果是是数 X （X 大于等于0，并且X小于等于 15，即：F）表示的大小为 X * 16的N次方。
    假设有一个十六进数 2AF5：
    用竖式计算： 2AF5换算成10进制:
    第0位： 5 * 16^0 = 5
    第1位： F * 16^1 = 240
    第2位： A * 16^2 = 2560
    第3位： 2 * 16^3 = 8192
    直接计算就是：
    5 * 16^0 + F * 16^1 + A * 16^2 + 2 * 16^3 = 10997
 * 
 */
void task6(void)
{
    int a ;
    printf("请输入十进制整数:");
    scanf("%d", &a); while (getchar() != '\n');
    int arr[20] = {0};
    int c = a;
    int i = 19;
    while(1)
    {
        arr[i] = c%16;
        if(c == 0){
            break;
        }
        c = c/16;
        i-- ;
    }
    printf("0x");
    for (size_t j = i+1; j < 20; j++)
    {
        int w = arr[j];
        switch (w)
        {
        case 10:
            printf("A");
            break;
        case 11:
            printf("B");
            break;
        case 12:
            printf("C");
            break;
        case 13:
            printf("D");
            break;
        case 14:
            printf("E");
            break;
        case 15:
            printf("F");
            break;
        default:
            printf("%d", w);
            break;
        }
    }
    printf("\n");

}








