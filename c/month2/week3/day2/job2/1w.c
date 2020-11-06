#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
    char path[90] = "/home/gec/a_fifo";
    if (access(path, F_OK) != 0)
    {
        int flag = mkfifo(path, 0777);
        if (flag == -1)
        {
            perror("fifo create failed \n");
        }
    }

     int w_fd;
    w_fd = open(path, O_RDWR);
    if (w_fd == -1)
    {
        perror("fifo file open failed\n");
    }

    printf("%s\n", path);

    int x;
    while (1)
    {
        sleep(1);
        x = vfork();

        if (x == 0)
            break;
        if (x > 0)
            wait(NULL);
    }

    char buf[50];
    bzero(buf, sizeof(buf));
    pid_t pid = getpid();
    sprintf(buf, "%d", pid);
    write(w_fd, buf, strlen(buf));

     

    exit(0);
    
    close(w_fd);

    return 0;
}
