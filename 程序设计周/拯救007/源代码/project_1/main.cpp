#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"
#include "Deque.h"
#include "error.h"

//��һ��case����һ��Graph��*Bank��¼��̵���Ӱ���·��
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
		for (i = 0; i < (num << 1); i++)  //һ�����������
			fscanf_s(InFile, "%d", &x);
		*Bank = 1;
	}
	else if (num > 0)    //007���뾭������ͷ�ϵ����
	{
		num += 2;
		G = GraphNew(num);
		for (i = 2; i < num; i++)   //������node��ʼ������
		{
			fscanf_s(InFile, "%d", &x);
			fscanf_s(InFile, "%d", &y);
			G[i].X = x;
			G[i].Y = y;
			if (CheckForStart(x, y, JamesJump))  //�ж��Ƿ������ϸõ�
			{
				G[i].Path = 1;  //007��������
				G[i].Step = 1;  //һ��
				if (CheckForEnd(x, y, JamesJump))//�ж��Ƿ�������
				{
					*Bank = i;//007��������
					Times = (num - i - 1) << 1;
					for (i = 0; i < Times; i++)  //���ؼ�����������
						fscanf_s(InFile, "%d", &y);
					DequeClear(D);
					break;
				}
				else
					Inject(i, D);  //����õ㣬����ʼ��һ�����
			}
		}
		while (!IsEmpty(D))  //ֻ����һ�������޷����������뻹Ҫ����������������
		{
			V = Pop(D);
			for (i = 2; i < num; i++)//����ֻ��������������������
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

//д������������·��
void write_result(FILE* OutFile, Vertex Bank, Graph G, Deque D)
{
	unsigned int Times, i;
	Vertex V;
	switch (Bank) {
	case 0:  //007�޷�����
		fprintf(OutFile, "%d\n", -1);
		break;
	case 1:   //007����ֱ������
		fprintf(OutFile, "%d\n", 1);
		break;
	default:
		Times = G[Bank].Step + 1;   //���Ĳ���
		while (Bank != 1)    //����·��
		{
			Push(Bank, D);
			Bank = G[Bank].Path;
		}
		fprintf(OutFile, "%d\n", Times);  //���
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
		G = read_case(in, VertexNum, &Bank, D);//���ļ�ֱ����β
		write_result(out, Bank, G, D);
		if (G)
			GraphDelete(G);
	}
	fclose(in);
	fclose(out);
	DequeDelete(D);
	return 0;
}