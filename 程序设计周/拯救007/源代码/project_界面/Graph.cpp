#include "Graph.h"
#include <stdlib.h>
#include "error.h"

//创建新的Graph
Graph GraphNew(int NodeNum) 
{
	Graph G;
	int i;
	if (NodeNum <= 0)
		return NULL;
	G = (Graph)malloc(NodeNum * sizeof(GraphNode));   //分配空间
	CHECK(G);
	for (i = 0; i < NodeNum; i++)                            //初始化
	{
		G[i].X = 0;
		G[i].Y = 0;
		G[i].Step = INFINITY;
		G[i].Path = 0;
	}
	return G;
}


//删除一个Graph
void GraphDelete(Graph G)
{
	if (G)
		free(G);
}

//判断007是否能从起点跳至该点(x,y)，步长是d
int CheckForStart(int x, int y, Distance d)
{
	double t;
	//x^2+y^2<=(ISLAND_DIAMETER/2.0+d)^2
	t = (ISLAND_DIAMETER + (d * 2.0));
	return (x * x + y * y) <= t * t / 4.0;
}

//判断007能否从该点跳至河岸，步长是d
int CheckForEnd(int x, int y, Distance d)
{
	if (x < 0)
		x = -x;
	if (y < 0)
		y = -y;
	//因为湖是正方形，只需要检查这两距离
	return (d >= LAKE_BOUNDARY_X - x) || (d >= LAKE_BOUNDARY_Y - y);
}

//判断007能否从点i跳至点j，步长是d
int CheckForConnect(Graph g, Vertex i, Vertex j, Distance d)
{
	int x, y;
	x = g[i].X - g[j].X;
	y = g[i].Y - g[j].Y;
	return x * x + y * y <= d * d;
}