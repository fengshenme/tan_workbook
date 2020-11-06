#!/bin/bash

if [ -e *.out ]; then
    rm *.out
fi

# 插入排序,改
# 电子相册
c_name="show_chinese"

dir_name="*"

if [ $1 == "x86" ]; then
    # x86_64平台的gcc编译
    gcc $dir_name.c -o $c_name.out -Wall
elif [ $1 == "arm" ]; then
    #* 用arm-linux-gcc交叉编译生成的是arm平台的linux系统执行文件
    arm-linux-gcc $dir_name.c -o $c_name.out -Wall -I./libfont -L./libfont -lfont 
    # arm-linux-gcc d3t5.c -o show_chinese.out -L./libfontch.so -Wall -shared
fi


if [ -e $c_name.out ] && [ -x $c_name.out ]; then

    if [ $2 ]; then
        ./$c_name.out $2
    else
        ./$c_name.out
    fi

else
    echo "编译没有成功,执行文件没有生成"
fi
