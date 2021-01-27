#!/bin/bash
# 写一个回射服务器，这个服务器功能就是客户端发送什么数据给服务器，服务器就会将数据回发到客户端。

if [ -e ./*.out ] 
then
    rm ./*.out
fi

gcc server.c -o server.out -Wall 
gcc client.c -o client.out -Wall -lpthread
