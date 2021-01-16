#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <fcntl.h>    /* For O_* constants */
#include <sys/stat.h> /* For mode constants */
#include <semaphore.h>

#define MEM_SIZE 2048

void *send1(void *arg);

int main(int argc, char const *argv[])
{

    pthread_t pid1 ,pid2 , pid3, pid4;

    char str[11] = "helloworld";
     pthread_create(&pid1, NULL, send1, (void *)str);
     pthread_create(&pid2, NULL, send1, (void *)str);
     pthread_create(&pid3, NULL, send1, (void *)str);
     pthread_create(&pid4, NULL, send1, (void *)str);


    pthread_join(pid1, NULL);
    pthread_join(pid2, NULL);
    pthread_join(pid2, NULL);
    pthread_join(pid3, NULL);

    printf("\n");
    return 0;
}

void *send1(void *arg)
{

    
    int i;
    for ( i = 0; i < 11; i++)
    {
        usleep(200*1000);
        printf("%c", ((char *)arg)[i]);
    }
    
}
