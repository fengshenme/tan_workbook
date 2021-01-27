#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	/*
    O_RDONLY：只读方式打开文件  |
    O_WRONLY：只写方式打开文件  | 这三个参数互斥
    O_RDWR：读写方式打开文件    |
     O_CREAT：如果文件不存在，则创建该文件。 
     O_EXCL：如果使用 O_CREAT 选项且文件存在，则返回错误消息。 
     O_NOCTTY：如果文件为终端，那么终端不可以作为调用 open()系统 调用的那个进程的控制终端。
      O_TRUNC：如文件已经存在，则删除文件中原有数据。
     O_APPEND：以追加方式打开文件。 
     mode 如果文件被新建，指定其权限为 mode（八进制表示法）
    */
	// O_RDWR：读写方式打开文件,如果文件不存在，O_CREAT：则创建该文件 O_APPEND：以追加方式打开文件。
	int fp = open("./day6/aa.txt", O_WRONLY | O_CREAT | O_APPEND, 0666);
	char *p = "adsfdgadag";
	int count = write(fp, p, 11);
	printf("%d\n", count);
	close(fp);

	char s[1024];
	int fr = open("./day6/aa.txt", O_RDONLY | O_CREAT);
	printf("%d\n", fr);
	int r_count = read(fr, s, 20);
	printf("实际读到的字节数:%d\n", r_count);
	printf("%s\n", s);
	close(fr);

	int frw = open("./day6/ac.txt", O_RDWR | O_CREAT |O_TRUNC);
	write(frw, "assssss\naa", 11);
	char sa[12];
	read(frw, sa, 11);
	printf("38,%s\n", sa);

	close(frw);
	close(fp);

	return 0;
}
