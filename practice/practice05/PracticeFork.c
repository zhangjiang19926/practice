#include <sys/types.h>
#include <unistd.h>
#include <stdio.h> 
#include <stdlib.h>

int main (int argv, char **argc)
{
	pid_t result;
	result = fork();//返回了两个值，分别是子进程的ID和父进程的ID。:
	if (result == -1)
	{
		perror("fork:");
		exit;
	}
	//返回值等于0代表的是子进程
	else if (result == 0)
	{
		printf("The return balue is %d\nIn child process!!\nMy PID is %d\n",result, getpid());
	}
	//返回值大于0代表的是父进程
	else 
	{
		printf("The return value is %d\nIn father process!!\nMy PID is %d\n",result,getpid());
	}
	return 0;
}
