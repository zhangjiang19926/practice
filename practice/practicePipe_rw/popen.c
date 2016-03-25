#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#define BUFSIZE 1000

int main (int argv, char **argc)
{
	FILE *fp;
	char *cmd = "ps -ef";
	char buf[BUFSIZE];
	if ((fp = popen(cmd,"r")) == NULL)
		perror("popen");
	while ((fgets(buf, BUFSIZE, fp)) != NULL)
		printf("%s\n", buf);
	pclose(fp);
	return 0;
}
