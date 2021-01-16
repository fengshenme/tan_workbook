CC=gcc
AR=ar

TARGET=bin/1t1d.out
 
C_SOURCE=$(wildcard src/*.c)
C_MAIN=$(wildcard main/*.c)

INCLUDE_PATH=-I include
LIB_PATH=-L lib -lpthread -lpool
LIB_SO=lib/libpool.so
LIB_A=lib/libpool.a

DEBUG=-Wall
TARGET_SO=-fPIC -shared
TARGET_A=-fPIC

O_SOURCE=$(patsubst %.c,%.o,$(C_SOURCE))

cop:
	cd src
	pwd
	$(CC) $(C_SOURCE) -o $(O_SOURCE) -c  

# 编译main函数
install:
	# 生成静态库
	ar rcs $(LIB_A) $(O_SOURCE) $(TARGET_A) $(INCLUDE_PATH)
	
	# 生成动态库
	$(CC) $(TARGET_SO) $(O_SOURCE) -o $(LIB_SO) $(INCLUDE_PATH)

	$(CC) $(C_MAIN) -o $(TARGET) $(INCLUDE_PATH) $(LIB_PATH)  $(DEBUG)

clean:
	$(RM) $(TARGET)  $(LIB_A) $(LIB_SO) src/*.o


.PHONY: clean