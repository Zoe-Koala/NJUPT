#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include "head.h"
int main()
{   
	//��ҳ����
	int i=1,n;
	printf("*********************************************\n");
	printf(" \n");
    printf("            ");printf("����ϵͳ�����û�\n");
	printf(" \n");
	printf("*********************************************\n");
	getchar();
	system("cls");
	login();
	getchar();
	system("cls");
	while(i)
	{
	    printf("�����Ʒ�����ɶ���������������������1\n");
	    printf("��ѯ��������ʾ����������������������2\n");
	    printf("ͳ�ƹ�����á�����������������������3\n");
	    printf("������Ϣ��������������������������4\n");
	    printf("������������Ҫִ�еĲ�����");
	    scanf("%d",&n);
	    switch(n)
	    {
	    case 1:
	     	order();
		    break;
	    case 2:
		inquiry();
		    break;
	    case 3:
		    count();
		    break;
	    case 4:
	    	personal();
	 	    break;
	    }
		printf("���Ƿ�Ҫ����������\n");
		printf("��0��\t�ǣ�1��\n");
		scanf("%d",&i);
		system("cls");
	}
	expand();
	return 0;
}