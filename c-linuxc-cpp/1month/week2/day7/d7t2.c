#include <stdio.h>

/*
实验题4;定义一个结构体变量(包括年月日)。计算该日在本年中是第几天？注意闰年问题
*/
struct yearmday
{
    unsigned int year;
    unsigned int month;
    unsigned int day;
};

int main(int argc, char const *argv[])
{
    struct yearmday ya;
    printf("请输入年月日,计算是当年的第几天\n");
    printf("年份:");
    scanf("%d", &(ya.year)); while (getchar() != '\n');
    printf("月份:"); 
    scanf("%d", &(ya.month)); while (getchar() != '\n');
    printf("天数:");
    scanf("%d", &(ya.day)); while (getchar() != '\n');
    printf("%d年%d月 %d日\n",ya.year,ya.month,ya.day);
    // 0为平年 1为闰年
    int a = 0;
    // 能被4整除的大多是闰年；能被100整除而不能被400整除的年份不是闰年；
    // 能被3200整除的也不是闰年；如1900年是平年，2000年是闰年，3200年不是闰年。
    if (ya.year % 4 == 0)
    {
        a = 1;
        if (ya.year % 100 == 0 && ya.year % 400 != 0)
        {
            a = 0;
        }
    }
    // int mon[7] = {1,3,5,7,8,10,12} ;// 31
    // int ac[5] =  {2,4,6,9,11};   //30
    int count = 0;
    int i;
    for ( i = 1; i < ya.month; i++)
    {
        if ((i >= 8 && i % 2 == 0) || (i < 8 && i % 2 != 0))
        {
            count += 31;
        }
        else
        {
            count += 30;
        }
    }
    count += ya.day;
    if (ya.month > 2)
    {
        if (a == 1)
        {
            count--;
        }
        else
        {
            count -= 2;
        }
    }

    printf("这是今年第%d天\n", count);

    return 0;
}

