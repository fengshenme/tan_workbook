#include <stdio.h>

int main(int argc, char const *argv[])
{

    int i, j, k, flag;
    int a[100] = {0};
    a[0] = 2;
    k = 1;
    printf("%d ", a[0]);
    for (i = 3; i < 100; i++)
    {
        flag = k;
        for (j = 0; j < k; j++)
        {
            if (i % a[j] == 0)
            {
                flag++;
            }
            
        }
        if (flag == k)
        {
            // printf("[%d]:%d ", __LINE__, i);
            printf("%d ", i);
            a[k] = i;
            k++;
        }
    }
    printf("\n");
    return 0;
}