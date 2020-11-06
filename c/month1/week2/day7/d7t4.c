#include <stdio.h>

double get_max(double a, double b);

double get_min(double a, double b);

double get_sub(double a, double b);

double get_add(double a, double b);

// 6、 声明 4 个函数，并把一个指针数组初始化为指向它们。每个函数接受两个 double 参数并返回 double 值
int main(int argc, char const *argv[])
{
    double a = 3.0, b = 1.0;
    double (*func_arr[4])(double, double);

    func_arr[0] = get_max;
    func_arr[1] = get_min;
    func_arr[2] = get_sub;
    func_arr[3] = get_add;

    printf("最大值%lf\n", (*func_arr[0])(a, b));
    printf("最小值%lf\n", (*func_arr[1])(a, b));
    printf("减法%lf\n", (*func_arr[2])(a, b));
    printf("加法%lf\n", (*func_arr[3])(a, b));

    return 0;
}

double get_max(double a, double b)
{
    return a > b ? a : b;
}

double get_min(double a, double b)
{
    return a < b ? a : b;
}

double get_sub(double a, double b)
{
    return a - b;
}

double get_add(double a, double b)
{
    return a + b;
}
