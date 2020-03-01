#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Goods
{
	char name[20];
	char type[20];
	char cost[20];
	char stock[20];
};
typedef struct Goods Goods;
void expand()
{
	Goods g[100];
	FILE *fp;
	char *token;
	int j=0,k=9,num[200]={0};
	char file_str[1024],find_str[100]="2019";
	char ptr[200][200];
	char arr[200][200];
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
		     {
			     strcpy(arr[i],token);
				 if(i==3)
				 {
					 strcpy(ptr[j],arr[3]);
					 num[j]=atoi(ptr[j]);
					 if(num[j]>k)
						 k=num[j];
					 j++;
				 }
				 i++;
			     token=strtok(NULL,"\t");
		     }
		}
	}
    printf("您一次性购买次数最多产品的数量是:%d\n",k);
	printf("为您推荐：ABC\n");
	fclose(fp);
}
