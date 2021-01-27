#!/bin/bash

if [ -e *.out ]; then
    rm *.out
fi

# jpg格式图片由上到下显示
exe_name="d33"

if [ $1 != NULL ];then

if [ $1 == "x86" ]; then
    # x86_64平台的gcc编译
    env_name="gcc"
elif [ $1 == "arm" ]; then
    #* 用arm-linux-gcc交叉编译生成的是arm平台的linux系统执行文件
    env_name="arm-linux-gnueabi-gcc"
fi

$env_name ./src/*.c -I ./include ./lib/libjpeg.s* -o ./dist/$exe_name.out -Wall -pthread

fi

# if [ -e $c_name.out ] && [ -x $c_name.out ]; then

#     if [ $2 ]; then
#         ./$c_name.out $2
#     else
#         ./$c_name.out
#     fi

# else
#     echo "编译没有成功,执行文件没有生成"
# fi
