#include <stdio.h>
// 下面函数实现数组元素的逆转，请填写空白处使其完整。
void recur(int a[], int k)
{
    int tmp;
    if (k > 0)
    {
        recur(a+1, k-2);
        tmp = a[0];
        a[0] = a[k - 1];
        a[k - 1] = tmp;
    }
}

int main(int argc, char const *argv[])
{
    int arr[7] = {1, 3, 5, 7, 9, 11, 13};
    for (size_t i = 0; i < 7; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    recur(arr, 7);
    for (size_t i = 0; i < 7; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}
