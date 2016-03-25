#include <stdio.h>

#define MAXVEX 9
#define INFINITY 65535
typedef char VertexType; 
typedef int EdgeType;
typedef int Pathmatirx[MAXVEX];
typedef int ShorPathTable[MAXVEX];

typedef struct/*定义图的结构体*/ 
{
	VertexType vexs[MAXVEX];
	EdgeType arc[MAXVEX][MAXVEX];
	int numVertexes, numEdges;
}MGraph;
/*********************************************************************************
*	1.选择第一个节点开始寻找离它最近的节点，并记录下这个节点的节点号和它们的和；
*	2.从第二个节点开始继续寻找与它相连接的节点，并将与之相连的几个节点的边的权
*	  与之前记录离第一个节点最近的节点间的权值相加，并比较它们这几个权值相加之
*	  后的和，寻找最小的那一个记录节点号与权值和；
*	3.重复一二两步，直到到达终点。
 *********************************************************************************/
void ShortestPath_Dijkstra(MGraph G, int v0, Pathmatirx *P, ShorPathTable *D)
{
	int v, w, k, min;
	int final[MAXVEX];
	for (v = 0; v < G.numVertexes; ++v)
	{
		(*D)[v]	= G.arc[v0][v];
		(*P)[v] = 0;
	}
	(*D)[v0] = 0;
	final[v0] = 1;
	for (v = 1; v < G.numVertexes; ++v)
	{
		min = INFINITY;	
		for (w = 1; w < G.numVertexes; ++w)
		{
			if (!final[w] && (*D)[w] < min)	
			{
				k = w;	
				min = (*D)[w];
			}
		}
		final[k] = 1;
		for (w = 0; w < G.numVertexes; ++w)
		{
			if (!final[w] && (min + G.arc[k][w] < (*D)[w]))	
			{
				(*D)[w]	= min + G.arc[k][w];
				(*P)[w] = k;
			}
		}
	}
}
