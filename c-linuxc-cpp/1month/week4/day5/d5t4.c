#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include<grp.h> 
#include<sys/types.h>
#include <pwd.h>
#include <stdlib.h>


void pen(struct stat *buf);
void filetype(struct stat *buf);

// 实现 ls -l 类似效果
int main(int argc, char const *argv[])
{
    // char filename[20];
    // bzero(filename, sizeof(filename));
    // fgets(filename, sizeof(filename), stdin);
    // strtok(filename, "\n");
    if(argc != 2)
    {
        printf("Usage: %s <filename>\n", argv[0]); 
        exit(1);
    }


    // 获取属性
    struct stat buf;
    if (stat(argv[1], &buf) == -1)
    {
        perror("stat failed");
        return 1;
    }

    // 1.文件类型(st_mode的高4位)
    // printf("st_mode: %d\n", buf.st_mode);
    // st_mode:	xxxx yyyz zzzz zzzz
    // 		&	1111 0000 0000 0000
    // 	--->	xxxx 0000 0000 0000
    // 			1100 0000 0000 0000
    filetype(&buf);
    
    // 2.文件权限(st_mode的低9位)
    // 使用位操作，将所有权限打印出来
    pen(&buf);

    // 3.硬链接数
	// printf("%lu ", buf.st_nlink);

	// 4.用户名
	// printf("st_uid: %d\n", buf.st_uid);
	// 使用到  getuid函数
     printf("%s ",  getpwuid( buf.st_uid)->pw_name);
	// 5.组名
	// printf("st_gid: %d\n", buf.st_gid);
	// 使用到  getgid函数
    printf("%s ",  getgrgid(buf.st_gid)->gr_name );

    // 6.文件大小（单位：字节）
    printf("%ld ", buf.st_size);

    // 7.最后属性更改时间
    // printf("st_ctime: %ld\n", buf.st_ctime);
    // 使用
    printf("%s",  strtok(ctime(&buf.st_ctime), "\n"));
    // 8.文件名
    printf("%s\n", argv[1]);

    return 0;
}

void filetype(struct stat *buf)
{
    switch (buf->st_mode & S_IFMT)
    {
    case S_IFLNK:
        printf("l "); //链接
        break;
    case S_IFSOCK: // 套接字
        printf("s ");
        break;
    case S_IFREG: // 普通文件
        printf("- ");
        break;
    case S_IFDIR:
        printf("d "); // 目录
        break;
    case S_IFBLK: // 块设备
        printf("b ");
        break;
    case S_IFCHR: // 字符设备
        printf("c ");
        break;
    case S_IFIFO: // 管道
        printf("p ");
        break;
    }
}

void pen(struct stat *buf)
{
    char rwx[3] = {'r', 'w', 'x'};
    // 100 000 000 权限相关用8进制 0400 
    for (size_t i = 0; i < 9; i++)
    {
        printf("%c", buf->st_mode & (0400 >> i) ? rwx[i%3] : '-');
    }
}