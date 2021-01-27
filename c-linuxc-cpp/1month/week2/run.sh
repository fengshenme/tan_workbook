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
# gcc ./day1/d1t1.c -o a.out -Wall -lm
# 初始化数组
# gcc ./day1/d1t2.c -o a.out -Wall 
# 五只小猪称体重,找出数组中最重的一只.
# gcc ./day1/d1t3.c -o a.out -Wall 
# 数组的数组的使用二维数组使用
# gcc ./day1/d1t4.c -o a.out -Wall 
# 通过指针输出 int (*a)[6]即为一个数组指针。int *p[6]则是一个大小为6且存放整型指针的数组
# gcc ./day1/d1t5.c -o a.out -Wall 
# 假如有如下定义： int a[3][5]; a. 用 1 种方法表示 a[2][3]的地址。 
# b. 用 2 种方法表示 a[2][0]的地址。 c. 用 3 种方法表示 a[0][0]的地址
# gcc ./day1/d1t6.c -o a.out -Wall 
# /**
#  * 编写一个函数，返回一个 double 型数组中最大和最小值的差值，并在一个简单的程序中测试这个函数。
# gcc ./day1/d1t7.c -o a.out -Wall 
# gcc ./day1/d1t8.c -o a.out -Wall 

# 指针
# gcc ./day2/d2t1.c -o a.out -Wall 
# gcc ./day2/d2t2.c -o a.out -Wall
# 数组指针：
# 指向数组的指针。（行指针）
# gcc ./day2/d2t3.c -o a.out -Wall

# 指针习题 1-8
# gcc ./day3/d3t2.c -o a.out -Wall 
# 指针习题 9 // 函数递归 ,通过指针将数组中元素改为降序排列
# gcc ./day3/d3t3.c -o a.out -Wall 
# 指针习题 10 // 指针交换数据
# gcc ./day3/d3t4.c -o a.out -Wall
# 指针习题 11-12
# 就是我使用的是64位的系统，但是在调试时显示的地址为48位，如下图。通过查阅资料，可以知道：地址为48位是表象，
#  * 出现这样结果的原因是x86_64处理器硬件限制。因为x86_64处理器地址线只有48条，故而导致硬件要求传入的地址48位到63位地址必须相同，若表示为16进制，则前4位为ffff或者是0000。也就是说有两段合法的地址空间：
#     0x00000000 0000 0000-0x0000 7fff ffff ffff
#     0xffff8000 0000 0000-0xffff ffff ffff ffff
#     由上可知，可表示的地址空间为2^48Byte=2^8TB=256TB,这就是当前处理器的寻址能力，又因为操作系统一般使用地段地址，故而一般只用到第一段地址空间，
#     如果要用到第二段地址空间，则需要内存达到寻址空间的一般128TB。根据以上分析，下图即可知：0x7fff ffff da20完整的地址其实是0x0000 7fff ffff da20,为64位。
#  * 
# gcc ./day3/d3t5.c -o a.out -Wall
# 指针习题 13-16
# gcc ./day3/d3t6.c -o a.out -Wall
# 指针习题 17-18
# gcc ./day3/d3t7.c -o a.out -Wall
# 实验手册 题1
# gcc ./day3/d3t8.c -o a.out -Wall
# 实验手册 题2
# gcc ./day3/d3t9.c -o a.out -Wall
# # 实验手册 题3  实验3
#  * 声明一个二维 int 型数组 a，再声明另一个一维数组指针数组，
#  * 使该数组的每一个指针分别指向二维数组中 的每一个元素(即每一个一维数组)，然后利用数组 b 计算数组 a 的和。
# gcc ./day3/d3t10.c -o a.out -Wall
# 实验6  题4 一个有 N 个元素的整型数组，求该数组的各个子数组中，子数组之和的最大值是多少？ 例如数组 a[6] = {-2, 5, 3, -6, 4, -8, 6};则子数组之和的最大值是 8 (即 a[1] + a[2])。
# gcc ./day3/d3t11.c -o a.out -Wall
# 实验手册 题6编写一个程序，去掉给定字符串中重复的字符。例如给定”google”，输出”gole”。（华为笔试题
# gcc ./day3/d3t12.c -o a.out -Wall

# const 指针
# gcc ./day4/d4t1.c -o a.out -Wall 
#  编写一个函数，使其返回 2 个整型参数中的最大值 
# gcc ./day4/d4t2.c -o a.out -Wall
# 实验题3 3、 编写一个函数，使其返回 3 个整型参数中的最大值 
# gcc ./day4/d4t4.c -o a.out -Wall
# 4、 编写一个函数 my_power，用循环的方法实现返回一个 float 类型数的某个整数次幂(保留 6 位小数)。例如： 调用 my_power(3.14, -2)返回 0.101424 
# gcc ./day4/d4t5.c -o a.out -Wall
# 编写一个程序，将两个字符串连接起来，不要用 strcat 或 strncat 函数 
# gcc ./day4/d4t6.c -o a.out -Wall 
# 编写一个函数 Fibonacci()，要求程序输出第 n 项斐波那契数，n 由用户输入。 斐波那契数列：1, 1, 2, 3, 5, 8, 13, 21, 
# gcc ./day4/d4t7.c -o a.out -Wall 
# 编写一个程序，清除用户输入字符串中的空格符并将之输出。（例如用户输入”a b”，输出”ab”）
# gcc ./day4/d4t8.c -o a.out -Wall 

# echo "开启调试编译"
# gcc ../practice1/debug.c -o b_debug.out -Wall -DDEBUG
# echo "无调试编译"
# gcc ../practice1/debug.c -o a.out -Wall

# 数据交换
# gcc ./day5/d5t1.c -o a.out -Wall
# 整数次幂
# gcc ./day5/d5t2.c -o a.out -Wall
# 数组函数
# gcc ./day5/d5t3.c -o a.out -Wall
# 二维数组函数
# gcc ./day5/d5t4.c -o a.out -Wall
# 通过函数修改指针
# gcc ./day5/d5t5.c -o a.out -Wall
# 通过函数修改指针
# gcc ./day5/d5t6.c -o a.out -Wall
# 编写一个函数，它返回函数自身被调用的次数，并在一个循环中测试之
# gcc ./day5/d5t7.c -o a.out -Wall


# gcc ./day6/main.c ./day6/func.c -o a.out -Wall
# 申请内存
# gcc ./day6/d6t1.c -o a.out -Wall
# 函数申请内存
# gcc ./day6/d6t2.c -o a.out -Wall
# 结构体练习
# gcc ./day6/d6t3.c -o a.out -Wall
# 今日作业1
# 1.构造一个结构体模板（图书信息），有下列成员：
# 序号	int
# 书名	char [20]
# 页数	int
# 价格	float
# 同时定义一个变量 stu1
# 可通过scanf循环输入不同的数字，执行不同的操作，如
# 1写入数据到该结构体变量中(可继续使用scanf输入)
# 2显示结构体变量所有信息
# gcc ./day6/d6t4.c -o a.out -Wall
# 实验题1-3 与题定义一个结构体变量(包括年月日)。计算该日在本年中是第几天？注意闰年问题
# gcc ./day6/d6t5.c -o a.out -Wall

#  结构体
# gcc ./day7/d7t1.c -o a.out -Wall
# 实验题4、定义一个结构体变量(包括年月日)。计算该日在本年中是第几天？注意闰年问题
# gcc ./day7/d7t2.c -o a.out -Wall
#  实验题5..声明一个枚举类型，使用 choices 作为标记，将枚举常量 no、yes 和 maybe 分别设置为 0、1 和 2。
# gcc ./day7/d7t3.c -o a.out -Wall
# 6、 声明 4 个函数，并把一个指针数组初始化为指向它们。每个函数接受两个 double 参数并返回 double 值。
# gcc ./day7/d7t4.c -o a.out -Wall
# 7.
# gcc ./day7/d7t5.c -o a.out -Wall
# 编写一个 transform()函数，它接受 4 个参数：包含 double 类型数据的源数组名，double 类型的目标数组名， 
# 表示数组元素个数的 int 变量以及一个函数名(或者等价的指向函数的指针)。
# transform()函数把指定的函数作 用于源数组的每个元素，并将返回值放到目标数组中。 
# 例如：transform(source, target, 100, sin); 这个函数调用 sin(source[0])赋给 target[0]，等等。
# 共有 100 个元素。在一个程序中测试该函数，调用 4 次 transform()，
# 分别使用 math.h 函数库中的两个函数以及自己设计的两个适合的函数作为参数。
# # 8 math.h 的double参数需要加-lm
gcc ./day7/d7t6.c -o a.out -Wall -lm


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