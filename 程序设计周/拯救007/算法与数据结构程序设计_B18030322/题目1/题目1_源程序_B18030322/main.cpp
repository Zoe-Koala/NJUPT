#include "Graph.h"
#include "Deque.h"
#include "error.h"
#include "draw.h"

int main()
{
	int flag = 1;
	while (flag==1)
	{
		graph_draw();
		
		// �����ַ������������������û�����
		wchar_t again[10];
		InputBox(again, 10, L"�Ƿ����¿�ʼ�����¿�ʼ������1");
		// ���û�����ת��Ϊ����
		flag = _wtoi(again);
	}
	return 0;
}
