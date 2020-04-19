/*
#include <stdio.h>
#include <malloc.h>
#include <iostream>
using namespace std;
typedef int ElemType;
typedef struct 
{
	ElemType **a;   //�ڽӾ���
	int n;      //ͼ�Ķ�����
	int e;      //ͼ��ǰ�ı���
	ElemType noEdge;    //�������ޱ�ʱ��ֵ
}mGraph;
//��ʼ��,nSize������,noEdgeValue�ޱߵ�ֵ
int Init(mGraph *mg, int nSize, ElemType noEdgeValue) 
{
	int j;
	mg->n = nSize;
	mg->e = 0;        //��ʼ��û�б�
	mg->noEdge = noEdgeValue;
	mg->a = (ElemType**)malloc(nSize * sizeof(ElemType*));  //���ɳ���Ϊn��һά����ָ��
	if (!mg->a) 
	    return 0;
	for (int i = 0; i < mg->n; i++) 
	{
		mg->a[i] = (ElemType*)malloc(nSize * sizeof(ElemType));
		for (j = 0; j < mg->n; j++) mg->a[i][j] = mg->noEdge;
		mg->a[i][i] = 0;                                  //�Ի�·����Ϊ0
	}
	return 1;
}
//����������������ʱ��˳���ܱ䣬���ͷ�ָ������ͻ��Ҳ�������ָ��
int Destory(mGraph *mg) {
	for (int i = 0; i < mg->n; i++) free(mg->a[i]);    //�ͷ�n��һά����洢�ռ�
	free(mg->a);                                //�ͷ�n��һάָ������Ĵ洢�ռ�
	return 1;
}
//�ߵ������������жϱ��ڲ���ͼ��
int Exist(mGraph *mg, int u, int v) {
	if (u<0 || v<0 || u>mg->n - 1 || v>mg->n - 1 || u == v || mg->a[u][v] == mg->noEdge) {
		cout << "�����߲�����." << endl;
		return 0;
	}
	cout << "�����ߴ���." << endl;
	cout << "�����ߵĳ���Ϊ:" << mg->a[u][v] << endl;
	return 1;
}
//�ߵĲ���
int Insert(mGraph *mg, int u, int v, ElemType w) {
	if (u<0 || v<0 || u>mg->n - 1 || v>mg->n - 1 || u == v) return 0;
	if (mg->a[u][v] != mg->noEdge) {
		cout << "�ñ��Ѵ���." << endl;
		return 0;
	}
	mg->a[u][v] = w;
	mg->e++;
	return 1;
}

//�ߵ�ɾ��
int Remove(mGraph *mg, int u, int v) {
	if (u<0 || v<0 || u>mg->n - 1 || v>mg->n - 1 || u == v)
		return 0;
	if (mg->a[u][v] == mg->noEdge) 
		return 0;   //ɾ���ı߲�����
	mg->a[u][v] = mg->noEdge;
	mg->e--;
	return 1;
}


int main()
{
	mGraph mg;
	int n, n1, u, v, w, a, b;
	printf_s("�����붥��ĸ�����" );
	scanf_s("%d", &n);
	Init(&mg, n, 0);
	printf_s( "���������ߵĸ���:" );
	scanf_s("%d", &n1);
	printf_s("���������ߵ����(��������0��ʼ)���յ�ͱ�Ȩ:\n");
	for (int i = 0; i < n; i++) {
		scanf_s("%d%d%d", &u, &v, &w);
		Insert(&mg, u, v, w);
	}
	printf_s("��������ҵıߵ������˵�:\n");
	scanf_s("%d%d", &a, &b);
	Exist(&mg, a, b);
	Destory(&mg);
	Remove(&mg, 0, 1);
	getchar();
	getchar();
	getchar();
	return 0;
}
*/


//#include<queue>
//#include <iostream>
//using namespace std;
//typedef int ElemType;
//typedef struct {
//	ElemType **a;   //�ڽӾ��� 
//	int n;      //ͼ�Ķ����� 
//	int e;      //ͼ��ǰ�ı��� 
//	ElemType noEdge;    //�������ޱ�ʱ��ֵ 
//}mGraph;
//
////��ʼ��,nSize������,noEdgeValue�ޱߵ�ֵ 
//int Init(mGraph *mg, int nSize, ElemType noEdgeValue) {
//	int j;
//	mg->n = nSize;
//	mg->e = 0;        //��ʼ��û�б� 
//	mg->noEdge = noEdgeValue;
//	mg->a = (ElemType**)malloc(nSize * sizeof(ElemType*));  //���ɳ���Ϊn��һά����ָ��
//	if (!mg->a) return 0;
//	for (int i = 0; i < mg->n; i++) {
//		mg->a[i] = (ElemType*)malloc(nSize * sizeof(ElemType));
//		for (j = 0; j < mg->n; j++) mg->a[i][j] = mg->noEdge;
//		mg->a[i][i] = 0;                                  //�Ի�·����Ϊ0 
//	}
//	return 1;
//}
////����������������ʱ��˳���ܱ䣬���ͷ�ָ������ͻ��Ҳ�������ָ���� 
//int Destory(mGraph *mg) {
//	for (int i = 0; i < mg->n; i++) free(mg->a[i]);    //�ͷ�n��һά����洢�ռ� 
//	free(mg->a);                                //�ͷ�n��һάָ������Ĵ洢�ռ� 
//	return 1;
//}
////�ߵ������������жϱ��ڲ���ͼ�� 
//int Exist(mGraph *mg, int u, int v) {
//	if (u<0 || v<0 || u>mg->n - 1 || v>mg->n - 1 || u == v || mg->a[u][v] == mg->noEdge) {
//		cout << "�����߲�����." << endl;
//		return 0;
//	}
//	cout << "�����ߴ���." << endl;
//	cout << "�����ߵĳ���Ϊ:" << mg->a[u][v] << endl;
//	return 1;
//}
////�ߵĲ���
//int Insert(mGraph *mg, int u, int v, ElemType w) {
//	if (u<0 || v<0 || u>mg->n - 1 || v>mg->n - 1 || u == v) return 0;
//	if (mg->a[u][v] != mg->noEdge) {
//		cout << "�ñ��Ѵ���." << endl;
//		return 0;
//	}
//	mg->a[u][v] = w;
//	mg->e++;
//	return 1;
//}
//
////�ߵ�ɾ��
//int Remove(mGraph *mg, int u, int v) {
//	if (u<0 || v<0 || u>mg->n - 1 || v>mg->n - 1 || u == v)
//		return 0;
//	if (mg->a[u][v] == mg->noEdge) return 0;   //ɾ���ı߲�����
//	mg->a[u][v] = mg->noEdge;
//	mg->e--;
//	return 1;
//}
//
//void dfs(mGraph mg, int i, int visited[]) {
//	visited[i] = 1;
//	cout << i << " ";
//	for (int j = 0; j < mg.n; j++) {
//		if (mg.a[i][j] != 0 && visited[j])
//			dfs(mg, j, visited);
//	}
//}
//void dfsGraph(mGraph mg, int visited[]) {
//	int i;
//	for (int i = 0; i < mg.n; i++) visited[i] = 0;
//	for (int i = 0; i < mg.n; i++) {
//		if (!visited[i])
//			dfs(mg, i, visited);
//	}
//}
//
//int bfsGraph(mGraph *mg, int visited[]) {
//	queue<int> q;
//	for (int i = 0; i < mg->n; i++) visited[i] = 0;
//	for (int i = 0; i < mg->n; i++) {
//		if (!visited[i]) {
//			visited[i] = 1;
//			cout << i << " ";
//			q.push(i);
//			while (!q.empty()) {
//				q.pop();
//				for (int j = 0; j < mg->n; j++) {
//					if (!visited[j] && mg->a[i][j] != 0) {
//						visited[j] = 1;
//						cout << j << " ";
//						q.pop();
//					}
//				}
//			}
//		}
//	}
//	return 1;
//}
//
//int main() {
//	mGraph mg;
//	int n, n1, u, v, w, a, b, visited[10010];
//	memset(visited, 0, sizeof(visited));
//
//	cout << "�����붥��ĸ�����" << endl;
//	cin >> n;
//	Init(&mg, n, 0);
//	cout << "���������ߵĸ���:" << endl;
//	cin >> n1;
//	cout << "���������ߵ����(��������0��ʼ)���յ�ͱ�Ȩ:" << endl;
//	for (int i = 0; i < n1; i++) {
//		cin >> u >> v >> w;
//		Insert(&mg, u, v, w);
//	}
//
//	cout << "�ڽӾ���洢�£�ͼ����ȱ������ʹ��Ľ�㣺";
//	dfsGraph(mg, visited);
//	cout << endl;
//	cout << "�ڽӾ���洢�£�ͼ�Ŀ�ȱ������ʹ��Ľ�㣺";
//	bfsGraph(&mg, visited);
//	cout << endl;
//	getchar();
//	system("pause");
//	return 0;
//}

/*
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
#include<windows.h>
#include<queue>
#define ERROR 0
#define OK 1
#define Overflow 2  //��ʾ����
#define Underflow 3  //��ʾ����
#define NotPresent 4 //��ʾԪ�ز�����
#define Duplicate 5  //��ʾ���ظ�Ԫ��
typedef int ElemType;
typedef int Status;

//�ڽӾ���Ľṹ�嶨��
typedef struct {
	ElemType** a;     //�ڽӾ���
	int n;            //ͼ�ĵ�ǰ������
	int e;            //ͼ�ĵ�ǰ����
	ElemType noEdge;  //��������ޱ�ʱ��ֵ
}mGraph;


//ѭ�����еĽṹ�嶨��
typedef struct {
	int front;
	int rear;
	int maxSize;    //�������
	ElemType* element;
}Queue;


//����һ��������mSize����Ԫ�Ŀն���
void Create(Queue* Q, int mSize) {
	Q->maxSize = mSize;
	Q->element = (ElemType*)malloc(sizeof(ElemType) * mSize);
	Q->front = Q->rear = 0;
}


//�ж϶����Ƿ�Ϊ��,����,�򷵻�TRUE;���򷵻�FALSE
BOOL IsEmpty(Queue* Q) {
	return Q->front == Q->rear;
}


//�ж϶����Ƿ�����,����,�򷵻�TRUE,���򷵻�FALSE
BOOL IsFULL(Queue* Q) {
	return (Q->rear + 1) % Q->maxSize == Q->front;
}


//��ȡ��ͷԪ��,��ͨ��x����.�������ɹ�,�򷵻�TRUE,���򷵻�FALSE
BOOL Front(Queue* Q, ElemType* x) {
	if (IsEmpty(Q))      //�ն��д���
		return FALSE;
	*x = Q->element[(Q->front + 1) % Q->maxSize];
	return TRUE;
}


//���.�ڶ���Q�Ķ�β����Ԫ��x(��Ӳ���)�������ɹ�,�򷵻�TRUE,���򷵻�FALSE
BOOL EnQueue(Queue* Q, ElemType x) {
	if (IsFULL(Q))      //�������
		return FALSE;
	Q->rear = (Q->rear + 1) % Q->maxSize;
	Q->element[Q->rear] = x;
	return TRUE;
}


//����.�Ӷ���Q��ɾ����ͷԪ��(���Ӳ���)�������ɹ�,�򷵻�TRUE,���򷵻�FALSE
BOOL DeQueue(Queue* Q) {
	if (IsEmpty(Q)) {   //�ն��д���
		return FALSE;
	}
	Q->front = (Q->front + 1) % Q->maxSize;
	return TRUE;
}


//�ڽӾ���ĳ�ʼ��
Status Init(mGraph* mg, int nSize, ElemType noEdgeValue) {
	int i, j;
	mg->n = nSize;               //��ʼ��������
	mg->e = 0;                   //��ʼ��ʱû�б�
	mg->noEdge = noEdgeValue;    //��ʼ��û�б�ʱ��ȡֵ
	mg->a = (ElemType**)malloc(nSize * sizeof(ElemType*));  //���ɳ���Ϊn��һάָ������
	if (!mg->a) return ERROR;
	for (i = 0; i < mg->n; i++) {   //��̬���ɶ�ά����
		mg->a[i] = (ElemType*)malloc(nSize * sizeof(ElemType));
		for (j = 0; j < mg->n; j++) {
			mg->a[i][j] = mg->noEdge;
		}
		mg->a[i][i] = 0;        //�Ի�·����Ϊ0
	}
	return OK;
}


//�ڽӾ���ĳ���(�ĳ���int�ͣ��з���ֵ),���ͷ�һά����,���ͷ�ָ������
int Destory(mGraph* mg) {
	int i;
	for (i = 0; i < mg->n; i++) {
		free(mg->a[i]);  //�ͷ�n��һά����Ĵ洢�ռ�
	}
	free(mg->a);         //�ͷ�һά����Ĵ洢�ռ�
	return 1;
}


//�ڽӾ���ıߵ�����
Status Exist(mGraph* mg, int u, int v) {
	if (u < 0 || v < 0 || u > mg->n - 1 || v > mg->n - 1 || u == v || mg->a[u][v] == mg->noEdge) return ERROR;
	return OK;
}


//�ڽӾ���ıߵĲ���
Status Insert(mGraph* mg, int u, int v, ElemType w) {
	if (u < 0 || v < 0 || u > mg->n - 1 || v > mg->n - 1 || u == v) return ERROR;
	if (mg->a[u][v] != mg->noEdge) return Duplicate;  //����������Ѵ���,�򷵻س�����Ϣ
	mg->a[u][v] = w;                                 //�����±�
	mg->e++;                                        //����һ����
	return OK;
}


//�ڽӾ���ıߵ�ɾ��
Status Remove(mGraph* mg, int u, int v) {
	if (u < 0 || v < 0 || u > mg->n - 1 || v > mg->n - 1 || u == v) return ERROR;
	if (mg->a[u][v] == mg->noEdge) return NotPresent;  //����ɾ���߲�����,�򷵻س�����Ϣ
	mg->a[u][v] = mg->noEdge;                         //ɾ����
	mg->e--;
	return OK;
}


//�ڽӾ���ĵ�һ����DFS
void DFS(int v, int visited[], mGraph g) {
	int j;
	printf("%d ", v);              //���ʶ���v
	visited[v] = 1;               //Ϊ����v���Ϸ��ʱ��       
	for (j = 0; j < g.n; j++) {      //����v���ڽӵ�
		if (!visited[j] && g.a[v][j] > 0) {  //��δ����������Ȩֵ
			DFS(j, visited, g);
		}
	}
}


//�ڽӾ����ȫͼDFS
void DFSGraph(mGraph g) {
	int i;
	int* visited = (int*)malloc(g.n * sizeof(int)); //��̬���ɱ������visted
	for (i = 0; i < g.n; i++) {
		visited[i] = 0;          //visted�����ʼ��
	}                            //visted�����ʼ��
	for (i = 0; i < g.n; i++) {     //��һ���ÿ������,��δ������,�����DFS
		if (!visited[i]) {   //��δ����������Ȩֵ
			DFS(i, visited, g);
		}
	}
	free(visited);                       //�ͷ�visted����
}


//�ڽӾ���ĵ�һ����BFS
void BFS(int v, int visited[], mGraph g) {
	Queue q;
	Create(&q, g.n);                        //��ʼ������
	visited[v] = 1;                        //Ϊ����v���Ϸ��ʱ��
	printf("%d ", v);                       //���ʶ���v
	EnQueue(&q, v);                         //������v�������
	while (!IsEmpty(&q)) {
		Front(&q, &v);
		DeQueue(&q);                       //���׶��������
		for (int i = 0; i < g.n; i++) {       //����v��ÿһ��
			if (!visited[i] && g.a[v][i] > 0) {       //��δ����������Ȩֵ,������ʲ��������,ע�������жϵ���g.a[v][i]��ά����
				visited[i] = 1;
				printf("%d ", i);
				EnQueue(&q, i);
			}
		}
	}
}


//�ڽӾ����ȫͼBFS
void BFSGraph(mGraph g) {
	int i;
	int* visited = (int*)malloc(g.n * sizeof(int));  //��̬����visited����
	for (i = 0; i < g.n; i++) {                         //��ʼ��visited����
		visited[i] = 0;
	}
	for (i = 0; i < g.n; i++) {                        //��һ���ÿ������,��δ������,�����BFS
		if (!visited[i]) {
			BFS(i, visited, g);
		}
	}
	free(visited);
}



int main() {
	mGraph g;
	int nSize, edge, u, v, i;
	ElemType w;
	printf("�����붥�����:");
	scanf_s("%d", &nSize);
	Init(&g, nSize, -1);
	printf("������ߵ�����:");
	scanf_s("%d", &edge);
	for (i = 0; i < edge; i++) {
		printf("�������:");
		scanf_s("%d%d%d", &u, &v, &w);
		Insert(&g, u, v, w);
	}
	printf("DFS:\n");
	DFSGraph(g);
	printf("\nBFS:\n");
	BFSGraph(g);
	printf_s("\n");
	system("pause");
	return 0;
}
*/

/*
#include <iostream>
using namespace std;
typedef int ElemType;
typedef struct Enode {
	int adjVex;     //���ⶥ��u���ڵĵ�
	ElemType w;     //�ߵ�Ȩֵ
	struct Enode* nextArc;  //ָ����һ���߽�� 
}Enode;
typedef struct {
	int n;  //������
	int e;  //�ߵĸ���
	Enode **a;  //ָ��һάָ������ 
}Lgraph;

//��ʼ��
int init(Lgraph *lg, int nSize) {
	lg->a = (Enode **)malloc(nSize * sizeof(Enode*));
	lg->n = nSize;
	lg->e = 0;
	if (!lg->a) return 0;
	else {
		for (int i = 0; i < nSize; i++) {
			lg->a[i] = NULL;
		}
		return 1;
	}
}

//�ڽӱ�ĳ���
int Destory(Lgraph *lg) {
	int i;
	Enode *p, *q;
	for (int i = 0; i < lg->n; i++) {
		p = lg->a[i];
		q = p;
		while (p) {
			p = p->nextArc;
			free(q);
			q = p;
		}
	}
	free(lg->a);    //�ͷ�һάָ������a�Ĵ洢�ռ� 
	return 1;
}

//������
int Exist(Lgraph *lg, int u, int v) {
	Enode *p;
	if (u < 0 || v<0 || u >= lg->n || v>lg->n || u == v) return 0;
	p = lg->a[u];
	while (p &&p->adjVex != v) {
		p = p->nextArc;
	}
	if (!p) return 0;
	else {
		cout << "�ñߵ�ȨֵΪ" << p->w << ",";
		return 1;
	}
}

//�����
int Insert(Lgraph *lg, int u, int v, int w) {
	Enode *p;
	if (u < 0 || v < 0 || u >= lg->n || v >= lg->n || u == v) return 0;
	if (Exist(lg, u, v))  return 0;
	p = (Enode *)malloc(sizeof(Enode));  //Ϊ�����ɵı߷���洢�ռ�
	p->adjVex = v;
	p->w = w;
	p->nextArc = lg->a[u];    //�����������еĿ�ͷ 
	lg->a[u] = p;
	lg->e++;
	return 1;
}

//ɾ����
int Remove(Lgraph *lg, int u, int v) {
	if (u < 0 || v < 0 || u >= lg->n || v >= lg->n || u == v) return 0;
	Enode *p, *q;
	p = lg->a[u];
	q = NULL;
	while (p &&p->adjVex != v) {
		q = p;
		p = p->nextArc;
	}
	if (!p) return 0;        //q�Ǵ�ɾ����ǰ�����,p�Ǵ�ɾ��� 
	if (q) q->nextArc = p->nextArc;
	else  lg->a[u] = p->nextArc;
	free(q);
	lg->e--;
	return 1;
}

int main() {
	Lgraph lg;
	int n, u, v, w;
	bool flag1, flag2, flag3;
	flag1 = flag2 = flag3 = false;
	cout << "�����붥��ĸ���:" << endl;
	cin >> n;
	init(&lg, n);
	cout << "���������ıߵ���������ͱ�Ȩ:��0 0 0��ʾ���������" << endl;
	while (cin >> u >> v >> w) {
		if (u == 0 && v == 0 && w == 0) break;
		Insert(&lg, u, v, w);
	}

	cout << "����������ҵıߵ���������:" << endl;
	cin >> u >> v;
	flag1 = Exist(&lg, u, v);
	if (flag1) cout << "�ñߴ���." << endl;
	else cout << "�ñ߲�����." << endl;

	cout << endl;

	cout << "�������ɾ���ıߵ���������:" << endl;
	cin >> u >> v;
	flag2 = Remove(&lg, u, v);
	if (flag2) cout << "ɾ���ɹ�." << endl;
	else cout << "ɾ��ʧ��." << endl;

	cout << "�����ڽӱ�." << endl;
	flag3 = Destory(&lg);
	if (flag3) cout << "�����ɹ�." << endl;
	else cout << "����ʧ��." << endl;
	system("pause");
	return 0;
}
*/


/*
#include <iostream>
#define maxn 10010
using namespace std;
int visited[maxn];
typedef struct Enode{
	int adjVex;     //������u���ڵĵ�
	int w;          //��Ȩ
	struct Enode *nextArc;  //ָ����һ���߽��
}Enode;
typedef struct{
	int n,e;
	Enode **a;
}Lgraph;

//��һ��������
void dfs(int v,int visited[],Lgraph g){
	Enode *w;
	cout<<v<<" ";  //���ʽ��v
	visited[v]=1;
	for(w=g.a[v];w ;w=w->nextArc)   //�����ڽӵ�
	{
		if(!visited[w->adjVex]){
			dfs(w->adjVex,visited,g);
		}
	}
}
//��ʼ��
int init(Lgraph *lg,int nSize){
	lg->n=nSize;
	lg->e=0;
	lg->a=(Enode **)malloc(nSize*sizeof(Enode *));
	if(!lg->a) return 0;
	for(int i=0;i<lg->n;i++){
		lg->a[i]=NULL;
	}
	return 1;
}
//�����
int Insert(Lgraph *lg,int u,int v,int w){
	if(u<0||v<0||u>lg->n-1||v>lg->n-1||u==v) return 0;
	Enode *p;
	p=(Enode *)malloc(sizeof(Enode));
	p->adjVex=v;
	p->w=w;
	p->nextArc=lg->a[u];
	lg->a[u]=p;         //����ע�⣬��ʼд���ˣ����˺þ�
	lg->e++;
	return 1;
}

//ȫͼ����
void dfsGraph(Lgraph g){
	int *visited=(int *)malloc(g.n*sizeof(int ));
	for(int i=0;i<g.n;i++)
		visited[i]=0;
	for(int i=0;i<g.n;i++){
		if(!visited[i]){
			dfs(i,visited,g);
		}
	}
	free(visited);
}

int main(){
	Lgraph lg;
	int n,u,v,w,visited[maxn],p;
	memset(visited,0,sizeof(visited));

	cout<<"�����붥��ĸ���."<<endl;
	cin>>n;

	init(&lg,n);
	cout<<"�����������ߵ������˵�ͱ�Ȩ.(��0 0 0��β)"<<endl;
	while(cin>>u>>v>>w){
		if(u==0 &&v==0 &&w==0) break;
		Insert(&lg,u,v,w);
	}

	cout<<"���������������."<<endl;
	cin>>u;
	//��һ��������
	cout<<"��һ��������:";
	dfs(u,visited,lg);
	cout<<endl;

	//ȫͼ����
	cout<<"ȫͼ����:";
	dfsGraph(lg);
	cout<<endl;

	cout<<"���ѽ���"<<endl;
	system("pause");
	return 0;
}
*/

/*
#include <iostream>
#include <queue>
#define maxn 10010
using namespace std;
typedef struct Enode {
	int adjVex;     //���ڵĽ�� 
	int w;  //��Ȩ 
	struct Enode * nextArc;
}Enode;
typedef struct {
	int n;      //������
	int e;      //����
	Enode **a;  //һάָ������ 
}Lgraph;

int init(Lgraph *lg, int nSize) {
	lg->n = nSize;
	lg->e = 0;
	lg->a = (Enode **)malloc(nSize * sizeof(Enode *));
	if (!lg->a) return 0;
	for (int i = 0; i < lg->n; i++)
		lg->a[i] = NULL;
	return 1;
}

int Insert(Lgraph *lg, int u, int v, int w) {
	if (u<0 || v<0 || u>lg->n - 1 || v>lg->n - 1 || u == v) return 0;
	Enode *p;
	p = (Enode *)malloc(sizeof(Enode));
	p->adjVex = v;
	p->w = w;
	p->nextArc = lg->a[u];
	lg->a[u] = p;
	return 1;
}

void bfs(int v, int visited[], Lgraph g) {
	Enode *w;
	queue<int > q;  //����STL��
	visited[v] = 1;
	cout << v << " ";
	q.push(v);
	while (!q.empty()) {
		q.front();  //ȡ����Ԫ�� 
		q.pop();    //����Ԫ�س���
		for (w = g.a[v]; w; w = w->nextArc) {
			if (!visited[w->adjVex]) {
				visited[w->adjVex] = 1;
				cout << w->adjVex << " ";
				q.push(w->adjVex);
			}
		}
	}
}

void bfsGraph(Lgraph g) {
	int i;
	int *visited = (int *)malloc(g.n * sizeof(int));
	for (int i = 0; i < g.n; i++) visited[i] = 0;
	for (int i = 0; i < g.n; i++) {
		if (!visited[i]) bfs(i, visited, g);
	}
	free(visited);
}

int main() {
	Lgraph lg;
	int n, visited[maxn], u, v, w, v1;
	memset(visited, 0, sizeof(visited));

	cout << "�����붥��ĸ���." << endl;
	cin >> n;

	init(&lg, n);
	cout << "�����������ߵ������˵�ͱ�Ȩ.(��0 0 0��β)" << endl;
	while (cin >> u >> v >> w) {
		if (u == 0 && v == 0 && w == 0) break;
		Insert(&lg, u, v, w);
	}
	cout << "����������������:" << endl;
	cin >> v1;
	cout << "���ѵĽ�㣺";
	bfs(v1, visited, lg);
	cout << endl;

	cout << "ȫͼ����: ";
	bfsGraph(lg);
	cout << endl << "���ѽ�����" << endl;
	getchar();
	getchar();
	return 0;
}
*/


#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
#define INF 0xfffff    //Ȩֵ����
#define maxn 110  //��󶥵����
int n;       //�������

struct arcnode  //�߽��
{
	int vertex;     //���ͷ������ڵĶ�����
	int weight;     //����������ıߵ�Ȩֵ
	arcnode * next; //ָ����һ���ڽӵ�
	arcnode() {}
	arcnode(int v, int w) :vertex(v), weight(w), next(NULL) {}
};

struct vernode      //�����㣬Ϊÿһ���ڽӱ�ı�ͷ���
{
	int vex;    //��ǰ������
	arcnode * firarc;   //��ö��������ĵ�һ��������ɵı�
}Ver[maxn];

void Init()  //����ͼ���ڽӱ���Ҫ�ȳ�ʼ��������������
{
	for (int i = 1; i <= n; i++)
	{
		Ver[i].vex = i;
		Ver[i].firarc = NULL;
	}
}

void Insert(int a, int b, int w)  //β�巨��������aΪ��㣬bΪ�յ㣬ȨΪw�ıߣ�Ч�ʲ���ͷ�壬���ǿ���ȥ�ر�
{
	arcnode * q = new arcnode(b, w);
	if (Ver[a].firarc == NULL)
		Ver[a].firarc = q;
	else
	{
		arcnode * p = Ver[a].firarc;
		if (p->vertex == b)
		{
			if (p->weight > w)
				p->weight = w;
			return;
		}
		while (p->next != NULL)
		{
			if (p->next->vertex == b)
			{
				if (p->next->weight > w)
					p->next->weight = w;
				return;
			}
			p = p->next;
		}
		p->next = q;
	}
}
void Insert2(int a, int b, int w)   //ͷ�巨��Ч�ʸ��ߣ�������ȥ�ر�
{
	arcnode * q = new arcnode(b, w);
	if (Ver[a].firarc == NULL)
		Ver[a].firarc = q;
	else
	{
		arcnode * p = Ver[a].firarc;
		q->next = p;
		Ver[a].firarc = q;
	}
}
struct node     //����ڵ㣬����id�͵�Դ����Ĺ�����룬���ȶ�����Ҫ������
{
	int id;     //Դ����id�͹������
	int w;
	friend bool operator<(node a, node b)   //��Ҫʵ����С�ѣ����������У������Ҫ������������ض������ȼ�����СΪ��
	{
		return a.w > b.w;
	}
};

int parent[maxn];   //ÿ������ĸ��׽ڵ㣬�������ڻ�ԭ���·����
bool visited[maxn]; //�����ж϶����Ƿ��Ѿ������·�����У�����˵�Ƿ����ҵ����·��
node d[maxn];      //Դ�㵽ÿ�����������룬�����ΪԴ�㵽���ж�������·��
priority_queue<node> q; //���ȶ���stlʵ��
void Dijkstra(int s)    //Dijkstra�㷨������Դ����
{
	for (int i = 1; i <= n; i++) //��ʼ��
	{
		d[i].id = i;
		d[i].w = INF;           //���������INF
		parent[i] = -1;         //ÿ�����㶼�޸��׽ڵ�
		visited[i] = false;     //��δ�ҵ����·
	}
	d[s].w = 0;                 //Դ�㵽Դ�����·ȨֵΪ0
	q.push(d[s]);               //ѹ�������
	while (!q.empty())           //�㷨�ĺ��ģ����п�˵������˲���
	{
		node cd = q.top();      //ȡ��С������붥��
		q.pop();
		int u = cd.id;
		if (visited[u])
			continue;
		visited[u] = true;
		arcnode * p = Ver[u].firarc;
		//�ɳڲ���
		while (p != NULL)    //�������������ڵĶ��㣬�����ɳڲ��������¹�����룬ѹ����С�
		{
			int v = p->vertex;
			if (!visited[v] && d[v].w > d[u].w + p->weight)
			{
				d[v].w = d[u].w + p->weight;
				parent[v] = u;
				q.push(d[v]);
			}
			p = p->next;
		}
	}
}

int main()
{
	int m, a, b, c, st, ed;
	printf("������ص�����·������\n");
	scanf_s("%d%d", &n, &m);
	printf("������·���Լ�·�����ȣ�a, b, c)\n");
	Init();     //����ǰ�����ʼ��
	while (m--)
	{
		scanf_s("%d%d%d", &a, &b, &c);
		Insert2(a, b, c);   //����ͼע��洢������
		Insert2(b, a, c);
	}
	printf_s("�����������յ㣺\n");
	scanf_s("%d%d", &st, &ed);
	Dijkstra(st);
	if (d[ed].w != INF)
		printf_s("%d��%d���·������Ϊ��%d\n", st, ed, d[ed].w);
	else
		printf_s("�����ڴӵص�%d���ص�%d�����·����\n", st, ed);
	getchar();
	getchar();
	return 0;
}

