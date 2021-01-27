#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void math(int nu, char *str)
{
    char tm[3] = {0};

    if (nu != 1)
    {
        
        sprintf(tm, "%d", nu % 2);
        strcat(str, tm);
        nu = nu / 2;
        math(nu, str);
        return ;
    }

    sprintf(tm, "%d", nu);
    strcat(str, tm);

    return;
}

int main(int argc, char const *argv[])
{

    int num = atoi(argv[1]);
    printf("%s \n", argv[1]);
    char st[3000] = {0};
    char sta[3000] = {0};
    math(num, st);
    int len = strlen(st);
    int i;
    for ( i = len -1; i >= 0 ; i--)
    {
        // sta[i] = st[i];
        strncat(sta, st+i, 1);
        printf("%c", st[i]);
    }
    int slen = strlen(sta);
    printf("\n");
    printf("%s \n", sta);
    printf("%d \n", slen);
    printf("%s \n", st);

    return 0;
}
