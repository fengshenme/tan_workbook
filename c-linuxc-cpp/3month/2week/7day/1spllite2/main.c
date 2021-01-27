#include <stdio.h>
#include <sys/types.h> /* See NOTES */
#include <sys/socket.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <pthread.h>

#include <sqlite3.h>

#define ADDINFO 1000
#define DELINFO 1001
#define UPDATEINFO 1002
#define SEARCHINFO 1003
#define SHOWINFO 1004
#define EXIT 1005

struct ChatInfo
{
	int cmd;
	char name[32];
	char old_name[32];
	char tel[32];
	int result;
};

typedef struct ChatInfo Chat;

int fd[1024] = {0};
pthread_t tid; //线程号--线程标识符
//socket -- bind -- listen --accept --recv --send --close
int InitNet()
{
	struct sockaddr_in server_addr;				  //地址结构
	int sockfd = socket(AF_INET, SOCK_STREAM, 0); //套接字描述符: ipv4 流式
	if (-1 == sockfd)
	{
		perror("socket");
		exit(1);
	}

	int opt = 1;
	setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

	memset(&server_addr, 0, sizeof(server_addr));
	server_addr.sin_family = PF_INET;						  //设置地址族 ipv4
	server_addr.sin_port = htons(3333);						  //设置端口号
	server_addr.sin_addr.s_addr = inet_addr("192.168.1.111"); //ip地址
	int ret = bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
	if (ret == -1)
	{
		perror("bind");
		exit(1);
	}

	ret = listen(sockfd, 10); //最大请求数
	if (ret == -1)
	{
		perror("listen");
		exit(1);
	}

	return sockfd;
}

void exit_client(int fd)
{
	printf("客户端 %d 下线\n", fd);
	close(fd);				 //关闭TCP连接
	pthread_exit((void *)0); //线程退出
}

void *client_handler(void *arg) //线程函数
{
	Chat c;
	int fd = *(int *)arg;
	while (1)
	{
		int ret = recv(fd, &c, sizeof(c), 0);
		if (-1 == ret)
		{
			perror("recv");
		}
		switch (c.cmd)
		{
		case ADDINFO:
			add_info(&c);
			break;
		case DELINFO:
			delete_info(&c);
			break;
		case UPDATEINFO:
			updata_info(&c);
			break;
		case SEARCHINFO:
			search(fd, &c);
			break;
		case SHOWINFO:
			show_info(fd);
			break;
		case EXIT:
			exit_client(fd);
			break;
		}
	}
}

void main_handler(int sockfd)
{
	int i = 0;
	struct sockaddr_in client_addr;
	int length = sizeof(client_addr);
	while (1)
	{
		for (i = 0; i < 1024; i++)
		{
			if (0 == fd[i])
			{
				break;
			}
		}
		fd[i] = accept(sockfd, (struct sockaddr *)&client_addr, &length); //接收客户端的连接，client_addr客户端地址
		printf("接收客户端连接%d\n", fd[i]);
		int ret = pthread_create(&tid, NULL, client_handler, &fd[i]); //启动线程处理连接（一个线程对应一个客户端）--client_handler线程函数的起始地址--fd[i]函数的参数
		if (-1 == ret)
		{
			perror("pthread_create");
			exit(1);
		}
	}
}

//1.创建数据库文件
//2.创建保存联系人信息的表
void InitDataBase()
{

	sqlite3 *ppdb; //数据库句柄

	int ret = sqlite3_open("address.db", &ppdb);
	if (ret != SQLITE_OK)
	{
		printf("sqlite3_open:%s\n", sqlite3_errmsg(ppdb));
		exit(1);
	}

	char sql[128] = {0};
	sprintf(sql, "create table if not exists address (name text, tel text);");
	ret = sqlite3_exec(ppdb, sql, NULL, NULL, NULL);
	if (ret != SQLITE_OK)
	{
		printf("sqlite3_exec1:%s\n", sqlite3_errmsg(ppdb));
		exit(1);
	}
	sqlite3_close(ppdb);
}

void add_info(Chat *c)
{
	sqlite3 *ppdb;
	int ret = sqlite3_open("address.db", &ppdb);
	if (ret != SQLITE_OK)
	{
		printf("sqlite3_open : %s\n", sqlite3_errmsg(ppdb));
	}

	char sql[128] = {0};
	sprintf(sql, "insert into address values ('%s','%s');", c->name, c->tel);
	ret = sqlite3_exec(ppdb, sql, NULL, NULL, NULL);
	if (ret != SQLITE_OK)
	{
		printf("sqlite3_exec:%s\n", sqlite3_errmsg(ppdb));
	}
	sqlite3_close(ppdb);
}

void updata_info(Chat *c)
{
	sqlite3 *ppdb;
	int ret = sqlite3_open("address.db", &ppdb);
	if (ret != SQLITE_OK)
	{
		printf("sqlite3_open : %s\n", sqlite3_errmsg(ppdb));
	}

	char sql[128] = {0};
	sprintf(sql, "update address set name = '%s',tel = '%s' where name = '%s';", c->name, c->tel, c->old_name);
	ret = sqlite3_exec(ppdb, sql, NULL, NULL, NULL);
	if (ret != SQLITE_OK)
	{
		printf("sqlite3_exec:%s\n", sqlite3_errmsg(ppdb));
	}
	sqlite3_close(ppdb);
}

int sendinfo(void *para, int columnCount, char **columnVal, char **columnName)
{
	int fd = *(int *)para;
	Chat c;

	strcpy(c.name, columnVal[0]);
	strcpy(c.tel, columnVal[1]);
	int ret = send(fd, &c, sizeof(c), 0);
	if (-1 == ret)
	{
		perror("send");
	}

	return 0;
}

void search(int fd, Chat *c)
{
	sqlite3 *ppdb;
	int ret = sqlite3_open("address.db", &ppdb);
	if (ret != SQLITE_OK)
	{
		printf("sqlite3_open : %s\n", sqlite3_errmsg(ppdb));
	}

	char sql[128] = {0};
	sprintf(sql, "select * from address where name = '%s';", c->name);
	ret = sqlite3_exec(ppdb, sql, sendinfo, &fd, NULL);
	if (ret != SQLITE_OK)
	{
		printf("sqlite3_exec:%s\n", sqlite3_errmsg(ppdb));
		exit(1);
	}
	Chat a;
	strcpy(a.name, "bye");
	strcpy(a.tel, "bye");
	ret = send(fd, &a, sizeof(a), 0);
	if (-1 == ret)
	{
		perror("send");
	}
}

void show_info(int fd)
{
	sqlite3 *ppdb;
	int ret = sqlite3_open("address.db", &ppdb);
	if (ret != SQLITE_OK)
	{
		printf("sqlite3_open : %s\n", sqlite3_errmsg(ppdb));
	}

	char sql[128] = "select * from address;";

	ret = sqlite3_exec(ppdb, sql, sendinfo, &fd, NULL);
	if (ret != SQLITE_OK)
	{
		printf("sqlite3_exec:%s\n", sqlite3_errmsg(ppdb));
		exit(1);
	}

	Chat c;
	strcpy(c.name, "bye");
	strcpy(c.tel, "bye");
	ret = send(fd, &c, sizeof(c), 0);
	if (-1 == ret)
	{
		perror("send");
	}
}

void delete_info(Chat *c)
{
	sqlite3 *ppdb;
	int ret = sqlite3_open("address.db", &ppdb);
	if (ret != SQLITE_OK)
	{
		printf("sqlite3_open : %s\n", sqlite3_errmsg(ppdb));
	}

	char sql[128] = {0};
	sprintf(sql, "delete from address where name = '%s';", c->name);
	ret = sqlite3_exec(ppdb, sql, NULL, NULL, NULL);
	if (ret != SQLITE_OK)
	{
		printf("sqlite3_exec:%s\n", sqlite3_errmsg(ppdb));
	}
	sqlite3_close(ppdb);
}

int main()
{
	int sockfd;
	sockfd = InitNet(); //初始化网络设置

	InitDataBase(); //初始化数据库

	main_handler(sockfd);

	return 0;
}
