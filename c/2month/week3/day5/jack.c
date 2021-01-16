#include <signal.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <string.h>
#include <stdio.h>
#include <sys/shm.h>
#include <unistd.h>

//写入数据
int main(int argc, char const *argv[])
{
    key_t key =  ftok(".", 10);

    int shmid = shmget(key, 1024*10, IPC_CREAT | 0666);

    char *buf = shmat(shmid, NULL, 0);

    while (1)
    {
       fgets(buf, 50, stdin);
       if (strncmp("quit", buf, 4) == 0)
       {
           break;
       }
       
    }
    
    return 0;
}
