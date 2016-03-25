#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 1000
typedef int QElemType;
typedef int Status;
typedef struct
{
	QElemType data[MAXSIZE];
	int front;
	int rear;
}SqQueue;

Status InitQueue(SqQueue *Q)/*初始化队列*/
{
	 Q->front = 0;
	 Q->rear = 0;
	 return OK;
}

int QueueLength(SqQueue Q)/*计算队列长度*/
{
	return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}

Status DeQueue(SqQueue *Q, QElemType *e)/*出队列*/
{
	if (Q->front == Q->rear)
		return ERROR;
	*e = Q->data[Q->front];
	Q->front = (Q->front + 1) % MAXSIZE;

	return OK;
}

Status DeQueue(SqQueue *Q, QElemType e)/*入队列*/
{
	if ((Q->rear + 1) % MAXSIZE == Q->front)
		return ERROR;
	Q->data[Q->rear] = e;
	Q->rear = (Q->rear + 1) % MAXSIZE;
	return OK;
}
