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

void *send(void *arg);

int main(int argc, char const *argv[])
{
    pthread_t pid;

    int ret = pthread_create(&pid, NULL, send, NULL);
    if (ret == 0)
    {
        printf("pthread create success!\n");
    }
    key_t key = ftok(".", 10);

    //2. 根据key值去申请id号。
    int shmid = shmget(key, MEM_SIZE, IPC_CREAT | 0666);

    //3. 根据id号去映射一片内存空间。
    char *p = shmat(shmid, NULL, 0);
    // 读取数据
    bzero(p, 2048);
        // 1.创建有名信号量 需要打开/创建的有名信号量的名字，必须以"/"开头    "/sem_test"
    sem_t *signal_val = sem_open("/sem_test2", O_CREAT, 0777, 0);

    // 读取数据
    bzero(p, 2048);
    while (1)
    {
        if (sem_wait(signal_val) == -1) // 2.读取数据前进行p操作
        {
            perror("p operate failed! \n");
        }
        printf("rose message %s", p);
        //退出
        if (strncmp("quit\n", p, 5) == 0)
        {
            // 3.关闭有名信号量
            if (sem_close(signal_val) == -1)
            {
                perror("close signal failed \n");
            }
            // 4.删除有名信号量
            if (sem_unlink("/sem_test") == -1)
            {
                perror("delete /sem_test(Named semaphore) failed \n");
            }
            //5. 撤销映射
            shmdt(p);
            //6. 删除共享内存的对象
            shmctl(shmid, IPC_RMID, NULL);
            exit(0);
        }
    }

    pthread_join(pid, NULL);

    return 0;
}

void *send(void *arg)
{
    //1. 申请key值。
    key_t key_w = ftok(".", 20);

    //2. 根据key值去申请id号。
    int shmid_w = shmget(key_w, MEM_SIZE, IPC_CREAT | 0666);

    //3. 根据id号去映射一片内存空间。
    char *w_p = shmat(shmid_w, NULL, 0);

    // 1.创建有名信号量 需要打开/创建的有名信号量的名字，必须以"/"开头    "/sem_test"
    sem_t *signal_val = sem_open("/sem_test", O_CREAT, 0777, 0);
    bzero(w_p, 2048);

    while (1)
    {
        // 从键盘获取数据 // 写入数据
        fgets(w_p, MEM_SIZE, stdin);
        if (sem_post(signal_val) == -1)
        {
            printf(" v operate failed\n");
        }

        //退出
        if (strncmp("quit\n", w_p, 5) == 0)
        {
            // 3.关闭有名信号量
            if (sem_close(signal_val) == -1)
            {
                perror("close signal failed \n");
            }
            //5. 撤销映射
            shmdt(w_p);
            exit(0);
        }
    }
}