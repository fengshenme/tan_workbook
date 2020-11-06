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
//验证阻塞属性会被子进程继承

void my_fun(int sig)
{
	printf("catch sig = %d\n",sig);
}

int main()
{
	//1. 先让原来的那个进程设置阻塞属性
	sigset_t set;
	sigemptyset(&set);
	sigaddset(&set,SIGUSR1);
	sigprocmask(SIG_BLOCK,&set,NULL);

	//2. 父亲带着对SIGUSR1阻塞的状态去产生一个子进程
	pid_t x;
	x = fork();
	if(x > 0)
	{
		//6. 先休息一会，让小孩准备好
		sleep(3);
		kill(x,SIGUSR1);
		printf("I send signal to child!\n");

		wait(NULL);
		exit(0);
	}

	if(x == 0)
	{
		//3. 小孩说： 将来我收到SIGUSR1这个信号，我就调用my_fun这个函数
		signal(SIGUSR1,my_fun);

		//4. 小孩等待SIGUSR1信号到达。
		//待会需要观察的情况：
		//1)如果3s时，能马上响应SIGUSR1信号  -> 说明没有继承。
		//2)如果3s时收到信号，但是没有响应，要等到10s后解除阻塞之后，才会响应。 -> 继承了

		int i;
		for(i=10;i>0;i--)
		{
			sleep(1);
			printf("child waiting signal time : %d\n",i);
		} 

		//5. 10s，让小孩解除阻塞
		sigprocmask(SIG_UNBLOCK,&set,NULL);

		exit(0);
	}

	return 0;
}

