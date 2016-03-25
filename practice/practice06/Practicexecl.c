/*execl.c*/
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argv, char **argc)
{
	//调用exicl函数，注意给出的ps所在的完整地址
	if (fork() == 0)
	{
		if (execl("/bin/ps","ps","-ef",NULL) < 0)
			perror("execl error1");
	}
	return 0;
}
