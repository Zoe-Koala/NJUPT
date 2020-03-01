//#include <iostream>
//using namespace std;
//
//const int LEN = 140 + 10;
//int arr[LEN][2 + 10];  //�洢����Ԫ��
//int relation[LEN][LEN]; //��ϵ����
//int n; //����Ԫ�ظ���
//int num; //���Ϲ�ϵ����
//void Reflexivity();
//void Symmetry();
//void Transmission();
//void Irreflexivity();
//void Irsymmetry();
//
//int main()
//{
//	cout << "�����뼯���е�Ԫ�ظ���:";
//	cin >> n;
//	int m;
//	cout << "�����뼯���е�Ԫ��:";
//	for (int i = 0; i < n; i++)
//		cin >> m;
//	cout << "�����뼯���еĹ�ϵ����:";
//	cin >> num;
//	cout << "�����뼯���еĹ�ϵԪ�أ�һ����" << num << "�Թ�ϵ" << endl;
//	memset(arr, 0, sizeof(arr));               //��ʼ��
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
//	cout << "�����ϵ���� : " << endl;
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
//	cout << "�жϽ��� : " << endl;
//	
//	Reflexivity();                 //�ж��Ƿ������Է���
//	
//	Symmetry();                    //�ж��Ƿ�����Գ���
//	
//	Transmission();                 //�ж��Ƿ����㴫����
//	
//	Irreflexivity();                  //�ж��Ƿ����㷴�Է���
//	
//	Irsymmetry();                  //�ж��Ƿ����㷴�Գ���
//	getchar();
//	getchar();
//	return 0;
//}
//
//void Reflexivity()                 //�ж��Ƿ������Է���
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
//		cout << "�����Է���" << endl;
//	}
//	else
//	{
//		cout << "�������Է���" << endl;
//	}
//}
//
//void Symmetry()                      //�ж��Ƿ�����Գ���
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
//		cout << "����Գ���" << endl;
//	}
//	else
//	{
//		cout << "������Գ���" << endl;
//	}
//}
//
//void Transmission()                        //�ж��Ƿ����㴫����
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
//		cout << "���㴫����" << endl;
//	}
//	else
//	{
//		cout << "�����㴫����" << endl;
//	}
//}
//
//void Irreflexivity()               //�ж��Ƿ����㷴�Է���
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
//		cout << "���㷴�Է���" << endl;
//	}
//	else
//	{
//		cout << "�����㷴�Է���" << endl;
//	}
//
//}
//
//void Irsymmetry()                        //�ж��Ƿ����㷴�Գ���
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
//		cout << "���㷴�Գ���" << endl;
//	}
//	else
//	{
//		cout << "�����㷴�Գ���" << endl;
//	}
//}
