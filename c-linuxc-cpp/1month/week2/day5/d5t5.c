#include <stdio.h>

// # 通过函数修改指针
void func_1(int *p, int *b);

int main(int argc, char const *argv[])
{
    int a = 100;
    int b = 200;

    int *p1 = &a;

    printf("(1)*p1: %d\n", *p1);
    
    func_1(p1, &b);

    printf("(2)*p1: %d\n", *p1);

    return 0;
}

void func_1(int *p, int *b)
{
    *p = *b ;

}