
# 制作sqllite数据库动态库
# gcc -fPIC -shared *.c -o libsqllite3.so -Wall

gcc src/*.c main/main.c  -o bin/server.out -Wall -lpthread

# ./bin/ticket_shop.out