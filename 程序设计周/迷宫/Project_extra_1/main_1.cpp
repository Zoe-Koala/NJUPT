#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

//����״̬�붨��
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define NULL 0

//ǽ��ͨ·��ǰ��������϶���
#define WALL 0//��ǰ������ǽ
#define PATH 1//��ǰ��ͨ·��δ�߹�
#define RIGHT -1//������ͨ·�Ҵ���������
#define DOWN -2//������ͨ·�Ҵ���������
#define LEFT -3//������ͨ·�Ҵ���������
#define UP -4//������ͨ·�Ҵ���������
#define BACK -5//������ͨ·�Ҵ������һ��
#define DESTINATION -6//����ǰ������ͨ·����Ŀ��λ��

#define M 30
#define N 30
typedef int MazeType[M + 2][N + 2];//�������ʼ��ǽ��ʵ�ʺ�(M-2)(N-2)������
typedef int Status;
typedef int ElemType;//�Թ������е�Ԫ������

//ջ�Ķ����ʵ�֣�����˳��洢�ṹ
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
typedef struct {
	int x;
	int y;
}PosType;//�Թ��������λ��

typedef struct {
	int ord;
	PosType seat;
	int di;
}SElemType;//ջ��Ԫ������

typedef struct {
	SElemType* base;
	SElemType* top;
	int staticsize;
}Stack;//ջ����

Status InitStack(Stack& S) {
	//�����ջS
	S.base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!S.base) exit(OVERFLOW);//�洢����ʧ��
	S.top = S.base;//��ջ
	S.staticsize = STACK_INIT_SIZE;
	return OK;
}//��ʼ��ջ
Status Push(Stack& S, SElemType e) {
	//����eΪջ��Ԫ��
	if (S.top - S.base >= S.staticsize)//ջ�������·���ռ�
	{
		S.base = (SElemType*)realloc(S.base, (S.staticsize + STACKINCREMENT) * sizeof(SElemType));
		if (!S.base) exit(OVERFLOW);
		S.top = (S.base + S.staticsize);//ʹ��S.top����ָ��ԭջ������realloc
		S.staticsize += STACK_INIT_SIZE;
	}
	*S.top++ = e;//topָ�������λ��
	return OK;
}
Status Pop(Stack& S, SElemType& e) {
	//��ջ������ջ��Ԫ�س�ջ����e������ֵ
	if (S.top == S.base) return ERROR;
	else
		e = *(--S.top);//ջ��Ԫ��Ϊ*(S.top-1)
	return OK;
}
Status GetTop(Stack S, SElemType& e) {
	if (S.top == S.base) return ERROR;
	e = *(S.top - 1);//ע��topָ�������λ��
	return OK;
}
Status StackEmpty(Stack S) {//�п�
	if (S.top == S.base) return TRUE;
	else
		return FALSE;
}
Status StackTraverse(Stack S, Status(*visit)(SElemType)) {
	//��ջ��Ԫ�ص�ջ��Ԫ������ִ��visit������ͨ���������ջ��Ԫ��
	SElemType* p = S.base;
	if (S.base == S.top) printf_s("��ջ\n");
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


//�Թ��������㷨
Status MakeMaze(MazeType& maze) {//�����Թ���0��ʾPATH��1��ʾWALL
	PosType m;
	srand(time(NULL));
	for (m.y = 0; m.y <= N + 1; m.y++) { maze[0][m.y] = WALL; maze[M + 1][m.y] = WALL; }
	for (m.x = 1; m.x <= M; m.x++) { maze[m.x][0] = WALL; maze[m.x][N+1] = WALL; }
	for (m.x = 1; m.x <= M; m.x++)
		for (m.y = 1; m.y <= N; m.y++)
			maze[m.x][m.y] = rand() % 2;
	return OK;
}

//����

void PrintMaze(MazeType maze) {
	int x, y;
	for (x = 0; x <= M+1; x++) {
		for (y = 0; y <= N+1; y++) {
			switch (maze[x][y]) {
			case WALL:printf_s("��"); break;
			case PATH:printf_s("  "); break;
		    case RIGHT:printf_s("��"); break;
			case DOWN:printf_s("��"); break;
			case LEFT:printf_s("��"); break;
			case UP:printf_s("��"); break;
			case BACK:printf_s("@ "); break;
	        case DESTINATION:printf_s("��"); break;
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
		printf_s("��ǰ�Թ�û�����\n");
		return FALSE;
	}
	do {
		if (maze[curpos.x][curpos.y] == PATH) {//��ǰλ�ÿ�ͨ
			e.ord = curstep;
			e.seat = curpos;
			e.di = 1;
			Push(S, e);
			if (curpos.x == end.x && curpos.y == end.y) {
				maze[curpos.x][curpos.y] = DESTINATION;
				return OK;
			}
			else {
				maze[curpos.x][curpos.y] = RIGHT;//����
				curpos = Nextpos(curpos, 1);
				curstep++;
			}
		}
		else {//��ǰλ�ò�ͨ
			GetTop(S, e);
			while (!StackEmpty(S) && e.di == 4) {
				maze[e.seat.x][e.seat.y] = BACK;
				Pop(S, e);
				curstep--;
				if (StackEmpty(S)) break;
				GetTop(S, e);
			}
			if (e.di < 4) {//ջ��λ���������������ѡ��
				Pop(S, e);
				e.di++;
				Push(S, e); maze[e.seat.x][e.seat.y] = -e.di;//ע��ǰ�������ټ���e.di��Ϊ�෴��
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
	printf_s("�Թ���ʼΪ��\n");
	PrintMaze(maze);
	printf_s("�����Թ������λ�������(0,0)��(%d,%d)��", M, N);
	scanf_s("%d %d", &start.x, &start.y);
	printf_s("�����Թ��ĳ���λ�������(0,0)��(%d,%d)��", M, N);
	scanf_s("%d %d", &end.x, &end.y);
	if (PassMaze(maze, start, end, S)) {
		printf_s("�Թ���ͨ��·���ټ����£�\n");
		PrintMaze(maze);
		printf_s("����·��Ϊ��\n");
		StackTraverse(S, PrintSElem);
	}
	else {
		printf_s("�Թ�����ͨ��·���ܼ����£�\n");
		PrintMaze(maze);
	}
	return 0;
}

