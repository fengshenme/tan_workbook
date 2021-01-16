/**
 * @file 1job.c
 * @author 
 * @brief 

现在有4个线程，他们的任务都是从银行卡(整型变量)中取200块，一开始银行卡有200块 
    -> 1个退出，3个在条件变量中睡眠。
5s后，主线程往(整型变量)增加数据(+400)，然后唤醒所有的线程                
    -> 3个退出，1个在条件变量中睡眠。
3s后，主线程往(整型变量)增加数据(+200)，然后随机唤醒一个                 
     -> 4个退出，0个在睡眠。
销毁条件变量即可。 	（每次线程拿钱时，都把拿之前的金额与拿之后的金额打印出来）

 * @version 0.1
 * @date 2020-11-10
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct var_tmp
{
    int count;
    pthread_cond_t cond;
    pthread_mutex_t mt;
} cond_num;


void *takes(void *arg);

int main(int argc, char const *argv[])
{
    cond_num * cn = malloc(sizeof(cond_num));
    pthread_mutex_t *mt = &cn->mt; // 互斥锁动态初始化
    pthread_cond_t *cond = &cn->cond;
    int *count = &cn->count;

    if (pthread_mutex_init(mt, NULL) != 0)
        perror("mutex init failed");
    
    // 初始化条件变量
    if (pthread_cond_init(cond, NULL) != 0)
        perror("cont init failed\n");
    
    *count = 200;
    pthread_t tid[4];
    int i;
    for (i = 0; i < 4; i++)
    {
        pthread_create(&tid[i], NULL, takes, (void *)cn);
    }
    
    sleep(2);
    pthread_mutex_lock(mt);
    *count += 400;
    pthread_cond_broadcast(cond);
    pthread_mutex_unlock(mt);

    sleep(1);
    pthread_mutex_lock(mt);
    *count += 200;
    if (*count >= 200)
    {
        pthread_cond_signal(cond);
    }

    pthread_mutex_unlock(mt);

    for (i = 0; i < 4; i++)
    {
        pthread_join(tid[i], NULL);
    }
    //销毁
    pthread_mutex_destroy(mt);
    pthread_cond_destroy(cond);
    free(cn);

    return 0;
}

void *takes(void *arg)
{
   cond_num * cn=  (cond_num *)arg;

    pthread_mutex_t *mt = &cn->mt;
    pthread_cond_t *cond = &cn->cond;
    int *count = &cn->count;

    // printf("%d: %d\n", __LINE__, *count);

    pthread_mutex_lock(mt); // 加锁

    while (*count < 200)
    {
        pthread_cond_wait(cond, mt);
    }
    fprintf(stderr, "balance : %d\n", *count);
    *count -= 200;
    fprintf(stderr, "balance : %d\n", *count);

    pthread_mutex_unlock(mt); // 解锁

    pthread_exit(NULL);
}
