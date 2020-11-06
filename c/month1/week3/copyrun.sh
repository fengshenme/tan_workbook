#!/bin/bash

if [ -e *.out ]
then
rm *.out 
fi

# echo "开启调试编译"
# gcc ../practice1/debug.c -o b_debug.out -Wall -DDEBUG
# echo "无调试编译"
# gcc ../practice1/debug.c -o a.out -Wall

# 
# gcc ./day1/d1t1.c -o a.out -Wall -lm
# 计算字符串长度
# gcc ./day1/d1t2.c -o a.out -Wall -lm
# gcc ./day1/d1t3.c -o a.out -Wall -lm
# 写一个带参数的宏 MIN(x, y)，这个宏输入两个参数并返回较小的一个
# gcc ./day1/d1t4.c -o a.out -Wall 
# 设计一个 C 函数，若处理器是大端序的则返回 0，若处理器是小端序的则返回 1。
# gcc ./day1/d1t6.c -o a.out -Wall 
#  编写一个函数，计算 1+2+3+4+…+n 的值
# gcc ./day1/d1t7.c -o a.out -Wall 
# 用递归的思想重做实验四的第 4 道题（my_power 函数）
# gcc ./day1/d1t8.c -o a.out -Wall 
# 下面函数实现数组元素的逆转，请填写空白处使其完整。
# gcc ./day1/d1t9.c -o a.out -Wall 
# //字符串输入 同时空格也保存
# gcc ./day1/d1t10.c -o a.out -Wall 

# 判断大小端序
# gcc ./day3/d3t1.c -o a.out -Wall 
# 2.运行程序后，每隔1秒钟，将当前时间写入到 time.txt中
# 温馨提示：使用 system()、sleep() 函数。
# gcc ./day3/d3t2.c -o loctime.out -Wall 

# 在第二周d6t4基础上图书管理系统 增加 修改 删除 查询 crud
# gcc ./day4/d4t1.c -o a.out -Wall 
 
# 基础上图书管理系统增加登录验证
# gcc ./day5/d5t1.c -o a.out -Wall 

# 基础上图书管理系统增加借书还书功能以及用内核链表重写
# gcc ./day6/d6t1.c -o a.out -Wall 
# 删除一本书
# gcc ./day6/d6t2.c -o a.out -Wall 
# 使用系统io中open和close
# gcc ./day6/d6t3.c -o a.out -Wall
#  文件复制5.scanf输入一段字符串，并写入。
# hello,123
# 修改偏移量后，再scanf输入你的名字Jerry，并写入
# 这时读取文件所有内容：
# hello,Jerry
# gcc ./day6/d6t4.c -o a.out -Wall
# 作业1 1.浏览书本、资料，尝试使用open创建一个文件并写入数据。
# gcc ./day6/d6t5.c -o a.out -Wall
# 2.使用系统IO实现文件复制功能。
gcc ./day6/d6t6.c -o a.out -Wall
# gcc ./day6/d6t7.c -o a.out -Wall
 


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