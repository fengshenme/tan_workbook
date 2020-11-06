#!/bin/bash

if [ -e *.out ]
then
rm *.out 
fi

# 位运算
# gcc d7t1.c -o a.out -Wall
# 分支结构
# gcc d7t2.c -o a.out -Wall 
# gcc d7t3.c -o a.out -Wall 
# 循环结构
gcc d7t4.c -o a.out -Wall 


# -e确定文件是否存在,-x确定文件是否有执行权限
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