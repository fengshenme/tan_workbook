#include <stdio.h>

int main(int argc, char const *argv[])
{
    // 题17
    char a[] = "Language", b[] = "Programe";
    char *p1, *p2;
    int k;
    p1 = a;
    p2 = b;
    for (k = 0; k < 8; k++)
        if (*(p1 + k) == *(p2 + k))
            printf("%c", *(p1 + k));
    printf("\n");
    // 题18
    char *pa[10] = {"abc", "aabdfg", "dcdbe", "abbd", "cd"};
    printf("题18:%d\n", strlen(pa[4]));
    return 0;
}
