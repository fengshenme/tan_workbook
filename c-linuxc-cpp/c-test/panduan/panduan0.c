#include<stdio.h>
/*
判断语句
C 语言提供了以下类型的判断语句。点击链接查看每个语句的细节。

语句	描述
if 语句	一个 if 语句 由一个布尔表达式后跟一个或多个语句组成。
if...else 语句	一个 if 语句 后可跟一个可选的 else 语句，else 语句在布尔表达式为假时执行。
嵌套 if 语句	您可以在一个 if 或 else if 语句内使用另一个 if 或 else if 语句。
switch 语句	一个 switch 语句允许测试一个变量等于多个值时的情况。
嵌套 switch 语句	您可以在一个 switch 语句内使用另一个 switch 语句。
*/
int A=10;
int B=20;
char buy;
int sum,number;

int main()
{

    printf("以下是本店的商品及价格：\n A 商品每个十元；\n B 商品每个二十元；\n\n");
    printf("请输入你所需的产品(A 或 B):");
    scanf("%c",&buy);
    printf("请输入所需的数量：");
    scanf("%d",&number);
    sum=buy=='A'?A*number:B*number;
    printf("\n你所需要的%d个%c商品总共%d元。\n",number,buy,sum);

    int num;
    printf("输入一个数字 : ");
    scanf("%d",&num);
    (num%2==0)?printf("偶数"):printf("奇数");
    
    return 0;
}