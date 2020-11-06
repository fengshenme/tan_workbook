#include <stdio.h>

/**
 * 作业1

*/
int main(int argc, char const *argv[])
{
    int arr[6] = {1, 2, 9, 4, 5, 6};

    int *p = &arr[0];

    int i;
    for ( i = 0; i < 6; i++)
    {
        printf("%d ", *(p+i));
        
    }
    printf("\n");
    // int (*a)[6]即为一个数组指针。int *p[6]则是一个大小为6且存放整型指针的数组
    int (*a)[6];
    a = &arr;
    for ( i = 0; i < 6; i++)
    {
        printf("%d ", (*a)[i]);
    }

    return 0;
}
