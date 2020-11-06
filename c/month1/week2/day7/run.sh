#!/bin/bash

if [ -e *.out ]
then
rm *.out 
fi

# echo "开启调试编译"
# gcc ../practice1/debug.c -o b_debug.out -Wall -DDEBUG
# echo "无调试编译"
# gcc ../practice1/debug.c -o a.out -Wall
#  结构体
# gcc ./d7t1.c -o a.out -Wall
# 实验题4、定义一个结构体变量(包括年月日)。计算该日在本年中是第几天？注意闰年问题
# gcc ./d7t2.c -o a.out -Wall
#  实验题5..声明一个枚举类型，使用 choices 作为标记，将枚举常量 no、yes 和 maybe 分别设置为 0、1 和 2。
# gcc ./d7t3.c -o a.out -Wall
# 6、 声明 4 个函数，并把一个指针数组初始化为指向它们。每个函数接受两个 double 参数并返回 double 值。
# gcc ./d7t4.c -o a.out -Wall
# 7.
# gcc ./d7t5.c -o a.out -Wall
# 8 math.h 的double参数需要加-lm
gcc ./d7t6.c -o a.out -Wall -lm


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