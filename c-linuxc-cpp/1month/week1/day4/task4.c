#include <stdio.h>

int main(int argc, char const *argv[])
{
    // 一个水分子的重量 单位为克
    float a = 3.0e-23;
    // 1 夸脱水大约有 950g 单位为克
    int b = 950;
    int n = 0;
    printf("请输入水的夸脱数:");
    scanf("%d", &n); while (getchar() != '\n');
    // 水分子数量
    long double c; 
    c = n*b / a;
    printf("水分子数量 : %.Lf \n", c);

    return 0;
}
