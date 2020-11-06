#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

#define TEXTSIZE 50

#define JACK 10
#define ROSE 11

struct mybuf
{
    long mtype;
    char mtext[TEXTSIZE];
};

int main(int argc, char const *argv[])
{
    key_t key = ftok(".", 10);

    int smgid = msgget(key, IPC_CREAT | 0666);

    struct mybuf w_buf, r_buf;

    pid_t x = fork();

    if (x > 0)
    {
        while (1)
        {
            signal(SIGINT, SIG_DFL);
            // 读取数据
            bzero(&r_buf, sizeof(r_buf));
            msgrcv(smgid, &r_buf, sizeof(r_buf.mtext), ROSE, IPC_NOWAIT);
            if (strlen(r_buf.mtext) > 0)
            {
                printf("%s", r_buf.mtext);
            }
            //退出
            if (strncmp("quit\n", r_buf.mtext, sizeof(r_buf.mtext)) == 0)
            {
                kill(x, SIGINT); 
                break;
            }
        }
        msgctl(smgid, IPC_RMID, NULL); //删除消息队列
        wait(NULL);
        exit(0);
    }

    if (x == 0)
    {
        while (1)
        {
            signal(SIGINT, SIG_DFL);
            // 清空
            bzero(&w_buf, sizeof(w_buf));
            // 从键盘获取数据
            fgets(w_buf.mtext, TEXTSIZE, stdin);
           
            // 写入数据
             w_buf.mtype = JACK ;
            msgsnd(smgid, &w_buf, TEXTSIZE, IPC_NOWAIT);

            //退出
            if (strncmp("quit\n", w_buf.mtext, sizeof(w_buf.mtext)) == 0)
             {
                 kill(getppid(), SIGINT);
                 exit(0);
             }   
                
        }
        
    }

    return 0;
}
