#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 1.浏览书本、资料，尝试使用open创建一个文件并写入数据。
int main(int argc, char const *argv[])
{
    int fla = open("./day6/test.txt", O_RDWR | O_CREAT | O_TRUNC);
    if(fla == -1)
    {
        perror("file open failed!\n");
        return 0;
    }
    char input_str[20];
    bzero(input_str,20);
    scanf("%s", input_str); while(getchar() != '\n');
    int len = strlen(input_str) + 1;
    write(fla, input_str, len);

    char output_des[len];
    lseek(fla, 0, SEEK_SET);
    read(fla, output_des, len);
    printf("%s\n", output_des);
    close(fla);
    // system("cat ./day6/test.txt ");

    return 0;
}
