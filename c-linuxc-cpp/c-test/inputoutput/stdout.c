/*
实例解析：
所有的 C 语言程序都需要包含 main() 函数。 代码从 main() 函数开始执行。
printf() 用于格式化输出到屏幕。printf() 函数在 "stdio.h" 头文件中声明。
stdio.h 是一个头文件 (标准输入输出头文件) and #include 是一个预处理命令，用来引入头文件。 当编译器遇到 printf() 函数时，
如果没有找到 stdio.h 头文件，会发生编译错误。
return 0; 语句用于表示退出程序。

*/
#include <stdio.h>
int main()
{
    int testInteger = 5;
    printf("Number = %d \n", testInteger);

    // %f 格式化输出浮点型数据 在 printf() 函数的引号中使用 "%d" (整型) 来匹配整型变量 testInteger 并输出到屏幕。
    float f;
    printf("Enter a number: ");
    // %f 匹配浮点型数据
    scanf("%f",&f);
    printf("Value = %f", f);

    /*
    getchar() & putchar() 函数
    int getchar(void) 函数从屏幕读取下一个可用的字符，并把它返回为一个整数。
    这个函数在同一个时间内只会读取一个单一的字符。您可以在循环内使用这个方法，以便从屏幕上读取多个字符。
    int putchar(int c) 函数把字符输出到屏幕上，并返回相同的字符。这个函数在同一个时间内只会输出一个单一的字符。
    您可以在循环内使用这个方法，以便在屏幕上输出多个字符。
    请看下面的实例：
    
    */
   int c;
 
   printf( "\nEnter a value :");
   c = getchar( );
 
   printf( "\nYou entered: ");
   putchar( c );
   printf( "\n");

    /*
    
    scanf() 和 printf() 函数
    int scanf(const char *format, ...) 函数从标准输入流 stdin 读取输入，并根据提供的 format 来浏览输入。
    int printf(const char *format, ...) 函数把输出写入到标准输出流 stdout ，并根据提供的格式产生输出。
    format 可以是一个简单的常量字符串，但是您可以分别指定 %s、%d、%c、%f 等来输出或读取字符串、整数、字符或浮点数。
    还有许多其他可用的格式选项，可以根据需要使用。
    如需了解完整的细节，可以查看这些函数的参考手册。现在让我们通过下面这个简单的实例来加深理解：

    */
   char str[100];
   int i;
   printf( "Enter a value :");
   scanf("%s %d", str, &i);
   printf( "\nYou entered: %s %d ", str, i);
   printf("\n");
    /*
    在这里，应当指出的是，scanf() 期待输入的格式与您给出的 %s 和 %d 相同，这意味着您必须提供有效的输入，比如 "string integer"，如果您提供的是 "string string" 或 "integer integer"，它会被认为是错误的输入。
    另外，在读取字符串时，只要遇到一个空格，scanf() 就会停止读取，所以 "this is test" 对 scanf() 来说是三个字符串。
    */

   return 0;
}
