#include <stdio.h>

void task0(void); 

int main(int argc, char const *argv[])
{
    printf("++++++++++++实验3范例1+++++++++++++\n");
    task0();

    return 0;
}

/**
 * 实验3    C 语言控制流 
 * 范例
*/
void task0(void) 
{
    int count;
    scanf("%d", &count); while (getchar() != '\n');
    int i;
    for ( i = 0; i < count; i++)
    {   
        int c = i;
        while ( c >= 0)
        {
            printf("$ ");
            c--;
        }
        printf("\n");
    }

}

