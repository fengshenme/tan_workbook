/*

实验题5.声明一个枚举类型，使用 choices 作为标记，将枚举常量 no、yes 和 maybe 分别设置为 0、1 和 2。
*/

#include <stdio.h>

enum choices
{
    no = 0,
    yes = 1,
    maybe = 2
};

int main(int argc, char const *argv[])
{
    printf("%d\n", no);
    printf("%d\n", yes);
    printf("%d\n", maybe);

    return 0;
}
