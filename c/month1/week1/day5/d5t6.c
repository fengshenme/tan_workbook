#include <stdio.h>


/**
 * 打印如下图案：
   *
  ***
 *****
*******
 *****
  ***
   *

*/
int main(int argc, char const *argv[])
{

    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = 4-i; j>1; j--)
        {
            printf(" ");
        }
        for (size_t k = 0; k <= i*2; k++)
        {
            printf("*");
        }
         printf("\n");
    }
    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = 0; j <= i; j++)
        {
            printf(" ");
        }
        for (size_t k = 5-i; k > i; k--)
        {
            printf("*");
        }
         printf("\n");

    }

    return 0;
}

