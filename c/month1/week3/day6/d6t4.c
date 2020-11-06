#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>


int main(int argc, char const *argv[])
{

    char p[20];
    
    int frw = open("./day6/as.txt", O_RDWR | O_CREAT );
    scanf("%s", p);while(getchar() != '\n');
    write(frw, p, strlen(p));
    lseek(frw, 6, SEEK_SET);
    printf("%s \n", p);

    char s[20];
    scanf("%s", s);while(getchar() != '\n');
    int len = strlen(s)+1;
    write(frw, s, len);
    lseek(frw, 0, SEEK_SET);

    char des[6+len];
    read(frw, des, 6+len);
    printf("%s \n", des);

    close(frw);
    return 0;
}
