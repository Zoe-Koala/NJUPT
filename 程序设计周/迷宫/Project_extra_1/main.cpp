//#include <stdio.h>
//#include <malloc.h>
//#include <stdlib.h>
//#include <time.h>
//#include <math.h>
//
////函数状态码定义
//#define TRUE 1
//#define FALSE 0
//#define OK 1
//#define ERROR 0
//#define INFEASIBLE -1
//#define NULL 0
//
////墙或通路及前进方向符合定义
//#define WALL 0
//#define PATH 1
//#define RIGHT -1
//#define DOWN -2
//#define LEFT -3
//#define UP -4
//#define BACK -5
//#define DESTINATION -6
//
//typedef int MazeType[10][10];
//typedef int Status;
//typedef int ElemType;
//
////栈的定义和实现，采用顺序存储结构
//#define STACK_INIT_SIZE 100
//#define STACKINCREMENT 10
//typedef struct {
//	int x;
//	int y;
//}PosType;//迷宫中坐标的位置
//typedef struct {
//	int ord;
//	PosType seat;
//	int di;
//}SElemType;//栈中元素类型
//typedef struct {
//	SElemType* base;
//	SElemType* top;
//	int staticsize;
//}Stack;//栈类型
//Status InitStack(Stack& S) {
//	//构造空栈S
//	S.base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
//	if (!S.base) exit(OVERFLOW);
//	S.top = S.base;
//	S.staticsize = STACK_INIT_SIZE;
//	return OK;
//}
//Status Push(Stack& S, SElemType e) {
//	if (S.top - S.base >= S.staticsize)
//	{
//		S.base = (SElemType*)realloc(S.base, (S.staticsize + STACKINCREMENT) * sizeof(SElemType));
//		if (!S.base) exit(OVERFLOW);
//		S.top = (S.base + S.staticsize);
//		S.staticsize += STACK_INIT_SIZE;
//	}
//	*S.top++ = e;
//	return OK;
//}
//Status Pop(Stack& S, SElemType& e) {
//	if (S.top == S.base) return ERROR;
//	else
//		e = *(--S.top);
//	return OK;
//}
//Status GetTop(Stack S, SElemType& e) {
//	if (S.top == S.base) return ERROR;
//	e = *(S.top - 1);
//	return OK;
//}
//Status StackEmpty(Stack S) {
//	if (S.top == S.base) return TRUE;
//	else
//		return FALSE;
//}
//Status StackTraverse(Stack S, Status(*visit)(SElemType)) {
//	SElemType* p = S.base;
//	if (S.base == S.top) printf_s("空栈\n");
//	else
//		while (p < S.top) {
//			(*visit)(*p);
//			++p;
//		}
//	return OK;
//}
//Status PrintSElem(SElemType e) {
//	printf_s("step:%d to (%d,%d)\n", e.ord, e.seat.x, e.seat.y);
//	return OK;
//}
//
//
////迷宫求解具体算法
//Status MakeMaze(MazeType& maze) {
//	PosType m;
//	srand(time(NULL));
//	for (m.y = 0; m.y <= 9; m.y++) { maze[0][m.y] = WALL; maze[9][m.y] = WALL; }
//	for (m.x = 1; m.x <= 8; m.x++) { maze[m.x][0] = WALL; maze[m.x][9] = WALL; }
//	for (m.x = 1; m.x <= 8; m.x++)
//		for (m.y = 1; m.y <= 8; m.y++)
//			maze[m.x][m.y] = rand() % 2;
//	return OK;
//}
//
////■◎
//
//void PrintMaze(MazeType maze) {
//	int x, y;
//	for (x = 0; x <= 9; x++) {
//		for (y = 0; y <= 9; y++) {
//			switch (maze[x][y]) {
//			case WALL:printf_s("■"); break;
//			case PATH:printf_s(" "); break;
//			case RIGHT:printf_s("→"); break;
//			case DOWN:printf_s("↓"); break;
//			case LEFT:printf_s("←"); break;
//			case UP:printf_s("↑"); break;
//			case BACK:printf_s("@"); break;
//			case DESTINATION:printf_s("◎"); break;
//			default:printf_s("error\n"); exit(-1);
//			}
//		}
//		printf_s("\n");
//	}
//}
//
//PosType Nextpos(PosType position, ElemType direction) {
//	PosType result;
//	result = position;
//	switch (direction)
//	{
//	case 1:result.y++; break;
//	case 2:result.x++; break;
//	case 3:result.y--; break;
//	case 4:result.x--; break;
//	}
//	return result;
//}
//
//Status PassMaze(MazeType& maze, PosType start, PosType end, Stack& S) {
//	PosType curpos;
//	SElemType e;
//	int curstep = 1;
//	curpos = start;
//	if (maze[curpos.x][curpos.y] != PATH) {
//		printf_s("当前迷宫没有入口\n"); 
//		return FALSE; 
//	}
//	do {
//		if (maze[curpos.x][curpos.y] == PATH) {
//			e.ord = curstep;
//			e.seat = curpos;
//			e.di = 1;
//			Push(S, e);
//			if (curpos.x == end.x && curpos.y == end.y) {
//				maze[curpos.x][curpos.y] = DESTINATION;
//				return OK;
//			}
//			else {
//				maze[curpos.x][curpos.y] = RIGHT;
//				curpos = Nextpos(curpos, 1);
//				curstep++;
//			}
//		}
//		else {
//			GetTop(S, e);
//			while (!StackEmpty(S) && e.di == 4) {
//				maze[e.seat.x][e.seat.y] = BACK;
//				Pop(S, e);
//				curstep--;
//				if (StackEmpty(S)) break;
//				GetTop(S, e);
//			}
//			if (e.di < 4) {
//				Pop(S, e);
//				e.di++;
//				Push(S, e); maze[e.seat.x][e.seat.y] = -e.di;
//				curpos = Nextpos(e.seat, e.di);
//			}
//		}
//	} while (!StackEmpty(S));	
//	return FALSE;
//}
//
//
//int main()
//{
//	MazeType maze;
//	PosType start, end;
//	Stack S;
//	InitStack(S);
//	MakeMaze(maze);
//	printf_s("迷宫初始为：\n");
//	PrintMaze(maze);
//	printf_s("输入迷宫的入口位置坐标从(0,0)到(9,9)：");
//	scanf_s("%d %d", &start.x, &start.y);
//	printf_s("输入迷宫的出口位置坐标从(0,0)到(9,9)：");
//	scanf_s("%d %d", &end.x, &end.y);
//	if (PassMaze(maze, start, end, S)) {
//		printf_s("迷宫可通，路径踪迹如下：\n");
//		PrintMaze(maze);
//		printf_s("具体路径为：\n");
//		StackTraverse(S, PrintSElem);
//	}
//	else {
//		printf_s("迷宫不可通，路径总计如下：\n");
//		PrintMaze(maze);
//	}
//	return 0;
//}
//	
