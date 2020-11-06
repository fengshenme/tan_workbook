// 实验题2
/**
 * 2、 写出下面所描述的各个函数的 ANSI 函数头。注意：只写出函数头即可，不需要实现。 
 * a) donut()接受一个 int 类型的参数，然后输出若干个 0，输出 0 的数目等于参数的值。
 * int donut(int x) 
 * b) gear()接受两个 int 类型的参数并返回 int 类型的值。
 * int gear(int x, int y)
 * c) stuff_it()的参数包括一个 double 类型的值以及一个 double 类型变量的地址，功能是把第一个数值存放 到指定的地址中。
 * void stuff_it(double x, double *y)
*/


// 实验题1
/**
 * 
 * 说明函数传参的方式和异同
 * 1.按值传递
　　　使用这种方式，调用函数本身不对实参进行操作，也就说，即使形参的值在函数中发生了变化，实参的值也完全不会受到影响，仍为调用前的值。这相当于把实参赋值一份给形参，然后调用内存回收。
　　int sum(int x,int y){
　　　　return x+y;
　　}
　　int mian(){
　　　　int result=sum(2,3);//通过直接对sum传递参数
　　　　printf("%d",result);
　　　　return 0;
　　}
 * 2.地址传递
　　地址传递与按值传递的不同在于，它把实参的存储地址传送给对应的形参，从而使得形参指针和实参指针指向同一个地址。
因此，被调函数中对形参指针所指向的地址中内容的任何改变都会影响到实参。
#include<stdio.h>
　　int sum(int *x,int *y){
　　　　return *x+*y;//表示获取x中的内容+y中内容
　　}
　　int main(){
　　　　int a,b;
　　　　a=2;b=3;
　　　　int result=sum(&a,&b);//通过地址对sum传递参数
　　　　printf("%d\n",result);
　　　　return 0;
　　}


 * 
*/