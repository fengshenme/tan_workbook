/*

预处理器运算符
C 预处理器提供了下列的运算符来帮助您创建宏：
宏延续运算符（\）
一个宏通常写在一个单行上。但是如果宏太长，一个单行容纳不下，则使用宏延续运算符（\）。例如：
#define  message_for(a, b)  \
    printf(#a " and " #b ": We love you!\n")
字符串常量化运算符（#）
在宏定义中，当需要把一个宏的参数转换为字符串常量时，则使用字符串常量化运算符（#）。
在宏中使用的该运算符有一个特定的参数或参数列表。例如：



*/

#include <stdio.h>

#define  message_for(a, b)  \
    printf(#a " and " #b ": We love you!\n")

/*
标记粘贴运算符（##）
宏定义内的标记粘贴运算符（##）会合并两个参数。它允许在宏定义中两个独立的标记被合并为一个标记。例如：
*/
#define tokenpaster(n) printf ("token" #n " = %d\n", token##n)
/*
这个实例演示了 token##n 会连接到 token34 中，在这里，我们使用了字符串常量化运算符（#）和标记粘贴运算符（##）。
defined() 运算符
预处理器 defined 运算符是用在常量表达式中的，用来确定一个标识符是否已经使用 #define 定义过。如果指定的标识符已定义，则值为真（非零）。
如果指定的标识符未定义，则值为假（零）。下面的实例演示了 defined() 运算符的用法：
*/
#if !defined (MESSAGE)
   #define MESSAGE "You wish!"
#endif

int main(void)
{
   message_for(Carole, Debra);

    int token34 = 40;
   tokenpaster(34);

    printf("Here is the message: %s\n", MESSAGE); 

   return 0;
}
