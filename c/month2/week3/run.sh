#!/bin/bash

if [ -e *.out ]; then
    rm *.out
fi

# 用进程相关API函数编程一个程序，使之产生一个进程扇：父进程产生一系列子进程，每个子进程打印自己的PID然后退出。要求父进程最后打印PID
# day1/job1
# 实现一个父进程要比子进程先打印PID的版本。（即打印的PID一般是递增的）
# day1/job21
# 实现一个子进程要比父进程先打印PID的版本。（即打印的PID一般是递减的）
# day1/job22

# 1、用命名管道分别写一个服务器程序和一个客户机程序，客户机的父进程负责每隔一秒产生一个子进程（形成一个进程扇），
# 而每个子进程则往FIFO写入自己的PID号码。服务器负责从该FIFO中读取数据并将之打印到屏幕上。 将数据打印到屏幕
# 要求一： 不使用access函数来解决重复创建管道的问题。  -> open()
# day2/job2/2r
# day2/job2/2w
# 要求二： 使用access函数来解决重复创建管道的问题。
# access()函数通过man手册可以查询
# day2/job2/1r
# day2/job2/1w
# 2、尝试使用无名管道让小孩给父亲发送数据
# day2/job2/3t.c
# 3、当子进程给父进程发送show_bmp字符串时，父进程就显示一张图片在lcd设备上
# day2/job2/4t.c

# 定义一个信号集，然后清空，再将SIGUSR1加入到集合中，判断这个信号在不在集合中。
# day3/d3t1.c
# 1、编写一段程序，使用系统调用函数fork( )创建两个子进程，再用系统调用函数signal( )让父进程捕捉信号SIGINT（用kill命令来触发），当捕捉到中断信号后，
# 父进程用系统调用函数kill( )向两个子进程发出信号，子进程捕捉到父进程发来的信号后，分别输出下列信息后终止：
# 		Child process 1 is killed by parent!
# 		Child process 2 is killed by parent!
#                或者
#    Child process 2 is killed by parent!
#                Child process 1 is killed by parent!
# 父进程等待两个子进程终止后，输出以下信息后终止：
#         Parent process exit!
# day3/1signal.c

# 消息队列的读写, server负责读 client负责写
# day4/server.c day4/client.c



if [ $1 == "x86" ]; then
    # x86_64平台的gcc编译
    gcc $c_name.c -o $c_name.out -Wall
elif [ $1 == "arm" ]; then
    arm-linux-gcc $c_name.c -o $c_name.out -Wall
fi

# // 用arm-linux-gcc交叉编译生成的是arm平台的linux系统执行文件
if [ -e $c_name.out ] && [ -x $c_name.out ]; then

    if [ $2 ]; then
        ./$c_name.out $2
    else
        ./$c_name.out
    fi

else
    echo "编译没有成功,执行文件没有生成"
fi
