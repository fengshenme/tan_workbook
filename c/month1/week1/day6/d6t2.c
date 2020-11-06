#include <stdio.h>
#include <math.h>
/**
1.输入一个十位数，例如57 将其拆分开来，打印5和7 
# 尝试着输入千位数，例如1234，分别打印1.2.3.4）
# 发现，如果pow(a,b),如果a，b都是常量时，是
# 不会出现提示的，但是，如果a，b中有任何一个是变量，那么编译时 都会出现提示。
# 现象就是这么简单，解决方式就是在编译的时候加上-lm，其实man
# 手册上写的很清楚了
# 
*/
int main(int argc, char const *argv[])
{
    int d;
    scanf("%d", &d); while (getchar() != '\n');
    int c;
    int e[10] = {0};
    printf("11:%.f\n", pow(10.0,0.0));
    for (size_t i = 0; i < 10; i++)
    {
        if (d < (int)pow(10.0,(float)i))
        {
            c = i;
            break;
        }
    }

    e[0] = d/(int)pow(10.0, (float)c-1);
    
    for (size_t i = c; i > 1 ; i--)
    {
        int f = (int)pow(10.0, (float)i-1);
        int fa = (int)pow(10.0, (float)i-2);
        e[c-i+1] = (d%f)/fa;
    }
    for (size_t i = 0; i < c; i++)
    {
        printf("%d ", e[i]);
    }
    printf("\n");
    
    return 0;
}
