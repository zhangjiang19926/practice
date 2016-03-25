#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
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
	while(1)
	{
		for (i = 0; i < 3; i++)
			printf("This is a pthread2.\n");
		sleep(1);
	}
	pthread_exit(0);
}

int main (int argv, char **argc)
{
	pthread_t id1, id2;
	int i, ret;
	pthread_attr_t attr;
	/*initilize the attribute*/
	pthread_attr_init(&attr);
	/*let the attributer is PTHREAD_SCOPE_SYSTEM 设置该线程为绑定的，即该线程具有一个单独的内核线程与它进行交互*/
	pthread_attr_setscope(&attr, PTHREAD_SCOPE_SYSTEM);
	/*let the attributer is PTHREAD_CREATE_DETACHED 设置它的属性为分离，即线程结束后自动释放内存*/
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
	/*create a pthread1,and the pthread1's function is thread1*/
	ret = pthread_create(&id1, &attr, (void *) thread1, NULL);
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
	/*监测线程2是否退出，若推出，则释放它该线程所占用的资源。*/
	pthread_join(id2, NULL);	
	return 0;
}
