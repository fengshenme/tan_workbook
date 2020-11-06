#include <stdio.h>
#include <stdbool.h>

int main(int argc, char const *argv[])
{
    printf("char: %lu\n",sizeof(char));
    printf("short: %lu\n",sizeof(short));
    printf("int: %lu\n",sizeof(int));
    printf("long: %lu\n",sizeof(long));
    printf("long long: %lu\n",sizeof(long long));
    printf("float: %lu\n",sizeof(float));
    printf("double: %lu\n",sizeof(double));
    printf("bool: %lu\n",sizeof(bool));

    return 0;
}
