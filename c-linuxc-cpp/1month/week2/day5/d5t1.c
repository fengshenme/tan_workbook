#include <stdio.h>
// # 数据交换
void func_swap(int *a, int *b);

int main(int argc, char const *argv[])
{
    int a = 200, b = 120;
    func_swap(&a, &b);
    printf("c:%d,d:%d\n", a, b);

    return 0;
}

void func_swap(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
    *b = tmp;
}
