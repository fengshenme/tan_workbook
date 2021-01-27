#include <stdio.h>

//题9// 函数递归 ,通过指针将数组中元素改为降序排列
void fun(int *a, int i, int j)
{
    int t;
    if (i < j)
    {
        t = a[i];
        a[i] = a[j];
        a[j] = t;
        fun(a, ++i, --j);
    }
}
int main(void)
{
    int a[] = {1, 2, 3, 4, 5, 6}, i;
    fun(a, 0, 5);
    for (i = 0; i < 6; i++)
        printf("% d", a[i]);
    printf("\n" );
    printf(" %d \n", a);
    printf(" %d \n", a+1);

}