#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <semaphore.h>
#include <stdio.h>
#include <pthread.h>

static sem_t st;
static pthread_mutex_t mt;
//jack: 负责将数据发送到共享内存上。
void *jack(void *p)
{

    while (1)
    {
        // 从键盘中获取数据，然后将数据存放在共享内存中
        pthread_mutex_lock(&mt);
        fgets((char *)p, 2048, stdin);
        pthread_mutex_unlock(&mt);
        sem_post(&st); //加一
        if (strncmp((char *)p, "quit\n", 5) == 0)
        {
            break;
        }
    }

    pthread_exit(NULL);
}

void *rose(void *arg)
{
    while (1)
    {
        sem_wait(&st); // 减一
        printf( "jack from : %s", (char *)arg);
        if (strncmp((char *)arg, "quit\n", 5) == 0)
        {
            break;
        }
    }

    pthread_exit(NULL);
}

int main()
{

    //1. 申请key值。
    key_t key = ftok(".", 10);

    //2. 根据key值去申请id号。
    int shmid = shmget(key, 2048, IPC_CREAT | 0666);

    //3. 根据id号去映射一片内存空间。
    char *p = shmat(shmid, NULL, 0);
    bzero(p, 2048);

    pthread_t pid[2];
     // 互斥锁动态初始化
    if (pthread_mutex_init(&mt, NULL) != 0)
        perror("mutex init failed");

    sem_init(&st, 0, 0);

    pthread_create(&pid[0], NULL, jack, (void *)p);
    pthread_create(&pid[1], NULL, rose, (void *)p);

    pthread_join(pid[0], NULL);
    pthread_join(pid[1], NULL);

    pthread_mutex_destroy(&mt);
    //删除信号量
    sem_destroy(&st);

    //5. 撤销映射
    shmdt(p);


    return 0;
}
