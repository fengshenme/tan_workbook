#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *send1(void *arg);
void cancel_fun(void *arg);

int main(int argc, char const *argv[])
{

    pthread_t pid[4];

    pthread_mutex_t st;
    pthread_mutex_init(&st, NULL);

    int i;
    for (i = 0; i < 4; i++)
    {
        
        pthread_create(&pid[i], NULL, send1, (void *)&st);
    }

    for (i = 0; i < 4; i++)
    {
        
        if (i == 1)
            pthread_cancel(pid[2]);
        pthread_join(pid[i], NULL);
    }

    printf("\n");
    pthread_mutex_destroy(&st);

    return 0;
}

void cancel_fun(void *arg)
{
    printf("pthread canceled \n");
    pthread_mutex_unlock((pthread_mutex_t *)arg); // 解锁
}

void *send1(void *arg)
{
    //线程取消例程函数 需要与删除函数一起使用
    pthread_cleanup_push(cancel_fun, arg);

    char str[11] = "helloworld";
    pthread_mutex_lock((pthread_mutex_t *)arg); // 上锁
    int i;
    for (i = 0; i < 11; i++)
    {
        usleep(200 * 1000);
        fprintf(stderr, "%c", str[i]);
    }
    pthread_mutex_unlock((pthread_mutex_t *)arg); // 解锁
    // 删除函数。
    pthread_cleanup_pop(0);

    pthread_exit(NULL);
}
