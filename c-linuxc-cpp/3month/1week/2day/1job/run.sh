
rm ./*.out

# 实现TCP客户端与TCP服务器互相可以收发。
gcc server.c -o server.out -Wall -lpthread
gcc client.c -o client.out -Wall -lpthread

