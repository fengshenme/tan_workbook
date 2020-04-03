#include <stdio.h>
/*
只要给定的条件为真，C 语言中的 while 循环语句会重复执行一个目标语句。
语法
C 语言中 while 循环的语法：
while(condition)
{
   statement(s);
}
在这里，statement(s) 可以是一个单独的语句，也可以是几个语句组成的代码块。
condition 可以是任意的表达式，当为任意非零值时都为 true。
当条件为 true 时执行循环。 
当条件为 false 时，退出循环，程序流将继续执行紧接着循环的下一条语句。
*/ 
int main ()
{
   /* 局部变量定义 */
   int a = 10;

   /* while 循环执行 */
   while( a < 20 )
   {
      printf("a 的值： %d\n", a);
      a++;
   }
   return 0;
}
