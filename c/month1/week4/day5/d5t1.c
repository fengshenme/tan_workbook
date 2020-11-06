#include <stdio.h>
#include <string.h>



int main(int argc, char const *argv[])
{
    char str[30];
    fgets(str, 40, stdin);

    printf("%s\n", str);
    char *strdes = strtok(str, "\n");
    printf("%s\n", strdes);
    fputs(strdes, stdout);
    return 0;
}
