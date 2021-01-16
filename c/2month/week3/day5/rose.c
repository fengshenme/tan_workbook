#include <signal.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <string.h>
#include <stdio.h>
#include <sys/shm.h>
#include <unistd.h>

// 读取数据
int main(int argc, char const *argv[])
{
    key_t key = ftok(".", 10);

    int shmid = shmget(key, 1024 * 10, IPC_CREAT | 0666);

    char *buf;
    while (1)
    {
        sleep(1);
        buf = shmat(shmid, NULL, 0);
        printf("from jack: %s\n", buf);
        if (strncmp("quit", buf, 4) == 0)
        {
            break;
        }
    }
    //5. 撤销映射
    shmdt(buf);

    //6. 删除共享内存的对象
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}
