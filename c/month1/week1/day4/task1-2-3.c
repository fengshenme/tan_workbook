#include <stdio.h>

/*

作业一
'\b' 字符
1066 短整型数字
99.44 一个单精度浮点型数字
0XAA 16进制数字
2.0e30 一个长整型数字 2.0*10^30
3.0e-20 一个double 双精度浮点型数字 3.0*10^(-20)
*/

// 作业2
int main(int argc, char const *argv[])
{
    int a;
    // -128~127  ASCII可显示字符 32~126
    int b = 1;
    printf("请输入一个 ASCII 码值: ");
    while(b){
        scanf("%d", &a); while (getchar() != '\n');
        if (a>=32 && a<=126)
        {
            /* code */
            printf("字符为:%c\n", a);
            b = 0;
            // return 0;
        }
        else
        {
           printf("这不是一个可显示字符的ASCII码值! \n请重新输入: ");
        }
    }
    
    //作业5 
    char c ;
     // \r 回车符 \n 换行
    c = '\r';
    // 10进制
    c = 13;
    // 16进制
    c = 0x0D;
    // 8进制
    c = 015;
    printf("aa %d \n", c);
     // 作业6 'A'是字符 "A"这是字符串 

    return 0;
}
 
/*
作业3
include导入标准库没有前缀#

main函数 没有定义返回值类型 main函数定义应是main(void){}
一行定义多个数据类型应该用,而不是;隔开.
e21应为1e21
rate 没有定义,没有初始化

*/