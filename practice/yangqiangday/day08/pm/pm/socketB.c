#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <linux/un.h>
#include <unistd.h>


int main (int argc, char ** argv)
{
	int fd;
	int r;
	struct sockaddr_un addr = {0};
	/*1.建立socket文件*/
	fd = socket(AF_UNIX, SOCK_DGRAM, 0);
	/*2.连接到文件*/
	addr.sun_family = AF_UNIX;
	memcpy(addr.sun_path, "my.sock", strlen("my.sock"));
	r = connect(fd, (struct sockaddr *)&addr, sizeof(addr));
	/*3.发送数据*/
	write(fd, "Hello", 5);
	/*4.关闭socket文件*/
	close(fd);
	return 0;
}


