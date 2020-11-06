#!/bin/bash

if [ -e *.out ]
then
rm *.out 
fi

# 指针习题 1-8
# gcc ./d3t2.c -o a.out -Wall 
# 指针习题 9
# gcc ./d3t3.c -o a.out -Wall 
# 指针习题 10
# gcc ./d3t4.c -o a.out -Wall
# 指针习题 11-12
# gcc ./d3t5.c -o a.out -Wall
# 指针习题 13-16
# gcc ./d3t6.c -o a.out -Wall
# 指针习题 17-18
# gcc ./d3t7.c -o a.out -Wall
# 实验手册 题1
# gcc ./d3t8.c -o a.out -Wall
# 实验手册 题2
# gcc ./d3t9.c -o a.out -Wall
# 实验手册 题3
# gcc ./d3t10.c -o a.out -Wall
# 实验手册 题4
# gcc ./d3t11.c -o a.out -Wall
# 实验手册 题6
gcc ./d3t12.c -o a.out -Wall
 

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