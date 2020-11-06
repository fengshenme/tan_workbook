#!/bin/bash

if [ -e *.out ]
then
rm *.out 
fi

# 1.输入一个十位数，例如57 将其拆分开来，打印5和7 
# 尝试着输入千位数，例如1234，分别打印1.2.3.4）
# 发现，如果pow(a,b),如果a，b都是常量时，是
# 不会出现提示的，但是，如果a，b中有任何一个是变量，那么编译时 都会出现提示。
# 现象就是这么简单，解决方式就是在编译的时候加上-lm，其实man
# 手册上写的很清楚了
gcc d6t2.c -o a.out -Wall -lm
# gcc d6t3.c -o a.out -Wall 
# 3.从小到大，输入3个数据。
# A. 判断这个数据是否可以组成三角形？
# （两边和大于最长边）
# B.判断三角形是否为直角三角形？
# （勾股定理） 用排序
# gcc d6t4.c -o a.out -Wall 

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