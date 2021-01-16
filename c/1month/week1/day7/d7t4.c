#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n1,n2;
    printf("输入两个数,用空格分开,计算两数间偶数和奇数");
    scanf("%d%d", &n1, &n2); while (getchar() != '\n');

    printf("这是偶数:");
    int i;
    for ( i = n1; i < n2; i++)
    {
        if (i%2 == 0)
        {
            printf("%d  ", i);
        }
    }
    printf("\n这是奇数: ");
    for ( i = n1; i < n2; i++)
    {
        if (i%2 != 0)
        {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}
