
#include "../head.h"

int main(int argc,char *argv[])  //  ./Rose xxx.xxx.xxx.xxx 端口号
{
	//1. 创建UDP套接字
	int sockfd;
	sockfd = socket(AF_INET,SOCK_DGRAM,0);

	//2. 绑定IP地址，端口号，协议到UDP协议中
	struct sockaddr_in srvaddr;
	socklen_t len = sizeof(srvaddr);
	bzero(&srvaddr,len);

	srvaddr.sin_family = AF_INET;
	srvaddr.sin_port = htons(atoi(argv[2]));

    inet_pton(AF_INET,argv[1],&srvaddr.sin_addr);


	//
	char buf[100];

	while(1)
	{
		bzero(buf,sizeof(buf));


        fgets(buf, sizeof(buf), stdin);

		if (strlen(buf) > 0)
		{
			sendto(sockfd,buf,sizeof(buf),0,(struct sockaddr *)&srvaddr,len); 
		}
		
		
		if(strncmp(buf,"quit\n",5) == 0)
		{
			break;
		}
	}
	
	//5. 回收套接字资源
	close(sockfd);

	return 0;
}