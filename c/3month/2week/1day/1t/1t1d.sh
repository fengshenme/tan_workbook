#!/bin/bash

echo -e 'GZ2067\tguanguoyuan\t192.168.24.82'

echo -e 'GZ2067\nguanguoyuan\n192.168.24.82'

echo $#
echo $1
echo $2
echo $*
echo $? 


for var in ${arr[*]}; do
    var=${var%.c} # 字符串删除扩展名.c
    echo $var
    if [ -e $var.c ] && [ -e $var.out ]; then
        #获取文件做后修改时间戳
        l_c=$(stat -c %Y $var.c)
        l_out=$(stat -c %Y $var.out)
        if [ $l_c -gt $l_out ]; then
            gcc $var.c -o $var.out -lpthread -Wall 
        else
            echo $var.out is last \; No need to compile 
        fi
    elif [ -e $var.c ]; then
        gcc $var.c -o $var.out -Wall -lpthread
    fi
done