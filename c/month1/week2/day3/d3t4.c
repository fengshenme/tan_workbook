#include <stdio.h>

void swap1(int c0[], int c1[])
{
    int t;
    t = c0[0];
    c0[0] = c1[0];
    c1[0] = t;
}
void swap2(int *c0, int *c1)
{
    int t;
    t = *c0;
    *c0 = *c1;
    *c1 = t;
}
int main(void)
{
    int a[2] = {3, 5}, b[2] = {3, 5};
    swap1(a, a + 1);
    swap2(&b[0], &b[1]); // 5,3 5, 3
    printf("%d %d %d %d \n", a[0], a[1], b[0], b[1]);
   
}