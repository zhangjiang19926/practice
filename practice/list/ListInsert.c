#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20
typedef int Status;
typedef int ElemType;
typedef struct 
{
	ElemType data[MAXSIZE];
	int length;
}SqList;

Status ListInsert(SqList *L, int i, ElemType e)/*将元素插入线性表*/
{
	int k;
	if (L -> length == MAXSIZE)
		return ERROR;
	if (i < 1 || i > length + 1)
		return ERROR;
	if (i < L->Length)
	{
		for (k = L->Length - 1; k >= i - 1; --k)	
			data[k + 1] = data[k];
	}
	L->data[i - 1] == e;
	++L->Length;
	return OK;
}
