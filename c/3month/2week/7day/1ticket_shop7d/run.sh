
# 制作sqllite数据库动态库
# gcc -fPIC -shared *.c -o libsqllite3.so -Wall

gcc src/client.c -o bin/client.out -Wall
gcc src/server.c src/load_data.c -o bin/server.out -Wall -lpthread

# ./bin/ticket_shop.out