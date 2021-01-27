#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *fun(void *arg)
{
    int i;
    for (i = 0; i < 5; i++)
    {
        printf("child i = %d\n", i);
        sleep(1);
    }
}

int main()
{
    pthread_t tid;
    pthread_create(&tid, NULL, fun, NULL);

    sleep(2);
    pthread_cancel(tid);
    printf("I send cancel to child!\n");

    int ret;
    ret = pthread_join(tid, NULL);
    printf("ret = %d\n", ret);
    return 0;
}