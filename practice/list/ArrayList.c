#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 1000
typedef int ElemType;
typedef int Status;
typedef struct
{
	ElemType data;
	int cur;
}Component, StaticLinkList[MAXSIZE];

Status InitList(StaticLinkList space)/*初始化一个静态数组列表*/
{
	int i;
	for (i = 0; i < MAXSIZE - 1; ++i)
		space[i].cur = i + 1;
	space[MAXSIZE - 1].cur = 0;/*首位相连，构成环形的静态的线性表*/
	return OK;
}

int Malloc_SLL(StaticLinkList space)/*模拟malloc动态分配内存，space[0].cur中记录着第一个可以被利用的空闲空间*/
{
	int i = space[0].cur;
	while (space[0].cur)
		space[0].cur = space[i].cur;
	return i;
}

Status ListInsert(StaticLinkList L, int i, ElemType e)/*在i-1 与 i 之间插入数据e*/
{
	int j, k, l;
	k = MAXSIZE - 1;
	if (i < 1 || i > ListLength(L) + 1)
		return ERROR;
	j = Malloc_SLL(L);
	if (j)
	{
		L[j].data = e;	
		for (l = 1; l <= i - 1; ++l)
			k = L[k].cur;
		L[j].cur = L[k].cur;
		L[k].cur = j;
		return OK;
	}
	return ERROR;
}

Status ListDelete (StaticLinkList L, int i)
{
	int j, k, i;
	if (i < 1 || i > ListLength(L))
		return ERROR;
	k = MAXSIZE - 1;/*因为L[MAXSIZE - 1].cur是指向头结点的*/
	for (j = 1; j <= i - 1; ++j)
		k = L[k].cur;
	j = L[k].cur;
	L[k].cur = L[j].cur;
	Free_SLL(L, j);
	return OK;
}

void Free_SLL(StaticLinkList L, int k)/*删除j这个节点*/
{
	space[k].cur = space[0].cur;/*头结点中记录的是当前空闲的空间，并方便利用*/
	space[0].cur = k;
}
void ListLength(StaticLinkList L)/*计算该静态链表长度*/
{
	int j = 0;
	int i = L[MAXSIZE - 1].cur;
	while (i)
	{
		i = L[i].cur;	
		++j;
	}
	return j;
}
