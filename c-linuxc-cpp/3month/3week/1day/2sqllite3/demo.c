#include <stdio.h>
#include <time.h>


int main(int argc, char const *argv[])
{
    printf("%d-%ld", __LINE__, time(0));
    return 0;
}
