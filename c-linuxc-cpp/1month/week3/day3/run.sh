#!/bin/bash

if [ -e *.out ]
then
rm *.out 
fi

# echo "开启调试编译"
# gcc ../practice1/debug.c -o b_debug.out -Wall -DDEBUG
# echo "无调试编译"
# gcc ../practice1/debug.c -o a.out -Wall

# 判断大小端序
# gcc d3t1.c -o a.out -Wall 
# 2.运行程序后，每隔1秒钟，将当前时间写入到 time.txt中
# 温馨提示：使用 system()、sleep() 函数。
gcc d3t2.c -o loctime.out -Wall 



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