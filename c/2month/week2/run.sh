#!/bin/bash

if [ -e *.out ]; then
    rm *.out
fi

# 插入排序,改
# c_name="d1t1"
# 链式栈
# c_name="d1t2"
# 1.使用链式栈，实现10进制数转换为8进制和16进制数。
# c_name="d1t3"
# 2.尝试根据链式队列的示意图，把实现代码完成。
# c_name="d1t4"
# 电子相册
# c_name="d1t5"
# 电子相册
# c_name="d2t1"

# -----day3----
# 编译成动态库 gb2312编码中文显示于开发板
# arm-linux-gnueabi-gcc -fPIC d3t4.c -I ../include -o libFontch.so -shared -Wall
# arm-linux-gnueabi-gcc -fPIC font_libs.c -I ../include -o libFontch.so -shared -Wall
# 字符编码转换.
# arm-linux-gnueabi-gcc -fPIC char_conversion.c -I ../include -o libCharConversion.so -shared -Wall
# 链接动态库
# arm-linux-gnueabi-gcc d3t5.c -I ../include lib/*.so -o d32.out -Wall
# 编译成静态库
# arm-linux-gnueabi-gcc d3t4.c -c -I ../include -Wall; ar rcs libFontch.a d3t4.o
# 引用
# arm-linux-gnueabi-gcc d3t5.c -I ../include lib/libFontch.a -o d32.out -Wall

# 将中英文显示 ,编码转换功能编译成动态库 day3/t2
# arm-linux-gnueabi-gcc -fPIC *.c -I ../include -o libFontch.so -shared -Wall
# arm-linux-gnueabi-gcc main.c -I ../include ../lib/*.so -o ../dist/d32.out -Wall
# 链式队列
# c_name='d3t1'
# 排序链表函数封装
# c_name='d4t1'

#  -----------------day6----------------
# gcc x86_64平台的gcc编译
# aarch64-none-linux-gnu-gcc  arm平台的gcc编译
# arm-linux-gnueabi-gcc arm平台的gcc编译
# env CC=aarch64-none-linux-gnu-gcc ./configure --prefix=/home/gec/install/dist --host=aarch64-none-linux-gnu
# env CC=arm-linux-gnueabi-gcc ./configure --prefix=/home/gec/install/dist --host=arm-linux-gnueabi-gcc
# Target: arm-linux-gnueabi  
#  编译到arm平台的库 ./configure --prefix=/home/gec/install/dist --host=arm-linux-gnueabi
# 显示图片 引用动态
# arm-linux-gnueabi-gcc src/d6t1.c -I include lib/libjpeg.s* -o dist/d33.out -Wall
# 引用静态
# arm-linux-gnueabi-gcc src/d6t1.c -I include lib/libjpeg.a -o dist/d33.out -Wall
# 显示图片从上,下落
# arm-linux-gnueabi-gcc src/d6t1.c -I include lib/libjpeg.s* -o dist/d33.out -Wall
# 通过位运算,将4个16进制数拼接起来 month2/demo/ 目录下
# gcc month2/demo/d1.c  -o month2/demo/d33.out -Wall
# 
arm-linux-gnueabi-gcc ./src/d*.c -I ./include ./lib/libjpeg.s* -o ./dist/d33.out -Wall

# if [ $1 == "x86" ]; then
#     # x86_64平台的gcc编译
#     gcc $c_name.c -o $c_name.out -Wall
# elif [ $1 == "arm" ]; then
#     #* 用arm-linux-gcc交叉编译生成的是arm平台的linux系统执行文件
#     arm-linux-gcc $c_name.c -o $c_name.out -Wall
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
