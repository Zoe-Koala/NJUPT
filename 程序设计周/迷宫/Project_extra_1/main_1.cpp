#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

//函数状态码定义
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define NULL 0

//墙或通路及前进方向符合定义
#define WALL 0//当前格子是墙
#define PATH 1//当前是通路且未走过
#define RIGHT -1//代表是通路且从其向右走
#define DOWN -2//代表是通路且从其向下走
#define LEFT -3//代表是通路且从其向左走
#define UP -4//代表是通路且从其向上走
#define BACK -5//代表是通路且从其后退一步
#define DESTINATION -6//代表当前格子是通路且是目标位置

#define M 30
#define N 30
typedef int MazeType[M + 2][N + 2];//最外遭初始化墙，实际含(M-2)(N-2)个格子
typedef int Status;
typedef int ElemType;//迷宫数组中的元素类型

//栈的定义和实现，采用顺序存储结构
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
typedef struct {
	int x;
	int y;
}PosType;//迷宫中坐标的位置

typedef struct {
	int ord;
	PosType seat;
	int di;
}SElemType;//栈中元素类型

typedef struct {
	SElemType* base;
	SElemType* top;
	int staticsize;
}Stack;//栈类型

Status InitStack(Stack& S) {
	//构造空栈S
	S.base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!S.base) exit(OVERFLOW);//存储分配失败
	S.top = S.base;//空栈
	S.staticsize = STACK_INIT_SIZE;
	return OK;
}//初始化栈
Status Push(Stack& S, SElemType e) {
	//插入e为栈顶元素
	if (S.top - S.base >= S.staticsize)//栈满则重新分配空间
	{
		S.base = (SElemType*)realloc(S.base, (S.staticsize + STACKINCREMENT) * sizeof(SElemType));
		if (!S.base) exit(OVERFLOW);
		S.top = (S.base + S.staticsize);//使得S.top重新指向原栈顶，因realloc
		S.staticsize += STACK_INIT_SIZE;
	}
	*S.top++ = e;//top指向待插入位置
	return OK;
}
Status Pop(Stack& S, SElemType& e) {
	//若栈不空则栈顶元素出栈并用e带回其值
	if (S.top == S.base) return ERROR;
	else
		e = *(--S.top);//栈顶元素为*(S.top-1)
	return OK;
}
Status GetTop(Stack S, SElemType& e) {
	if (S.top == S.base) return ERROR;
	e = *(S.top - 1);//注意top指向待插入位置
	return OK;
}
Status StackEmpty(Stack S) {//判空
	if (S.top == S.base) return TRUE;
	else
		return FALSE;
}
Status StackTraverse(Stack S, Status(*visit)(SElemType)) {
	//从栈底元素到栈顶元素依次执行visit函数，通常用于输出栈中元素
	SElemType* p = S.base;
	if (S.base == S.top) printf_s("空栈\n");
	else
		while (p < S.top) {
			(*visit)(*p);
			++p;
		}
	return OK;
}
Status PrintSElem(SElemType e) {
	printf_s("step:%d to (%d,%d)\n", e.ord, e.seat.x, e.seat.y);
	return OK;
}


//迷宫求解具体算法
Status MakeMaze(MazeType& maze) {//生成迷宫，0表示PATH，1表示WALL
	PosType m;
	srand(time(NULL));
	for (m.y = 0; m.y <= N + 1; m.y++) { maze[0][m.y] = WALL; maze[M + 1][m.y] = WALL; }
	for (m.x = 1; m.x <= M; m.x++) { maze[m.x][0] = WALL; maze[m.x][N+1] = WALL; }
	for (m.x = 1; m.x <= M; m.x++)
		for (m.y = 1; m.y <= N; m.y++)
			maze[m.x][m.y] = rand() % 2;
	return OK;
}

//■◎

void PrintMaze(MazeType maze) {
	int x, y;
	for (x = 0; x <= M+1; x++) {
		for (y = 0; y <= N+1; y++) {
			switch (maze[x][y]) {
			case WALL:printf_s("■"); break;
			case PATH:printf_s("  "); break;
		    case RIGHT:printf_s("→"); break;
			case DOWN:printf_s("↓"); break;
			case LEFT:printf_s("←"); break;
			case UP:printf_s("↑"); break;
			case BACK:printf_s("@ "); break;
	        case DESTINATION:printf_s("◎"); break;
			default:printf_s("error\n"); exit(-1);
			}
		}
		printf_s("\n");
	}
}

PosType Nextpos(PosType position, ElemType direction) {
	PosType result;
	result = position;
	switch (direction)
	{
	case 1:result.y++; break;
	case 2:result.x++; break;
	case 3:result.y--; break;
	case 4:result.x--; break;
	}
	return result;
}

Status PassMaze(MazeType& maze, PosType start, PosType end, Stack& S) {
	PosType curpos;
	SElemType e;
	int curstep = 1;
	curpos = start;
	if (maze[curpos.x][curpos.y] != PATH) {
		printf_s("当前迷宫没有入口\n");
		return FALSE;
	}
	do {
		if (maze[curpos.x][curpos.y] == PATH) {//当前位置可通
			e.ord = curstep;
			e.seat = curpos;
			e.di = 1;
			Push(S, e);
			if (curpos.x == end.x && curpos.y == end.y) {
				maze[curpos.x][curpos.y] = DESTINATION;
				return OK;
			}
			else {
				maze[curpos.x][curpos.y] = RIGHT;//向右
				curpos = Nextpos(curpos, 1);
				curstep++;
			}
		}
		else {//当前位置不通
			GetTop(S, e);
			while (!StackEmpty(S) && e.di == 4) {
				maze[e.seat.x][e.seat.y] = BACK;
				Pop(S, e);
				curstep--;
				if (StackEmpty(S)) break;
				GetTop(S, e);
			}
			if (e.di < 4) {//栈顶位置有其他方向可以选择
				Pop(S, e);
				e.di++;
				Push(S, e); maze[e.seat.x][e.seat.y] = -e.di;//注意前进方向踪迹与e.di互为相反数
				curpos = Nextpos(e.seat, e.di);
			}
		}
	} while (!StackEmpty(S));
	return FALSE;
}


int main()
{
	MazeType maze;
	PosType start, end;
	Stack S;
	InitStack(S);
	MakeMaze(maze);
	printf_s("迷宫初始为：\n");
	PrintMaze(maze);
	printf_s("输入迷宫的入口位置坐标从(0,0)到(%d,%d)：", M, N);
	scanf_s("%d %d", &start.x, &start.y);
	printf_s("输入迷宫的出口位置坐标从(0,0)到(%d,%d)：", M, N);
	scanf_s("%d %d", &end.x, &end.y);
	if (PassMaze(maze, start, end, S)) {
		printf_s("迷宫可通，路径踪迹如下：\n");
		PrintMaze(maze);
		printf_s("具体路径为：\n");
		StackTraverse(S, PrintSElem);
	}
	else {
		printf_s("迷宫不可通，路径总计如下：\n");
		PrintMaze(maze);
	}
	return 0;
}

