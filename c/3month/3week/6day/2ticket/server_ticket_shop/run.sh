
# 制作sqllite数据库动态库
# gcc -fPIC -shared *.c -o libsqllite3.so -Wall

gcc src/*.c main/main.c lib/libsqllite3.so -I include -o bin/server.out -Wall -lpthread -ldl

# ./bin/ticket_shop.out