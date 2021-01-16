#!/bin/bash

if [ -e *.out ]; then
    rm *.out
fi

# 增加多线程复制能力, linux下文件复制, 实现功能有,文件复制, 文件复制到目标目录下, 源目录及源目录下文件复制到目标目录下
1day/*

# 最终版多线程文件复制
2day/1t2d
# tcp/ip的使用
2day/*t2d
# tcp/ip的作业
2day/*job

# udp的使用
3day/1t3d
# 要求写一个TCP服务器，不断等待实现客户端连接，如果客户端连接上，则客户端信息存放到链表(内核链表)中，用户可以随机说话，服务器就需要判断该用户发送的内容。
3day/*job
# 完成版 要求写一个TCP服务器，不断等待实现客户端连接，如果客户端连接上，则客户端信息存放到链表(内核链表)中，用户可以随机说话，服务器就需要判断该用户发送的内容。
3day/5job
# 利用多线程,阻塞io的实现的一个tcp服务器
3day/6job

# 非阻塞io实现的tcp服务器
4day/1t4d
# 要求使用非阻塞IO去做 写一个TCP协议服务器，最多可以接收20个用户的连接，可以随时接受客户端连接，每一个客户端的数据使用双向循环链表来储存， 只要连接上该服务器的客户端有消息发送给服务器，服务器就会打印出来
4day/1job
# 使用多路复用完成以下的效果。
# 在开发板运行： ./xxx bmp_dir/  （这个目录中有一堆你学过图片）
# 1）先显示目录下的第一张图片。
# 2）这时候点击屏幕右边松开 / 输入"next" 都可以显示下一张图片。
#    这时候点击屏幕左边松开 / 输入"prev" 都可以显示上一张图片。
4day/2job
# 利用多线程,阻塞io的实现的一个tcp服务器
4day/3job

# 多路复用,超时控制的, tcp协议,一对一收发消息的
5day/demo3
# udp 信号驱动
5day/*t5d

# 复习udp协议，实现udp的服务端和客户端，开通的端口是6868/udp 不是6868/tcp
6day/1f6d
# 复习udp协议，实现udp的服务端和客户端，服务端使用信号驱动
6day/2f6d
# 复习tcp协议，实现tcp的服务端和客户端
6day/3f6d
# 复习tcp协议，实现tcp的服务端和客户端 ,多路复用,对套接字设置超时属性
6day/4f6d
# 复习tcp协议，实现tcp的服务端和客户端 ,多路复用,使用集合set进行超时控制
6day/5f6d
# 复习tcp协议，实现tcp的服务端和客户端 ,多路复用,使用集合set进行超时控制,增加多线程进行观察
6day/6f6d

# 复习,非阻塞io实现的tcp服务器
7day/1f7d
# 复习,非阻塞io实现的tcp服务器 和 同时连接多个客户端, 会使cpu资源使用率到百分之九十以上
7day/2f7d
# 复习 ,socket连接套接字设置为非阻塞
7day/3f7d


# 根据生成的执行文件与源文件的时间戳比较来编译,源文件最后修改时间比执行文件最后修改时间大则进行编译
# arr=$(ls *.c)

# for var in ${arr[*]}; do
#     var=${var%.c} # 字符串删除扩展名.c
#     echo $var
#     if [ -e $var.c ] && [ -e $var.out ]; then
#         #获取文件做后修改时间戳
#         l_c=$(stat -c %Y $var.c)
#         l_out=$(stat -c %Y $var.out)
#         if [ $l_c -gt $l_out ]; then
#             gcc $var.c -o $var.out -lpthread -Wall 
#         else
#             echo $var.out is last \; No need to compile 
#         fi
#     elif [ -e $var.c ]; then
#         gcc $var.c -o $var.out -Wall -lpthread
#     fi
# done

if [ $1 == "x86" ]; then
    # x86_64平台的gcc编译
    gcc $c_name.c -o $c_name.out -Wall
elif [ $1 == "arm" ]; then
    arm-linux-gcc $c_name.c -o $c_name.out -Wall
fi

# 用arm-linux-gcc交叉编译生成的是arm平台的linux系统执行文件
if [ -e $c_name.out ] && [ -x $c_name.out ]; then

    if [ $2 ]; then
        ./$c_name.out $2
    else
        ./$c_name.out
    fi

else
    echo "编译没有成功,执行文件没有生成"
fi
