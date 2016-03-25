#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 1000
typedef int SElemType;
typedef int Status;
typedef struct 
{
	SElemType data[MAXSIZE];
	int top;
}SqStack;

Status Push(SqStack *S, SElemType e)/*入栈*/
{
	if (s->top == MAXSIZE - 1)/*是否已经满栈了*/
		return ERROR;	
	++s->top;
	s->data[s->top] = e;
	return OK;
}

Status Pop(SqStack *s, SElemType *e)/*出栈*/
{
	if (s->top == -1)/*出栈完毕*/
		return ERROR;	
	*e = s->data[s->top];
	--s->top;
	return OK;
}

/******************************************
*	共享栈的建立
*
*******************************************/
/*
typedef struct  
{
	SElemType data[MAXSIZE];
	int top1;
	int top2;
}SqDoubleStack;

Status Push(SqDoubleStack *s, SElemType e, int stackNumber)
{
	if (s->top1 + 1 == s->top2)
		return ERROR;
	if (stackNumber == 1)	
	{
		++s->top1;
		s->data[s->top1] = e;
	}	
	else if (stackNumber == 2)	
	{
		--s->top2;
		s->data[s->top2] = e;
	}	
	return OK;
}

Status Pop(SqDoubleStack *s, SElemType *e, int stackNumber)
{
	if (stackNumber == 1)
	{
		if (s->top1 == -1)	
			return ERROR;
		*e = s->data[s->top1];
		--s->top1;
	}
	else if (stackNumber == 2)
	{
		if (s->top2 == MAXSIZE)	
			return ERROR;
		*e = s->data[s->top2];
		++s->top2;
	}
	return OK;
}
*/
