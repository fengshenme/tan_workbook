#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

// 实现一个子进程要比父进程先打印PID的版本。（即打印的PID一般是递减的）
int main(int argc, char const *argv[])
{

    pid_t x = -1;
    int i;


    for (i = 5; i > 0; i--)
    {
        x = fork();
        if (x > 0) //父进程
        {
            sleep(i);
            printf("1 parent: %d \n", getpid());
            exit(0);
            // break;
        }
        if (x == 0) // 子进程
        {
            // sleep(1);
            // printf("1 parent: %d \n", getpid());
            // printf("2 child: %d \n", getpid());
        }

    }
    printf("32  parent: %d \n", getpid());

    return 0;
}
