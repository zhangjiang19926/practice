#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argv, char **argc)
{
	int pipe_fd[2];
	//create a pipe,pipe_fd[0] is reading,pipe_fd[1] is writing.
	if (pipe(pipe_fd) < 0)
	{
		printf("pipe create error\n");
		return -1;
	}
	else
		printf("pipe create success\n");
	close(pipe_fd[0]);//close the file descriptor
	close(pipe_fd[1]);
	return 0;
}
