CC=gcc

TARGET=bin/server.out
LIB_NAME=./lib/libserver.so

C_FUN=$(wildcard src/*.c)
C_MAIN=$(wildcard main/*.c)

INCLUDE_PATH=-I ./include/   
LIB_PATH=-L ./lib -lserver -lpthread lib/*

OBJ=$(patsubst %.c,%.o,$(C_FUN))

%.o:%.c
	$(CC) $^ -o $@ -c -fPIC $(INCLUDE_PATH)

$(LIB_NAME):$(OBJ)
	$(CC) -fPIC -shared -o $@ $^

install:$(C_MAIN)
	$(CC) $^ -o $(TARGET) $(INCLUDE_PATH) $(LIB_PATH)

.PHONY:clean

clean:
	$(RM) $(TARGET)
	$(RM) ./src/*.o
	$(RM) $(LIB_NAME)
	