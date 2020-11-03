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
		
		// 定义字符串缓冲区，并接收用户输入
		wchar_t again[10];
		InputBox(again, 10, L"是否重新开始？重新开始请输入1");
		// 将用户输入转换为数字
		flag = _wtoi(again);
	}
	return 0;
}
