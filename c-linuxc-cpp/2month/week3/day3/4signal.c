/**
 * @file 4signal.c
 * @author 验证挂起队列上的信号不会被子进程继承
 * @brief 
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

    pid_t y = fork();
    if (y == 0)
    {
        sleep(2);
        kill(getppid(), SIGUSR1);
        kill(getppid(), SIGUSR1);
        kill(getppid(), SIGUSR1);
        kill(getppid(), SIGUSR1);
        kill(getppid(), SIGUSR1);
        kill(getppid(), SIGUSR1);
        kill(getppid(), SIGUSR1);
        exit(0);
    }

    if (y > 0)
    {

        pid_t x = fork();
        sigset_t set;

        if (x > 0)
        {

            sigemptyset(&set);
            sigaddset(&set, SIGUSR1);
            sigprocmask(SIG_BLOCK, &set, NULL); // 设置阻塞的状态
            int i;
            for (i = 10; i > 0; i--)
            {

                sleep(1);

                printf("block time: %d\n", i);
            }
            signal(SIGUSR1, my_func);
            sigprocmask(SIG_UNBLOCK, &set, NULL); //设置解除阻塞的状态

            wait(NULL);

            exit(0);
        }

        //子进程：

        if (x == 0)
        {
            sleep(2);
            signal(SIGUSR1, my_func); // 验证挂起队列上的信号不会被子进程继承
            printf("child time: %d\n", 11);
            sigprocmask(SIG_UNBLOCK, &set, NULL); //设置解除阻塞的状态

            exit(0);
        }
    }

    return 0;
}

void my_func(int sig)
{
    printf("73: %d \n", sig);
}
