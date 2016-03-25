/*execve.c*/
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argv, char **argc)
{
	char *arg[] = {"env",NULL};
	char *envp[] = {"PATH=/tmp","USER=zhang",NULL};
	if (fork() == 0)
		if (execve("/usr/bin/env",arg,envp) < 0)
			perror("execve error!");
	return 0;
}
