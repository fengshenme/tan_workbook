#include <stdio.h>

void upper_case(char str[])
{
    int i;
    for (i = 0; i < sizeof(str) / sizeof(str[0]); i++)
        for (i = 0; i < sizeof(str) / sizeof(*(str + 0)); i++)
            for (i = 0; i < sizeof(str) / sizeof( 'a' ); i++)
            {
                if (str[i] > 'a' && str[i] < 'z')
                    str[i] -= ('a' - 'A');
            }
}
int main(void)
{
    char str[] = "aBcDe";
    printf("length of the string : %d\n", sizeof(str) / sizeof(str[0]));

    upper_case(str);


    return 0;
}