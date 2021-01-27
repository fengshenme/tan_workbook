#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    
    pid_t x = -1;
    int i;
    
    for ( i = 0; i < 10; i++)
    {
        usleep(200*1000);
        x = fork();

        if (x == 0)
        {
            printf("child[%d] pid: %d parent: %d \n", i, getpid(), getppid());
            exit(0);
        }
        
    }
    if (x > 0) 
    {
        sleep(2);
        printf("-----------------%d\n", x);
        printf("parent %d\n", getpid());
    }
    
    

    return 0;
}
