#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int ElemType;
typedef struct Node
{
	ElemType data;
	struct Node *next;
}Node;
typedef struct Node *LinkList;
typedef int Status;

Status GetElem(LinkList L, int i, ElemType *e)/*获取线性链表中第i个元素的数据，并放入e中*/
{
	int j;
	LinkList p;
	p = L->next;
	j = 1;
	while (p && j < i)
	{
		p = p->next;	
		++j;
	}
	if (!p || j > i)
		return ERROR;
	*e = p->data;
	return OK;
}

Status ListInsert(LinkList *L, int i, ElemType e)/*插入数据到该链表的第i个节点后*/
{
	int j;
	LinkList p, s;
	p = *L;
	j = 1;
	while (p && j < i)
	{
		p = p->next;	
		++j;
	}
	if (!p || j > i)
		return ERROR;
	s = (LinkList)malloc(sizeof(Node));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}

Status ListDelete(LinkList *L, int i, ElemType *e)/*将该链表的第i个元素删除，并将删除的数据通过e返回*/
{
	int j;
	LinkList p, q;
	p = *L;
	j = 1;
	while (p->next && j < i)
	{
		p = p->next;	
		++j;
	}
	if (!(p->next) || j > i)
		return ERROR;
	q = p->next;
	p->next = q->next;
	*e = q->data;
	free(q);
	return OK;
}

void CreateListHead(LinkList *L, int n)/*创建有头结点的链表（头插法）*/
{
	LinkList p;
	int i;
	srand(time(0));
	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;
	for (i = 0; i < n; ++i)
	{
		p = (LinkList)malloc(sizeof(Node));
		p->data = rand()%100 + 1;
		p->next = (*L)->next;
		(*L)->next = p;
	}
}

void CreateListTail(LinkList *L, int n)/*从尾巴上插入数值*/
{
	LinkList p, r;
	int i;
	srand(time(0));
	*L = (LinkList)malloc(sizeof(Node));
	r = *L;
	for (i = 0; i < n; i++)
	{
		p = (LinkList)malloc(sizeof(Node));	
		p->data = rand()%100 + 1;
		r->next = p;
		r = p;
	}
	r->next = NULL;
}

Status ClearList(LinkList *L)/*将该链表整体删除*/
{
	LinkList p, q;
	p = (*L)->next;
	while (p)
	{
		q = p->next;	
		free(p);
		p = q;
	}
	(*L)->next = NULL;
	return OK;
}
