#include <stdio.h>

/**
 * 用递归的思想重做实验四的第 4 道题（my_power 函数）
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