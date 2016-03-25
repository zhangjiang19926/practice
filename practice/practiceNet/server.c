#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <stdlib.h>

#define SERVPORT 3333 
#define BACKLOG 10
#define MAX_CONNECTED_NO 10
#define MAXDATASIZE 5

int main (int argv, char **argc)
{
	struct sockaddr_in server_sockaddr, client_sockaddr;
	int sin_size, recvbytes;
	int sockfd, client_fd;
	char buf[MAXDATASIZE];
	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
	{
		perror("socket");
		exit(1);
	}
	printf("socket success! sockfd = %d\n", sockfd);
	server_sockaddr.sin_family = AF_INET;
	server_sockaddr.sin_port = htons(SERVPORT);
	server_sockaddr.sin_addr.s_addr = INADDR_ANY;
	memset(&(server_sockaddr.sin_zero), 0, 8);
	if (bind(sockfd, (struct sockaddr *)&server_sockaddr, sizeof(struct sockaddr)) == -1)
	{
		perror("bind");
		exit(1);
	}
	printf("bind success!\n");
	if (listen(sockfd, BACKLOG) == -1)//端口监听
	{
		perror("listen");
		exit(1);
	}
	printf("listening...\n");
	if ((client_fd = accept(sockfd, (struct sockaddr *)&client_sockaddr, &sin_size)) ==-1)//阻塞服务端，等待客户端的连接
	{
		perror("accept");
		exit(1);
	}
	if ((recvbytes = recv(client_fd, buf, MAXDATASIZE, 0)) == -1)
	{
		perror("recv");
		exit(1);
	}
	printf("received connection : %s\n", buf);
	close(sockfd);
}

