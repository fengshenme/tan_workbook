#include <stdio.h>

/**
 * 题3
 * 编写一个程序，该程序读取输入直到遇到#字符，然后报告读取的空格数目、读取的换行符数目以及读取 的所有其他字符数目
*/
int main(int argc, char const *argv[])
{
    int space = 0;
    int lfb = 0;
    int elsb = 0;
    printf("输入键盘字符,按 # 退出 ");
    while (1)
    {
        char c ;
        int h;
        scanf("%c", &c);  //while (getchar() != '\n');
        h = c;
        switch (h)
        {
            case 35:
                printf("空格数目:%d 换行符数目: %d 其他字符数目 :%d \n", space, lfb, elsb);
                return 0;
            case 32:
                space++;
                break;
            case 10:
                lfb++;
                break;
            default:
                elsb++;
                break;
        }
        
    }
    
    
    return 0;
}
