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

Status GetElem(SqList L, int i, ElemType *e)/*获取i位置上的数据并返回给e*/
{
	if (L.lenth == 0 || i < 1 || i > L.Length)
		return 0;
	*e = L.data[i - 1];
	return OK;
}
