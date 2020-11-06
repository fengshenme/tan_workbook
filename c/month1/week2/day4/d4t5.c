#include <stdio.h>
/**
 * 编写一个函数 my_power，用循环的方法实现返回一个 float 类型数的某个整数次幂(保留 6 位小数)。例如： 调用 my_power(3.14, -2)返回 0.101424
 */
float my_power(float x, int y)
{
    if (y == 0)
        return 1;

    return y < 0 ? 1 / x * my_power(x, ++y) : x * my_power(x, --y);
}

int main(int argc, char const *argv[])
{
    float a = 3.14;
    int b = -2;
    printf("%0.6f\n", my_power(a, b));
    return 0;
}
