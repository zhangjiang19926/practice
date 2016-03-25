#include <stdio.h>
#include <stdlib.h>
#define OVERFLOW -2
//定义二叉树节点
typedef struct Node
{
	 char ch;
	  struct Node *lchild,*rchild;
}Node,*BTree;
//Node *pRoot=NULL;
//输出二叉树函数
void PrintBinaryTree(Node *Tree)
{
	 if(Tree==NULL)
		     return;
	  
	   //printf("%c-->",Tree->ch);
	   PrintBinaryTree(Tree->lchild);
	     printf("%c-->",Tree->ch);
		   PrintBinaryTree(Tree->rchild);

}

//创建二叉树

Node* CreateTree(Node** pTree) 
{
	    char chr;
		    scanf("%c",&chr);
			    if(chr=='#')
					    {
							        (*pTree)=NULL;
									    }
				    else
						    {
								        if(!((*pTree)=(Node*)malloc(sizeof(Node))))
											        {
														            exit(OVERFLOW);
																	        }
										        (*pTree)->ch=chr;
												  CreateTree(&((*pTree)->lchild));//(*pTree)->lchild为Node *变量，而参数则是Node **变量，则需要&取址，否则形参无法保留*lchild值
												    CreateTree(&((*pTree)->rchild));
													    }
					return *pTree;
}

void main()
{
	 Node *treehead;
	  Node *test;
	   //Node  *bitree=NULL;
	   char ch;
	    printf("现在开始创建二叉树...输入N结束\n");
		   test=CreateTree(&treehead);
		    printf("所创建的二叉树为：\n");
			 PrintBinaryTree(test);
			  while(1);
}
