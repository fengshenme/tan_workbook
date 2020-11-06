/*
9、编写一个 transform()函数，它接受 4 个参数：包含 double 类型数据的源数组名，double 类型的目标数组名， 
表示数组元素个数的 int 变量以及一个函数名(或者等价的指向函数的指针)。
transform()函数把指定的函数作 用于源数组的每个元素，并将返回值放到目标数组中。 
例如：transform(source, target, 100, sin); 这个函数调用 sin(source[0])赋给 target[0]，等等。
共有 100 个元素。在一个程序中测试该函数，调用 4 次 transform()，
分别使用 math.h 函数库中的两个函数以及自己设计的两个适合的函数作为参数。
double sqrt(double x)
double tanh(double x)
*/

#include <stdio.h>
#include <math.h>

void transform(double *source, double *target, int num, double (*p)(double));
double absac(double a);

double suber(double a);

int main(int argc, char const *argv[])
{
    int c = 10;
    double arr1[10] = {[0 ... 9] = 9};
    double arr2[10] = {0};
    transform(arr1, arr2, c, sqrt);
    transform(arr1, arr2, c, tanh);
    transform(arr1, arr2, c, absac);
    transform(arr1, arr2, c, suber);

    return 0;
}

void transform(double *source, double *target, int num, double (*p)(double))
{
    for (size_t i = 0; i < num; i++)
    {
        target[i] = (*p)(source[i]);
        printf("%.2lf ", target[i]);
    }
    printf("\n--------\n");
}

double absac(double a)
{
    return a >= 0 ? a : -a;
}

double suber(double a)
{
    return --a;
}
