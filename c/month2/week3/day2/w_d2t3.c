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
    if (access(path, F_OK) != 0)
    {
        int flag = mkfifo(path, 0777);
        if (flag == -1)
        {
            perror("fifo create failed \n");
        }
    }

    int w_fd ;
    w_fd = open(path, O_RDWR);
    if (w_fd == -1)
    {
        perror("fifo file open failed\n");
    }
    
    printf("%s\n", path);

    char buf[50];

    while (1)
    {

        bzero(buf, sizeof(buf));

        fgets(buf, sizeof(buf), stdin);
        
        if (strlen(buf) > 0)
        {
            write(w_fd, buf, strlen(buf));
        }

        if (strncmp(buf, "I LOVE YOU", 10) == 0)
            break;
    }

    close(w_fd);

    return 0;
}
