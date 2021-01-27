

TARGET=bin/3job
 
C_SOURCE=$(wildcard src/*.c)
C_MAIN=$(wildcard main/*.c)
LIB_PATH=-lpthread
INCLUDE_PATH=-I include
DEBUG=-Wall

$(TARGET): $(C_SOURCE) 
	$(CC) $(C_SOURCE) $(C_MAIN) -o $(TARGET)  $(INCLUDE_PATH) $(LIB_PATH) $(DEBUG)

clean:
	$(RM) $(TARGET)

.PHONY: clean