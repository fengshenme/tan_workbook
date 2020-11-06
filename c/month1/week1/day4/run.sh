#!/bin/bash

if [ -e *.out ]
then
rm *.out 
fi

# 各基本数据类型所占的字节数
# gcc d4t1.c -o a.out -Wall
# 各种进制
# gcc d4t2.c -o a.out -Wall
# 打印变量
# gcc d4t3.c -o a.out -Wall
# 用户输入一个 ASCII 码值(如 66)，程序输出相应的字符。
gcc task1-2-3.c -o a.out -Wall
# 要求输入水的夸脱数，然后 显示这么多水中包含多少个水分子。
# gcc task4.c -o a.out -Wall

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