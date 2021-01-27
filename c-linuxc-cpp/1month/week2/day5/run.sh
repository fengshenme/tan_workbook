#!/bin/bash

if [ -e *.out ]
then
rm *.out 
fi

# echo "开启调试编译"
# gcc ../practice1/debug.c -o b_debug.out -Wall -DDEBUG
# echo "无调试编译"
# gcc ../practice1/debug.c -o a.out -Wall

# 数据交换
# gcc ./d5t1.c -o a.out -Wall
# 整数次幂
# gcc ./d5t2.c -o a.out -Wall
# 数组函数
# gcc ./d5t3.c -o a.out -Wall
# 二维数组函数
# gcc ./d5t4.c -o a.out -Wall
# 通过函数修改指针
# gcc ./d5t5.c -o a.out -Wall
# 通过函数修改指针
# gcc ./d5t6.c -o a.out -Wall
# 编写一个函数，它返回函数自身被调用的次数，并在一个循环中测试之
gcc ./d5t7.c -o a.out -Wall



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