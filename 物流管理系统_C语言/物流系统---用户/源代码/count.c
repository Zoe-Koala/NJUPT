/*ͳ�ƣ�ͳ��ʱ����ڻ���ĳ�ֲ�Ʒ�Ĺ������*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void count()
{
	FILE *fp;
	char *token;
	char find_str[100];
	char file_str[1024];
	char arr[200][200]={""};
	char ptr1[200][200]={""},ptr2[200][200]={""};
	double cost;
	int num=0,j=0;
	printf("*******************************************\n");
	printf("ͳ��/������������Ҫ��ѯ�Ĳ�Ʒ���ƣ�\n");
	getchar();
	gets(find_str);
	printf("����    ������ã�\n");
	fp=fopen("D:\\order.txt","r");
	if(fp==NULL)
	{
		printf("file error!\n");
		exit(1);
	}
	while(fgets(file_str,sizeof(file_str),fp))
	{
		int i=0;
	    if(strstr(file_str,find_str))
		{
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
	printf("%s\t%lf\n",find_str,num*cost);
}