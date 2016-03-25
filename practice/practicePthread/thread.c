#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
/*create the pthread1's function*/
void thread1(void)
{
	int i = 0;
	for (i = 0; i < 6; i++)
	{
		printf("This is a pthread1.\n");
		if (i == 2)
			pthread_exit(0);
		sleep(1);
	}
}
/*create the pthread2's function*/
void thread2(void)
{
	int i;
	for (i = 0; i < 3; i++)
		printf("This is a pthread2.\n");
	pthread_exit(0);
}

int main (int argv, char **argc)
{
	pthread_t id1, id2;
	int i, ret;
	/*create a pthread1,and the pthread1's function is thread1*/
	ret = pthread_create(&id1, NULL, (void *) thread1, NULL);
	if (ret != 0)
	{
		printf("Create pthread error!\n");
		exit(1);
	}
	/*create a pthread1,and the pthread1's function is thread2*/
	ret = pthread_create(&id2, NULL, (void *) thread2, NULL);
	if (ret != 0)
	{
		printf("Create pthread error!\n");
		exit(1);
	}
	pthread_join(id1, NULL);	
	pthread_join(id2, NULL);	
	exit(0);
}
