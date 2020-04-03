/*

参数化的宏
CPP 一个强大的功能是可以使用参数化的宏来模拟函数。例如，下面的代码是计算一个数的平方：
int square(int x) {
   return x * x;
}
我们可以使用宏重写上面的代码，如下：
#define square(x) ((x) * (x))
在使用带有参数的宏之前，必须使用 #define 指令定义。
参数列表是括在圆括号内，且必须紧跟在宏名称的后边。宏名称和左圆括号之间不允许有空格。例如：

*/

#include <stdio.h>

#define MAX(x,y) ((x) > (y) ? (x) : (y))

int main(void)
{
   printf("Max between 20 and 10 is %d\n", MAX(10, 20));  
   return 0;
}