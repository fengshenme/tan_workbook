/**
 * @file 5signal.c验证在响应信号时，信号会互相嵌套
 * @author 
 * @brief 验证在响应信号时，信号会互相嵌套
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

void my_func(int sig);

int main(int argc, char const *argv[])
{

    pid_t x = fork();
    sigset_t set;

    if (x > 0)
    {

        int i;
        for (i = 10; i > 0; i--)
        {
            
            
            signal(SIGUSR2, my_func);
            
            signal(SIGSTOP, my_func);
            
            printf("block time: %d\n", i);
            sleep(1);
            signal(SIGCONT, my_func);
            signal(SIGUSR1, my_func);
            
            
        }
        

        wait(NULL);

        exit(0);
    }

    //子进程：

    if (x == 0)
    {
        sleep(1);
        kill(getppid(), SIGUSR2);
        kill(getppid(), SIGUSR2);
        kill(getppid(), SIGSTOP);
        kill(getppid(), SIGUSR2);
        kill(getppid(), SIGUSR1);
        kill(getppid(), SIGUSR1);
        kill(getppid(), SIGUSR1);
        kill(getppid(), SIGUSR2);
        kill(getppid(), SIGUSR2);
        sleep(5);
        kill(getppid(), SIGCONT);

        exit(0);
    }

    return 0;
}

void my_func(int sig)
{
    printf("73: %d \n", sig);
}
