#!/bin/bash

if [ -e *.out ]
then
rm *.out 
fi

# 各基本数据类型所占的字节数
# gcc ./day4/d4t1.c -o a.out -Wall
# 各种进制
# gcc ./day4/d4t2.c -o a.out -Wall
# 打印变量
# gcc ./day4/d4t3.c -o a.out -Wall
# 用户输入一个 ASCII 码值(如 66)，程序输出相应的字符。
# gcc ./day4/task1-2-3.c -o a.out -Wall
# 要求输入水的夸脱数，然后 显示这么多水中包含多少个水分子。
# gcc ./day4/task4.c -o a.out -Wall

# 实验2 5个技术点强化
# gcc ./day5/d5t1.c -o a.out -Wall
# 实验2 5个技术点强化
# gcc ./day5/experiment.c -o a.out -Wall
# 用户输入一个分钟数，程序将其转换成以小时和分钟表示的时 间并输出到屏幕上。（使用#define 来定义一个代表 60 的符号常量）
# gcc ./day5/d5t2.c -o a.out -Wall
#  作业2
#  A-Z之间 的ascii编码  65-90
#   编写一个程序，用户输入某个大写字母，产生一个金字塔图案。例如用户输入字母 E，则产生如下图案
#      A
#     ABA
#    ABCBA
#   ABCDCBA
#  ABCDEDCBA
# gcc ./day5/d5t3.c -o a.out -Wall
# 编写一个程序，该程序读取输入直到遇到#字符，然后报告读取的空格数目、读取的换行符数目以及读取 的所有其他字符数目
# gcc ./day5/d5t4.c -o a.out -Wall
# 输入一个华氏温度，要求输出摄氏温度。要求结果保留 2 位小数
# gcc ./day5/d5t5.c -o a.out -Wall 
#  打印如下图案：
#    *
#   ***
#  *****
# *******
#  *****
#   ***
#    *
# gcc ./day5/d5t6.c -o a.out -Wall -lm
# 将一个十进制数转换为十六进制数。比如输入 10，输出 0xA
# gcc ./day5/d5t7.c -o a.out -Wall 
# 编写一个程序，接受一个整数输入，然后显示所有小于或等于该数的素数。
# gcc ./day5/d5t8.c -o a.out -Wall -lm

# 1.输入一个十位数，例如57 将其拆分开来，打印5和7 
# 尝试着输入千位数，例如1234，分别打印1.2.3.4）
# 发现，如果pow(a,b),如果a，b都是常量时，是
# 不会出现提示的，但是，如果a，b中有任何一个是变量，那么编译时 都会出现提示。
# 现象就是这么简单，解决方式就是在编译的时候加上-lm，其实man
# 手册上写的很清楚了
# gcc d6t2.c -o a.out -Wall -lm
# gcc d6t3.c -o a.out -Wall 
# 3.从小到大，输入3个数据。
# A. 判断这个数据是否可以组成三角形？
# （两边和大于最长边）
# B.判断三角形是否为直角三角形？
# （勾股定理） 用排序
# gcc d6t4.c -o a.out -Wall

# 位运算
# gcc d7t1.c -o a.out -Wall
# 分支结构
# gcc d7t2.c -o a.out -Wall 
# 三数选最大值出来
# gcc d7t3.c -o a.out -Wall 
# 循环结构 计算两数间偶数和奇数
gcc d7t4.c -o a.out -Wall 


# -e确定文件是否存在,-x确定文件是否有执行权限
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