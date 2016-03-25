#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <errno.h>

#define SERVERPORT 3333
#define MAXDATASIZE 100

int main (int argv, char **argc)
{
	int sockfd, sendbytes;
	char buf[MAXDATASIZE];
	struct hostent *host;
	struct sockaddr_in serv_addr;
	if (argv < 2)
	{
		fprintf(stderr, "please enter the server's hostname!\n");
		exit(1);
	}
	if ((host = gethostbyname(*argc + 1)) == NULL)
	{
		perror("gethostbyname");
		exit(1);
	}
	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
	{
		perror("socket");
		exit(1);
	}

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(SERVERPORT);
	serv_addr.sin_addr = *((struct in_addr *) host -> h_addr);
	memset(&(serv_addr.sin_zero), 0, 8);

	if (connect(sockfd, (struct sockaddr *)&serv_addr,sizeof(struct sockaddr)) == -1)
	{
		perror("connect");
		exit(1);
	}
	if ((sendbytes = send(sockfd, "hello", 5, 0)) == -1)
	{
		perror("send");
		exit(1);
	}
	close(sockfd);
}
