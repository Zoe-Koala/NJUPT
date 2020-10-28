#include <easyx.h>			// 引用图形库头文件
#include <conio.h>
#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"
#include "Deque.h"
#include "error.h"
#define width 760
#define height 600
#define step_length 15

Graph read_case(FILE* InFile, int num, Vertex* Bank, Deque D);
void write_result(FILE* OutFile, Vertex Bank, Graph G, Deque D);

int main()
{
	int count = 0;
	initgraph(width, height);	// 创建绘图窗口，大小为 760x600 像素
	// 设置背景色为蓝色
	setbkcolor(BLUE);
	// 用背景色清空屏幕
	cleardevice();
	rectangle((width/2-250), (height/2-250), (width / 2 + 250), (height / 2 + 250));//画湖面，100*100的放大五倍
	solidcircle(width/2, height/2, 37.5);	// 画圆，圆心
	//画网格线
	for (int i = 1; i <= 25; i++)
	{
		line((width / 2 - 250), (height / 2 - 250) + 20 * i, (width / 2 + 250), (height / 2 - 250) + 20 * i);
		line((width / 2 - 250) + 20 * i, (height / 2 - 250), (width / 2 - 250) + 20 * i, (height / 2 + 250));
	}

	MOUSEMSG m;		// 定义鼠标消息
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
		// 获取一条鼠标消息
		m = GetMouseMsg();

		switch (m.uMsg)
		{
		case WM_MOUSEMOVE:
			// 鼠标移动的时候画红色的小点
			putpixel(m.x, m.y, RED);
			break;

		case WM_LBUTTONDOWN:
			// 如果点左键的同时按下了 Ctrl 键
			if (m.mkCtrl)
			{
				// 画一个大方块
				if (m.x >= width / 2 && m.y >= height / 2)
					fprintf(in, "%5d %5d\n", (m.x - width / 2) / 5, (m.y - height / 2) / 5);
				else if(m.x > width / 2 && m.y < height / 2)
					fprintf(in, "%5d %5d\n", (m.x - width / 2) / 5, (height / 2 - m.y) / 5);
				else if(m.x <= width / 2 && m.y >= height / 2)
					fprintf(in, "%5d %5d\n", (m.x - width / 2) / 5, (m.y - height / 2) / 5);
				else if (m.x < width / 2 && m.y < height / 2)
					fprintf(in, "%5d %5d\n", (m.x - width / 2) / 5, (height / 2 - m.y) / 5);


				//fprintf(in, "%5d %5d\n", (m.x - (width / 2 - 250)) / 5, (m.y - (height / 2 - 250)) / 5);
				fillrectangle(m.x - 10, m.y - 10, m.x + 10, m.y + 10);
				count++;
			}
			else
				// 画一个小方块
				fillrectangle(m.x - 5, m.y - 5, m.x + 5, m.y + 5);
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
				G = read_case(in, VertexNum, &Bank, D);//读文件直到结尾
				write_result(out, Bank, G, D);
				if (G)
					GraphDelete(G);
			}
			fclose(in);
			fclose(out);
			DequeDelete(D);

			fopen_s(&out, "output.txt", "r");
			if (NULL == out)
			{
				fprintf(stderr, "Can not open output.txt");
				exit(-1);
			}


			closegraph();			// 关闭绘图窗口
			_getch();				// 按任意键继续
			return 0;	// 按鼠标右键退出程序
		}
	}
}


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
		fprintf(OutFile, "%5d\n", -1);
		break;
	case 1:   //007可以直接跳出
		fprintf(OutFile, "%5d\n", 1);
		break;
	default:
		Times = G[Bank].Step + 1;   //跳的步数
		while (Bank != 1)    //跟踪路径
		{
			Push(Bank, D);
			Bank = G[Bank].Path;
		}
		fprintf(OutFile, "%5d\n", Times);  //输出
		for (i = 1; i < Times; i++)
		{
			V = Pop(D);
			fprintf_s(OutFile, "%5d ", G[V].X);
			fprintf_s(OutFile, "%5d\n", G[V].Y);
		}
	}
}