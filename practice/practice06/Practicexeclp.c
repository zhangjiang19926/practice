/*execlp.c*/
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argv, char **argc)
{
	if (fork() == 0)
	{
		//直接运行ps -ef这条命令，创建了个子进程
		if (execlp("ls","ls","-al",NULL) < 0)
			perror("execlp error!");
	}
	return 0;
}

