/**
 * @file 1signal.c
 * @author 
 * @brief  1、编写一段程序，使用系统调用函数fork( )创建两个子进程，再用系统调用函数signal( )让父进程捕捉信号SIGINT（用kill命令来触发），当捕捉到中断信号后，
        父进程用系统调用函数kill( )向两个子进程发出信号，子进程捕捉到父进程发来的信号后，分别输出下列信息后终止：  
		Child process 1 is killed by parent!
		Child process 2 is killed by parent!
               或者
                Child process 2 is killed by parent!
               Child process 1 is killed by parent!
        父进程等待两个子进程终止后，输出以下信息后终止：
        Parent process exit!
 * @version 0.1
 * @date 2020-11-04
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

void func(int sig);
void func2(int sig);

static int pid[2]; //全局变量

int main(int argc, char const *argv[])
{

    pid_t x;
    bzero(pid, sizeof(pid));
    int i;
    for (i = 1; i < 3; i++)
    {
        x = fork();

        if (x > 0) //父进程
        {
            pid[i] = x;
            continue;
        }

        if (x == 0) // 子进程
        {
            break;
        }
    }

    if (x > 0)
    {
        signal(SIGINT, func);
        printf("%d\n", getpid());
        pause();

        wait(NULL); // 回收子进程资源
        printf("Parent process exit!\n");
    }

    if (x == 0)
    {

        signal(SIGUSR1, func2);
        pause();
        printf("Child process %d is killed by parent!\n", i);

        exit(0);
    }

    return 0;
}

void func(int sig)
{
    kill(pid[1], SIGUSR1);
    kill(pid[2], SIGUSR1);
    printf("%d\n", sig);
}

void func2(int sig)
{
    printf("2:%d\n", sig);
}

/**
 * 
 * binutils-doc gcc-9-locales  make autoconf automake 
  libtool flex bison gcc-doc 
  gcc-9-multilib
  gcc-9-doc glibc-doc
  gcc-multilib


    binutils-doc gcc-9-locales gcc-9-doc make autoconf automake libtool flex bison gcc-doc
    gdb-arm-linux-gnueabi
   cpp-doc gcc-9-multilib-arm-linux-gnueabi

 * 
 */