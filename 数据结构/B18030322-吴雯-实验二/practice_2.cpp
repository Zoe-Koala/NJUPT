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

BinaryTreeNode* PreCreateBt(BinaryTreeNode* &t) //���򴴽�������
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


void PreOrderTransverse(BinaryTreeNode *t)  //�������
{
	if (t == NULL)
		return;
	printf("%c  ", t->Data);
	PreOrderTransverse(t->LChild);
	PreOrderTransverse(t->RChild);
}

void InOrderTransverse(BinaryTreeNode *t)  //�������
{
	if (t == NULL)
		return;
	InOrderTransverse(t->LChild);
	printf("%c  ", t->Data);
	InOrderTransverse(t->RChild);
}

void PostOrderTransverse(BinaryTreeNode *t)  //�������
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
	printf("�ɹ�����!\n");
	printf_s("�������:");
	PreOrderTransverse(t);
	printf_s("\n�������:");
	InOrderTransverse(t);
	printf_s("\n�������:");
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

BinaryTreeNode* PreCreateBt(BinaryTreeNode* &t) //���򴴽�������
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


void PreOrderTransverse(BinaryTreeNode *t)  //�������
{
	if (t == NULL)
		return;
	printf("%c  ", t->Data);
	PreOrderTransverse(t->LChild);
	PreOrderTransverse(t->RChild);
}

void InOrderTransverse(BinaryTreeNode *t)  //�������
{
	if (t == NULL)
		return;
	InOrderTransverse(t->LChild);
	printf("%c  ", t->Data);
	InOrderTransverse(t->RChild);
}

void PostOrderTransverse(BinaryTreeNode *t)  //�������
{
	if (t == NULL)
		return;
	PostOrderTransverse(t->LChild);
	PostOrderTransverse(t->RChild);
	printf("%c  ", t->Data);
}

int NodeSize(BinaryTreeNode* &t)     //��������ڵ����
{
	if (t == NULL)
		return 0;
	int LSize = NodeSize(t->LChild);
	int RSize = NodeSize(t->RChild);
	return 1 + LSize + RSize;
}


int i = 0;
int LeafNodeSize(BinaryTreeNode* &t)    //��Ҷ�ӽڵ����
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


int TreeHeight(BinaryTreeNode* &t)    //��������߶�
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

void exchange_rootFirlst(BinaryTreeNode* &t)  //������������
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
	printf_s("�ɹ�����!\n");
	printf_s("�������:");
	PreOrderTransverse(t);
	printf_s("\n�������:");
	InOrderTransverse(t);
	printf_s("\n�������:");
	PostOrderTransverse(t);
	printf_s("\n");
	printf_s("������������:%d\n",NodeSize(t));
	printf_s("������Ҷ�ӽڵ����:%d\n", LeafNodeSize(t));
	printf_s("�������ĸ߶�:%d\n", TreeHeight(t));
	printf_s("��������������������:\n");
	exchange_rootFirlst(t);
	printf_s("�������:");
	PreOrderTransverse(t);
	printf_s("\n�������:");
	InOrderTransverse(t);
	printf_s("\n�������:");
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
#define MAX 1000 //����������������
#define MAXW 1000 //Ȩֵ���
using namespace std;
//�����������ṹ
typedef struct HNode
{
	ElementType data; //����,��Ҷ�ڵ�ΪNULL
	double weight;//Ȩ��
	int parent, lchild, rchild;//˫�ף�-1��ʾû��˫�ף������ڵ�     //���ӣ������±�,-1��ʾ�����ӣ���Ҷ�ڵ�    //�Һ���
}Hnode;
//����ṹ
typedef struct HCNode
{
	ElementType data; //����
	string code;//���ַ�����
};
//������С����±�
typedef struct minnodes
{
	int m1;//���߸�СȨֵ����±�
	int m2;
	bool flag;//���ҵ���Ϊtrue,����Ϊfalse��false˵������һ�����
};
//������־���� ��Ǹý��Ϊ�������Ƿ��Ѽ����������
bool flag[MAX] = { false };
Hnode HT[MAX];//��������
HCNode HC[MAX];//��������������			   
//ѡ��������СȨֵ���� ����max����ǰ��Ȩֵ����±�+1
minnodes Select(int max)
{
	double min = MAXW;
	minnodes mins;
	mins.m2 = -1;
	//���ҵ�һ����СȨֵ�Ľ���±�
	for (int i = 0; i < max; i++)
	{
		if (!flag[i] && HT[i].weight < min)//δ�����������,Ȩֵ��С
		{
			min = HT[i].weight;//������СȨֵ
			mins.m1 = i;
		}
	}
	flag[mins.m1] = true;//���������������
	min = MAXW;
	//���ҵڶ�����СȨֵ����±꣬���ܲ�����
	for (int i = 0; i < max; i++)
	{
		if (!flag[i] && HT[i].weight < min)//δ�����������,Ȩֵ��С
		{
			min = HT[i].weight;//������СȨֵ
			mins.m2 = i;
		}
	}
	flag[mins.m2] = true;//���������������
	if (-1 == mins.m2)//��ʣ��һ�����δ�����������
	{
		mins.flag = false;//δ�ҵ�������СȨֵ��
	}
	else
	{
		mins.flag = true;
	}
	return mins;
}
//��ӡ��������
void PrintHT(int max)
{
	cout << "�±�\t" << "����\t" << "Ȩ��\t" << "˫��\t" << "����\t" << "�Һ���" << endl;
	for (int i = 0; i < max; i++)
	{
		cout << i << "\t" << HT[i].data << "\t" << HT[i].weight << "\t" << HT[i].parent << "\t" << HT[i].lchild << "\t" << HT[i].rchild << endl;
	}
}
//��ӡ����
void PrintHC(int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << HC[i].data << ":" << HC[i].code << endl;;
	}
}
//������������
void CreateHT()
{
	int n;//�ַ�����������������Ҷ�ڵ����
	minnodes mins;
	cout << "�������ַ�������" << endl;
	cin >> n;
	cout << "�������ַ���Ȩֵ��" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> HT[i].data >> HT[i].weight;
		HT[i].lchild = -1; HT[i].rchild = -1;
	}
	int i = n;
	for (;; i++)
	{
		mins = Select(i);//�ҵ����ø�Ȩֵ��С����
		if (mins.flag == false)//��ʣ��һ����ʱ����
		{
			HT[mins.m1].parent = -1;
			break;
		}
		HT[i].weight = HT[mins.m1].weight + HT[mins.m2].weight;//�¼�������������Ϊ�������Ȩֵ֮��
		HT[i].data = ' ';
		HT[mins.m1].parent = i;                                //����Ȩֵ��С���˫��Ϊ�¼�����
		HT[mins.m2].parent = i;
		HT[i].lchild = mins.m1;//��С�ִ�
		HT[i].rchild = mins.m2;
	}
	PrintHT(i);//��ӡ��������
}
//������������
void Code()
{
	int i = 0;
	for (;; i++)//������Ҷ�ӽ�����
	{
		int j = i;
		string str = "";
		HC[i].data = HT[i].data;//��������
		while (-1 != HT[j].parent)//��Ҷ�ڵ��ҵ���
		{
			if (HT[HT[j].parent].lchild == j)//��0��1
			{
				str += '0';
			}
			else
			{
				str += '1';
			}
			j = HT[j].parent;
		}
		reverse(str.begin(), str.end());//����
		HC[i].code = str;              //����������
		if (HT[i].lchild == -1 && HT[i].rchild == -1)continue;//��Ҷ�Ӳ�����
		else break;
	}
	PrintHC(i);
}
//������������ �Ӹ���ʼ����0��1��ֱ��Ҷ�ڵ�
void Encode()
{
	string s;
	int root = 0;//��¼���ڵ���±�
	cout << "������01�ַ���:" << endl;
	cin >> s;
	while (HT[root].parent != -1) root++;
	int j = root;
	for (int i = 0; i < s.length(); i++)//���������01��
	{
		if ('0' == s[i])
		{
			j = HT[j].lchild;
		}
		else
		{
			j = HT[j].rchild;
		}
		if (HT[j].lchild == -1 && HT[j].rchild == -1)//����Ҷ�ڵ�
		{
			cout << HT[j].data;
			j = root;//���ظ��ڵ����
		}
	}
	cout << endl;
}
//����WPL
void WPL()
{
	double WPL = 0;
	for (int i = 0;; i++)
	{
		if (HT[i].lchild != -1 || HT[i].rchild != -1)break;
		WPL += HT[i].weight*HC[i].code.length();//Ȩֵ��·�����ȣ����볤�ȣ�	
	}
	cout << "WPL:" << WPL << endl;
}
//�˵�
void menu()
{
	cout << "************1.������������   2.����************" << endl;
	cout << "************3.����           4.����wpl*********" << endl;
	cout << "************5.�˳� " << endl;
}
//������
int main()
{
	int choice = 0;
	while (1)
	{
		menu();
		printf("������˵���ţ�\n");
		scanf_s("%d", &choice);
		if (5 == choice) break;
		switch (choice)
		{
		case 1:CreateHT(); break;
		case 2:Code(); break;
		case 3:Encode(); break;
		case 4:WPL(); break;
		default:printf("������󣡣���\n"); break;
		}
	}
	return 0;
}
