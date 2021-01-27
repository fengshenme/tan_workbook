#include <stdio.h>
#include <time.h>


int main(int argc, char const *argv[])
{
    long  a = time(0);
    printf("%ld \n", a);
    printf("%ld \n", a%1000000000);
    return 0;
}

