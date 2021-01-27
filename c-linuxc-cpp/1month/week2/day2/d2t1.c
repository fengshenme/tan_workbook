#include <stdio.h>

int main(int argc, char const *argv[])
{
    int arr[2][3] = {{1, 3, 5}, {7, 9, 11}};

    printf("%d\n", arr[0][2]++);
    printf("%d\n", arr[0][2]);

    int *p = &arr[0][0];
    printf("%d\n", *(p+2)=10);
    return 0;
}
