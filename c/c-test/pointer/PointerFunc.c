/*

C 传递指针给函数
C 指针 C 指针
C 语言允许您传递指针给函数，只需要简单地声明函数参数为指针类型即可。
下面的实例中，我们传递一个无符号的 long 型指针给函数，并在函数内改变这个值：

*/
#include <stdio.h>
#include <time.h>
 
void getSeconds(unsigned long *par);

int main ()
{
   unsigned long sec;
   getSeconds( &sec );
   /* 输出实际值 */
   printf("Number of seconds: %ld\n", sec );
   return 0;
}

void getSeconds(unsigned long *par)
{
   /* 获取当前的秒数 */
   *par = time( NULL );
   return;
}
