#include <stdio.h>
#include <stdlib.h>
/*双亲表示法来表示一株树*/
#define MAX_TREE_SIZE 100
#define OVERFLOW -1
typedef char TElemType;

typedef struct PTNode
{
	TElemType data;
	int parent;
}PTNode;

//typedef struct
//{
	//PTNode nodes[MAX_TREE_SIZE];
	//int r, n; /*根的位置和节点数*/
//}PTree;
//
///*孩子表示法来表示一株树*/
//typedef struct CTNode
//{
	//int child;
	//struct CTNode *next;
//}*ChildPtr;
//typedef struct
//{
	//TElemType data;
	//ChildPtr firstchild;
//}CTBox;
//typedef struct
//{
	//CTBox nodes[MAX_TREE_SIZE];
	//int r, n; /*根的位置和节点数*/
//}CTree;
/*二叉树的存储结构*/
typedef struct BiTNode
{
	TElemType data;
	struct BiTNode *Lchild, *Rchild;
}BiTNode, *BiTree;

/*前序遍历算法*/
//void PreOrderTraverse(BiTtree T)
//{
	//if (T == NULL)
		//return;
	//printf("%c", T->data);
	//PreOrderTraverse(T->Lchild);
	//PreOrderTraverse(T->Rchild);
//}
///*中序遍历算法*/
//void InOrderTraverse(BiTtree T)
//{
	//if (T == NULL)
		//return;
	//InOrderTraverse(T->Lchild);
	//printf("%c", T->data);
	//InOrderTraverse(T->Rchild);
//}
int index1 = 0;
/*后序遍历算法*/
void PostOrderTraverse(BiTree T)
{
	if (T == NULL)
		return;
	PostOrderTraverse(T->Lchild);
	PostOrderTraverse(T->Rchild);
	printf("%c\n", T->data);
}
/*生成二叉树*/
char str[] = {"ABDH#K###E##CFI###G#J##"};
void CreateBiTree(BiTree *T)
{ 
	TElemType ch;
	/* scanf("%c",&ch); */
	ch = str[index1++];
	if(ch=='#') 
		*T=NULL;
	else
	{
		*T=(BiTree)malloc(sizeof(BiTNode));
		if(!*T)
			exit(OVERFLOW);
		(*T)->data=ch; /* 生成根结点 */
		CreateBiTree(&(*T)->Lchild); /* 构造左子树 */
		CreateBiTree(&(*T)->Rchild); /* 构造右子树 */
	}
}
int main (int argc, char **argv)
{
	BiTree T;
	CreateBiTree(&T);
	PostOrderTraverse(T);
	return 0;
}
