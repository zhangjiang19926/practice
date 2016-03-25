/**********************************************************
*			作者：		张江
*		    程序功能：  实现TCP协议的socket服务器功能  
*						在其中使用一个线程进行监听，负
*						责发送功能。
*		    完成时间：  2016/01/22	
***********************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 12000               
#define BACKLOG 5
#define BUFFERLEN 1024

void pthreadRcv(void);
void pthreadR(void);
void display(char *str);

char buffer[BUFFERLEN] = {'\0'};
char msg[BUFFERLEN];
int sockfd, client_fd; 

int main(int argc, char **argv)
{
	struct sockaddr_in server_sockaddr;
	int size;
	pthread_t pthread;
	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
	{
		perror("socket");	
		exit(1);
	}
	memset(&server_sockaddr, 0, sizeof(server_sockaddr));
	server_sockaddr.sin_family = AF_INET;
	server_sockaddr.sin_port = htons(PORT);
	server_sockaddr.sin_addr.s_addr = INADDR_ANY;
	if (bind(sockfd, (struct sockaddr *)&server_sockaddr, sizeof(server_sockaddr)) == -1)
	{
		perror("bind");	
		exit(1);
	}
	if (listen(sockfd, BACKLOG) == -1)
	{
		perror("listen");	
		exit(-1);
	}
	printf("I'm ready!you can send a message to me!\n");
	if ((pthread_create(&pthread, NULL, (void *)pthreadRcv, NULL))!= 0)
	{
		perror("pthread_create");	
		exit(1);
	}
	while(1)
	{

		scanf("%s",msg);
		if (send(client_fd, msg, strlen(msg), 0) == -1)
		{
			perror("send");	
			exit(1);
		}
		if (strcmp(msg,"exit") == 0)
		{
			printf("exited!\n");
			close(client_fd);
			close(sockfd);
			exit(1);
		}
	}
	return 0;
}

void pthreadRcv(void)
{
	int err;
    struct sockaddr_in client_sockaddr;
	pthread_t pthread;
	int size = sizeof(struct sockaddr_in);
	if ((client_fd = accept(sockfd, (struct sockaddr *)&client_sockaddr, &size)) == -1)	
	{
		perror("accept");	
		exit(1);
	}
	if ((pthread_create(&pthread, NULL, (void *)pthreadR, NULL))!= 0)
	{
		perror("pthread_create");	
		exit(1);
	}
}
void pthreadR(void)
{
	while(1)
	{
		char buff[BUFFERLEN];
		char quit[BUFFERLEN];
		int numbytes;
		numbytes = recv(client_fd, buff, BUFFERLEN, 0);
		if (numbytes == -1)
		{
			perror("recv");
			exit(1);
		}
		if (numbytes == 0)
		{
			strcpy(buff, "exit");
		}
		printf("I receive a message:%s\n", buff);
		if (strcmp(buff, "exit") == 0)
		{
			printf("Do you want to exit?\n");
			scanf("%s",quit);
			if ((strcmp(quit, "Y") == 0) || (strcmp(quit, "y") == 0))
			{
				close(client_fd);
				close(sockfd);
				exit(1);
			}
			printf("you want play a long time\n");
		}
	}
}
void display(char *str)
{
	printf("%s\n", str);
}
