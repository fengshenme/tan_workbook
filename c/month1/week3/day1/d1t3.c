#include <stdio.h>
#include <string.h>

typedef void ia;

void test(void)
{

    char *str = (char *)malloc(100);
    strcpy(str, "he1l0");
    free(str);
    if (str != NULL)
    {
        strcpy(str, "world");
        printf("%s\n", str);
        printf("%d\n", strlen(str));
    }
}

int main(void)
{
    test();
    char p[] = "asdc vv";
    char *op;
    op = p;
    printf("%s\n", op);
    char s[] = "man";
    // void v;
    ia *oop;
    int i;
    for (i = 0; s[i]; i++)
        printf("\n%c%c%c%c", s[i], *(s + i), *(i + s), i[s]);
}