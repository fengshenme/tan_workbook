#include <stdio.h>

int main(int argc, char const *argv[])
{
    int c = 100;
    int *e = &c;
    int **a = &e;
    printf("%d\n", **a);

    //指针数组：
// 存储了指针的数组。
// int *a[10]
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *f[10];
    int total = 0;
    for (size_t i = 0; i < 10; i++)
    {
        /* code */
        f[i] = &arr[i];  // 与 f[i] = arr+1;的操作一样
        total += *f[i];
    }
    printf("总和: %d\n", total);

    return 0;
}
