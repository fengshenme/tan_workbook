#!/bin/bash

if [ -e *.out ]; then
    rm *.out
fi

# 插入排序,改
# 电子相册
# c_name="pro_c"

dir_name="src/*"

# 将中英文显示 ,编码转换功能编译成动态库
# arm-linux-gnueabi-gcc -fPIC *.c -I ../include -o libFontch.so -shared -Wall
arm-linux-gnueabi-gcc $dir_name.c -I include lib/*.so -o dist/pro_c.out -Wall

# if [ $1 == "x86" ]; then
#     # x86_64平台的gcc编译
#     gcc $dir_name.c -o $c_name.out -Wall
# elif [ $1 == "arm" ]; then
#     #* 用arm-linux-gcc交叉编译生成的是arm平台的linux系统执行文件
#     arm-linux-gnueabi-gcc $dir_name.c -o $c_name.out -Wall
# fi


# if [ -e $c_name.out ] && [ -x $c_name.out ]; then

#     if [ $2 ]; then
#         ./$c_name.out $2
#     else
#         ./$c_name.out
#     fi

# else
#     echo "编译没有成功,执行文件没有生成"
# fi
