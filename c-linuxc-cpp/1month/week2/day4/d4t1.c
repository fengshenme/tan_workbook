#include <stdio.h>

// const指针
int main(int argc, char const *argv[])
{
    char a = 'a';
    const char *p1 = &a;
    char const *p2 = &a;
    char *const p3 = &a;

     char b = 'c';
     p1 = &b;
     p2 = &b;
    //  p3 = &b;
    printf("%c\n", *p1);
    printf("%c\n", *p2);
    printf("%c\n", p3);
    return 0;
}
