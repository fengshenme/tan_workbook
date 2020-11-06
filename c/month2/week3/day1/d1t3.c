#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>


int main(int argc, char const *argv[])
{
    
    pid_t x ;
    x = fork();

    if (x == 0) // 子进程
    {
        printf("child %d\n", getpid());
        printf("parent %d\n", getppid());
    }

    if (x > 0)  // 父进程
    {
        sleep(2);
        printf("child %d\n", 123);
        printf("child %d\n", x);
        printf("parent %d\n", getpid());
        wait(NULL);
    }
    
    

    return 0;
}
