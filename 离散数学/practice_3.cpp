//#include <cstdlib>
//#include <cstdio>
//#include <cmath>
//#include <vector>
//#include <cstring>
//#include <map>
//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//const int LEN = 140 + 10;
//int n;
//int cnt;
//int arr[LEN];
//
////求最大公约数
//int gcd(int n, int m);
//
//int main()
//{
//	cout << "请输入一个整数(>0) : ";
//	while (cin >> n)  //连续输入，Ctrl+Z终止
//	{
//		cout << endl;
//		int k = (int)floor(sqrt(n) + 0.5);
//		cnt = 1;
//		for (int i = 1; i <= k; i++)
//		{
//			if (n % i == 0)
//			{
//				if (i != n / i)
//				{
//					arr[cnt++] = i;
//					arr[cnt++] = n / i;
//				}
//				else
//				{
//					arr[cnt++] = i;
//				}
//			}
//		}
//
//		sort(arr, arr + cnt);  //排序
//
//		//输出偏序集上的盖住关系
//		cout << "输出偏序集上的盖住关系 : ";
//		for (int i = 1; i < cnt; i++)
//		{
//			for (int j = i + 1; j < cnt; j++)
//			{
//				if (arr[j] % arr[i] == 0 && i < j)
//				{
//					bool flag = true;
//					for (int k = i + 1; k < j; k++)
//					{
//						if (arr[j] % arr[k] == 0 && arr[k] % arr[i] == 0 && i < k && k < j)
//						{
//							flag = false;
//							break;
//						}
//					}
//					if (flag)
//					{
//						cout << "(" << arr[i] << "," << arr[j] << ")" << "   ";
//					}
//				}
//			}
//		}
//
//		cout << endl << endl;
//
//		int brr[LEN];
//		memset(brr, 0, sizeof(brr));
//
//		for (int i = 1; i < cnt; i++)
//		{
//			for (int j = i + 1; j < cnt; j++)
//			{
//				int temp = gcd(arr[i], arr[j]);
//				if (temp == 1 && arr[i] * arr[j] == n)
//				{
//					brr[i] = 1;
//					brr[j] = 1;
//					break;
//				}
//				else
//				{
//					continue;
//				}
//			}
//		}
//
//		bool res = true;
//		for (int i = 1; i < cnt; i++)
//		{
//			if (brr[i] == 0)
//			{
//				res = false;
//			}
//		}
//		if (res)
//		{
//			cout << "是有补格！" << endl << endl;
//		}
//		else
//		{
//			cout << "不是有补格！" << endl << endl;
//		}
//		memset(arr, 0, sizeof(arr));
//		memset(brr, 0, sizeof(brr));
//
//		cout << "请输入一个整数（>0） : ";
//	}
//	return 0;
//}
//
//int gcd(int n, int m)   //求最大公约数
//{
//	if (n < m)
//	{
//		int temp = n;
//		n = m;
//		m = temp;
//	}
//	int remainer = n % m;
//	while (remainer)
//	{
//		n = m;
//		m = remainer;
//		remainer = n % m;
//	}
//	return m;
//}