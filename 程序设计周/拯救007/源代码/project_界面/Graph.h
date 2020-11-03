#ifndef _GRAPH_H_
#define _GRAPH_H_
#define ISLAND_DIAMETER 15  //小岛的直径
#define LAKE_BOUNDARY_X 50  //小岛到湖边的距离，在X轴上
#define LAKE_BOUNDARY_Y 50  //小岛到湖边的距离，在Y轴上
#define INFINITY 10000      //可以跳的最大步数

typedef unsigned int Vertex;
typedef double Distance;

typedef struct GraphNodeRecord {
	int X;                  //X轴坐标
	int Y;                  //Y轴坐标
	unsigned int Step;      //跳至该点的步数
	Vertex Path;            //记录上一个点
}GraphNode;
typedef GraphNode *Graph;

Graph GraphNew(int NodeNum);
void GraphDelete(Graph G);

//判断007是否能从起点跳至该点(x,y)
int CheckForStart(int x, int y, Distance d);

//判断007能否从该点跳至河岸
int CheckForEnd(int x, int y, Distance d);

//判断007能否从点i跳至点j
int CheckForConnect(Graph g, Vertex i, Vertex j, Distance d);

#endif // !_GRAPH_H_
