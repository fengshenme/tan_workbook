#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <strings.h>

int main(int argc, char const *argv[])
{
    char path[90] = "/home/gec/a_fifo";

    int ret = open(path, O_RDWR);
    if (ret == -1)
    {
        int flag = mkfifo(path, 0777);
        if (flag == -1)
        {
            perror("fifo create failed \n");
        }
    }

    int fd = open(path, O_RDWR);
    if (fd == -1)
    {
        perror("fifo file open failed\n");
    }
    char buf[30];
    while (1)
    {
        bzero(buf, sizeof(buf));

        read(fd, buf, sizeof(buf));

        printf("read : %s \n", buf);
    }

    close(fd);

    return 0;
}
