/*
位域声明
在结构内声明位域的形式如下：
struct {
  type [member_name] : width ;
};
下面是有关位域中变量元素的描述：
元素	描述
type	只能为 int(整型)，unsigned int(无符号整型)，signed int(有符号整型) 三种类型，决定了如何解释位域的值。
member_name	位域的名称。
width	位域中位的数量。宽度必须小于或等于指定类型的位宽度。
带有预定义宽度的变量被称为位域。位域可以存储多于 1 位的数，
例如，需要一个变量来存储从 0 到 7 的值，您可以定义一个宽度为 3 位的位域，如下： 
struct {
  unsigned int age : 3;
} Age;
上面的结构定义指示 C 编译器，age 变量将只使用 3 位来存储这个值，如果您试图使用超过 3 位，则无法完成。让我们来看下面的实例：
*/
#include <stdio.h>
#include <string.h>
 
struct
{
  unsigned int age : 3;
} Age;
 
int main( )
{
   Age.age = 4;
   printf( "Sizeof( Age ) : %d\n", sizeof(Age) );
   printf( "Age.age : %d\n", Age.age );
 
   Age.age = 7;
   printf( "Age.age : %d\n", Age.age );
 
   Age.age = 8; // 二进制表示为 1000 有四位，超出
   printf( "Age.age : %d\n", Age.age );
 
   return 0;
}
/*

当上面的代码被编译时，它会带有警告，当上面的代码被执行时，它会产生下列结果：
Sizeof( Age ) : 4
Age.age : 4
Age.age : 7
Age.age : 0

*/