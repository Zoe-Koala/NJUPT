#include "Graph.h"
#include <stdlib.h>
#include "error.h"

//�����µ�Graph
Graph GraphNew(int NodeNum) 
{
	Graph G;
	int i;
	if (NodeNum <= 0)
		return NULL;
	G = (Graph)malloc(NodeNum * sizeof(GraphNode));   //����ռ�
	CHECK(G);
	for (i = 0; i < NodeNum; i++)                            //��ʼ��
	{
		G[i].X = 0;
		G[i].Y = 0;
		G[i].Step = INFINITY;
		G[i].Path = 0;
	}
	return G;
}


//ɾ��һ��Graph
void GraphDelete(Graph G)
{
	if (G)
		free(G);
}

//�ж�007�Ƿ��ܴ���������õ�(x,y)��������d
int CheckForStart(int x, int y, Distance d)
{
	double t;
	//x^2+y^2<=(ISLAND_DIAMETER/2.0+d)^2
	t = (ISLAND_DIAMETER + (d * 2.0));
	return (x * x + y * y) <= t * t / 4.0;
}

//�ж�007�ܷ�Ӹõ������Ӱ���������d
int CheckForEnd(int x, int y, Distance d)
{
	if (x < 0)
		x = -x;
	if (y < 0)
		y = -y;
	//��Ϊ���������Σ�ֻ��Ҫ�����������
	return (d >= LAKE_BOUNDARY_X - x) || (d >= LAKE_BOUNDARY_Y - y);
}

//�ж�007�ܷ�ӵ�i������j��������d
int CheckForConnect(Graph g, Vertex i, Vertex j, Distance d)
{
	int x, y;
	x = g[i].X - g[j].X;
	y = g[i].Y - g[j].Y;
	return x * x + y * y <= d * d;
}