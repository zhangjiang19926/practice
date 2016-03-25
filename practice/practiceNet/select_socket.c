#include <sys/types.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/un.h>
#include <sys/time.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <stdlib.h>

#define SERVPORT 3333
#define BACKLOG 10
#define MAX_CONNECTED_NO 10
#define MAXDATASIZE 100

int main (int argv, char **argc)
{
	struct sockaddr_in server_sockaddr, client_sockaddr;//定义服务器和客户端的IP定制与端口结构体
	int sin_size, recvbytes;
	fd_set readfd;//定义文件描述符集合
	fd_set writefd;
	int sockfd, client_fd;
	char buf[MAXDATASIZE];
	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)//生成socket，并将文件描述符赋给sockfd
	{
		perror("socket");
		exit(1);
	}
	printf("socket success ! sockfd %d\n", sockfd);

	/*负责sever_sockaddr结构体中的各个量进行初始化*/
	server_sockaddr.sin_family = AF_INET;
	server_sockaddr.sin_port = htons(SERVPORT);
	server_sockaddr.sin_addr.s_addr = INADDR_ANY;
	memset(&(server_sockaddr.sin_zero), 0, 8);

	/*进行端口号与IP地址的绑定阶段*/
	if (bind(sockfd, (struct sockaddr *)&server_sockaddr, sizeof(struct sockaddr)) == -1)
	{
		perror("bind");
		exit(1);
	}
	printf("bind success!\n");
	/*进行监听这个sockfd这个文件描述符下的一举一动*/
	if (listen(sockfd, BACKLOG) == -1)
	{
		perror("listen");
		exit(1);
	}
	printf("listening...\n");
	/*将readfd进行清零，并将sockfd加入到readfd这个描述符集当中去*/
	FD_ZERO(&readfd);
	FD_SET(sockfd,&readfd);
	while (1)
	{
		sin_size = sizeof(struct sockaddr_in);
		if (select(MAX_CONNECTED_NO, &readfd, NULL, NULL, (struct timeval *)0) > 0)/*此东西的作用就是等待readfd中的一个文件描述符响应，若响应了就执行下面的语句*/
		{
			if (FD_ISSET(sockfd,&readfd) > 0)/*通过判断该响应的文件描述符是否是readfd这个文件描述符中的其中一个，若是的话就进行下面的程序的执行*/
			{
				if ((client_fd = accept(sockfd, (struct sockaddr *)&client_sockaddr, &sin_size)) == -1)/*判断是否接收此连接*/
				{
					perror("accept");
					exit(1);
				}
				if ((recvbytes = recv(client_fd, buf, MAXDATASIZE, 0)) == -1)
				{
					perror("recv");
					exit(1);
				}
				if (read(client_fd, buf, MAXDATASIZE) < 0)
				{
					perror("client_fd");
					exit(1);
				}
				printf("received a connection %s", buf);
			}
			close(client_fd);
		}
	}
}
