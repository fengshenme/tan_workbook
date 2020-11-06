#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a[2][3] = {{1, 3, 5}, {7, 8, 9}};

    /**
     * 数组指针：
    指向数组的指针。（行指针）
    int (*p) [10]
    */

    int (*p1)[3] = a;

    int total = 0;
    for (size_t i = 0; i < 6; i++)
    {
        total += (*p1)[i];
        printf("%d ", (*p1)[i]);
    }

    printf("total:%d\n", total);


    return 0;
}
