#include <easyx.h>			// ����ͼ�ο�ͷ�ļ�
#include <conio.h>
#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"
#include "Deque.h"
#include "error.h"
#define width 760
#define height 600
#define step_length 20

Graph read_case(FILE* InFile, int num, Vertex* Bank, Deque D);
void write_result(FILE* OutFile, Vertex Bank, Graph G, Deque D);

int main()
{
	int count = 0;
	initgraph(width, height);	// ������ͼ���ڣ���СΪ 760x600 ����
	// ���ñ���ɫΪ��ɫ
	setbkcolor(BLUE);
	// �ñ���ɫ�����Ļ
	cleardevice();
	rectangle((width/2-250), (height/2-250), (width / 2 + 250), (height / 2 + 250));//�����棬100*100�ķŴ��屶
	solidcircle(width/2, height/2, 37.5);	// ��Բ��Բ��
	//��������
	for (int i = 1; i <= 25; i++)
	{
		DWORD a[4] = { 5, 15, 3, 8 };
		setlinestyle(PS_USERSTYLE | PS_ENDCAP_FLAT, 1, a, 4);
		line((width / 2 - 250), (height / 2 - 250) + 20 * i, (width / 2 + 250), (height / 2 - 250) + 20 * i);
		line((width / 2 - 250) + 20 * i, (height / 2 - 250), (width / 2 - 250) + 20 * i, (height / 2 + 250));
	}

	MOUSEMSG m;		// ���������Ϣ
	FILE* in, * out;
	fopen_s(&in, "input.txt", "w+");
	if (NULL == in)
	{
		fprintf(stderr, "Can not open input.txt");
		exit(-1);
	}
	fprintf(in, "11111 11111\n");
	//fprintf(in, "1 2\n");
	while (true)
	{
		// ��ȡһ�������Ϣ
		m = GetMouseMsg();

		switch (m.uMsg)
		{
		case WM_MOUSEMOVE:
			// ����ƶ���ʱ�򻭺�ɫ��С��
			//putpixel(m.x, m.y, RED);
			break;

		case WM_LBUTTONDOWN:
			// ����������ͬʱ������ Ctrl ��
			if (m.mkCtrl)
			{
				if (m.x >= width / 2 + 250 || m.x <= width / 2 - 250 || m.y <= height / 2 - 250 || m.y >= height / 2 + 250)
					break;
				// ��һ���󷽿�
				else
					fprintf(in, "%5d %5d\n", (m.x - width / 2) / 5, (height / 2 - m.y) / 5);
				fillcircle(m.x, m.y, 5);
				count++;
			}
			else
				break;
				// ��һ��С����
				//fillcircle(m.x, m.y, 2);
			break;

		case WM_RBUTTONUP:
			rewind(in);
			fprintf(in, "%5d ", count);	
			fprintf(in, "%5d", step_length);
			fclose(in);
			int VertexNum;
			Deque D;
			Graph G = NULL;
			Vertex Bank = 0;
			D = DequeNew();
			fopen_s(&in, "input.txt", "r");
			if (NULL == in)
			{
				fprintf(stderr, "Can not open input.txt");
				exit(-1);
			}
			fopen_s(&out, "output.txt", "w+");
			if (NULL == out)
			{
				fprintf(stderr, "Can not open output.txt");
				fclose(in);
				exit(-1);
			}
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
			/************************************************************/
			int Times, i, x, y;
			fopen_s(&out, "output.txt", "r");
			if (NULL == out)
			{
				fprintf(stderr, "Can not open output.txt");
				exit(-1);
			}
			fscanf_s(out, "%d", &Times);
			if (Times == -1)
			{
				printf_s("can not jump to the side!!!\n");
			}
			else if (Times == 1)
			{
				printf_s("can jump to the side without the help of crocodile!!!\n");
			}
			else if (Times > 1)
			{
				printf_s("can jump to the side with the help of crocodile!!!\n");
				int position[100][2] = { 0 };
				for (i = 1; i < Times; i++)
				{
					fscanf_s(out, "%d", &x);
					fscanf_s(out, "%d", &y);
					printf_s("��%d����������Ϊ(%d, %d)��\n", i, x, y);
					position[i - 1][0] = x;
					position[i - 1][1] = y;
					setfillcolor(BLACK);
					solidcircle(x * 5 + width / 2, (-y) * 5 + height / 2, 8);//��·������������
				}
				setlinecolor(BLACK);
				setlinestyle(PS_DASH | PS_ENDCAP_FLAT, 3);
				line(width / 2, height / 2, position[0][0] * 5 + width / 2, position[0][1] * (-5) + height / 2);
				if ((position[Times - 2][1] < 0) && (height / 2 + 250 - (-position[Times - 2][1] * 5 + height / 2) <= step_length))//x�·�
					line(position[Times - 2][0] * 5 + width / 2, -position[Times - 2][1] * 5 + height / 2, position[Times - 2][0] * 5 + width / 2, height / 2 + 250);
				else if ((position[Times - 2][1] >= 0) && ((-position[Times - 2][1] * 5 + height / 2) - (height / 2 - 250) <= step_length))//x�Ϸ�
					line(position[Times - 2][0] * 5 + width / 2, -position[Times - 2][1] * 5 + height / 2, position[Times - 2][0] * 5 + width / 2, height / 2 - 250);
				else if ((position[Times - 2][0] >= 0) && (width / 2 + 250 - (position[Times - 2][0] * 5 + width / 2) <= step_length))//y�ҷ�
					line(position[Times - 2][0] * 5 + width / 2, -position[Times - 2][1] * 5 + height / 2, width / 2 + 250, -position[Times - 2][1] * 5 + height / 2);
				else if ((position[Times - 2][0] < 0) && ((position[Times - 2][0] * 5 + width / 2) - (width / 2 - 250)) <= step_length)//y��
				    line(position[Times - 2][0] * 5 + width / 2, -position[Times - 2][1] * 5 + height / 2, width / 2 - 250, -position[Times - 2][1] * 5 + height / 2);

				/*if (i == Times - 1)
				{
					if (height / 2 + 250 - (-y * 5 + height / 2) <= step_length)
						line(x * 5 + width / 2, -y * 5 + height / 2, x * 5 + width / 2, height / 2 + 250);
					else if ((-y * 5 + height / 2) - (height / 2 - 250) <= step_length)
						line(x * 5 + width / 2, -y * 5 + height / 2, x * 5 + width / 2, height / 2 - 250);
					else if (width / 2 + 250 - (x * 5 + width / 2) <= step_length)
						line(x * 5 + width / 2, -y * 5 + height / 2, width / 2 + 250, -y * 5 + height / 2);
					else if ((x * 5 + width / 2) - (-y * 5 + height / 2) <= step_length)
						line(x * 5 + width / 2, -y * 5 + height / 2, width / 2 - 250, -y * 5 + height / 2);
				}*/
			}
			fclose(out);
			getchar();
			/**************************************************************/
			closegraph();			// �رջ�ͼ����
			_getch();				// �����������
			return 0;	// ������Ҽ��˳�����
		}
	}
}


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
		fprintf(OutFile, "%5d\n", -1);
		break;
	case 1:   //007����ֱ������
		fprintf(OutFile, "%5d\n", 1);
		break;
	default:
		Times = G[Bank].Step + 1;   //���Ĳ���
		while (Bank != 1)    //����·��
		{
			Push(Bank, D);
			Bank = G[Bank].Path;
		}
		fprintf(OutFile, "%5d\n", Times);  //���
		for (i = 1; i < Times; i++)
		{
			V = Pop(D);
			fprintf_s(OutFile, "%5d ", G[V].X);
			fprintf_s(OutFile, "%5d\n", G[V].Y);
		}
	}
}