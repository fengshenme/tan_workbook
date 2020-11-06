// 设计一个 C 函数，若处理器是大端序的则返回 0，
// 若处理器是小端序的则返回 1。
#include <stdio.h>

union node
{
    unsigned int m;
    char c;
};

int mtk(void)
{
    union node data;
    data.m = 0x12345678; 
    // 计算机为大端序,则高有效位为12,data.c为12
    // 计算机为小端序,则高有效位为78,data.c为78
    return data.c == 78 ? 1:0;
}

int main(int argc, char const *argv[])
{
    printf("%d\n",mtk());
    
    return 0;
}
