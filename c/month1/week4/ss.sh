#!/bin/bash

if [ -e *.out ]
then
rm *.out 
fi

# echo "开启调试编译"
# gcc ../practice1/debug.c -o b_debug.out -Wall -DDEBUG
# echo "无调试编译"
# gcc ../practice1/debug.c -o a.out -Wall


# 图书管理系统增加,链表,借书还书功能
# gcc ./day1/d1t1.c -o a.out -Wall 
# 文件复制
gcc ./day1/d1t2.c -o a.out -Wall -lm


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