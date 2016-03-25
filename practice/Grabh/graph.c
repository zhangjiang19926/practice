#include <stdio.h>

#define MAXVEX 100
#define INFINITY 65535
/*利用邻接矩阵产生的图*/
typedef char VertexType; 
typedef int EdgeType;
typedef struct/*定义图的结构体*/ 
{
	VertexType vexs[MAXVEX];
	EdgeType arc[MAXVEX][MAXVEX];
	int numVertexes, numEdges;
}MGraph;

void CreareMGraph(MGraph *G)/*创建一个有向图*/
{
	int i, j, k, w;
	printf("请输入顶点数和边数：\n");
	scanf("%d%d", &G->numVertexes, &G->numEdges);
	for(i = 0; i < G->numVertexes; ++i)
		scanf("%c", &G->vexs[i]);	
	for (i = 0; i < G->numVertexes; ++i)
		for (j = 0; j < G->numVertexes; ++j)
			G->arc[i][j] = INFINITY;
	for (k = 0; k < G->numEdges; ++k)
	{
		printf("输入边(vi, vj)下标i, 下标j和权w:\n");	
		scanf("%d%d%d", &i, &j, &w);
		G->arc[i][j] = w;
		G->arc[j][i] = G->arc[i][j];
	}
}
/*利用邻接表产生图*/
typedef struct EdgeNode 
{
	int adjvex;
	EdgeType weight;
	struct EdgeNode *next;
}EdgeNode;

typedef struct VertexNode
{
	VertexType data;/*存储顶点的数据信息*/
	EdgeNode *firstedge;
}VertexNode, AdjList[MAXVEX];

typedef struct 
{
	AdjList adjList;
	int numVertexes, numEdges;
}GraphAdjList;

void CreateALGraph (GraphAdjList *G)/*创建一个无向图，使用的是邻接表的方法*/
{
	int i, j, k;
	EdgeNode *e;
	printf("请输入顶点和边数：\n");
	scanf("%d%d", &G->numVertexes, &G->numEdges);
	for(i = 0; i < G->numVertexes; ++i)
	{
		scanf("%c", &G->adjList[i].data);	
		G->adjList[i].firstedge = NULL;
	}
	for(k = 0; k < G->numEdges; ++k)
	{
		printf("输入边(Vi, Vj)上的顶点序号：\n");	
		scanf("%d%d", &i, &j);
		e = (EdgeNode *)malloc(sizeof(EdgeNode));
		e->adjvex = j;
		e->next = G->adjList[i].firstedge;
		G->adjList[i].firstedge = e;
		e = (EdgeNode *)malloc(sizeof(EdgeNode));
		e->adjvex = i;
		e->next = G->adjList[j].firstedge;
		G->adjList[j].firstedge = e;
	}
}
