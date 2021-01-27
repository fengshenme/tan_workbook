#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{

    if (argc != 2)
    {
        printf("uage: %s <src>\n", argv[0]);
        exit(1);
    }

    int fd = open(argv[1], O_RDONLY);
    char buf[10];
    read(fd, buf, 10);

    close(fd);

    switch (atoi(buf))
    {
    case 10:
        printf("large\n");
        break;
    case 5:
        printf("middle\n");
        break;
    case 1:
        printf("small\n");
        break;

    default:
        printf("error\n");
        break;
    }

    return 0;
}
