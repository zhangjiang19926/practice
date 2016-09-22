#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <linux/un.h>
#include <string.h>
#include <unistd.h>

int main (int argc, char ** argv)
{
	int fd;
	int r;
	char buf[20];
	/*1.建立socket*/
	fd = socket(AF_UNIX, SOCK_DGRAM, 0);
	/*1.地址类型：AF_LOCAL, AF_UNIX,AF_INET
	 *2.数据类型：SOCK_DGRAM, SOCK_STEAM 
	 *3.数据交换协议：
	 */
	if (fd == -1)
	{
		printf("socket %m\n");	
		exit(-1);
	}
	/*2.构造本地文件地址*/
	struct sockaddr_un addr = {0};
	addr.sun_family = AF_UNIX;	
	memcpy(addr.sun_path, "my.sock", strlen("my.sock"));
	/*3.绑定地址*/
	r = bind(fd, (struct sockaddr *)&addr, sizeof(addr));
	if (r == -1) printf("bind err:%m\n"),exit(-1);
	printf("地址绑定成功!\n");
	/*4.接收数据*/
	bzero(buf, sizeof(buf));
	r = read(fd, buf, sizeof(buf));
	buf[r] = 0;
	printf("%s\n", buf);
	/*5.关闭socket文件*/
	close(fd);
	/*6.删除socket*/
	unlink("my.sock");
	return 0;
}

