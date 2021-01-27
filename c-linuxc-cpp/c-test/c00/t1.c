#include <stdio.h>
 
/*
在 C 中，有两种简单的定义常量的方式：

使用 #define 预处理器。
使用 const 关键字。
#define 预处理器
下面是使用 #define 预处理器定义常量的形式：
*/ 
int main()
{
    //把常量定义为大写字母形式，是一个很好的编程实践。
   const int  LENGTH = 10;
   const int  WIDTH  = 5;
   const char NEWLINE = '\n';
   int area;  
   
   area = LENGTH * WIDTH;
   printf("value of area : %d", area);
   printf("%c", NEWLINE);
 
   return 0;
}