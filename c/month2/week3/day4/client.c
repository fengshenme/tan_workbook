#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <string.h>

#define TEXTSIZE 50

struct mybuf
{
    long mtype;
    char mtext[TEXTSIZE];
    /* data */
};

int main(int argc, char const *argv[])
{
    key_t key = ftok(".", 10);

    int smgid = msgget(key, IPC_CREAT | 0666);

    struct mybuf w_buf;

    int ret;

    while (1)
    {
        // 清空
        bzero(&w_buf, sizeof(w_buf));
        // 从键盘获取数据
        fgets(w_buf.mtext,TEXTSIZE, stdin);
        w_buf.mtype = 11;
        // 写入数据
        msgsnd(smgid, &w_buf, TEXTSIZE, IPC_NOWAIT);

        // todo 读取数据

        if (strncmp("quit\n", w_buf.mtext, sizeof(w_buf.mtext)) == 0)
        {
            break;
        }
    }

    return 0;
}
