/*
#include <stdio.h>
#include <malloc.h>
#include <iostream>
using namespace std;
typedef int ElemType;
typedef struct 
{
	ElemType **a;   //邻接矩阵
	int n;      //图的顶点数
	int e;      //图当前的边数
	ElemType noEdge;    //两顶点无边时的值
}mGraph;
//初始化,nSize顶点数,noEdgeValue无边的值
int Init(mGraph *mg, int nSize, ElemType noEdgeValue) 
{
	int j;
	mg->n = nSize;
	mg->e = 0;        //初始化没有边
	mg->noEdge = noEdgeValue;
	mg->a = (ElemType**)malloc(nSize * sizeof(ElemType*));  //生成长度为n的一维数组指针
	if (!mg->a) 
	    return 0;
	for (int i = 0; i < mg->n; i++) 
	{
		mg->a[i] = (ElemType*)malloc(nSize * sizeof(ElemType));
		for (j = 0; j < mg->n; j++) mg->a[i][j] = mg->noEdge;
		mg->a[i][i] = 0;                                  //自回路设置为0
	}
	return 1;
}
//撤销操作，撤销的时候顺序不能变，先释放指针数组就会找不到数组指针
int Destory(mGraph *mg) {
	for (int i = 0; i < mg->n; i++) free(mg->a[i]);    //释放n个一维数组存储空间
	free(mg->a);                                //释放n个一维指针数组的存储空间
	return 1;
}
//边的搜索操作，判断边在不在图中
int Exist(mGraph *mg, int u, int v) {
	if (u<0 || v<0 || u>mg->n - 1 || v>mg->n - 1 || u == v || mg->a[u][v] == mg->noEdge) {
		cout << "这条边不存在." << endl;
		return 0;
	}
	cout << "这条边存在." << endl;
	cout << "这条边的长度为:" << mg->a[u][v] << endl;
	return 1;
}
//边的插入
int Insert(mGraph *mg, int u, int v, ElemType w) {
	if (u<0 || v<0 || u>mg->n - 1 || v>mg->n - 1 || u == v) return 0;
	if (mg->a[u][v] != mg->noEdge) {
		cout << "该边已存在." << endl;
		return 0;
	}
	mg->a[u][v] = w;
	mg->e++;
	return 1;
}

//边的删除
int Remove(mGraph *mg, int u, int v) {
	if (u<0 || v<0 || u>mg->n - 1 || v>mg->n - 1 || u == v)
		return 0;
	if (mg->a[u][v] == mg->noEdge) 
		return 0;   //删除的边不存在
	mg->a[u][v] = mg->noEdge;
	mg->e--;
	return 1;
}


int main()
{
	mGraph mg;
	int n, n1, u, v, w, a, b;
	printf_s("请输入顶点的个数：" );
	scanf_s("%d", &n);
	Init(&mg, n, 0);
	printf_s( "请输入插入边的个数:" );
	scanf_s("%d", &n1);
	printf_s("请输入插入边的起点(顶点计算从0开始)、终点和边权:\n");
	for (int i = 0; i < n; i++) {
		scanf_s("%d%d%d", &u, &v, &w);
		Insert(&mg, u, v, w);
	}
	printf_s("请输入查找的边的两个端点:\n");
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
//	ElemType **a;   //邻接矩阵 
//	int n;      //图的顶点数 
//	int e;      //图当前的边数 
//	ElemType noEdge;    //两顶点无边时的值 
//}mGraph;
//
////初始化,nSize顶点数,noEdgeValue无边的值 
//int Init(mGraph *mg, int nSize, ElemType noEdgeValue) {
//	int j;
//	mg->n = nSize;
//	mg->e = 0;        //初始化没有边 
//	mg->noEdge = noEdgeValue;
//	mg->a = (ElemType**)malloc(nSize * sizeof(ElemType*));  //生成长度为n的一维数组指针
//	if (!mg->a) return 0;
//	for (int i = 0; i < mg->n; i++) {
//		mg->a[i] = (ElemType*)malloc(nSize * sizeof(ElemType));
//		for (j = 0; j < mg->n; j++) mg->a[i][j] = mg->noEdge;
//		mg->a[i][i] = 0;                                  //自回路设置为0 
//	}
//	return 1;
//}
////撤销操作，撤销的时候顺序不能变，先释放指针数组就会找不到数组指针啦 
//int Destory(mGraph *mg) {
//	for (int i = 0; i < mg->n; i++) free(mg->a[i]);    //释放n个一维数组存储空间 
//	free(mg->a);                                //释放n个一维指针数组的存储空间 
//	return 1;
//}
////边的搜索操作，判断边在不在图中 
//int Exist(mGraph *mg, int u, int v) {
//	if (u<0 || v<0 || u>mg->n - 1 || v>mg->n - 1 || u == v || mg->a[u][v] == mg->noEdge) {
//		cout << "这条边不存在." << endl;
//		return 0;
//	}
//	cout << "这条边存在." << endl;
//	cout << "这条边的长度为:" << mg->a[u][v] << endl;
//	return 1;
//}
////边的插入
//int Insert(mGraph *mg, int u, int v, ElemType w) {
//	if (u<0 || v<0 || u>mg->n - 1 || v>mg->n - 1 || u == v) return 0;
//	if (mg->a[u][v] != mg->noEdge) {
//		cout << "该边已存在." << endl;
//		return 0;
//	}
//	mg->a[u][v] = w;
//	mg->e++;
//	return 1;
//}
//
////边的删除
//int Remove(mGraph *mg, int u, int v) {
//	if (u<0 || v<0 || u>mg->n - 1 || v>mg->n - 1 || u == v)
//		return 0;
//	if (mg->a[u][v] == mg->noEdge) return 0;   //删除的边不存在
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
//	cout << "请输入顶点的个数：" << endl;
//	cin >> n;
//	Init(&mg, n, 0);
//	cout << "请输入插入边的个数:" << endl;
//	cin >> n1;
//	cout << "请输入插入边的起点(顶点计算从0开始)、终点和边权:" << endl;
//	for (int i = 0; i < n1; i++) {
//		cin >> u >> v >> w;
//		Insert(&mg, u, v, w);
//	}
//
//	cout << "邻接矩阵存储下，图的深度遍历访问过的结点：";
//	dfsGraph(mg, visited);
//	cout << endl;
//	cout << "邻接矩阵存储下，图的宽度遍历访问过的结点：";
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
#define Overflow 2  //表示上溢
#define Underflow 3  //表示下溢
#define NotPresent 4 //表示元素不存在
#define Duplicate 5  //表示有重复元素
typedef int ElemType;
typedef int Status;

//邻接矩阵的结构体定义
typedef struct {
	ElemType** a;     //邻接矩阵
	int n;            //图的当前顶点数
	int e;            //图的当前边数
	ElemType noEdge;  //两顶点间无边时的值
}mGraph;


//循环队列的结构体定义
typedef struct {
	int front;
	int rear;
	int maxSize;    //最大容量
	ElemType* element;
}Queue;


//创建一个能容纳mSize个单元的空队列
void Create(Queue* Q, int mSize) {
	Q->maxSize = mSize;
	Q->element = (ElemType*)malloc(sizeof(ElemType) * mSize);
	Q->front = Q->rear = 0;
}


//判断队列是否为空,若是,则返回TRUE;否则返回FALSE
BOOL IsEmpty(Queue* Q) {
	return Q->front == Q->rear;
}


//判断队列是否已满,若是,则返回TRUE,否则返回FALSE
BOOL IsFULL(Queue* Q) {
	return (Q->rear + 1) % Q->maxSize == Q->front;
}


//获取队头元素,并通过x返回.若操作成功,则返回TRUE,否则返回FALSE
BOOL Front(Queue* Q, ElemType* x) {
	if (IsEmpty(Q))      //空队列处理
		return FALSE;
	*x = Q->element[(Q->front + 1) % Q->maxSize];
	return TRUE;
}


//入队.在队列Q的队尾插入元素x(入队操作)。操作成功,则返回TRUE,否则返回FALSE
BOOL EnQueue(Queue* Q, ElemType x) {
	if (IsFULL(Q))      //溢出处理
		return FALSE;
	Q->rear = (Q->rear + 1) % Q->maxSize;
	Q->element[Q->rear] = x;
	return TRUE;
}


//出队.从队列Q中删除队头元素(出队操作)。操作成功,则返回TRUE,否则返回FALSE
BOOL DeQueue(Queue* Q) {
	if (IsEmpty(Q)) {   //空队列处理
		return FALSE;
	}
	Q->front = (Q->front + 1) % Q->maxSize;
	return TRUE;
}


//邻接矩阵的初始化
Status Init(mGraph* mg, int nSize, ElemType noEdgeValue) {
	int i, j;
	mg->n = nSize;               //初始化顶点数
	mg->e = 0;                   //初始化时没有边
	mg->noEdge = noEdgeValue;    //初始化没有边时的取值
	mg->a = (ElemType**)malloc(nSize * sizeof(ElemType*));  //生成长度为n的一维指针数组
	if (!mg->a) return ERROR;
	for (i = 0; i < mg->n; i++) {   //动态生成二维数组
		mg->a[i] = (ElemType*)malloc(nSize * sizeof(ElemType));
		for (j = 0; j < mg->n; j++) {
			mg->a[i][j] = mg->noEdge;
		}
		mg->a[i][i] = 0;        //自回路设置为0
	}
	return OK;
}


//邻接矩阵的撤销(改成了int型，有返回值),先释放一维数组,再释放指针数组
int Destory(mGraph* mg) {
	int i;
	for (i = 0; i < mg->n; i++) {
		free(mg->a[i]);  //释放n个一维数组的存储空间
	}
	free(mg->a);         //释放一维数组的存储空间
	return 1;
}


//邻接矩阵的边的搜索
Status Exist(mGraph* mg, int u, int v) {
	if (u < 0 || v < 0 || u > mg->n - 1 || v > mg->n - 1 || u == v || mg->a[u][v] == mg->noEdge) return ERROR;
	return OK;
}


//邻接矩阵的边的插入
Status Insert(mGraph* mg, int u, int v, ElemType w) {
	if (u < 0 || v < 0 || u > mg->n - 1 || v > mg->n - 1 || u == v) return ERROR;
	if (mg->a[u][v] != mg->noEdge) return Duplicate;  //若待插入边已存在,则返回出错信息
	mg->a[u][v] = w;                                 //插入新边
	mg->e++;                                        //增加一条边
	return OK;
}


//邻接矩阵的边的删除
Status Remove(mGraph* mg, int u, int v) {
	if (u < 0 || v < 0 || u > mg->n - 1 || v > mg->n - 1 || u == v) return ERROR;
	if (mg->a[u][v] == mg->noEdge) return NotPresent;  //若待删除边不存在,则返回出错信息
	mg->a[u][v] = mg->noEdge;                         //删除边
	mg->e--;
	return OK;
}


//邻接矩阵的单一顶点DFS
void DFS(int v, int visited[], mGraph g) {
	int j;
	printf("%d ", v);              //访问顶点v
	visited[v] = 1;               //为顶点v打上访问标记       
	for (j = 0; j < g.n; j++) {      //遍历v的邻接点
		if (!visited[j] && g.a[v][j] > 0) {  //当未被访问且有权值
			DFS(j, visited, g);
		}
	}
}


//邻接矩阵的全图DFS
void DFSGraph(mGraph g) {
	int i;
	int* visited = (int*)malloc(g.n * sizeof(int)); //动态生成标记数组visted
	for (i = 0; i < g.n; i++) {
		visited[i] = 0;          //visted数组初始化
	}                            //visted数组初始化
	for (i = 0; i < g.n; i++) {     //逐一检查每个顶点,若未被访问,则调用DFS
		if (!visited[i]) {   //当未被访问且有权值
			DFS(i, visited, g);
		}
	}
	free(visited);                       //释放visted数组
}


//邻接矩阵的单一顶点BFS
void BFS(int v, int visited[], mGraph g) {
	Queue q;
	Create(&q, g.n);                        //初始化队列
	visited[v] = 1;                        //为顶点v打上访问标记
	printf("%d ", v);                       //访问顶点v
	EnQueue(&q, v);                         //将顶点v放入队列
	while (!IsEmpty(&q)) {
		Front(&q, &v);
		DeQueue(&q);                       //队首顶点出队列
		for (int i = 0; i < g.n; i++) {       //遍历v的每一项
			if (!visited[i] && g.a[v][i] > 0) {       //若未被访问且有权值,则将其访问并放入队列,注意这里判断的是g.a[v][i]二维数组
				visited[i] = 1;
				printf("%d ", i);
				EnQueue(&q, i);
			}
		}
	}
}


//邻接矩阵的全图BFS
void BFSGraph(mGraph g) {
	int i;
	int* visited = (int*)malloc(g.n * sizeof(int));  //动态生成visited数组
	for (i = 0; i < g.n; i++) {                         //初始化visited数组
		visited[i] = 0;
	}
	for (i = 0; i < g.n; i++) {                        //逐一检查每个顶点,若未被访问,则调用BFS
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
	printf("请输入顶点个数:");
	scanf_s("%d", &nSize);
	Init(&g, nSize, -1);
	printf("请输入边的条数:");
	scanf_s("%d", &edge);
	for (i = 0; i < edge; i++) {
		printf("请输入边:");
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
	int adjVex;     //任意顶点u相邻的点
	ElemType w;     //边的权值
	struct Enode* nextArc;  //指向下一个边结点 
}Enode;
typedef struct {
	int n;  //结点个数
	int e;  //边的个数
	Enode **a;  //指向一维指针数组 
}Lgraph;

//初始化
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

//邻接表的撤销
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
	free(lg->a);    //释放一维指针数组a的存储空间 
	return 1;
}

//搜索边
int Exist(Lgraph *lg, int u, int v) {
	Enode *p;
	if (u < 0 || v<0 || u >= lg->n || v>lg->n || u == v) return 0;
	p = lg->a[u];
	while (p &&p->adjVex != v) {
		p = p->nextArc;
	}
	if (!p) return 0;
	else {
		cout << "该边的权值为" << p->w << ",";
		return 1;
	}
}

//插入边
int Insert(Lgraph *lg, int u, int v, int w) {
	Enode *p;
	if (u < 0 || v < 0 || u >= lg->n || v >= lg->n || u == v) return 0;
	if (Exist(lg, u, v))  return 0;
	p = (Enode *)malloc(sizeof(Enode));  //为新生成的边分配存储空间
	p->adjVex = v;
	p->w = w;
	p->nextArc = lg->a[u];    //插入结点在序列的开头 
	lg->a[u] = p;
	lg->e++;
	return 1;
}

//删除边
int Remove(Lgraph *lg, int u, int v) {
	if (u < 0 || v < 0 || u >= lg->n || v >= lg->n || u == v) return 0;
	Enode *p, *q;
	p = lg->a[u];
	q = NULL;
	while (p &&p->adjVex != v) {
		q = p;
		p = p->nextArc;
	}
	if (!p) return 0;        //q是待删结点的前驱结点,p是待删结点 
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
	cout << "请输入顶点的个数:" << endl;
	cin >> n;
	init(&lg, n);
	cout << "请输入插入的边的两个顶点和边权:（0 0 0表示输入结束）" << endl;
	while (cin >> u >> v >> w) {
		if (u == 0 && v == 0 && w == 0) break;
		Insert(&lg, u, v, w);
	}

	cout << "请输入待查找的边的两个顶点:" << endl;
	cin >> u >> v;
	flag1 = Exist(&lg, u, v);
	if (flag1) cout << "该边存在." << endl;
	else cout << "该边不存在." << endl;

	cout << endl;

	cout << "请输入待删除的边的两个顶点:" << endl;
	cin >> u >> v;
	flag2 = Remove(&lg, u, v);
	if (flag2) cout << "删除成功." << endl;
	else cout << "删除失败." << endl;

	cout << "撤销邻接表." << endl;
	flag3 = Destory(&lg);
	if (flag3) cout << "撤销成功." << endl;
	else cout << "撤销失败." << endl;
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
	int adjVex;     //任意与u相邻的点
	int w;          //边权
	struct Enode *nextArc;  //指向下一个边结点
}Enode;
typedef struct{
	int n,e;
	Enode **a;
}Lgraph;

//单一顶点深搜
void dfs(int v,int visited[],Lgraph g){
	Enode *w;
	cout<<v<<" ";  //访问结点v
	visited[v]=1;
	for(w=g.a[v];w ;w=w->nextArc)   //访问邻接点
	{
		if(!visited[w->adjVex]){
			dfs(w->adjVex,visited,g);
		}
	}
}
//初始化
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
//插入边
int Insert(Lgraph *lg,int u,int v,int w){
	if(u<0||v<0||u>lg->n-1||v>lg->n-1||u==v) return 0;
	Enode *p;
	p=(Enode *)malloc(sizeof(Enode));
	p->adjVex=v;
	p->w=w;
	p->nextArc=lg->a[u];
	lg->a[u]=p;         //这里注意，开始写错了，查了好久
	lg->e++;
	return 1;
}

//全图深搜
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

	cout<<"请输入顶点的个数."<<endl;
	cin>>n;

	init(&lg,n);
	cout<<"请输入带插入边的两个端点和边权.(以0 0 0结尾)"<<endl;
	while(cin>>u>>v>>w){
		if(u==0 &&v==0 &&w==0) break;
		Insert(&lg,u,v,w);
	}

	cout<<"请输入搜索的起点."<<endl;
	cin>>u;
	//单一顶点深搜
	cout<<"单一顶点深搜:";
	dfs(u,visited,lg);
	cout<<endl;

	//全图深搜
	cout<<"全图深搜:";
	dfsGraph(lg);
	cout<<endl;

	cout<<"深搜结束"<<endl;
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
	int adjVex;     //相邻的结点 
	int w;  //边权 
	struct Enode * nextArc;
}Enode;
typedef struct {
	int n;      //顶点数
	int e;      //边数
	Enode **a;  //一维指针数组 
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
	queue<int > q;  //调用STL库
	visited[v] = 1;
	cout << v << " ";
	q.push(v);
	while (!q.empty()) {
		q.front();  //取队首元素 
		q.pop();    //队首元素出队
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

	cout << "请输入顶点的个数." << endl;
	cin >> n;

	init(&lg, n);
	cout << "请输入带插入边的两个端点和边权.(以0 0 0结尾)" << endl;
	while (cin >> u >> v >> w) {
		if (u == 0 && v == 0 && w == 0) break;
		Insert(&lg, u, v, w);
	}
	cout << "请输入宽度搜算的起点:" << endl;
	cin >> v1;
	cout << "宽搜的结点：";
	bfs(v1, visited, lg);
	cout << endl;

	cout << "全图宽搜: ";
	bfsGraph(lg);
	cout << endl << "宽搜结束。" << endl;
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
#define INF 0xfffff    //权值上限
#define maxn 110  //最大顶点个数
int n;       //顶点个数

struct arcnode  //边结点
{
	int vertex;     //与表头结点相邻的顶点编号
	int weight;     //连接两顶点的边的权值
	arcnode * next; //指向下一相邻接点
	arcnode() {}
	arcnode(int v, int w) :vertex(v), weight(w), next(NULL) {}
};

struct vernode      //顶点结点，为每一条邻接表的表头结点
{
	int vex;    //当前定点编号
	arcnode * firarc;   //与该顶点相连的第一个顶点组成的边
}Ver[maxn];

void Init()  //建立图的邻接表需要先初始化，建立顶点结点
{
	for (int i = 1; i <= n; i++)
	{
		Ver[i].vex = i;
		Ver[i].firarc = NULL;
	}
}

void Insert(int a, int b, int w)  //尾插法，插入以a为起点，b为终点，权为w的边，效率不如头插，但是可以去重边
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
void Insert2(int a, int b, int w)   //头插法，效率更高，但不能去重边
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
struct node     //顶点节点，保存id和到源顶点的估算距离，优先队列需要的类型
{
	int id;     //源顶点id和估算距离
	int w;
	friend bool operator<(node a, node b)   //因要实现最小堆，按升序排列，因而需要重载运算符，重定义优先级，以小为先
	{
		return a.w > b.w;
	}
};

int parent[maxn];   //每个顶点的父亲节点，可以用于还原最短路径树
bool visited[maxn]; //用于判断顶点是否已经在最短路径树中，或者说是否已找到最短路径
node d[maxn];      //源点到每个顶点估算距离，最后结果为源点到所有顶点的最短路。
priority_queue<node> q; //优先队列stl实现
void Dijkstra(int s)    //Dijkstra算法，传入源顶点
{
	for (int i = 1; i <= n; i++) //初始化
	{
		d[i].id = i;
		d[i].w = INF;           //估算距离置INF
		parent[i] = -1;         //每个顶点都无父亲节点
		visited[i] = false;     //都未找到最短路
	}
	d[s].w = 0;                 //源点到源点最短路权值为0
	q.push(d[s]);               //压入队列中
	while (!q.empty())           //算法的核心，队列空说明完成了操作
	{
		node cd = q.top();      //取最小估算距离顶点
		q.pop();
		int u = cd.id;
		if (visited[u])
			continue;
		visited[u] = true;
		arcnode * p = Ver[u].firarc;
		//松弛操作
		while (p != NULL)    //找所有与他相邻的顶点，进行松弛操作，更新估算距离，压入队列。
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
	printf("请输入地点数和路径数：\n");
	scanf_s("%d%d", &n, &m);
	printf("请输入路径以及路径长度（a, b, c)\n");
	Init();     //计算前必须初始化
	while (m--)
	{
		scanf_s("%d%d%d", &a, &b, &c);
		Insert2(a, b, c);   //无向图注意存储两条边
		Insert2(b, a, c);
	}
	printf_s("请输入起点和终点：\n");
	scanf_s("%d%d", &st, &ed);
	Dijkstra(st);
	if (d[ed].w != INF)
		printf_s("%d到%d最短路径长度为：%d\n", st, ed, d[ed].w);
	else
		printf_s("不存在从地点%d到地点%d的最短路径。\n", st, ed);
	getchar();
	getchar();
	return 0;
}

