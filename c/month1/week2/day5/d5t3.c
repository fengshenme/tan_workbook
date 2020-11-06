#include <stdio.h>
// # 数组函数
void show_array1(int arr[], int size);
void show_array2(int *arr, int size);

int main(int argc, char const *argv[])
{
    int a[6] = {1, 2, 3, 7, 9, 5};
    show_array1(a, 6);
    show_array2(a, 6);

    return 0;
}

void show_array1(int arr[], int size)
{
    for (size_t i = 0; i < size; i++)
    {
        /* code */
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void show_array2(int *arr, int size)
{
    for (size_t i = 0; i < size; i++)
    {
        /* code */
        printf("%d %d , ", arr[i],  *(arr+i));
    }
    printf("\n");
}