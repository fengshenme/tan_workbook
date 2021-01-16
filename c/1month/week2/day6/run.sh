#!/bin/bash

if [ -e *.out ]
then
rm *.out 
fi

# echo "开启调试编译"
# gcc ../practice1/debug.c -o b_debug.out -Wall -DDEBUG
# echo "无调试编译"
# gcc ../practice1/debug.c -o a.out -Wall

# 
# gcc ./main.c func.c -o a.out -Wall
# 申请内存
# gcc ./d6t1.c -o a.out -Wall
# 函数申请内存
# gcc ./d6t2.c -o a.out -Wall
# 结构体练习
# gcc ./d6t3.c -o a.out -Wall
# 今日作业1
gcc ./d6t4.c -o a.out -Wall
# 实验题1-3
# gcc ./d6t5.c -o a.out -Wall



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