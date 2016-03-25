#define OK 1
typedef int TElemType;
typedef int Status;
typedef enum {Link, Thread} PointerTag;
typedef struct BiThrNode
{
	TElemType data;
	struct BiThrNode *lchild, rchild;
	PointerTag LTag;
	PointerTag RTag;
}BiThrNode, *BiThrTree;

BiThrTree pre;
void InThreading (BiThrTree p)/*中序遍历进行终须线索化*/
{
	if (p)
	{
		InThreading(p->lchild);	
		if (!p->lchild)
		{
			p->LTag = Thread;	
			p->lchild = pre;
		}
		if (!pre->rchild)
		{
			pre->RTag = Thread;	
			pre->rchild = p;
		}
		pre = p;
		InThreading(p->rchild);	
	}
}

Status InOrderTraverse_Thr(BiThrTree T)/*中序遍历线索二叉树*/
{
	BiThrTree p;
	p = T->lchild;
	while (p != T)
	{
		while (p->LTag == Link)	
			p = p->lchild;
		printf("%c", p->data);
		while (p->RTag && p->rchild != T)
		{
			p = p->rchild;	
			printf("%c", p->data);
		}
		p = p->rchild;
	}
	return OK;
}
