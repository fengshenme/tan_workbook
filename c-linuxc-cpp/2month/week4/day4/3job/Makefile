vpath %.c = src:src2  #指定.c文件搜寻除当前路径之外的备用路径

OBJ = add_task.c add_thread.c pool.c remove_thread.c routine.c main.c

3job: $(OBJ) 
	gcc $^ -o bin/$@ -Wall  -I include -lpthread

clean:
	rm bin/3job

.PHONY: clean