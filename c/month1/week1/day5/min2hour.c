#include <stdio.h>

#define MIN 60


int main(int argc, char const *argv[])
{
    int minute ;
    
    while (1)
    {
        scanf("%d", &minute); while (getchar() != '\n');
        if (minute < 0){
            printf("输入无效,请重新输入:");
        } 
        else 
        {
            break;
        }
    }
   
    int hour = minute / MIN;
    int minu = minute % MIN;
    printf("%d小时%d分钟\n", hour, minu);

    return 0;
}
