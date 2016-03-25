/*execle.c*/
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argv, char **argc)
{
	char *envp[] = {"PATH=/tmp","USER=zhang",NULL};
	if (fork() == 0)
		if (execle("/usr/bin/env","env",NULL,envp) < 0)//将环境变量添加到新建的子进程中去
			perror("execle error!");
	return 0;
}
