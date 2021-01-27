/*
C 位域
如果程序的结构中包含多个开关量，只有 TRUE/FALSE 变量，如下：
struct {
  unsigned int widthValidated;
  unsigned int heightValidated;
} status;
这种结构需要 8 字节的内存空间，但在实际上，在每个变量中，我们只存储 0 或 1。
在这种情况下，C 语言提供了一种更好的利用内存空间的方式。如果您在结构内使用这样的变量，
您可以定义变量的宽度来告诉编译器，您将只使用这些字节。例如，上面的结构可以重写成：
struct
{
  unsigned int widthValidated : 1;
  unsigned int heightValidated : 1;
} status;
现在，上面的结构中，status 变量将占用 4 个字节的内存空间，但是只有 2 位被用来存储值。如果您用了 32 个变量，每一个变量宽度为 1 位，
那么 status 结构将使用 4 个字节，但只要您再多用一个变量，
如果使用了 33 个变量，那么它将分配内存的下一段来存储第 33 个变量，这个时候就开始使用 8 个字节。让我们看看下面的实例来理解这个概念：

*/
#include <stdio.h>
#include <string.h>
 
/* 定义简单的结构 */
struct
{
  unsigned int widthValidated;
  unsigned int heightValidated;
} status1;
 
/* 定义位域结构 */
struct
{
  unsigned int widthValidated : 1;
  unsigned int heightValidated : 1;
} status2;
 
int main( )
{
   printf( "Memory size occupied by status1 : %d\n", sizeof(status1));
   printf( "Memory size occupied by status2 : %d\n", sizeof(status2));
 
   return 0;
}
