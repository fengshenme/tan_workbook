#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 验证二维数组, 数组指针
int main(int argc, char const *argv[])
{
    fprintf(stderr, "%d --%d\n", __LINE__, 2);
    int (*a1)[2] ;
    a1 = malloc(sizeof(int) * 6);
    if (a1 == NULL)
    {
        perror("MALLOC FIALED NULL \n");
    }
   fprintf(stderr, "%d --%d\n", __LINE__, 2);
    int i, w = 0, h =0 ;
    for (i = 0; i < 6; w++, i++)
    {
        fprintf(stderr, "%d --%d\n", __LINE__, 2);
        if (w >= 2)
        {
            h++;
            w = 0;
        }
        a1[h][w] = i;
         fprintf(stderr, "%d --%d\n", __LINE__, i);
    }
    for ( i = 0; i < 3; i++)
    {
         printf("%d --%d ", __LINE__, a1[i][0]);
         printf("%d --%d\n", __LINE__, a1[i][1]);
    }
    
   free(a1);

    return 0;
}
