/*

访问共用体成员
为了访问共用体的成员，我们使用成员访问运算符（.）。
成员访问运算符是共用体变量名称和我们要访问的共用体成员之间的一个句号。
您可以使用 union 关键字来定义共用体类型的变量。下面的实例演示了共用体的用法：

*/
#include <stdio.h>
#include <string.h>
 
union Data
{
   int i;
   float f;
   char  str[20];
};
 
void main( )
{
   union Data data;        
 
   data.i = 10;
   printf( "data.i : %d\n", data.i);
   data.f = 220.5;
   printf( "data.f : %f\n", data.f);
   strcpy( data.str, "C Programming");
   printf( "data.str : %s\n", data.str);
   /*
   当上面的代码被编译和执行时，它会产生下列结果：
   data.i : 10
   data.f : 220.500000
   data.str : C Programming
   在这里，所有的成员都能完好输出，因为同一时间只用到一个成员。
   */
   return ;
}
/*
我们可以看到共用体的 i 和 f 成员的值有损坏，因为最后赋给变量的值占用了内存位置，
这也是 str 成员能够完好输出的原因。现在让我们再来看一个相同的实例，这次我们在同一时间只使用一个变量，这也演示了使用共用体的主要目的：
*/