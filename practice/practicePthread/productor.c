#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <semaphore.h>
#include <sys/stat.h>
#include <pthread.h>
#include <fcntl.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

#define FIFO "/home/zhang/practice/practicePthread/myfifo1"
#define N 5

int lock_var;
time_t end_time;
char buf_r[100];
sem_t mutex, full, avail;
int fd;

void producter(void *arg);
void customer(void *arg);

int main(int argv, char **argc)
{
	pthread_t productor, consumer;
	pthread_t mon_th_id;
	int ret;
	end_time = time(NULL) + 30;
	if ((mkfifo(FIFO, O_CREAT | O_EXCL | 0666) < 0) && errno != EEXIST)
		printf("cannot create fifoserver\n");
	printf("Perparing for reading bytes...\n");
	fd = open(FIFO, O_RDWR | O_NONBLOCK, 0);
	if (fd == -1)
	{
		perror("open");
		exit(1);
	}
	ret = sem_init(&mutex, 0, 1);
	ret = sem_init(&avail, 0, N);
	ret = sem_init(&full, 0, 0);
	if (ret != 0)
		perror("sem_init");
	ret = pthread_create(&productor, NULL, (void *)producter, NULL);
	if (ret != 0)
		perror("pthread_createproductor");
	ret = pthread_create(&consumer, NULL, (void *)customer, NULL);
	if (ret != 0)
		perror("pthread_createconsumer");
	pthread_join(productor, NULL);
	pthread_join(consumer, NULL);
	exit(0);
}

void producter(void *arg)
{
	int i, nwrite;	
	while (time(NULL) < end_time)
	{
		//sem_wait(&avail);
		sem_wait(&mutex);
		if ((nwrite = write(fd, "hello", 5)) == -1)
		{
			if (errno ==EAGAIN)
				printf("The FIFO has not been read yet.Please try later\n");
		}
		else 
			printf("write hello to the FIFO\n");
		sem_post(&full);
		sem_post(&mutex);
		sleep(1);
	}
}

void customer(void *arg)
{
	int ret, nread;	
	while (time(NULL) < end_time)
	{
		sem_wait(&full);
		sem_wait(&mutex);
		memset(buf_r, 0, sizeof(buf_r));
		if ((nread = read(fd, buf_r, 100)) == -1)
		{
			if (errno == EAGAIN)
				printf("no data yet\n");
		}
		printf("read %s from FIFO\n", buf_r);
		//sem_post(&avail);
		sem_post(&mutex);
		sleep(1);
	}
}
