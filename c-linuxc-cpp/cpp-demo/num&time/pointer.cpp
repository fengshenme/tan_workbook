/*
C++ 指针
学习 C++ 的指针既简单又有趣。通过指针，可以简化一些 C++ 编程任务的执行，还有一些任务，如动态内存分配，没有指针是无法执行的。所以，想要成为一名优秀的 C++ 程序员，学习指针是很有必要的。

正如您所知道的，每一个变量都有一个内存位置，每一个内存位置都定义了可使用连字号（&）运算符访问的地址，它表示了在内存中的一个地址。
请看下面的实例，它将输出定义的变量地址：
*/
#include <iostream>
 
using namespace std;
void pvar(); 
void nullPointer();
void pointerArithmetic();
void decrementPointer();
void pointerComparison();
void pointerArray();
void testpointer();
void referencesPointer();
void referparam();
void refeRetrun();
void linuxTime();

int main ()
{
   int  var1;
   char var2[10];
   cout << "var1 变量的地址： ";
   cout << &var1 << endl;
   cout << "var2 变量的地址： ";
   cout << &var2 << endl;
    pvar();
    nullPointer();
    pointerArithmetic();
    decrementPointer();
    pointerComparison();
    pointerArray();
    testpointer();
    referencesPointer();
    referparam();
    refeRetrun();
    linuxTime();
   return 0;
}

/*
什么是指针？
指针是一个变量，其值为另一个变量的地址，即，内存位置的直接地址。就像其他变量或常量一样，您必须在使用指针存储其他变量地址之前，对其进行声明。
指针变量声明的一般形式为：
type *var-name;
在这里，type 是指针的基类型，它必须是一个有效的 C++ 数据类型，var-name 是指针变量的名称。用来声明指针的星号 * 与乘法中使用的星号是相同的。
但是，在这个语句中，星号是用来指定一个变量是指针。以下是有效的指针声明：
int    *ip;    // 一个整型的指针 
double *dp;    // 一个 double 型的指针 
float  *fp;    // 一个浮点型的指针 
char   *ch;    // 一个字符型的指针 
所有指针的值的实际数据类型，不管是整型、浮点型、字符型，还是其他的数据类型，都是一样的，
都是一个代表内存地址的长的十六进制数。不同数据类型的指针之间唯一的不同是，指针所指向的变量或常量的数据类型不同。
C++ 中使用指针
使用指针时会频繁进行以下几个操作：定义一个指针变量、把变量地址赋值给指针、访问指针变量中可用地址的值。
这些是通过使用一元运算符 * 来返回位于操作数所指定地址的变量的值。下面的实例涉及到了这些操作：

*/
void pvar(){
    int  var = 20;   // 实际变量的声明
   int  *ip;        // 指针变量的声明
 
   ip = &var;       // 在指针变量中存储 var 的地址
 
   cout << "Value of var variable: ";
   cout << var << endl;
    
   // 输出在指针变量中存储的地址
   cout << "Address stored in ip variable: ";
   cout << ip << endl;
 
   // 访问指针中地址的值
   cout << "Value of *ip variable: ";
   cout << *ip << endl;

}

/*

C++ Null 指针
C++ 指针 C++ 指针
在变量声明的时候，如果没有确切的地址可以赋值，为指针变量赋一个 NULL 值是一个良好的编程习惯。
赋为 NULL 值的指针被称为空指针。
NULL 指针是一个定义在标准库中的值为零的常量。请看下面的程序：

*/
void nullPointer(){

    int  *ptr = NULL;
   cout << "ptr 的值是 " << ptr ;
    /*
    当上面的代码被编译和执行时，它会产生下列结果：

    ptr 的值是 0
    在大多数的操作系统上，程序不允许访问地址为 0 的内存，因为该内存是操作系统保留的。
    然而，内存地址 0 有特别重要的意义，它表明该指针不指向一个可访问的内存位置。但按照惯例，如果指针包含空值（零值），则假定它不指向任何东西。
    如需检查一个空指针，您可以使用 if 语句，如下所示：
    if(ptr)     // 如果 ptr 非空，则完成 
    if(!ptr)    // 如果 ptr 为空，则完成 
    因此，如果所有未使用的指针都被赋予空值，同时避免使用空指针，就可以防止误用一个未初始化的指针。
    很多时候，未初始化的变量存有一些垃圾值，导致程序难以调试。
    
    */
}

const int MAX = 3;
/*

C++ 指针的算术运算
C++ 指针 C++ 指针
指针是一个用数值表示的地址。因此，您可以对指针执行算术运算。可以对指针进行四种算术运算：++、--、+、-。
假设 ptr 是一个指向地址 1000 的整型指针，是一个 32 位的整数，让我们对该指针执行下列的算术运算：
ptr++
在执行完上述的运算之后，ptr 将指向位置 1004，因为 ptr 每增加一次，它都将指向下一个整数位置，即当前位置往后移 4 个字节。
这个运算会在不影响内存位置中实际值的情况下，移动指针到下一个内存位置。如果 ptr 指向一个地址为 1000 的字符，
上面的运算会导致指针指向位置 1001，因为下一个字符位置是在 1001。
递增一个指针
我们喜欢在程序中使用指针代替数组，因为变量指针可以递增，而数组不能递增，因为数组是一个常量指针。下面的程序递增变量指针，以便顺序访问数组中的每一个元素：

*/
void pointerArithmetic(){
    int  var[MAX] = {10, 100, 200};
   int  *ptr;
 
   // 指针中的数组地址
   ptr = var;
   for (int i = 0; i < MAX; i++)
   {
      cout << "Address of var[" << i << "] = ";
      cout << ptr << endl;
 
      cout << "Value of var[" << i << "] = ";
      cout << *ptr << endl;
 
      // 移动到下一个位置
      ptr++;
   }
}

/*
递减一个指针
同样地，对指针进行递减运算，即把值减去其数据类型的字节数，如下所示
*/
void decrementPointer(){
    int  var[MAX] = {10, 100, 200};
   int  *ptr;
 
   // 指针中最后一个元素的地址
   ptr = &var[MAX-1];
   for (int i = MAX; i > 0; i--)
   {
      cout << "Address of var[" << i << "] = ";
      cout << ptr << endl;
 
      cout << "Value of var[" << i << "] = ";
          cout << *ptr << endl;
 
      // 移动到下一个位置
      ptr--;
   }
}

/*
指针的比较
指针可以用关系运算符进行比较，如 ==、< 和 >。如果 p1 和 p2 指向两个相关的变量，
比如同一个数组中的不同元素，则可对 p1 和 p2 进行大小比较。
下面的程序修改了上面的实例，只要变量指针所指向的地址小于或等于数组的最后一个元素的地址 &var[MAX - 1]，则把变量指针进行递增
*/
void pointerComparison(){
    int  var[MAX] = {10, 100, 200};
   int  *ptr;
 
   // 指针中第一个元素的地址
   ptr = var;
   int i = 0;
   while ( ptr <= &var[MAX - 1] )
   {
      cout << "Address of var[" << i << "] = ";
      cout << ptr << endl;
 
      cout << "Value of var[" << i << "] = ";
      cout << *ptr << endl;
 
      // 指向上一个位置
      ptr++;
      i++;
   }
}

/*
C++ 指针 vs 数组
C++ 指针 C++ 指针
指针和数组是密切相关的。事实上，指针和数组在很多情况下是可以互换的。
例如，一个指向数组开头的指针，可以通过使用指针的算术运算或数组索引来访问数组。请看下面的程序：
*/
void pointerArray(){
    int  var[MAX] = {10, 100, 200};
   int  *ptr;
 
   // 指针中的数组地址
   ptr = var;
   for (int i = 0; i < MAX; i++)
   {
      cout << "var[" << i << "]的内存地址为 ";
      cout << ptr << endl;
 
      cout << "var[" << i << "] 的值为 ";
      cout << *ptr << endl;
 
      // 移动到下一个位置
      ptr++;
   }

}
/*
然而，指针和数组并不是完全互换的。例如，请看下面的程序：
*/
void testpointer(){
    int  var[MAX] = {10, 100, 200};
    
    /*
        把指针运算符 * 应用到 var 上是完全可以的，但修改 var 的值是非法的。这是因为 var 是一个指向数组开头的常量，不能作为左值。
        由于一个数组名对应一个指针常量，只要不改变数组的值，仍然可以用指针形式的表达式。例如，下面是一个有效的语句，把 var[2] 赋值为 500：
        *(var + 2) = 500;
        上面的语句是有效的，且能成功编译，因为 var 未改变
    */
   for (int i = 0; i < MAX; i++)
   {
      *var = i;    // 这是正确的语法
      // var++;       // 这是不正确的
   }
}

/*
C++ 引用
引用变量是一个别名，也就是说，它是某个已存在变量的另一个名字。一旦把引用初始化为某个变量，就可以使用该引用名称或变量名称来指向变量。

C++ 引用 vs 指针
引用很容易与指针混淆，它们之间有三个主要的不同：

不存在空引用。引用必须连接到一块合法的内存。
一旦引用被初始化为一个对象，就不能被指向到另一个对象。指针可以在任何时候指向到另一个对象。
引用必须在创建时被初始化。指针可以在任何时间被初始化。
C++ 中创建引用
试想变量名称是变量附属在内存位置中的标签，您可以把引用当成是变量附属在内存位置中的第二个标签。因此，您可以通过原始变量名称或引用来访问变量的内容。例如：
int i = 17;
我们可以为 i 声明引用变量，如下所示：
int&  r = i;
double& s = d;
在这些声明中，& 读作引用。因此，第一个声明可以读作 "r 是一个初始化为 i 的整型引用"，
*/
void referencesPointer(){
       // 声明简单的变量
   int    i;
   double d;
 
   // 声明引用变量
   int&    r = i;
   double& s = d;
   
   i = 5;
   cout << "Value of i : " << i << endl;
   cout << "Value of i reference : " << r  << endl;
 
   d = 11.7;
   cout << "Value of d : " << d << endl;
   cout << "Value of d reference : " << s  << endl;
}

// 函数声明
void swap(int& x, int& y);

/*
C++ 把引用作为参数
C++ 引用 C++ 引用

我们已经讨论了如何使用指针来实现引用调用函数。下面的实例使用了引用来实现引用调用函数。
*/
void referparam(){
       // 局部变量声明
   int a = 100;
   int b = 200;
 
   cout << "交换前，a 的值：" << a << endl;
   cout << "交换前，b 的值：" << b << endl;
 
   /* 调用函数来交换值 */
   swap(a, b);
 
   cout << "交换后，a 的值：" << a << endl;
   cout << "交换后，b 的值：" << b << endl;
}

// 函数定义
void swap(int& x, int& y)
{
   int temp;
   temp = x; /* 保存地址 x 的值 */
   x = y;    /* 把 y 赋值给 x */
   y = temp; /* 把 x 赋值给 y  */
  
   return;
}

double vals[] = {10.1, 12.6, 33.1, 24.1, 50.0};
 
double& setValues( int i )
{
  return vals[i];   // 返回第 i 个元素的引用
}

/*
C++ 把引用作为返回值
C++ 引用 C++ 引用

通过使用引用来替代指针，会使 C++ 程序更容易阅读和维护。C++ 函数可以返回一个引用，方式与返回一个指针类似。

当函数返回一个引用时，则返回一个指向返回值的隐式指针。这样，函数就可以放在赋值语句的左边。例如，请看下面这个简单的程序
*/
void refeRetrun(){
    cout << "改变前的值" << endl;
   for ( int i = 0; i < 5; i++ )
   {
       cout << "vals[" << i << "] = ";
       cout << vals[i] << endl;
   }
 
   setValues(1) = 20.23; // 改变第 2 个元素
   setValues(3) = 70.8;  // 改变第 4 个元素
 
   cout << "改变后的值" << endl;
   for ( int i = 0; i < 5; i++ )
   {
       cout << "vals[" << i << "] = ";
       cout << vals[i] << endl;
   }

}

/*
当返回一个引用时，要注意被引用的对象不能超出作用域。所以返回一个对局部变量的引用是不合法的，但是，可以返回一个对静态变量的引用。

int& func() {
   int q;
   //! return q; // 在编译时发生错误
   static int x;
   return x;     // 安全，x 在函数作用域外依然是有效的
}
*/
#include <stdio.h>
#include <sys/time.h>

/*
获取linux下的微秒数
*/
void linuxTimeUs(){
    struct timeval start, end;
    gettimeofday( &start, NULL );
    for ( int i = 0; i < 10; i++ )
   {
       cout << "vals[" << i << "] = ";
   }
    gettimeofday( &end, NULL );
    int timeuse = 1000000 * ( end.tv_sec - start.tv_sec ) + end.tv_usec - start.tv_usec;
    printf("time: %d us\n", timeuse);
}

long getSystemTime() {
    struct timeb t;
    ftime(&t);
    return 1000 * t.time + t.millitm;
}

void linuxTime(){
     long start=getSystemTime();
     for ( int i = 0; i < 1000; i++ )
   {
       cout << "vals[" << i << "] ";
       if(!(i%10)){
        cout << endl ;
       }
   }
    long end=getSystemTime();
    printf("time: %ld ms\n", end-start);

}