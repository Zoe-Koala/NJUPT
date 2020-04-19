/*查询*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void inquiry( )
{
	/*简单simple查询：依据时间查询生成的订单*/
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
	printf("简单查询/请输入您需要查询的日期：\n");
	gets(find_str1);
	fp=fopen("D:\\order.txt","r");
	if(fp==NULL)
	{
		printf("file error!\n");
		exit(1);
	}
	printf("名称   类型    价格 购买数量    购买时间\n");
	while(fgets(file_str,sizeof(file_str),fp))
	{
		if(strstr(file_str,find_str1))
	         printf("%s",file_str);
	}
	fclose(fp);
	printf("*******************************************\n");

/*模糊vague查询：能依据搜索关键字显示相应产品及相应的订单信息*/

	printf("模糊查询/请输入您需要查找的关键字：\n");
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
	printf("名称  类型   价格  库存\n");
	while(fgets(file_str,sizeof(file_str),fp))
	{
		if(strstr(file_str,find_str2))
	         printf("%s\n",file_str);
	}
	fclose(fp);
	printf("*******************************************\n");

/*关联查询：输入产品名称显示一段时间内的购买次数和数量以及价格等信息*/
	
	printf("关联查询/请输入产品名称：\n");
	gets(find_str3);
    fp=fopen("D:\\order.txt","r");
	if(fp==NULL)
	{
		printf("file error!\n");
		exit(1);
	}
	printf("名称   购买次数   购买数量   价格：\n");
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