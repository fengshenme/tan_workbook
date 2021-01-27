#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <fcntl.h>    
#include <semaphore.h>

#define MEM_SIZE 2048

void *send1(void *arg);

int main(int argc, char const *argv[])
{

    pthread_t pid[4];

    sem_t st;
    sem_init(&st, 0, 1);

    int i;
    for (i = 0; i < 4; i++)
    {
        
        pthread_create(&pid[i], NULL, send1, (void *)&st);
        pthread_join(pid[i], NULL);
        
    }
    printf("\n");
    sem_destroy(&st);
    return 0;
}

void *send1(void *arg)
{

    char str[11] = "helloworld";
    sem_wait((sem_t *)arg); // 减一
    int i;
    for (i = 0; i < 11; i++)
    {
        usleep(200 * 1000);
        fprintf(stderr, "%c", str[i]);
    }
    sem_post((sem_t *)arg);//加一
    pthread_exit(NULL);
}
