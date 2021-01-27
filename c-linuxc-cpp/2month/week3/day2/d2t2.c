#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{

    int fd[2] = {0};

    int flag = pipe(fd);
    if (flag == -1)
    {
        perror("pipe failed!\n");
    }

    pid_t x = fork();

    if (x > 0)
    {
        char buf[20] = {0};
        if (read(fd[0], buf, 20)>0)
        {
            printf("%s \n", buf);
        }
        wait(NULL);
        exit(0);
    }

    if (x == 0)
    {
        char buf[20] = "hello";

        write(fd[1], buf, strlen(buf));

        exit(0);
    }

    return 0;
}
