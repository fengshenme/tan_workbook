#include <stdio.h>

int main(void)
{
    int a[4] = {1, 2, 3, 4};
    int *p1 = (int *)(&a + 1); // 2,3,4
    int *p2 = (int *)((int)a + 1);
    printf("%x, %x\n", p1[-1], *p2);

    // int a[4] = {1, 2, 3, 4};
    // printf("%d\n", (int)a + 1);
    return 0;
}