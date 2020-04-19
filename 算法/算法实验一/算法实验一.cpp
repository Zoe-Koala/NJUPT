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
	SortableList(int mSize)  //构造函数
	{
		maxSize = mSize;
		l = new int[maxSize];
		n = 0;
	}
	~SortableList()   //析构函数
	{
		delete[]l;
	}

	void Iuput();   //输入待排序列
	void Output();  //输出已经排序好的序列

	void MergeSort();   //合并排序
	void MergeSort(int left, int right);
	void Merge(int left, int mid, int right);

	void QuickSort();  //快速排序
	void Swap(int i, int j);    //交换下标为 i 和 j 的数组元素
	void QuickSort(int left, int right);
	int Partition(int left, int right);  //分化函数 
private:
	int* l;
	int maxSize;
	int n;          //数组已有元素个数
};

void SortableList::MergeSort()  //Merge函数
{
	MergeSort(0, n - 1);
}

void SortableList::MergeSort(int left, int right)  //两路合并排序
{
	if (left < right)
	{
		int mid = (left + right) / 2;
		MergeSort(left, mid);
		MergeSort(mid + 1, right);
		Merge(left, mid, right);
	}
}

void SortableList::Merge(int left, int mid, int right)   //Merge函数
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

void SortableList::Swap(int i, int j)  //值交换
{
	int c = l[i];
	l[i] = l[j];
	l[j] = c;
}

int SortableList::Partition(int left, int right)  //分化函数
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

void SortableList::QuickSort()  //快速排序
{
	QuickSort(0, n - 1);
}
void SortableList::QuickSort(int left, int right)  //快速排序
{
	if (left < right)
	{
		int j = Partition(left, right);
		QuickSort(left, j - 1);
		QuickSort(j + 1, right);
	}
}

//输入函数
void SortableList::Iuput()
{
	int num;
	cout << "请输入数组元素个数:";
	cin >> num;
	n = num;
	cout << "产生" << n << "个随机整数" << endl;
	int i;
	for (i = 0; i < n; i++)
	{
		int b = rand() % 100;
		l[i] = b;
	}
}

//输出函数
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
	SortableList sortablelist(MAX);   //自动调用构造函数初始化最大数组大小,此处mSize赋值100
	clock_t start, finish;
	sortablelist.Iuput();  //输入待排序列

	//cout << "请做出选择（选择合并排序请输入字符'm',快速排序请选择字符'q')" << endl;
	char c;
	c = getchar();
	//合并排序
	start = clock();
	sortablelist.MergeSort();
	finish = clock();
	printf("\n两路合并排序：\n");
	cout << "开始时间为:" << (double)start / CLK_TCK << "    " << "结束时间为:" << (double)finish / CLK_TCK << "    " << "持续时间为:" << (double)(finish - start) / CLOCKS_PER_SEC << endl;
	//cout << "合并排序之后:";
	//sortablelist.Output();



	//快速排序
	start = clock();
	sortablelist.QuickSort();
	finish = clock();
	printf("\n快速排序：\n");
	cout << "开始时间为:" << (double)start / CLK_TCK << "    " << "结束时间为:" << (double)finish / CLK_TCK << "    " << "持续时间为:" << (double)(finish - start) / CLOCKS_PER_SEC << endl;
	//cout << "快速排序之后:";
	//sortablelist.Output();


	return 0;
}
