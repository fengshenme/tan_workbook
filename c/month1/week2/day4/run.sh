#!/bin/bash

if [ -e *.out ]
then
rm *.out 
fi

#    *
# gcc e3t6.c -o a.out -Wall -lm
# const 指针
# gcc ./d4t1.c -o a.out -Wall 
#  编写一个函数，使其返回 2 个整型参数中的最大值 
# gcc ./d4t2.c -o a.out -Wall
# 实验题3 3、 编写一个函数，使其返回 3 个整型参数中的最大值 
# gcc ./d4t4.c -o a.out -Wall
# 4、 编写一个函数 my_power，用循环的方法实现返回一个 float 类型数的某个整数次幂(保留 6 位小数)。例如： 调用 my_power(3.14, -2)返回 0.101424 
# gcc ./d4t5.c -o a.out -Wall
# 编写一个程序，将两个字符串连接起来，不要用 strcat 或 strncat 函数 
# gcc ./d4t6.c -o a.out -Wall 
# 编写一个函数 Fibonacci()，要求程序输出第 n 项斐波那契数，n 由用户输入。 斐波那契数列：1, 1, 2, 3, 5, 8, 13, 21, 
# gcc ./d4t7.c -o a.out -Wall 
# 编写一个程序，清除用户输入字符串中的空格符并将之输出。（例如用户输入”a b”，输出”ab”）
gcc ./d4t8.c -o a.out -Wall 

if [ -e a.out ] && [ -x a.out ]
then
    ./a.out
elif [ -e a.out ]
then
    sleep 6     # 文件没有生成延时6秒
    ./a.out
else
    echo "编译没有成功,执行文件没有生成"
fi