/*订单：选择产品类型显示相应产品、库存和价格，
录入需要购买的产品和数量，生成订单，
连同下单时间存入订单文件中*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
const unsigned char* COMPLICE_DATA = __DATE__;
const unsigned char* COMPLICE_TIME = __TIME__;
struct Goods
{
	char name[20];
	char type[20];
	char cost[20];
	char stock[20];
};
typedef struct Goods Goods;
void order()
{
	FILE *fp;
	Goods g[100],G[100];
	int i=0,j=0,n,m,k;
	char ty[20],na[20];
	const char*head="名称 类型    价格   购买数量  购买时间\n";
	fp=fopen("D:\\file2.txt","r");
	if(fp==0)
	{
		printf("file error!");
		exit (1);
	}
	printf("请选择您所需要的产品类型(aa,bb,cc,dd):\n");
	scanf("%s",ty);;
	fscanf(fp,"%[^\n]s",g);// <-----读最前面一行
		printf("%s\n",g);
	fscanf(fp,"%s%s%s%s\n",&g[i].name,&g[i].type,&g[i].cost,&g[i].stock);	
	while(!feof(fp))
    {   
		i++;
		fscanf(fp,"%s%s%s%s\n",&g[i].name,&g[i].type,&g[i].cost,&g[i].stock);
		n=i;
	}
	for(i=0;i<n;i++)
	{
		if(strcmp(ty,g[i].type)==0)
		{
			printf("%s\t%s\t%s\t%s\n",g[i].name,g[i].type,g[i].cost,g[i].stock);
			G[j]=g[i];
			j++;
			k=j;
		}
	}
	fclose(fp);
	fp=fopen("D:\\order.txt","a+");
	if(fp==0)
	{
		printf("file error!\n");
		exit (1);
	}
	fputs(head,fp);
	printf("您所需要购买的产品和数量：\n");
	scanf("%s%d",na,&m);
	for(i=0;i<k;i++)
	{
		if(strcmp(na,G[i].name)==0)
		{
			printf("名称：%s   类型：%s   价格：%s   购买数量%d\n",G[i].name,G[i].type,G[i].cost,m);
		    fprintf(fp,"%s\t%s\t%s\t%d\t",G[i].name,G[i].type,G[i].cost,m);
		}
	}
	printf("%s\t",COMPLICE_DATA);
    printf("%s\n",COMPLICE_TIME);
	fprintf(fp,"%s\t%s\n",COMPLICE_DATA,COMPLICE_TIME);
	fclose(fp);
}