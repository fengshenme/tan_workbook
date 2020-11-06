#include <stdio.h>

//字符串输入 同时空格也保存
int main(int argc, char const *argv[])
{
    char a[20];
    int i = 0;
    while (1)
    {
        scanf("%c", a + i);
        if (a[i] == '\n')
            break;
        i++;
    }
    a[i] = '\0';
    printf("%s\n", a);

    return 0;
}
