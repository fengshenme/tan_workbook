#include <stdio.h>

/**
  * 实验2 5个技术点强化
*/

void task1(void);
void task2(void);
void task3(float a);
void task4(void);

int main(int argc, char const *argv[])
{
    printf("================作业1=============== \n");
    task1();

    printf("================作业2=============== \n");
    task2();
    
    printf("================作业3=============== \n");
    float t3;
    printf("请输入一个浮点数:");
    scanf("%f", &t3); while (getchar() != '\n');
    task3(t3);
    
    printf("================作业4=============== \n");
    task4();
    
    return 0;

}

/* 
作业1
此程序要求输入一个整数，然后打印出从输入的值(含)到比输入的值大 10(含)的所有整数 值(比如输入 5，则输出 5 到 15)。
要求在各个输出值之间用空格、制表符或者换行符分开。
*/
void task1(void)
{
    int a;
    scanf("%d", &a); while (getchar() != '\n');
    int i;
    for (i = a; i <= a+10; i++)
    {
        printf("%d ", i);
    }
    printf("\n");
}

/*
作业2
写出下面表达式运算后 a 的值，设原来 a=12。设 a 和 n 已定义为整型变量。 
(1) a += a      (2) a -= 2                      (3) a *= 2+3 
(4) a /= a+a    (5) a %= (n%2)，n 的值为 5       (6) a += a -= a *= a
*/
void task2()
{
    printf("%d %d %d %d %d %d \n",24,10,27,13,12,0);
    // 6  a= a* a 144 a-a=a 0 a + a = a
}

/**
 * 作业3
 * 、编写一个程序，该程序要求输入一个 float 型数并打印概述的立方值。使用你自己设计的函数来计算该值 的立方并且将它的立方打印出来。
 *  main 函数负责把输入的值传递给该函数。
 * 
 */
void task3(float a)
{
    printf("%f \n", a*a*a );
} 

/**
 * 作业4
 * 编写一个程序，此程序要求输入天数，然后将该值转换为星期数和天数。
 * 例如输入 18，则要求输出： 18 days are 2 weeks, 4days.
 */
#define WEEK  7; // 使用#define 来定义一个代表 7 的符号常量

void task4(void)
{
    printf("请输入天数:");
    int day;
    scanf("%d", &day); while (getchar() != '\n');
    int a = day / WEEK ;
    int b = day % WEEK ;
    printf("%d days are %d weeks, %d days.\n", day, a, b);
    
}

/**
 * 5、分析并解释以下程序的执行结果。 
 * #include <stdio.h> 
 * int main(void) 
 * { 
 *      int a,b,c,d; 
 *      a=10; 
 *      b=a++; 
 *      c=++a; 
 *      d=10*a++; 
 *      printf(“b，c，d：%d，%d，%d”，b，c，d); 
 *      return 0; 
 * }
 * b = 10,a 11 ,c=12 ,a 12 ,d=130
 * 执行结果: b, c, d: 10, 12, 130
 * 
*/