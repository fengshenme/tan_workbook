#include <stdio.h>

int main(int argc, char const *argv[])
{
    int c;
    // 97-122
    scanf("%c", &c); while (getchar() != '\n');
    
    printf("%c \n", c-32);
    return 0;
}
