/*
#include <math.h>
#include <stdio.h>
#include<stdlib.h>
typedef char T;
typedef struct BinaryTreeNode
{
	T Data;
	struct BinaryTreeNode *LChild, *RChild;
}BinaryTreeNode,*BinTree;

BinaryTreeNode* PreCreateBt(BinaryTreeNode* &t) //先序创建二叉树
{

	char ch;
	ch = getchar();
	if (ch == '#')
		t = NULL;
	else
	{
		t = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
		t->Data = ch;
		t->LChild = PreCreateBt(t->LChild);
		t->RChild = PreCreateBt(t->RChild);
	}
	return t;
}


void PreOrderTransverse(BinaryTreeNode *t)  //先序遍历
{
	if (t == NULL)
		return;
	printf("%c  ", t->Data);
	PreOrderTransverse(t->LChild);
	PreOrderTransverse(t->RChild);
}

void InOrderTransverse(BinaryTreeNode *t)  //中序遍历
{
	if (t == NULL)
		return;
	InOrderTransverse(t->LChild);
	printf("%c  ", t->Data);
	InOrderTransverse(t->RChild);
}

void PostOrderTransverse(BinaryTreeNode *t)  //后序遍历
{
	if (t == NULL)
		return;
	PostOrderTransverse(t->LChild);
	PostOrderTransverse(t->RChild);
	printf("%c  ", t->Data);
}

int main()
{
	BinaryTreeNode *t;
	PreCreateBt(t);
	printf("成功创建!\n");
	printf_s("先序遍历:");
	PreOrderTransverse(t);
	printf_s("\n中序遍历:");
	InOrderTransverse(t);
	printf_s("\n后序遍历:");
	PostOrderTransverse(t);
	getchar();
	getchar();
	return 0;
}
*/

/* 
#include <math.h>
#include <stdio.h>
#include<stdlib.h>
typedef char T;
typedef struct BinaryTreeNode
{
	T Data;
	struct BinaryTreeNode *LChild, *RChild;
}BinaryTreeNode,*BinTree;

BinaryTreeNode* PreCreateBt(BinaryTreeNode* &t) //先序创建二叉树
{

	char ch;
	ch = getchar();
	if (ch == '#')
		t = NULL;
	else
	{
		t = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
		t->Data = ch;
		t->LChild = PreCreateBt(t->LChild);
		t->RChild = PreCreateBt(t->RChild);
	}
	return t;
}


void PreOrderTransverse(BinaryTreeNode *t)  //先序遍历
{
	if (t == NULL)
		return;
	printf("%c  ", t->Data);
	PreOrderTransverse(t->LChild);
	PreOrderTransverse(t->RChild);
}

void InOrderTransverse(BinaryTreeNode *t)  //中序遍历
{
	if (t == NULL)
		return;
	InOrderTransverse(t->LChild);
	printf("%c  ", t->Data);
	InOrderTransverse(t->RChild);
}

void PostOrderTransverse(BinaryTreeNode *t)  //后序遍历
{
	if (t == NULL)
		return;
	PostOrderTransverse(t->LChild);
	PostOrderTransverse(t->RChild);
	printf("%c  ", t->Data);
}

int NodeSize(BinaryTreeNode* &t)     //求二叉树节点个数
{
	if (t == NULL)
		return 0;
	int LSize = NodeSize(t->LChild);
	int RSize = NodeSize(t->RChild);
	return 1 + LSize + RSize;
}


int i = 0;
int LeafNodeSize(BinaryTreeNode* &t)    //求叶子节点个数
{
	if (t == NULL)
		return 0;
	if (t->LChild == NULL && t->RChild == NULL)
	{
		i++;
	}

	LeafNodeSize(t->LChild);
	LeafNodeSize(t->RChild);
	return i;
}


int TreeHeight(BinaryTreeNode* &t)    //求二叉树高度
{
	if (t == NULL)
		return 0;
	else
	{
		int LHeight = TreeHeight(t->LChild) + 1;
		int RHeight = TreeHeight(t->RChild) + 1;
		return LHeight > RHeight ? LHeight : RHeight;
	}
}

void exchange_rootFirlst(BinaryTreeNode* &t)  //交换左右子树
{
	if (t == NULL)
		return;
	BinaryTreeNode *temp = new BinaryTreeNode;
	if (t)
	{
		temp = t->RChild;
		t->RChild = t->LChild;
		t->LChild = temp;
		exchange_rootFirlst(t->LChild);
		exchange_rootFirlst(t->RChild);
	}
}

int main()
{
	BinaryTreeNode *t;
	PreCreateBt(t);
	printf_s("成功创建!\n");
	printf_s("先序遍历:");
	PreOrderTransverse(t);
	printf_s("\n中序遍历:");
	InOrderTransverse(t);
	printf_s("\n后序遍历:");
	PostOrderTransverse(t);
	printf_s("\n");
	printf_s("二叉树结点个数:%d\n",NodeSize(t));
	printf_s("二叉树叶子节点个数:%d\n", LeafNodeSize(t));
	printf_s("二叉树的高度:%d\n", TreeHeight(t));
	printf_s("交换二叉树左右子树后:\n");
	exchange_rootFirlst(t);
	printf_s("先序遍历:");
	PreOrderTransverse(t);
	printf_s("\n中序遍历:");
	InOrderTransverse(t);
	printf_s("\n后序遍历:");
	PostOrderTransverse(t);
	getchar();
	getchar();
	return 0;
}
*/



#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<string>
#include<set>
#include<list>
#include<vector>
#include<map>
#include<iterator>
#include<algorithm>
#include<iostream>
typedef char ElementType;
#define MAX 1000 //哈夫曼树最大结点个数
#define MAXW 1000 //权值最大
using namespace std;
//哈夫曼树结点结构
typedef struct HNode
{
	ElementType data; //数据,非叶节点为NULL
	double weight;//权重
	int parent, lchild, rchild;//双亲，-1表示没有双亲，即根节点     //左孩子，数组下标,-1表示无左孩子，即叶节点    //右孩子
}Hnode;
//编码结构
typedef struct HCNode
{
	ElementType data; //数据
	string code;//该字符编码
};
//两个最小结点下标
typedef struct minnodes
{
	int m1;//两者更小权值结点下标
	int m2;
	bool flag;//若找到则为true,否则为false，false说明仅有一个结点
};
//辅助标志数组 标记该结点为根的树是否已加入哈夫曼树
bool flag[MAX] = { false };
Hnode HT[MAX];//哈夫曼树
HCNode HC[MAX];//哈夫曼编码数组			   
//选择两棵最小权值的树 参数max，当前有权值结点下标+1
minnodes Select(int max)
{
	double min = MAXW;
	minnodes mins;
	mins.m2 = -1;
	//查找第一个最小权值的结点下标
	for (int i = 0; i < max; i++)
	{
		if (!flag[i] && HT[i].weight < min)//未加入哈夫曼树,权值更小
		{
			min = HT[i].weight;//更新最小权值
			mins.m1 = i;
		}
	}
	flag[mins.m1] = true;//将结点加入哈夫曼树
	min = MAXW;
	//查找第二个最小权值结点下标，可能不存在
	for (int i = 0; i < max; i++)
	{
		if (!flag[i] && HT[i].weight < min)//未加入哈夫曼树,权值更小
		{
			min = HT[i].weight;//更新最小权值
			mins.m2 = i;
		}
	}
	flag[mins.m2] = true;//将结点加入哈夫曼树
	if (-1 == mins.m2)//仅剩余一个结点未加入哈夫曼树
	{
		mins.flag = false;//未找到两棵最小权值树
	}
	else
	{
		mins.flag = true;
	}
	return mins;
}
//打印哈夫曼树
void PrintHT(int max)
{
	cout << "下标\t" << "数据\t" << "权重\t" << "双亲\t" << "左孩子\t" << "右孩子" << endl;
	for (int i = 0; i < max; i++)
	{
		cout << i << "\t" << HT[i].data << "\t" << HT[i].weight << "\t" << HT[i].parent << "\t" << HT[i].lchild << "\t" << HT[i].rchild << endl;
	}
}
//打印编码
void PrintHC(int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << HC[i].data << ":" << HC[i].code << endl;;
	}
}
//创建哈夫曼树
void CreateHT()
{
	int n;//字符个数，即哈夫曼树叶节点个数
	minnodes mins;
	cout << "请输入字符个数：" << endl;
	cin >> n;
	cout << "请输入字符及权值：" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> HT[i].data >> HT[i].weight;
		HT[i].lchild = -1; HT[i].rchild = -1;
	}
	int i = n;
	for (;; i++)
	{
		mins = Select(i);//找到两棵根权值最小的树
		if (mins.flag == false)//仅剩余一棵树时跳出
		{
			HT[mins.m1].parent = -1;
			break;
		}
		HT[i].weight = HT[mins.m1].weight + HT[mins.m2].weight;//新加入哈夫曼树结点为两个结点权值之和
		HT[i].data = ' ';
		HT[mins.m1].parent = i;                                //两个权值最小结点双亲为新加入结点
		HT[mins.m2].parent = i;
		HT[i].lchild = mins.m1;//左小又大
		HT[i].rchild = mins.m2;
	}
	PrintHT(i);//打印哈夫曼树
}
//哈夫曼树编码
void Code()
{
	int i = 0;
	for (;; i++)//给所有叶子结点编码
	{
		int j = i;
		string str = "";
		HC[i].data = HT[i].data;//复制数据
		while (-1 != HT[j].parent)//从叶节点找到根
		{
			if (HT[HT[j].parent].lchild == j)//左0右1
			{
				str += '0';
			}
			else
			{
				str += '1';
			}
			j = HT[j].parent;
		}
		reverse(str.begin(), str.end());//逆序
		HC[i].code = str;              //保存至编码
		if (HT[i].lchild == -1 && HT[i].rchild == -1)continue;//非叶子不编码
		else break;
	}
	PrintHC(i);
}
//哈夫曼树解码 从根开始，左0右1，直至叶节点
void Encode()
{
	string s;
	int root = 0;//记录根节点的下标
	cout << "请输入01字符串:" << endl;
	cin >> s;
	while (HT[root].parent != -1) root++;
	int j = root;
	for (int i = 0; i < s.length(); i++)//遍历输入的01串
	{
		if ('0' == s[i])
		{
			j = HT[j].lchild;
		}
		else
		{
			j = HT[j].rchild;
		}
		if (HT[j].lchild == -1 && HT[j].rchild == -1)//到达叶节点
		{
			cout << HT[j].data;
			j = root;//返回根节点继续
		}
	}
	cout << endl;
}
//计算WPL
void WPL()
{
	double WPL = 0;
	for (int i = 0;; i++)
	{
		if (HT[i].lchild != -1 || HT[i].rchild != -1)break;
		WPL += HT[i].weight*HC[i].code.length();//权值×路径长度（编码长度）	
	}
	cout << "WPL:" << WPL << endl;
}
//菜单
void menu()
{
	cout << "************1.创建哈夫曼树   2.编码************" << endl;
	cout << "************3.解码           4.计算wpl*********" << endl;
	cout << "************5.退出 " << endl;
}
//主函数
int main()
{
	int choice = 0;
	while (1)
	{
		menu();
		printf("请输入菜单序号：\n");
		scanf_s("%d", &choice);
		if (5 == choice) break;
		switch (choice)
		{
		case 1:CreateHT(); break;
		case 2:Code(); break;
		case 3:Encode(); break;
		case 4:WPL(); break;
		default:printf("输入错误！！！\n"); break;
		}
	}
	return 0;
}
