#include <stdio.h>
 
int main ()
{
   /* 局部变量定义 */
   int i, j;
   
   for(i=2; i<100; i++) {
       int a = i/j ;
      for(j=2; j <= a; j++){
        if(!(i%j)) break; // 如果找到，则不是质数
      }
      if(j > a) printf("%d 是质数\n", i);
   }
 
   return 0;
}