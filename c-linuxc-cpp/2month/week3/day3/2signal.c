/**
 * @file 2signal.c
 * @author 
 * @brief 验证在挂起队列中，没有相同的信号(即相同的信号会被丢弃))
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

int main(int argc, char const *argv[])
{

    pid_t x;

    int j;
    for (j = 0; j < 3; j++)
    {
        x = fork();

        if (x > 0) //父进程
        {
            continue;
        }

        if (x == 0) // 子进程
        {
            break;
        }
    }

    if (x > 0)
    {
        sigset_t set;
        sigemptyset(&set);
        sigaddset(&set, SIGUSR1);
        sigprocmask(SIG_BLOCK, &set, NULL); // 设置阻塞的状态
        int i;
        for (i = 10; i > 0; i--)
        {

            sleep(1);

            printf("block time: %d\n", i);
        }

        sigprocmask(SIG_UNBLOCK, &set, NULL); //设置解除阻塞的状态

        wait(NULL);

        exit(0);
    }

    //子进程：

    if (x == 0)
    {
        sleep(2); //确保父进程先捕捉
        if (kill(getppid(), SIGUSR1) == 0)
        {
            printf("I send SIGUSR1 to parent!\n"); // -> 3个不同进程发送两个相同信号,一共6个信号只响应一个。
        }
        if (kill(getppid(), SIGUSR1) == 0)
        {
            printf("I send SIGUSR1 to parent!\n"); 
        }

        exit(0);
    }

    return 0;
}
