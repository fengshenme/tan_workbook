# rm acd -r

# mkdir acd

# gcc src/*.c -o bin/1job7d.out -I include -lpthread -Wall

# ./bin/1job7d.out ../../day6 acd

# CC=gcc
# AR=ar

# TARGET=bin/1t1d.out

# C_SOURCE=src/*.c
# C_MAIN=main/*.c

HEAD_PATH="-I include"
# LIB_PATH=-L lib -lpthread -lpool
# LIB_SO=lib/libpool.so
# LIB_A=lib/libpool.a

# DEBUG=-Wall
# TARGET_SO=-fPIC -shared
# TARGET_A=-fPIC

# 生成.o文件
cd src
gcc *.c -c  -fPIC # $INCLUDE_PATH
cd ..

# 制作静态库
ar rcs lib/copy.a src/*.o 



