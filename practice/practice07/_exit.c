/*_exit.c*/
#include <stdio.h>
#include <unistd.h>

int main (int argv, char **argc)
{
	printf("Using _exit...\n");
	printf("This is the content in buffer");
	_exit(0);
}
