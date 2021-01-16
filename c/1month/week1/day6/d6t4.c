#include <stdio.h>

/**
# 3.从小到大，输入3个数据。
# A. 判断这个数据是否可以组成三角形？
# （两边和大于最长边）
# B.判断三角形是否为直角三角形？
# （勾股定理） 用排序
*/
int main(int argc, char const *argv[])
{
    int e[3] = {0};
    scanf("%d%d%d", &e[0], &e[1], &e[2]); while (/* condition */getchar() != '\n');
    
    // for (size_t i = 0; i < 3; i++)
    // {
    //     /* code */
    //     printf("%d ", e[i]);
    // }

    // 冒泡排序
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3-1; j++)
        {
            if (e[j] > e[j+1])
            {
                int p = e[j];
                e[j] = e[j+1];
                e[j+1] = p;
            }
        }
    }

    // for (size_t i = 0; i < 3; i++)
    // {
    //     /* code */
    //     printf("%d ", e[i]);
    // }
    
    if(e[2] < e[0]+e[1])
    {
        printf("可以组成三角形\n");
        if (e[2]*e[2] == e[0]*e[0]+e[1]*e[1])
        {
            printf("可以组成直角三角形\n");
        }
        else
        {
            printf("不可以组成直角三角形\n");
        }
    } 
    else
    {
        printf("不可以组成三角形\n");
    }
    
    
    
    return 0;
}
