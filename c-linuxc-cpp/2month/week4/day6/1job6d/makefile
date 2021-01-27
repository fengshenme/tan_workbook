TARGET=bin/3job.out
 
C_SOURCE=$(wildcard src/*.c)
C_MAIN=$(wildcard main/*.c)


INCLUDE_PATH=-I include
LIB_PATH=-L lib -lpthread -lpool
LIB_NAME=lib/libpool.so

DEBUG=-Wall
TARGET_SO=-fPIC -shared

# 制作动态库
$(LIB_NAME):
	$(CC) $(TARGET_SO) $(C_SOURCE) -o $(LIB_NAME) $(INCLUDE_PATH)

# 编译main函数
install:
	$(CC) $(C_MAIN) -o $(TARGET) $(INCLUDE_PATH) $(LIB_PATH)  $(DEBUG)

clean:
	$(RM) $(TARGET) $(LIB_NAME)

.PHONY: clean