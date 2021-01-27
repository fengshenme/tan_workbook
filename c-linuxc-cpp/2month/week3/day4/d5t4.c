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
//验证在响应信号时，信号会互相嵌套。
//如果给进程发送SIGUSR1信号，那么就1s输出helloworld这个字符串的一个字符。 -> 10s
//如果给进程发送SIGUSR2信号，那么就1s输出appletree这个字符串的一个字符。  -> 9s

void my_fun(int sig)
{
	int i;
	char str1[] = "helloworld";
	char str2[] = "appletree";

	//1. 判断是不是捕捉到SIGUSR1。
	if(sig == SIGUSR1)
	{
		//1s输出helloworld这个字符串的一个字符。 -> 10s
		for(i=0;str1[i]!='\0';i++)
		{
			printf("%c\n",str1[i]);
			sleep(1);
		}

	}

	if(sig == SIGUSR2)
	{
		//1s输出appletree这个字符串的一个字符。  -> 9s
		for(i=0;str2[i]!='\0';i++)
		{
			printf("%c\n",str2[i]);
			sleep(1);
		}
	}
}

int main()
{
	//1. 先打印进程的PID号。
	printf("my pid = %d\n",getpid());

	//2. 提前捕捉信号。
	signal(SIGUSR1,my_fun);
	signal(SIGUSR2,my_fun);

	//3. 不能让进程跑了。
	pause();
}