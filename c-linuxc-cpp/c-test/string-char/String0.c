/*
C 字符串
在 C 语言中，字符串实际上是使用 null 字符 '\0' 终止的一维字符数组。因此，一个以 null 结尾的字符串，包含了组成字符串的字符。
下面的声明和初始化创建了一个 "Hello" 字符串。由于在数组的末尾存储了空字符，所以字符数组的大小比单词 "Hello" 的字符数多一个。
char greeting[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
依据数组初始化规则，您可以把上面的语句写成以下语句：
char greeting[] = "Hello";
以下是 C/C++ 中定义的字符串的内存表示：
C/C++ 中的字符串表示
其实，您不需要把 null 字符放在字符串常量的末尾。C 编译器会在初始化数组时，自动把 '\0' 放在字符串的末尾。让我们尝试输出上面的字符串：

*/

#include <stdio.h>
 
int main ()
{
   char greeting[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
 
   printf("Greeting message: %s\n", greeting );
 
   return 0;
}