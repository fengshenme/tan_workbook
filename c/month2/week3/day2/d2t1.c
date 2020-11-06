#include <unistd.h>
#include <stdio.h>


int main(int argc, char const *argv[])
{
    
    int fd[2];

    int flag = pipe(fd);

    if (flag == -1)
    {
        perror("pipe init failed!\n");
    }

    printf("read: %d\n", fd[0]);
    printf("write: %d\n", fd[1]);
    

    return 0;
}
