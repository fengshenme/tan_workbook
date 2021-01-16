#!/bin/bash

if [ -e *.out ]; then
    rm *.out
fi

# 插入排序,改
# 电子相册
# c_name="pro_c"

# 使用的gcc编译器版本
cc="arm-linux-gnueabi-gcc"
# src目录下的所有c源文件
c_source="src/*.c"
# 引用自定义的头文件目录
head_dir="-I include"
# 引用自定义的库文件目录
lib_dir="-L lib"
# 引用库文件, 不需要写库的前缀'lib'与库的后缀'.so'等
lib_names="-lFontch -ljpeg -lpthread "
# 生成的可执行文件
exec_path="dist/d36.out"
# 是否需要详细检测
debug="-Wall"


# 编译安装jpeg的动态库和静态库 
# ./configure --prefix=/home/gec/install/dist --host=arm-linux-gnueabi
# make && make install >> install.log
#  字体显示库,编码转换功能,编译成动态库
# arm-linux-gnueabi-gcc -fPIC *.c -I ../include -o libFontch.so -shared -Wall
# 调用动态库 ,多线程,jpeg图片显示,支持中英文字符已点阵显示
$cc $c_source -o $exec_path $head_dir $lib_dir $lib_names $debug

# if [ $1 == "x86" ]; then
#     # x86_64平台的gcc编译
#     gcc $c_source -o $c_name.out -Wall
# elif [ $1 == "arm" ]; then
#     #* 用arm-linux-gcc交叉编译生成的是arm平台的linux系统执行文件
#     arm-linux-gnueabi-gcc $c_source -o $c_name.out -Wall
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
