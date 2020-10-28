#ifndef _GRAPH_H_
#define _GRAPH_H_
#define ISLAND_DIAMETER 15  //С����ֱ��
#define LAKE_BOUNDARY_X 50  //С�������ߵľ��룬��X����
#define LAKE_BOUNDARY_Y 50  //С�������ߵľ��룬��Y����
#define INFINITY 10000      //�������������

typedef unsigned int Vertex;
typedef double Distance;

typedef struct GraphNodeRecord {
	int X;                  //X������
	int Y;                  //Y������
	unsigned int Step;      //�����õ�Ĳ���
	Vertex Path;            //��¼��һ����
}GraphNode;
typedef GraphNode *Graph;

Graph GraphNew(int NodeNum);
void GraphDelete(Graph G);

//�ж�007�Ƿ��ܴ���������õ�(x,y)
int CheckForStart(int x, int y, Distance d);

//�ж�007�ܷ�Ӹõ������Ӱ�
int CheckForEnd(int x, int y, Distance d);

//�ж�007�ܷ�ӵ�i������j
int CheckForConnect(Graph g, Vertex i, Vertex j, Distance d);

#endif // !_GRAPH_H_
