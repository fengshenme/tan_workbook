#!/bin/bash

if [ -e *.out ]; then
    rm *.out
fi

# shell脚本编写
1day/*

# 在完成购票系统的使用
2day~7day

# sqllite3的使用
7day/*SQLlite

# 根据生成的执行文件与源文件的时间戳比较来编译,源文件最后修改时间比执行文件最后修改时间大则进行编译
# arr=$(ls *.c)

# for var in ${arr[*]}; do
#     var=${var%.c} # 字符串删除扩展名.c
#     echo $var
#     if [ -e $var.c ] && [ -e $var.out ]; then
#         #获取文件做后修改时间戳
#         l_c=$(stat -c %Y $var.c)
#         l_out=$(stat -c %Y $var.out)
#         if [ $l_c -gt $l_out ]; then
#             gcc $var.c -o $var.out -lpthread -Wall 
#         else
#             echo $var.out is last \; No need to compile 
#         fi
#     elif [ -e $var.c ]; then
#         gcc $var.c -o $var.out -Wall -lpthread
#     fi
# done

if [ $1 == "x86" ]; then
    # x86_64平台的gcc编译
    gcc $c_name.c -o $c_name.out -Wall
elif [ $1 == "arm" ]; then
    arm-linux-gcc $c_name.c -o $c_name.out -Wall
fi

# 用arm-linux-gcc交叉编译生成的是arm平台的linux系统执行文件
if [ -e $c_name.out ] && [ -x $c_name.out ]; then

    if [ $2 ]; then
        ./$c_name.out $2
    else
        ./$c_name.out
    fi

else
    echo "编译没有成功,执行文件没有生成"
fi
