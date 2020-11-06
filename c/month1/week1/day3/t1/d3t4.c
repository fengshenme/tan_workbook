#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n[6] = {1,2,3,4,5,6};
    char c[12] = "hello,world";
    float f[6] = {1.1,0.2,0.5,5.3,1.6,1.8};

    int *np = n;
    char *cp = c;
    float *fp = f;
    int i = 0;
    while (1)
    {
        if (*(np+i)=='\0')
            break;
        printf("%d ", *(np+i));
        i++;
       
    }
    printf("\n");

    printf("%s \n", cp);
    int j = 0;
    while (*(fp+j)!='\0')
    {
        printf("%.2f ", *(fp+j));
        j++;
    }
    printf("\n");

    return 0;
}
