#include <stdio.h>

/**
 * 输入一个华氏温度，要求输出摄氏温度。要求结果保留 2 位小数。 
 * 转换公式为：c = 5*(F-32)/9
 * 
 * 
*/
int main(int argc, char const *argv[])
{
    
    float a ;
    printf("输入华式温度:");
    scanf("%f", &a); while (getchar() != '\n');

    float b = 5*(a-32)/9;

    printf("摄氏温度:%.2f\n", b);

    return 0;
}
