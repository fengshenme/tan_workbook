#!/bin/bash

if [ -e *.out ]
then
rm *.out 
fi

# 实验2 5个技术点强化
# gcc d5t1.c -o a.out -Wall
# 实验2 5个技术点强化
# gcc experiment.c -o a.out -Wall

# 用户输入一个分钟数，程序将其转换成以小时和分钟表示的时 间并输出到屏幕上。（使用#define 来定义一个代表 60 的符号常量）
# gcc d5t2.c -o a.out -Wall
# 
#  作业2
#  A-Z之间 的ascii编码  65-90
#   编写一个程序，用户输入某个大写字母，产生一个金字塔图案。例如用户输入字母 E，则产生如下图案
#      A
#     ABA
#    ABCBA
#   ABCDCBA
#  ABCDEDCBA
# 
# gcc d5t3.c -o a.out -Wall

# 编写一个程序，该程序读取输入直到遇到#字符，然后报告读取的空格数目、读取的换行符数目以及读取 的所有其他字符数目
# gcc d5t4.c -o a.out -Wall

# 编写一个程序，接受一个整数输入，然后显示所有小于或等于该数的素数。
# gcc d7t1.c -o a.out -Wall -lm
# 输入一个华氏温度，要求输出摄氏温度。要求结果保留 2 位小数
# gcc e3t5.c -o a.out -Wall 
#  打印如下图案：
#    *
#   ***
#  *****
# *******
#  *****
#   ***
#    *
# gcc e3t6.c -o a.out -Wall -lm
gcc e3t7.c -o a.out -Wall 

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