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
# gcc d1t1.c -o a.out -Wall -lm
# 计算字符串长度
# gcc d1t2.c -o a.out -Wall -lm
# gcc d1t3.c -o a.out -Wall -lm
# 写一个带参数的宏 MIN(x, y)，这个宏输入两个参数并返回较小的一个
# gcc d1t4.c -o a.out -Wall 
# 设计一个 C 函数，若处理器是大端序的则返回 0，若处理器是小端序的则返回 1。
# gcc d1t6.c -o a.out -Wall 
#  编写一个函数，计算 1+2+3+4+…+n 的值
# gcc d1t7.c -o a.out -Wall 
# 用递归的思想重做实验四的第 4 道题（my_power 函数）
# gcc d1t8.c -o a.out -Wall 
# 下面函数实现数组元素的逆转，请填写空白处使其完整。
# gcc d1t9.c -o a.out -Wall 
# //字符串输入 同时空格也保存
gcc d1t10.c -o a.out -Wall 



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