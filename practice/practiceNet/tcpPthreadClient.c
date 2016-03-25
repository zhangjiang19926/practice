/**********************************************************
*			作者：		张江
*		    程序功能：  实现TCP协议的socket客户端功能  
*						在其中使用一个线程进行接收数据，
*						主线程负责发送功能。
*		    完成时间：  2016/01/22	
*			存在的问题：若有一方退出，另一方不能立马按
*						键退出
***********************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>
#include <netdb.h>
#include <pthread.h>

#define PORT 12000
#define BUFLEN 1024

void pthreadRcv(void);
void display(char *str);

char buffer[BUFLEN] = {'\0'};
int sockfd;
struct sockaddr_in client_addr;

int main (int argc, char *argv[])
{
	struct hostent *host;
	pthread_t pthread;
	if (argc < 2)
	{
		fprintf(stderr,"please enter the sever's hostname1\n");
		exit(1);
	}
	if ((host = gethostbyname(argv[1])) == NULL)
	{
		perror("gethostbyname");	
		exit(1);
	}
	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
	{
		perror("socket");	
		exit(1);
	}
	client_addr.sin_family = AF_INET;
	client_addr.sin_port = htons(PORT);
	client_addr.sin_addr = *((struct in_addr *)host -> h_addr);
	memset(&(client_addr.sin_zero), 0, 8);

	if (connect(sockfd, (struct sockaddr *)&client_addr, sizeof(struct sockaddr)) == -1)
	{
		perror("connect");	
		exit(1);
	}
	printf("I'm ready!you can send a message to me!\n");
	if (pthread_create(&pthread, NULL, (void *)pthreadRcv, NULL) != 0)
	{
		perror("pthread_create");	
		exit(1);
	}
	while(1)
	{
		char msg[BUFLEN];
		int numbytes;
		scanf("%s",msg);
		numbytes = send(sockfd, msg, strlen(msg), 0);
		if( numbytes == -1 )
		{
			perror("send");	
			exit(1);
		}
		if (strcmp(msg,"exit") == 0)
		{
			printf("client quit!\n");
			close(sockfd);	
			exit(1);
		}
	}
	return 0;
}

void pthreadRcv(void)
{
	while(1)
	{
		char buff[BUFLEN] = {'\0'};
		char quit[BUFLEN];
		int numbytes = recv(sockfd, buff, BUFLEN, 0);
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
			printf("Do you want to exit!\n");
			scanf("%s",quit);
			if ((strcmp(quit,"Y") == 0) || (strcmp(quit,"Y") == 0))
			{
				close(sockfd);	
				exit(1);
			}
			printf("you want to play a long time!\n");
		}
	}
}

void display(char *str)
{

}
