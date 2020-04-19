//#include<stdio.h>
//#include<iostream>
//#include<stdlib.h>
//#include<time.h>
//#define max 10
//typedef int KeyType;
//typedef int DataType;
//typedef struct entry
//{
//	KeyType key;
//	DataType data;
//}Entry;
//typedef struct list
//{
//	int n;
//	Entry D[max];
//}List;
//
//int FindMin(List list, int startIndex)  //简单选择排序
//{
//	int i, minIndex = startIndex;
//	for (i = startIndex + 1; i < list.n; i++)
//	{
//		if (list.D[i].key < list.D[minIndex].key)
//			minIndex = i;
//	}
//	return minIndex;
//}
//void Swap(Entry* D, int i, int j)
//{
//	if (i == j)return;
//	Entry temp = *(D + i);
//	*(D + i) = *(D + j);
//	*(D + j) = temp;
//}
//void SelectSort(List* list) //简单选择排序
//{
//	int minIndex, startIndex = 0;
//	while (startIndex < list->n - 1)
//	{
//		minIndex = FindMin(*list, startIndex);
//		Swap(list->D, startIndex, minIndex);
//		startIndex++;
//	}
//}
//
//void InsertSort(List *list) //直接插入排序
//{
//	int i, j;
//	for (i = 1; i < list->n; i++)
//	{
//		Entry insertItem = list->D[i];
//		for (j = i - 1; j >= 0; j--)
//		{
//			if (insertItem.key < list->D[j].key)
//				list->D[j + 1] = list->D[j];
//			else break;
//		}
//		list->D[j + 1] = insertItem;
//	}
//}
//
//void BubbleSort(List* list, int n) //冒泡排序,n为待排序的个数
//{
//	int i, j;
//	bool isSwap = false;
//	for (i = n - 1; i > 0; i--)
//	{
//		for (j = 0; j < i; j++)
//		{
//			if (list->D[j].key > list->D[j + 1].key)
//			{
//				Swap(list->D, j, j + 1);
//				isSwap = true;
//			}
//		}
//		if (!isSwap) break;
//	}
//}
//
//
//
//int Partition(List* list, int low, int high)
//{
//	int i = low, j = high + 1;
//	Entry pivot = list->D[low];
//	do
//	{
//		do i++; while (list->D[i].key < pivot.key); //i前进
//		do j--; while (list->D[j].key > pivot.key); //j前进
//		if (i < j) Swap(list->D, i, j);
//	} while (i < j);
//	Swap(list->D, low, j);
//	return j;
//}
//void QuickSort(List* list, int low, int high) //快速排序算法
//{
//	int k;
//	if (low < high)
//	{
//		k = Partition(list, low, high);
//		QuickSort(list, low, k - 1);
//		QuickSort(list, k + 1, high);
//	}
//}
//void QuickSort(List *list)  //快速排序的调用函数
//{
//	QuickSort(list, 0, list->n - 1);
//}
//
//
//Entry temp[100];
//long MergeSort(List* l)    //两路合并排序
//{
//	int size = 1, n1, n2;
//	while (size < l->n)
//	{
//		int k = 0;
//		int low = 0;
//		while (low + size <= l->n)
//		{
//			n1 = size;
//			if (low + size * 2 < l->n)
//			{
//				n2 = size;
//			}
//			else
//			{
//				n2 = l->n - low - size;
//			}
//
//			int i = low, j = low + n1;
//			while (i <= low + n1 - 1 && j <= low + n1 + n2 - 1)
//			{
//				if (l->D[i].key <= l->D[j].key)
//				{
//					temp[k++] = l->D[i++];
//				}
//				else
//				{
//					temp[k++] = l->D[j++];
//				}
//			}
//			while (i <= low + n1 - 1)
//			{
//				temp[k++] = l->D[i++];
//			}
//			while (j <= low + n1 + n2 - 1)
//			{
//				temp[k++] = l->D[j++];
//			}
//			low += n1 + n2;
//		}
//		for (int i = 0; i < l->n; i++)
//		{
//			l->D[i] = temp[i];
//		}
//		size *= 2;
//	}
//	return 0;
//}
//
//
//
//typedef struct maxheap
//{
//	int n, MaxHeap;
//	Entry D[max];
//}MaxHeap;
//void AdjustDown(List *list, int r, int j)
//{
//	int child = 2 * r + 1;
//	Entry temp = list->D[r];
//	while (child <= j)
//	{
//		if ((child < j) && (list->D[child].key < list->D[child + 1].key))
//			child++;
//		if (temp.key >= list->D[child].key)
//			break;
//		list->D[(child - 1) / 2] = list->D[child];
//		child = 2 * child + 1;
//	}
//	list->D[(child - 1) / 2] = temp;
//}
//void HeapSort(List *list)   //堆排序
//{
//	for (int i = (list->n - 2) / 2; i > -1; i--)
//		AdjustDown(list, i, list->n - 1);
//	for (int i = list->n - 1; i > 0; i--)
//	{
//		Swap(list->D, 0, i);
//		AdjustDown(list, 0, i - 1);
//	}
//}
//
//
//
//void Rand(List *list, int a[])  /*产生100以内的随机整数*/
//{
//	for (int i = 0; i < max; i++)
//	{
//		int b = rand() % 100;
//		list->D[i].key = b;
//		list->D[i].data = b;
//		a[i] = b;
//		printf("%d ", list->D[i].key);
//		list->n++;
//	}
//}
//
//void RepeatRand(List *list, int *a)  /*复制100以内的随机整数*/
//{
//	for (int i = 0; i < max; i++)
//	{
//		list->D[i].key = a[i];
//		list->D[i].data = a[i];
//	}
//}
//
//int main()
//{
//	List L1;
//	L1.n = 0;
//	int a[max];
//
//	Rand(&L1, a); /*产生100以内的随机整数*/
//
//	SelectSort(&L1);      //简单选择排序
//	printf("\n\n\n简单选择排序\n");
//	for (int i = 0; i < max; i++)
//		printf("%d ", L1.D[i].data);
//
//	printf("\n\n\n重新复制值：\n");
//	RepeatRand(&L1, a);
//	for (int i = 0; i < max; i++)
//		printf("%d ", a[i]);
//	printf("\n\n\n直接插入排序:\n");
//	InsertSort(&L1);      //直接插入排序
//	for (int i = 0; i < max; i++)
//		printf("%d ", L1.D[i].data);
//
//	printf("\n\n\n重新复制值：\n");
//	RepeatRand(&L1, a);
//	for (int i = 0; i < max; i++)
//		printf("%d ", a[i]);
//	BubbleSort(&L1, max);  //冒泡排序
//	printf("\n\n\n冒泡排序：\n");
//	for (int i = 0; i < max; i++)
//		printf("%d ", L1.D[i].data);
//
//	printf("\n\n\n重新复制值：\n");
//	RepeatRand(&L1, a);
//	for (int i = 0; i < max; i++)
//		printf("%d ", a[i]);
//	QuickSort(&L1);       //快速排序的调用函数
//	printf("\n\n\n快速排序：\n");
//	for (int i = 0; i < max; i++)
//		printf("%d ", L1.D[i].data);
//
//
//	printf("\n\n\n重新复制值：\n");
//	RepeatRand(&L1, a);
//	for (int i = 0; i < max; i++)
//		printf("%d ", a[i]);
//	MergeSort(&L1);      //两路合并排序
//	printf("\n\n\n两路合并排序：\n");
//	for (int i = 0; i < max; i++)
//		printf("%d ", L1.D[i].data);
//
//
//	printf("\n\n\n重新复制值：\n");
//	RepeatRand(&L1, a);
//	for (int i = 0; i < max; i++)
//		printf("%d ", a[i]);
//	HeapSort(&L1);       //堆排序
//	printf("\n\n\n堆排序：\n");
//	for (int i = 0; i < max; i++)
//		printf("%d ", L1.D[i].data);
//
//
//	system("pause");
//	return 0;
//}
