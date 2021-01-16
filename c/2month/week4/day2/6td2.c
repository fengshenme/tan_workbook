#define _XOPEN_SOURCE 800

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void cancel_fun(void *arg);

void *read1(void *arg);
void *read2(void *arg);
void *write1(void *arg);
void *write2(void *arg);
int a;
int main(int argc, char const *argv[])
{

    pthread_t pid[5];

    pthread_rwlock_t st;
    pthread_rwlock_init(&st, NULL);

    pthread_create(pid[0], NULL, read1, (void *)&st);
    pthread_create(pid[1], NULL, read2, (void *)&st);
    pthread_create(pid[2], NULL, write1, (void *)&st);
    pthread_create(pid[3], NULL, write2, (void *)&st);

    int i;
    for (i = 0; i < 4; i++)
    {
        pthread_join(pid[i], NULL);
    }

    printf("\n");
    pthread_rwlock_destroy(&st);

    return 0;
}

void cancel_fun(void *arg)
{
    printf("pthread canceled \n");
    pthread_rwlock_unlock((pthread_rwlock_t *)arg); // 解锁
}

void *read1(void *arg)
{
    //线程取消例程函数 需要与删除函数一起使用
    pthread_cleanup_push(cancel_fun, arg);

    pthread_rwlock_rdlock((pthread_rwlock_t *)arg); // 上锁
    sleep(3);
    fprintf(stderr, "%d\n", a);
    pthread_rwlock_unlock((pthread_rwlock_t *)arg); // 解锁
    // 删除函数。
    pthread_cleanup_pop(0);

    pthread_exit(NULL);
}

void *read2(void *arg)
{
    //线程取消例程函数 需要与删除函数一起使用
    pthread_cleanup_push(cancel_fun, arg);

    pthread_rwlock_rdlock((pthread_rwlock_t *)arg); // 上锁
    sleep(5);
    fprintf(stderr, "%d\n", a);
    pthread_rwlock_unlock((pthread_rwlock_t *)arg); // 解锁
    // 删除函数。
    pthread_cleanup_pop(0);

    pthread_exit(NULL);
}

void *write1(void *arg)
{
    //线程取消例程函数 需要与删除函数一起使用
    pthread_cleanup_push(cancel_fun, arg);

    pthread_rwlock_wrlock((pthread_rwlock_t *)arg); // 上锁
    sleep(4);
    fprintf(stderr, "%d", a);
    pthread_rwlock_unlock((pthread_rwlock_t *)arg); // 解锁
    // 删除函数。
    pthread_cleanup_pop(0);

    pthread_exit(NULL);
}
void *write2(void *arg)
{
    //线程取消例程函数 需要与删除函数一起使用
    pthread_cleanup_push(cancel_fun, arg);

    pthread_rwlock_wrlock((pthread_rwlock_t *)arg); // 上锁
    sleep(6);
    fprintf(stderr, "%d", a);
    pthread_rwlock_unlock((pthread_rwlock_t *)arg); // 解锁
    // 删除函数。
    pthread_cleanup_pop(0);

    pthread_exit(NULL);
}
