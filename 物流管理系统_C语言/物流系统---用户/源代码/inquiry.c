/*��ѯ*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void inquiry( )
{
	/*��simple��ѯ������ʱ���ѯ���ɵĶ���*/
	FILE *fp;
	int num=0,j=0;
	double cost;
	char *token;
	char arr[200][200]={""};
	char ptr1[200][200]={""},ptr2[200][200]={""};
	int count=0;
	char find_str1[100],find_str2[100],find_str3[100];
	char file_str[1024];
	getchar();
	printf("�򵥲�ѯ/����������Ҫ��ѯ�����ڣ�\n");
	gets(find_str1);
	fp=fopen("D:\\order.txt","r");
	if(fp==NULL)
	{
		printf("file error!\n");
		exit(1);
	}
	printf("����   ����    �۸� ��������    ����ʱ��\n");
	while(fgets(file_str,sizeof(file_str),fp))
	{
		if(strstr(file_str,find_str1))
	         printf("%s",file_str);
	}
	fclose(fp);
	printf("*******************************************\n");

/*ģ��vague��ѯ�������������ؼ�����ʾ��Ӧ��Ʒ����Ӧ�Ķ�����Ϣ*/

	printf("ģ����ѯ/����������Ҫ���ҵĹؼ��֣�\n");
	gets(find_str2);
	fp=fopen("D:\\order.txt","r");
	if(fp==NULL)
	{
		printf("file error!\n");
		exit(1);
	}
	while(fgets(file_str,sizeof(file_str),fp))
	{
		if(strstr(file_str,find_str2))
	         printf("%s",file_str);
	}
	fclose(fp);
	fp=fopen("D:\\file2.txt","r");
	printf("����  ����   �۸�  ���\n");
	while(fgets(file_str,sizeof(file_str),fp))
	{
		if(strstr(file_str,find_str2))
	         printf("%s\n",file_str);
	}
	fclose(fp);
	printf("*******************************************\n");

/*������ѯ�������Ʒ������ʾһ��ʱ���ڵĹ�������������Լ��۸����Ϣ*/
	
	printf("������ѯ/�������Ʒ���ƣ�\n");
	gets(find_str3);
    fp=fopen("D:\\order.txt","r");
	if(fp==NULL)
	{
		printf("file error!\n");
		exit(1);
	}
	printf("����   �������   ��������   �۸�\n");
	while(fgets(file_str,sizeof(file_str),fp))
	{
		int i=0;
		if(strstr(file_str,find_str3))
		{
			//printf("%s",file_str);
			count++;
			token=strtok(file_str,"\t");
			while(token)
			{
				strcpy(arr[i],token);
				if(i==3)
				{
					strcpy(ptr1[j],arr[3]);
					strcpy(ptr2[0],arr[2]);
				    num+=atoi(ptr1[j]);
					cost=atoi(ptr2[0]);
					j++;
				}
				i++;
				token=strtok(NULL,"\t");
			}
		}
	}
	printf("%s\t%d\t%d\t%lf\n",find_str3,count,num,cost);
	fclose(fp);
}