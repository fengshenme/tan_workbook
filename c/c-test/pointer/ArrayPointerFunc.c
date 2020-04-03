/*

C 传递指针给函数
C 指针 C 指针
C 语言允许您传递指针给函数，只需要简单地声明函数参数为指针类型即可。

能接受指针作为参数的函数，也能接受数组作为参数
*/
#include <stdio.h>
 
/* 函数声明 */
double getAverage(int *arr, int size);
 
int main () {
   /* 带有 5 个元素的整型数组  */
   int balance[5] = {1000, 2, 3, 17, 50};
   double avg;
 
   /* 传递一个指向数组的指针作为参数 */
   avg = getAverage( balance, 5 ) ;
 
   /* 输出返回值  */
   printf("Average value is: %f\n", avg );
   
   return 0;
}

double getAverage(int *arr, int size){
  int    i, sum = 0;      
  double avg;          
  for (i = 0; i < size; ++i){
    sum += arr[i];
  }
  return avg;
}
