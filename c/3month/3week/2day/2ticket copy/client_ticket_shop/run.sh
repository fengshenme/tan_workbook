#!/bin/bash
# 制作sqllite数据库动态库
# gcc -fPIC -shared *.c -o libsqllite3.so -Wall

gcc main/main.c src/client.c -o bin/client.out -Wall

# ./bin/ticket_shop.out