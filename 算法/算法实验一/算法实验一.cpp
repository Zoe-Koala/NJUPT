#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<time.h>
using namespace std;
#define MAX 10000000
class SortableList
{
public:
	SortableList(int mSize)  //���캯��
	{
		maxSize = mSize;
		l = new int[maxSize];
		n = 0;
	}
	~SortableList()   //��������
	{
		delete[]l;
	}

	void Iuput();   //�����������
	void Output();  //����Ѿ�����õ�����

	void MergeSort();   //�ϲ�����
	void MergeSort(int left, int right);
	void Merge(int left, int mid, int right);

	void QuickSort();  //��������
	void Swap(int i, int j);    //�����±�Ϊ i �� j ������Ԫ��
	void QuickSort(int left, int right);
	int Partition(int left, int right);  //�ֻ����� 
private:
	int* l;
	int maxSize;
	int n;          //��������Ԫ�ظ���
};

void SortableList::MergeSort()  //Merge����
{
	MergeSort(0, n - 1);
}

void SortableList::MergeSort(int left, int right)  //��·�ϲ�����
{
	if (left < right)
	{
		int mid = (left + right) / 2;
		MergeSort(left, mid);
		MergeSort(mid + 1, right);
		Merge(left, mid, right);
	}
}

void SortableList::Merge(int left, int mid, int right)   //Merge����
{
	int* temp = new int[right - left + 1];
	int i = left, j = mid + 1, k = 0;
	while ((i <= mid) && (j <= right))
		if (l[i] <= l[j]) temp[k++] = l[i++];
		else temp[k++] = l[j++];
	while (i <= mid)  temp[k++] = l[i++];
	while (j <= right) temp[k++] = l[j++];
	for (i = 0, k = left; k <= right;)
		l[k++] = temp[i++];
}

void SortableList::Swap(int i, int j)  //ֵ����
{
	int c = l[i];
	l[i] = l[j];
	l[j] = c;
}

int SortableList::Partition(int left, int right)  //�ֻ�����
{
	int i = left, j = right + 1;
	do {
		do i++; while (l[i] < l[left]);
		do j--; while (l[j] > l[left]);
		if (i < j) Swap(i, j);
	} while (i < j);
	Swap(left, j);
	return j;
}

void SortableList::QuickSort()  //��������
{
	QuickSort(0, n - 1);
}
void SortableList::QuickSort(int left, int right)  //��������
{
	if (left < right)
	{
		int j = Partition(left, right);
		QuickSort(left, j - 1);
		QuickSort(j + 1, right);
	}
}

//���뺯��
void SortableList::Iuput()
{
	int num;
	cout << "����������Ԫ�ظ���:";
	cin >> num;
	n = num;
	cout << "����" << n << "���������" << endl;
	int i;
	for (i = 0; i < n; i++)
	{
		int b = rand() % 100;
		l[i] = b;
	}
}

//�������
void SortableList::Output()
{
	int i;
	for (i = 0; i < n; i++)
	{
		cout << l[i] << " ";
	}
	cout << endl;
}

int main()
{
	SortableList sortablelist(MAX);   //�Զ����ù��캯����ʼ����������С,�˴�mSize��ֵ100
	clock_t start, finish;
	sortablelist.Iuput();  //�����������

	//cout << "������ѡ��ѡ��ϲ������������ַ�'m',����������ѡ���ַ�'q')" << endl;
	char c;
	c = getchar();
	//�ϲ�����
	start = clock();
	sortablelist.MergeSort();
	finish = clock();
	printf("\n��·�ϲ�����\n");
	cout << "��ʼʱ��Ϊ:" << (double)start / CLK_TCK << "    " << "����ʱ��Ϊ:" << (double)finish / CLK_TCK << "    " << "����ʱ��Ϊ:" << (double)(finish - start) / CLOCKS_PER_SEC << endl;
	//cout << "�ϲ�����֮��:";
	//sortablelist.Output();



	//��������
	start = clock();
	sortablelist.QuickSort();
	finish = clock();
	printf("\n��������\n");
	cout << "��ʼʱ��Ϊ:" << (double)start / CLK_TCK << "    " << "����ʱ��Ϊ:" << (double)finish / CLK_TCK << "    " << "����ʱ��Ϊ:" << (double)(finish - start) / CLOCKS_PER_SEC << endl;
	//cout << "��������֮��:";
	//sortablelist.Output();


	return 0;
}
