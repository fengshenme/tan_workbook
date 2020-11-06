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
	//1. 产生一个子进程
	pid_t x;
	x = fork();
	if(x > 0) //父进程
	{
		//2. 捕捉信号
		signal(SIGUSR1,my_fun);

		//3. 设置一个信号集，然后将信号加入到集合中。
		sigset_t set;
		sigemptyset(&set);
		sigaddset(&set,SIGUSR1);

		//4. 设置阻塞
		sigprocmask(SIG_BLOCK,&set,NULL);  

		int i;
		for(i=10;i>0;i--)   //10s内，只要父亲收到了SIGUSR1，父亲就这个信号放在挂起队列上。
		{
			sleep(1);
			printf("block time : %d\n",i);
		}

		//5. 解除阻塞
		sigprocmask(SIG_UNBLOCK,&set,NULL);
		//请问响应多少次？

		wait(NULL);
		exit(0);
	}

	if(x == 0) //子进程
	{
		sleep(2); //让父亲准备好。
		//6. 发送信号给父亲

		//7. 疯狂轰炸
		kill(getppid(),SIGUSR1);
		kill(getppid(),SIGUSR1);
		kill(getppid(),SIGUSR1);
		kill(getppid(),SIGUSR1);
		kill(getppid(),SIGUSR1);
		kill(getppid(),SIGUSR1);
		kill(getppid(),SIGUSR1);
		kill(getppid(),SIGUSR1);
		kill(getppid(),SIGUSR1);
		kill(getppid(),SIGUSR1);
		kill(getppid(),SIGUSR1);
		printf("I send 11 signal to parent!\n");

		exit(0);
	}




	return 0;
}