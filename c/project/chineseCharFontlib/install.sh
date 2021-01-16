#!/bin/bash

if [ -e dist/lib/x86_64/* ]; then
    rm dist/lib/x86_64/*
    rm dist/lib/arm/*
fi


if [ $1 == "x86" ]; then
    # x86_64平台的gcc编译
    gcc $c_name.c -o $c_name.out -Wall
elif [ $1 == "arm" ]; then
    arm-linux-gnueabi-gcc $c_name.c -o $c_name.out -Wall
else
    gcc -fPIC src/*.c -I include -o dist/lib/x86_64/libFontch.so -shared -Wall
    arm-linux-gnueabi-gcc -fPIC src/*.c -I include -o dist/lib/arm/libFontch.so -shared -Wall
    cp include/* dist/include/
    # arm-linux-gnueabi-gcc src/*.c -I include lib/*.so -o dist/pro_c.out -Wall
    echo "动态库生成完成"
fi


