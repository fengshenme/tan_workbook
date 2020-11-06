#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{


    pid_t x;
    x = fork();

    if (x > 0)
    {
        printf("child %d \n", x);
        printf("prent %d \n", getpid());
    }
    
    if(x == 0)
    {
        sleep(3);
        printf("child %d \n", getpid());
        printf("prent %d \n", getppid());
        exit(1);
    }

    return 0;
}
