#! /bin/bash

# 静态库制作
# gcc *.c -c   -I ../include
# ar rcs ../lib/libpool.a *.o
# 静态库使用
# gcc main/main.c -o main.out -I include -L lib -lpool -Wall -lpthread