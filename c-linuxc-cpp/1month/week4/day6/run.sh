#!/bin/bash

if [ -e *.out ]
then
rm *.out 
fi

# echo "开启调试编译"
# gcc ../practice1/debug.c -o b_debug.out -Wall -DDEBUG
# echo "无调试编译"
# gcc ../practice1/debug.c -o a.out -Wall


# 图书管理系统增加,链表,借书还书功能
# gcc ./day1/d1t1.c -o a.out -Wall 
# 文件复制
# gcc ./day1/d1t2.c -o a.out -Wall -lm
# 1.显示全屏的其他颜色
# arm-linux-gcc ./day1/d1t4.c -o ./day1/d1t4 -Wall 
# // 显示德国国旗（思考一下意大利国旗可以如何显示)？
# arm-linux-gcc ./day1/d1t5.c -o ./day1/d1t5 -Wall 
# // 意大利国旗可以如何显示)？
# arm-linux-gcc ./day1/d1t6.c -o ./day1/d1t6 -Wall 
# 显示德国国旗
# arm-linux-gcc ./day2/d2t2.c -o ./day1/d1t6 -Wall 
# 多种颜色循环切换
# arm-linux-gcc ./day2/d2t3.c -o ./day1/d1t6 -Wall 
# 多种颜色循环切换2
# arm-linux-gcc ./day2/d2t5.c -o ./day1/d1t6 -Wall 
# /*多种颜色循环切换，间隔一秒*/
# arm-linux-gcc ./day3/d3t1.c -o ./day1/d1t6 -Wall 
# 使用内存映射 进行多种颜色循环切换，间隔一秒
# arm-linux-gcc ./day3/d3t2.c -o ./day1/d1t6 -Wall 
# 使用内存映射,将功能封装成函数, 进行多种颜色循环切换，间隔一秒
# arm-linux-gcc ./day3/d3t3.c -o ./day1/d1t6 -Wall 
# /*多张图片循环切换，间隔一秒*/
# arm-linux-gcc ./day3/d3t4.c -o ./day1/d1t6 -Wall 
# 读取触摸屏数据,读取坐标数据
# arm-linux-gcc ./day3/d3t5.c -o ./day1/d1t6 -Wall 
# 点击屏幕左边为全屏白色,点击右边为出现图片
# arm-linux-gcc d4t1.c -o d4t1 -Wall 
# 
# arm-linux-gcc d4t2.c -o d4t2 -Wall 
# 读取触摸屏数据,读取坐标数据,结构体指针参数传输,
# arm-linux-gcc d4t3.c -o d4t3 -Wall 
# 
# gcc d4t4.c -o d4t4.out -Wall 
# 2.使用一下 fread函数，分别读取 99/100/101个字节的文件 要求全部读取完毕之后，打印出来。
# gcc d4t5.c -o d4t5.out -Wall 
#  1.电子相册。点击屏幕左边上一张点击屏幕右边下一张
# arm-linux-gcc d4t6.c -o d4t6.out -Wall 

# 第四周第5天 第一个代码/1.fgets函数会把换行符一起获取到。思考如何将尾部的换行符去除呢？（strtok函数）
# c_name="d5t1"
# 1.连续打印五个hello，没有换行符。 2.while(getchar()!='\n');思考上述语句有何作用？为什么scanf后面都需要添加？
# c_name="d5t2"
# 1.尝试使用stat函数获取某个文件的属性，存储在结构体中。将所有数据都打印出来！
# c_name="d5t3"
# 2.day5/code/demo2_ls-l（未完成）.c，根据其中的注释的提示。尽量完成  ls -l 的功能
# c_name="d5t4"
# 读取目录下的文件
# c_name="d6t1"
# 读取目录下的文件ebm
# c_name="d6t2"
# 读取目录下的文件ebm
c_name="d6t3"

if [ $1 == "x86" ]
then
# x86_64平台的gcc编译
gcc $c_name.c -o $c_name.out -Wall
elif [ $1 == "arm" ]
then
arm-linux-gcc $c_name.c -o $c_name.out -Wall 
fi

# // 用arm-linux-gcc交叉编译生成的是arm平台的linux系统执行文件
if [ -e $c_name.out ] && [ -x $c_name.out ] 
then

if [ $2 ] 
then
    ./$c_name.out $2
else
    ./$c_name.out
fi

else
    echo "编译没有成功,执行文件没有生成"
fi