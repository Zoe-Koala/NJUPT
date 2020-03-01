
#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstdlib>
#define Size 1000
using namespace std;
int n, m;


int G[Size][Size];

void Generate()  //�������ͼ
{
	printf("��������%d�����%d���ߵļ�����ͼ......\n", n, m);
	int cnt = 0;
	srand(time(NULL));
	while (cnt < m)
	{
		int x = rand() % n;
		int y = rand() % n;
		if (x != y && G[x][y] == 0)
		{
			G[x][y] = 1;
			G[y][x] = 1;
			cnt++;
		}
	}
	printf("�������\n\n");
	if (n <= 10)
	{
		printf("ͼ���ڽӾ���Ϊ:\n");
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				printf("%d ", G[i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}
}


int Judge()  //�ж�(��)ŷ��ͼ
{
	int flag = 0;
	for (int i = 0; i < n; i++)
	{
		int cnt = 0;
		for (int j = 0; j < n; j++)
		{
			if (G[i][j] == 1)
			{
				cnt++;
			}
		}
		if (cnt % 2 == 1)
		{
			flag++;
		}
	}
	if (flag == 0)
	{
		return 0;  //ŷ����·
	}
	else if (flag == 2)
	{
		return 1; //ŷ��·
	}
	else
	{
		return -1; //����ŷ��·Ҳ����ŷ����·
	}
}


int P[Size][Size];  //�ɴ��Ծ���
int T[Size][Size]; //��ʱ���G��n�η��ľ���
int TT[Size][Size];

int JudgeLianTong()  //�ж���ͨ��
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			P[i][j] = G[i][j];
			T[i][j] = G[i][j];
		}
	}
	for (int k = 2; k <= n; k++)  //n��4�η����Ӷ�,����ɴ��Ծ���
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				int t = 0;
				for (int a = 0; a < n; a++)
				{
					t += T[i][a] * G[a][j];
				}
				if (t == 0)
				{
					TT[i][j] = 0;
				}
				else
				{
					TT[i][j] = 1;
				}
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				T[i][j] = TT[i][j];
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (T[i][j] > 0 || P[i][j] > 0)
				{
					P[i][j] = 1;
				}
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i != j && P[i][j] == 0)
			{
				return 0;
			}
		}
	}
	return 1;
}



int choice, has;
int vis[Size][Size];
int record[Size];
int cnt;
void FindLu(int cur)
{
	if (choice == 1 && has == 1) return;
	if (cnt == m + 1)
	{
		for (int i = 0; i < cnt; i++)
		{
			if (i == 0) printf("%d", record[i]);
			else printf("->%d", record[i]);
		}
		printf("\n");
		has = 1;
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			if (G[cur][i] == 1 && vis[cur][i] == 0)
			{
				vis[i][cur] = vis[cur][i] = 1;
				record[cnt++] = i;
				FindLu(i);
				cnt--;
				vis[i][cur] = vis[cur][i] = 0;
			}
		}
	}
}








int main()
{
	do
	{
		printf("����������ͼ�Ľ�����:");
		scanf_s("%d", &n);
		printf("������ߵĸ���:");
		scanf_s("%d", &m);
		if (m > n*(n - 1) / 2)
		{
			printf("%d����������ͼ�����%d����\n", n, n*(n - 1) / 2);
		}
	} while (m > n*(n - 1) / 2);    //�ж�n��m�ĺ�����
	Generate();  //�������ͼ
	if (JudgeLianTong() == 0)   //�ж���ͨ��
	{
		printf("���ͼ����һ����ͨͼ������Ҳ����ŷ��ͼ�Ͱ�ŷ��ͼ\n");
	}
	else
	{
		printf("\n���ͼ����ͨͼ\n");
		int tmp = Judge();  //�ж�(��)ŷ��ͼ
		if (tmp == 0)
		{
			printf("���ͼ��һ�� ŷ��ͼ\n");
			printf("-----------------1.��ӡһ��ŷ����·------------------\n");
			printf("-----------------2.��ӡ����ŷ����·------------------\n");
			printf("          �������ѡ��:");
			scanf_s("%d", &choice);
			if (choice == 1)
			{
				printf("����һ��ŷ����·Ϊ:\n");
				record[cnt++] = 0;
				FindLu(0);  //�ҳ���·
				cnt--;
			}
			else if (choice == 2)
			{
				printf("���е�ŷ����·Ϊ:\n");
				for (int i = 0; i < n; i++)
				{
					record[cnt++] = i;
					FindLu(i);
					cnt--;
				}
			}
			else
			{
				printf_s("-----------------��������-----------------\n");
				system("pause");
			}
		}
		else if (tmp == 1)
		{
			printf("���ͼ��һ�� ��ŷ��ͼ\n");
			printf("-----------------1.��ӡһ��ŷ��·------------------\n");
			printf("-----------------2.��ӡ����ŷ��·------------------\n");
			printf("          �������ѡ��:");
			scanf_s("%d", &choice);
			if (choice == 1)
			{
				for (int i = 0; i < n; i++)
				{
					int t = 0;
					for (int j = 0; j < n; j++)
					{
						if (G[i][j] == 1)
						{
							t++;
						}
					}
					if (t % 2 == 1)
					{
						record[cnt++] = i;
						FindLu(i);
						cnt--;
						break;
					}
				}
			}
			else if (choice == 2)
			{
				printf("���е�ŷ��·Ϊ:\n");
				for (int i = 0; i < n; i++)
				{
					int t = 0;
					for (int j = 0; j < n; j++)
					{
						if (G[i][j] == 1)
						{
							t++;
						}
					}
					if (t % 2 == 1)
					{
						record[cnt++] = i;
						FindLu(i);
						cnt--;
					}
				}
			}
			else
			{
				printf("-----------------��������-----------------\n");
			}
		}
		else
		{
			printf("���ͼ�Ȳ���ŷ��ͼ��Ҳ���ǰ�ŷ��ͼ\n");
		}
	}
	system("pause");
	return 0;
}