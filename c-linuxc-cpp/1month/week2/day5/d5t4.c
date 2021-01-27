#include <stdio.h>
// # 二维数组函数
void func_2d_array1(int *a, int size);

void func_2d_array2(int mult , int size,int (*a)[size]);

int main(int argc, char const *argv[])
{
    int a[2][3] = {{1, 3, 5}, {7, 9, 11}};
    func_2d_array1(a[0], 6);
    func_2d_array1(&a[0][0], 6);
    func_2d_array1(*a, 6);
    func_2d_array2(2, 3, a);
    return 0;
}

void func_2d_array1(int *a, int size)
{
    for (size_t i = 0; i < size; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void func_2d_array2(int mult , int size,int (*a)[size]) //指针形式
{
    for (size_t i = 0; i < mult; i++)
    {
        for (size_t j = 0; j < size; j++)
            printf("%d ", (a)[i][j]);
        printf("\n");
    }
}