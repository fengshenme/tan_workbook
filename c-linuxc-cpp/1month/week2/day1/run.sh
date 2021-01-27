#!/bin/bash

if [ -e *.out ]
then
rm *.out 
fi


#  打印如下图案：
#    *
#   ***
#  *****
# *******
#  *****
#   ***
#    *
# gcc e3t6.c -o a.out -Wall -lm
# 初始化数组
# gcc ./d1t2.c -o a.out -Wall 
# 五只小猪称体重,找出数组中最重的一只.
# gcc ./d1t3.c -o a.out -Wall 
# 数组的数组的使用二维数组使用
# gcc ./d1t4.c -o a.out -Wall 
# 通过指针输出 int (*a)[6]即为一个数组指针。int *p[6]则是一个大小为6且存放整型指针的数组
# gcc ./d1t5.c -o a.out -Wall 
# 假如有如下定义： int a[3][5]; a. 用 1 种方法表示 a[2][3]的地址。 
# b. 用 2 种方法表示 a[2][0]的地址。 c. 用 3 种方法表示 a[0][0]的地址
# gcc ./d1t6.c -o a.out -Wall 
# /**
#  * 编写一个函数，返回一个 double 型数组中最大和最小值的差值，并在一个简单的程序中测试这个函数。
# gcc ./d1t7.c -o a.out -Wall 
gcc ./d1t8.c -o a.out -Wall 

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