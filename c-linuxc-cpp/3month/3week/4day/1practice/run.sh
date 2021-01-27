#!/bin/bash


if [ $# -ne 2 ]; then
    echo "param two error"
fi






# 售票系统项目
1day 2day

# c++基本语法
3day
# c++类的基本使用,函数重载等
day4












# rm acd -r


# mkdir acd

HEAD_PATH="-I include"

# 制作静态库

rm lib/*.so bin/*.out

arr='ls src/*.c'

for var in ${arr[*]}; do
    var=${var%.c} # 字符串删除扩展名.c
    echo $var
    if [ -e $var.c ] && [ -e $var.o ]; then
        # 如果var.c的文件比var.o文件修改时间更新则执行
        if [ $var.c -nt $var.o ]; then 
            gcc $var.c -o $var.o -c  -Wall -fPIC
        else
            echo $var.o is last  No need to compile 
        fi
    elif [ -e $var.c ]; then
        gcc $var.c -o $var.o -c -Wall -fPIC
    fi
done

# 制作动态库
gcc -fPIC -shared src/*.o -o lib/libcopy.so $HEAD_PATH -lpthread

# 执行程序
gcc main/*.c -o bin/2t1d.out lib/libcopy.so $HEAD_PATH -lpthread

./bin/2t1d.out $1 $2
