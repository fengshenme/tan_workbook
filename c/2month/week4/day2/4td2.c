#include <stdio.h>
#include <unistd.h>
#include <pthread.h>


void *send1(void *arg);

int main(int argc, char const *argv[])
{

    pthread_t pid[4];

    pthread_mutex_t st;
    pthread_mutex_init(&st, NULL);

    int i;
    for (i = 0; i < 4; i++)
        pthread_create(&pid[i], NULL, send1, (void *)&st);
    for (i = 0; i < 4; i++)
        pthread_join(pid[i], NULL);

    pthread_mutex_destroy(&st);
    printf("\n");

    return 0;
}

void *send1(void *arg)
{

    char str[11] = "helloworld";
    pthread_mutex_lock((pthread_mutex_t *)arg); // 上锁
    int i;
    for (i = 0; i < 11; i++)
    {
        usleep(100 * 1000);
        fprintf(stderr, "%c", str[i]);
    }
    pthread_mutex_unlock((pthread_mutex_t *)arg); // 解锁
    pthread_exit(NULL);

}
