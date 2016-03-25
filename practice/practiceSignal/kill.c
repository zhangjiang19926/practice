#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

int main (int argv, char **argc)
{
	pid_t pid;
	int ret;
	//create a subprocess
	if ((pid = fork()) < 0)
	{
		perror("fork");
		exit(1);
	}
	if (pid == 0)
	{
		raise(SIGSTOP);	
		exit(0);
	}
	else 
	{
		printf("pid=%d\n", pid);
		//wait for the subprocess exit.
		if ((waitpid(pid, NULL, WNOHANG)) == 0)
		{
			if ((ret = kill(pid, SIGKILL)) == 0)
				printf("kill %d,%d\n", pid, ret);
		}
		else
			perror("kill");
	}
	return 0;
}
