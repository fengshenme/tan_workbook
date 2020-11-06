#include <stdio.h>

/**
 * 将一个十进制数转换为十六进制数。比如输入 10，输出 0xA
 * 一.十进制转bai换十六进制
若十进制数du23785转为十六进制，则用 23785/16=1486余............9, 1486/16=92余……zhi14, 92/16=5余………….12,
5/16=0余……………..5，十六进制中，10对应为a、11对应为b、。。。。。。、15对应为f，再将余数倒写为5ce9,则十进制23785=十六进制5ce9。
二.十六进制转换十进制
十六进制数的第0位的权值为16的0次方，第1位的权值为16的1次方，第2位的权值为16的2次方。
所以，在第N（N从0开始）位上，如果是是数 X （X 大于等于0，并且X小于等于 15，即：F）表示的大小为 X * 16的N次方。
假设有一个十六进数 2AF5：
用竖式计算： 2AF5换算成10进制:
第0位： 5 * 16^0 = 5
第1位： F * 16^1 = 240
第2位： A * 16^2 = 2560
第3位： 2 * 16^3 = 8192
直接计算就是：
    5 * 16^0 + F * 16^1 + A * 16^2 + 2 * 16^3 = 10997
 * 
 */
int main(int argc, char const *argv[])
{
    int a ;
    printf("请输入十进制整数:");
    scanf("%d", &a); while (getchar() != '\n');
    int arr[20] = {0};
    int c = a;
    int i = 19;
    while(1)
    {
        
        arr[i] = c%16;
        if(c == 0){
            break;
        }
        c = c/16;
        i-- ;
        
    }
    printf("0x");
    for (size_t j = i+1; j < 20; j++)
    {
        int w = arr[j];
        switch (w)
        {
        case 10:
            printf("A");
            break;
        case 11:
            printf("B");
            break;
        case 12:
            printf("C");
            break;
        case 13:
            printf("D");
            break;
        case 14:
            printf("E");
            break;
        case 15:
            printf("F");
            break;
        default:
            printf("%d", w);
            break;
        }
    }
    printf("\n");
    
    return 0;
}
