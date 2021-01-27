#include <stdio.h>
/*
switch语句一般形式：
switch(表达式)
{
    case 常量表达式1:语句1;
    case 常量表达式2:语句2;
    ...
    default:语句n+1;
}
意思是先计算表达式的值，再逐个和 case 后的常量表达式比较，若不等则继续往下比较，若一直不等，则执行 default 后的语句；
若等于某一个常量表达式，则从这个表达式后的语句开始执行，并执行后面所有 case 后的语句。
与 if 语句的不同：if 语句中若判断为真则只执行这个判断后的语句，执行完就跳出 if 语句，不会执行其他 if 语句；
而 switch 语句不会在执行判断为真后的语句之后跳出循环，而是继续执行后面所有 case 语句。在每一 case 语句之后增加 break 语句，
使每一次执行之后均可跳出 switch 语句，从而避免输出不应有的结果。
*/
int main()
{
    int a;
    printf("input integer number: ");
    scanf("%d",&a);
    switch(a)
    {
        case 1:printf("Monday\n");
        break;
        case 2:printf("Tuesday\n");
        break;
        case 3:printf("Wednesday\n");
        break;
        case 4:printf("Thursday\n");
        break;
        case 5:printf("Friday\n");
        break;
        case 6:printf("Saturday\n");
        break;
        case 7:printf("Sunday\n");
        break;
        default:printf("error\n");
    }
}