/*������Ϣ�����޸�����ȸ��������޸�*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
struct Stuff
{
	char name[10];
	char password[20];
};
typedef struct Stuff Stuff;
void personal()
{
	Stuff stu;
	FILE *fp;
	char mima[20],mima1[20],mima2[20];
	printf("������ԭʼ���룺\n");
	getchar();
	gets(mima);
	fp=fopen("D:\\file1.txt","r+");
	if(fp==0)
	{
		printf("file error!\n");
		exit (1);
	}
	fscanf(fp,"%s",stu.name);
	fscanf(fp,"%s",stu.password);
		if(strcmp(mima,stu.password)==0)
		{
			 printf("\t������ȷ��\n");
			 printf("\t������������(��λ)��\n");
			 gets(mima1);
     		 printf("\t���ٴ����������루��λ����\n");
			 scanf("%s",mima2);
			 if(strcmp(mima1,mima2)==0)
			 {
				 printf("\t������ȷ��\n���μ����룡\n");
				 strcpy(stu.password,mima1);
				 rewind(fp);
				 fprintf(fp,"%s %s",stu.name,stu.password);
				 getch();
			 }
		     else
			 {
				 printf("\t�������벻һ�����޸�ʧ�ܣ�\n");
			 }
		}
		else
		{
			printf("�������\n");
		}
	fclose(fp);
}