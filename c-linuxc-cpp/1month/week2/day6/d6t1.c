#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int *a = malloc(sizeof(int)*8);
    *a = 10000045;
    printf("%d\n", *a);
    free(a);
    printf("%d\n", *a);

    int *b = calloc(5, 6); 

    return 0;
}
