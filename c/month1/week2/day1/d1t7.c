#include <stdio.h>

double max_min_bet_diff(double *p, int size);
// 实验5 题2
int main(int argc, char const *argv[])
{
    double arr[10] = {90.7,2,3,55,5,6,7,8,90,12};
    double *p = arr;
    int size = sizeof(arr)/sizeof(double);

    printf("%lf\n", max_min_bet_diff(p, size));
    return 0;
}

/**
 * 编写一个函数，返回一个 double 型数组中最大和最小值的差值，并在一个简单的程序中测试这个函数。
 * 
 */
double max_min_bet_diff(double *p, int size)
{
    double max=0, min=*p, md;
    int i = 0;
    for ( i = 0; i < size; i++)
    {
        md = *(p+i);
        if (max < md)
            max = md;
        if (min > md)
            min = md;
    }
    return max-min;    
}
