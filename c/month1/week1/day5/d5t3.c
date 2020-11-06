#include <stdio.h>

void task0(void);
void task1(void);

int main(int argc, char const *argv[])
{
    task0();
    task1();
    return 0;
}

/**
 * 实验3 技术点强化1
 * 编写一个程序，要求用相应的控制流语句往屏幕打印 26 个小写字母
 */
void task0(void)
{
    int i;
    for ( i = 65; i < 123; i++)
    {
        if ( i < 91 || i>96)
        {
            printf("%c ", i);
        }
    }
    printf("\n");

    
}

/** 
 * 技术点强化2
 * A-Z之间 的ascii编码  65-90
 * 编写一个程序，用户输入某个大写字母，产生一个金字塔图案。例如用户输入字母 E，则产生如下图案
     A
    ABA
   ABCBA
  ABCDCBA
 ABCDEDCBA
*/
void task1(void)
{
    char c ;
    int a;
    while (1)
    {
        printf("输入大写字符A-Z之间任意一个: ");
        scanf("%c", &c); while (getchar() != '\n');
        a = c;
        if (a > 64 && a < 91)
        {
            break ;
        } else
        {
            printf("输入字符无效! \n");
        }
    }
    
    for (size_t i = 0; i < 5; i++)
    {
        for (size_t k = i; k < 5; k++)
        {
            printf(" ");
        }// 69
        int j, l;
        for ( j = 0; j < i+1; j++)
        {
            printf("%c",a-4+j);
        }
        for ( l = j; l > 1 ; l--)
        {
            printf("%c",a+l-6);
        }
        
        printf("\n");
    }
    
}