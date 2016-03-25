#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argv, int **argc)
{
	int pipe_fd[2];	
	pid_t pid;
	char *p_wbuf;
	char buf_r[100];
	int r_num;
	memset(buf_r, 0, sizeof(buf_r));
	//create a pipe
	if (pipe(pipe_fd) < 0) 
	{
		printf("pipe create error\n");	
		return -1;
	}
	//create a process
	if ((pid = fork()) == 0)
	{
		printf("\n");
		//close(pipe_fd[1]);
		//if ((r_num = read(pipe_fd[0], buf_r, 100)) > 0)//return a the number of reading
			//printf("%d numbers read from the pipe is %s\n",r_num, buf_r);
		//close(pipe_fd[0]);

		close(pipe_fd[0]);	
		if ((write(pipe_fd[1], "songe xxx is", 12)) !=-1)//the number must match
			printf("son write2 success!\n");
		if ((write(pipe_fd[1], "xxx", 5)) !=-1)
			printf("son write2 success!\n");
		close(pipe_fd[1]);
		sleep(2);

		exit(0);
	}
	else if (pid > 0)
	{
		//close(pipe_fd[0]);	
		//if ((write(pipe_fd[1], "Hello", 5)) !=-1)
			//printf("parent write2 success!\n");
		//if ((write(pipe_fd[1], "Pipe", 5)) !=-1)
			//printf("parent write2 success!\n");
		//close(pipe_fd[1]);

		close(pipe_fd[1]);
		sleep(3);
		if ((r_num = read(pipe_fd[0], buf_r, 100)) > 0)//return a the number of reading
			printf("%d numbers read from the pipe is %s\n",r_num, buf_r);
		close(pipe_fd[0]);
		waitpid(pid, NULL, 0);
		exit(0);
	}
	return 0;
}
