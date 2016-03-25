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

Status ListDelete(SqList *L, int i, ElemType *e)/*将第i个元素删除，并将删除的那个元素放在e中*/
{
	int k;
	if (L->length == 0)
		return ERROR;
	if (i < 1 || i > L->length)
		return ERROR;
	*e = L->data[i - 1];
	if (i < L->length)
	{
		for (k = i; k <= length; ++k)	
			data[k - 1] = data[k];
	}
	--L->length;
	return OK;
}
