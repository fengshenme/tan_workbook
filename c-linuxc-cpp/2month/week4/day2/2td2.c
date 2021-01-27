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

    char str[11] = "helloworld";
    sem_t st;
    sem_init(&st, 0, 1);

    int i;
    for (i = 0; i < 4; i++)
    {
        sem_wait(&st); // 减一
        pthread_create(&pid[i], NULL, send1, (void *)str);
        pthread_join(pid[i], NULL);
        sem_post(&st);//加一
    }

    printf("\n");
    sem_destroy(&st);
    return 0;
}

void *send1(void *arg)
{

    int i;
    for (i = 0; i < 11; i++)
    {
        usleep(200 * 1000);
        fprintf(stderr, "%c", ((char *)arg)[i]);
    }
    pthread_exit(NULL);
}
