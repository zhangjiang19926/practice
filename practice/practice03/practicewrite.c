/*write.c*/
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//#define MAXSIZE	

int main (int argc, char **argv)
{
	int i, fd, size, len;
	char *buf = "Hello! I'am writing to this file!";
	char buf_r[10];
	len = strlen(buf);
	if((fd = open("/home/zhang/hello.c",O_CREAT | O_TRUNC | O_RDWR, 0666)) < 0)
	{
		perror("open:");
		exit(1);
	}
	else
		printf("open file:hello.c %d\n",fd);
	if((size = write(fd, buf,len)) < 0)
	{
		perror("write:");
		exit(1);
	}
	else 
		printf("Write : %s\n",buf);
	lseek(fd, 0, SEEK_SET);
	if((size = read(fd, buf_r, 10)) < 0)
	{
		perror("read:");
		exit(1);
	}
	else
		printf("read from file:%s\n",buf_r);
	if(close(fd) < 0)
	{
		perror("close:");
		exit(1);
	}
	else 
		printf("Close hello.c\n");
	exit(0);
}
