#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <strings.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdlib.h>

void my_fun(int sig)
{
	printf("catch sig = %d\n",sig);
}

int main()
{
	//0. 捕捉信号
	signal(SIGUSR1,my_fun); //继承给小孩，小孩也捕捉了。

	//1. 设置一个信号集，并将信号加入到集合中
	sigset_t set;
	sigemptyset(&set);
	sigaddset(&set,SIGUSR1);

	//2. 设置信号集为阻塞状态
	//现在这个进程对SIGUSR1是阻塞的，如果收到SIGUSR1，就会把这个信号存放在挂起队列中。
	sigprocmask(SIG_BLOCK,&set,NULL);

	int i;
	//待会我们需要在20s内，发生一个SIGUSR1给父进程。
	printf("parent pid = %d\n",getpid());
	for(i=10;i>0;i--)
	{
		sleep(1);
		printf("parent will recv SIGUSR1 signal!\n");
	}

	//由于父进程是SIGUSR1是阻塞的，所以现在父进程的挂起队列上有一个SIGUSR1的信号。

	//3. 父亲带着这个挂起队列去产生一个小孩
	pid_t x;
	x = fork();
	if(x > 0)
	{
		//挂起队列:SIGUSR1
		wait(NULL);
		exit(0);
	}

	if(x == 0)
	{
		//挂起队列:
		for(i=5;i>0;i--)
		{
			sleep(1);
			printf("after %d s ,I will set unblock!\n",i);
		}

		sigprocmask(SIG_UNBLOCK,&set,NULL);
	}

	return 0;
}