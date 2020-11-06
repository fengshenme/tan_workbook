#include <stdio.h>

// # 计算字符串长度
int func(char *s)
{
    char *t = s;
    while (*t++)
    {
        ;
    }
    t--;
    return (t - s);
}

int main(void)
{
    char *s = "abcdefghijk";
    int n = func(s);
    printf("%d\n", n);
}