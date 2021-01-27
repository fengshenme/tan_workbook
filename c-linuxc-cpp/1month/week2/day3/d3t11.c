#include <stdio.h>

/**
 * 一个有 N 个元素的整型数组，求该数组的各个子数组中，
 * 子数组之和的最大值是多少？ 例如数组 a[6] = {-2, 5, 3, -6, 4, -8, 6};则子数组之和的最大值是 8 (即 a[1] + a[2])。
*/
int main(int argc, char const *argv[])
{
    int n, i, j, k;
    printf("请输入数组大小：");
    scanf("%d", &n);
    int a[n], max = 0; // = {-2, 5, 3,-6};// 2 ,2 5,2 5 3, 5, 5 3 ,3
    int *p = a;
    printf("请输入数组各项数值):");
    for (k = 0; k < n; k++)
        scanf("%d", &a[k]);
    
    for (i = 0; i < n; i++)
    {
        int s = 0;
        for (j = 0; j < n - i; j++)
        {
            s += *(p + i + j);
            max = max > s ? max : s;
        }
    }
    printf("%d\n", max);

    return 0;
}
