#include <stdio.h>

float func_swap(float a, int b);

// # 整数次幂
int main(int argc, char const *argv[])
{
    float a = 3.14, b = -2;
    
    printf("c:%.6f\n", func_swap(a, b));

    return 0;
}

float func_swap(float a, int b)
{

    float sum = 1.0;

    if (b>0)
    {
        for (size_t i = 0; i < b; i++)
            sum*=a;
        
    }
    else
    {
        for (size_t i = 0; i < -b; i++)
            sum /= a;
    }
    
    return sum;
}
