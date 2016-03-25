#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 1000
typedef int SElemType;
typedef int Status;
typedef struct StackNode
{
	SElemType data;
	struct StackNode *next;
}StackNode, *LinkStackPtr;

typedef struct LinkStack
{
	LinkStackPtr top;
	int count;
}LinkStack;

Status Push (LinkStack *S, SElemType e)/*压栈操作*/
{
	LinkStackPtr p = (LinkStackPtr)malloc(sizeof(StackNode));
	p->data = e;
	p->next = S->top; 
	S->top = p;
	++S->count;
	return OK;
}

Status Pop(LinkStack *S, SElemType *e)/*出栈*/
{
	LinkStackPtr p;
	if (StackEmpty(*S))
	*e = S->top->data;
	p = S->top;
	S->top = S->top->next;	
	free(p);
	--S->count;
	return OK;
}
