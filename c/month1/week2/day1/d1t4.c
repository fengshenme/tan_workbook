#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a[2][2] = {{98, 70}, {80, 89}};

    printf("编号1总分:%d\n", a[0][0]+a[0][1]);
    printf("编号2总分:%d\n", a[1][0]+a[1][1]);
    printf("数学平均分:%d\n", (a[0][0]+a[1][0])/2);
    printf("英语平均分:%d\n", (a[0][1]+a[1][1])/2);
    return 0;
}
