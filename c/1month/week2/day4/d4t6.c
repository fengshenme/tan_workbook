#include <stdio.h>

int strlength(char *a)
{
    int i = 0;
    while (1)
    {
        if (*(a+i) == '\0')
            break;
        i++;
    }
    return i;
}
/**
 * 编写一个程序，将两个字符串连接起来，不要用 strcat 或 strncat 函数
 */
int main(int argc, char const *argv[])
{
    /* code */
    char *a = "asd";
    char *b = "cdnm";
    
    int i = strlength(a);
    int j= strlength(b);
    char c[i+j];
    int k;
    for ( k = 0; k < i; k++)
           c[k] = a[k];
    for ( k = 0; k < j; k++)
           c[i+k] = b[k];
    
    printf("%s\n",c);
    return 0;
}
