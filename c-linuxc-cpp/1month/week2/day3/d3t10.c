#include <stdio.h>

/**
 * 实验3
 * 声明一个二维 int 型数组 a，再声明另一个一维数组指针数组，
 * 使该数组的每一个指针分别指向二维数组中 的每一个元素(即每一个一维数组)，然后利用数组 b 计算数组 a 的和。
*/
int main(int argc, char const *argv[])
{
    int a[2][3] = {{1, 3,5},{2,7,9}};
    int *b[2];
    int i;
    for ( i = 0; i < 2; i++)
    {
        b[i] = a[i];
        for (size_t j = 0; j < 3; j++)
        {
             printf("%d\n", *(b[i]+j));
        }
    }
        

    return 0;
}
