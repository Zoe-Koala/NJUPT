//#include <iostream>
//using namespace std;
//
//const int LEN = 140 + 10;
//int arr[LEN][2 + 10];  //存储集合元素
//int relation[LEN][LEN]; //关系矩阵
//int n; //集合元素个数
//int num; //集合关系个数
//void Reflexivity();
//void Symmetry();
//void Transmission();
//void Irreflexivity();
//void Irsymmetry();
//
//int main()
//{
//	cout << "请输入集合中的元素个数:";
//	cin >> n;
//	int m;
//	cout << "请输入集合中的元素:";
//	for (int i = 0; i < n; i++)
//		cin >> m;
//	cout << "请输入集合中的关系个数:";
//	cin >> num;
//	cout << "请输入集合中的关系元素，一共有" << num << "对关系" << endl;
//	memset(arr, 0, sizeof(arr));               //初始化
//	memset(relation, 0, sizeof(relation));
//	int num1, num2;
//	for (int i = 1; i <= num; i++)
//	{
//		cin >> num1 >> num2;
//		arr[i][1] = num1;
//		arr[i][2] = num2;
//		relation[num1][num2] = 1;
//	}
//
//	cout << "输出关系矩阵 : " << endl;
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= n; j++)
//		{
//			cout << relation[i][j] << "     ";
//		}
//		cout << endl;
//	}
//	cout << endl;
//
//	cout << "判断结论 : " << endl;
//	
//	Reflexivity();                 //判断是否满足自反性
//	
//	Symmetry();                    //判断是否满足对称性
//	
//	Transmission();                 //判断是否满足传递性
//	
//	Irreflexivity();                  //判断是否满足反自反性
//	
//	Irsymmetry();                  //判断是否满足反对称性
//	getchar();
//	getchar();
//	return 0;
//}
//
//void Reflexivity()                 //判断是否满足自反性
//{
//	bool flag = true;
//	for (int i = 1; i <= n; i++)
//	{
//		if (relation[i][i] != 1)
//		{
//			flag = false;
//			break;
//		}
//	}
//	if (flag == true)
//	{
//		cout << "满足自反性" << endl;
//	}
//	else
//	{
//		cout << "不满足自反性" << endl;
//	}
//}
//
//void Symmetry()                      //判断是否满足对称性
//{
//	bool flag = true;
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= n; j++)
//		{
//			if (relation[i][j] != relation[j][i])
//			{
//				flag = false;
//			}
//		}
//	}
//	if (flag == true)
//	{
//		cout << "满足对称性" << endl;
//	}
//	else
//	{
//		cout << "不满足对称性" << endl;
//	}
//}
//
//void Transmission()                        //判断是否满足传递性
//{
//	bool flag = true;
//	for (int i = 1; i <= num - 1; i++)
//	{
//		for (int j = 2; j <= num; j++)
//		{
//			if (arr[i][2] == arr[j][1])
//			{
//				int num1 = arr[i][1], num2 = arr[j][2];
//				if (relation[num1][num2] != 1)
//				{
//					flag = false;
//					break;
//				}
//			}
//		}
//		if (flag == false)
//			break;
//	}
//	if (flag == true)
//	{
//		cout << "满足传递性" << endl;
//	}
//	else
//	{
//		cout << "不满足传递性" << endl;
//	}
//}
//
//void Irreflexivity()               //判断是否满足反自反性
//{
//	bool flag = true;
//	for (int i = 1; i <= n; i++)
//	{
//		if (relation[i][i] != 0)
//		{
//			flag = false;
//			break;
//		}
//	}
//	if (flag == true)
//	{
//		cout << "满足反自反性" << endl;
//	}
//	else
//	{
//		cout << "不满足反自反性" << endl;
//	}
//
//}
//
//void Irsymmetry()                        //判断是否满足反对称性
//{
//	bool flag = true;
//	for (int i = 1; i <= n - 1; i++)
//	{
//		for (int j = i + 1; j <= n; j++)
//		{
//			if (relation[i][j] == 1 && relation[j][i] == 1 && i != j)
//			{
//				flag = false;
//				break;
//			}
//		}
//	}
//	if (flag == true)
//	{
//		cout << "满足反对称性" << endl;
//	}
//	else
//	{
//		cout << "不满足反对称性" << endl;
//	}
//}
