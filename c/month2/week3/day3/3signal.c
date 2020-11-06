/**
 * @file 3signal.c
 * @author 
 * @brief 验证阻塞属性会被子进程继承
 * @version 0.1
 * @date 2020-11-04
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/wait.h>

void my_func(int sig);

int main(int argc, char const *argv[])
{

    sigset_t set;

    sigemptyset(&set); // 清空集合
    sigaddset(&set,SIGUSR1); //添加信号
    sigprocmask(SIG_BLOCK, &set, NULL); //给这个信号集设置阻塞

    pid_t x = fork();

    if (x > 0) // 父进程
    {
        
        printf("parent sleep....\n");
		sleep(3);

		//5. 父进程发送一个信号给子进程
		kill(x,SIGUSR1);
		printf("I send signal to child!\n");
        
		//6. 回收资源
		wait(NULL);
		//7. 父进程退出
		exit(0);
        
    }

    if (x == 0) // 子进程
    {
        int i;
        for (i = 6; i > 0; i--)
        {
            sleep(1);
            printf("%d \n", i);
        }
        sigprocmask(SIG_UNBLOCK, &set, NULL);
        // 捕捉信号
        signal(SIGUSR1, my_func);
        pause();
        
        exit(0);
    }

    return 0;
}

void my_func(int sig)
{
    printf("73: %d \n", sig);
}
