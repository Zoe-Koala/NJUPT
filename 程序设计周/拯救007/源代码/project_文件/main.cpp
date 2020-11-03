#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"
#include "Deque.h"
#include "error.h"

//读一个case返回一个Graph，*Bank记录最短到达河岸的路径
Graph read_case(FILE* InFile, int num, Vertex* Bank, Deque D)
{
	Graph G = NULL;
	Distance JamesJump;
	Vertex V;
	int x, y;
	int i, Times;
	*Bank = 0;
	fscanf_s(InFile, "%lf", &JamesJump);
	if (CheckForEnd(0, 0, JamesJump + ISLAND_DIAMETER / 2.0))
	{
		for (i = 0; i < (num << 1); i++)  //一步跳出的情况
			fscanf_s(InFile, "%d", &x);
		*Bank = 1;
	}
	else if (num > 0)    //007必须经过鳄鱼头上的情况
	{
		num += 2;
		G = GraphNew(num);
		for (i = 2; i < num; i++)   //第三个node开始是鳄鱼
		{
			fscanf_s(InFile, "%d", &x);
			fscanf_s(InFile, "%d", &y);
			G[i].X = x;
			G[i].Y = y;
			if (CheckForStart(x, y, JamesJump))  //判断是否能跳上该点
			{
				G[i].Path = 1;  //007可以跳到
				G[i].Step = 1;  //一步
				if (CheckForEnd(x, y, JamesJump))//判断是否能跳出
				{
					*Bank = i;//007可以跳出
					Times = (num - i - 1) << 1;
					for (i = 0; i < Times; i++)  //不必检验其他鳄鱼
						fscanf_s(InFile, "%d", &y);
					DequeClear(D);
					break;
				}
				else
					Inject(i, D);  //插入该点，并开始下一个检测
			}
		}
		while (!IsEmpty(D))  //只经过一个鳄鱼无法跳出，必须还要跳到其他鳄鱼的情况
		{
			V = Pop(D);
			for (i = 2; i < num; i++)//从这只鳄鱼跳到其他各个鳄鱼
			{
				if ((G[i].Step > G[V].Step + 1) && CheckForConnect(G, V, i, JamesJump))
				{
					G[i].Path = V;
					G[i].Step = G[V].Step + 1;
					if ((G[i].Step < G[*Bank].Step) && CheckForEnd(G[i].X, G[i].Y, JamesJump))
						*Bank = i;
					else
						Inject(i, D);
				}
			}
		}
	}
	return G;
}

//写出结果，即最短路径
void write_result(FILE* OutFile, Vertex Bank, Graph G, Deque D)
{
	unsigned int Times, i;
	Vertex V;
	switch (Bank) {
	case 0:  //007无法跳出
		fprintf(OutFile, "%d\n", -1);
		break;
	case 1:   //007可以直接跳出
		fprintf(OutFile, "%d\n", 1);
		break;
	default:
		Times = G[Bank].Step + 1;   //跳的步数
		while (Bank != 1)    //跟踪路径
		{
			Push(Bank, D);
			Bank = G[Bank].Path;
		}
		fprintf(OutFile, "%d\n", Times);  //输出
		for (i = 1; i < Times; i++)
		{
			V = Pop(D);
			fprintf_s(OutFile, "%d ", G[V].X);
			fprintf_s(OutFile, "%d\n", G[V].Y);
		}
	}	
}






int main(int argc,char *argv[])
{
	FILE* in, * out;
	Deque D;
	int VertexNum;
	Graph G = NULL;
	Vertex Bank = 0;
	fopen_s(&in, "input.txt", "r");
	if (NULL == in)
	{
		fprintf(stderr, "Can not open input.txt");
		exit(-1);
	}
	fopen_s(&out, "output.txt", "w");
	if (NULL == out)
	{
		fprintf(stderr, "Can not open output.txt");
		fclose(in);
		exit(-1);
	}
	D = DequeNew();
	while ((EOF != fscanf_s(in, "%d", &VertexNum)) && (0 <= VertexNum))
	{
		G = read_case(in, VertexNum, &Bank, D);//读文件直到结尾
		write_result(out, Bank, G, D);
		if (G)
			GraphDelete(G);
	}
	fclose(in);
	fclose(out);
	DequeDelete(D);
	return 0;
}