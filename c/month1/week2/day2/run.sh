#!/bin/bash

if [ -e *.out ]
then
rm *.out 
fi

#    *
# gcc e3t6.c -o a.out -Wall -lm
# gcc ./d2t1.c -o a.out -Wall 
# gcc ./d2t2.c -o a.out -Wall
# 数组指针：
# 指向数组的指针。（行指针）
gcc ./d2t3.c -o a.out -Wall 

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