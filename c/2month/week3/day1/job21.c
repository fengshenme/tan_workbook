#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

//实现一个父进程要比子进程先打印PID的版本。（即打印的PID一般是递增的）

int main(int argc, char const *argv[])
{

    pid_t x = -1;
    int i;

    x = fork();
    if (x == 0) //子进程
    {
        for (i = 0; i < 10; i++)
        {
            x = fork();
            usleep(500 * 1000);
            if (x > 0) //父进程
            {
                printf("child: %d parent: %d \n", getpid(), getppid());
                exit(0);
                break;
            }
            
        }
    }
    else
    {
        printf("parent: %d \n", getpid()); 
    }

    return 0;
}
