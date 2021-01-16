

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
//目标：尝试在正在运行的过程中，去创建一个新的线程
//效果：看看会不会同时做两件事情。

//线程的例程函数
void *fun(void *arg)
{
	//3. 子线程也会继续运行。
	int i;
	for(i=0;i<10;i++)
	{
		printf("child thread print apple!\n");
		sleep(1);
	}
}

int main()
{
	/* 单进程 */
	printf("helloworld!\n");

	//1. 创建一个新的子线程
	pthread_t tid;
	int ret;
	ret = pthread_create(&tid,NULL,fun,NULL);
	if(ret == 0)
	{
		printf("pthread_create success!\n");
	}
	else{
		printf("pthread_create error!\n");
	}

	//2. 接下来，这个进程称之为主线程，会继续运行。
	int i;
	for(i=0;i<5;i++)
	{
		printf("main thread print hello!\n");
		sleep(1);
	}

	return 0;
}
