#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Goods
{
	char name[20];//物品名称
	char ads[20];//遗失地点
	char time[20];//时间
	char type[20];//类型
	char tt[20];//型号
	char flag[20];//认领状态
	char time1[20];//认领时间
	char id[20];//认领人学号
	char phone[20];//认领人手机
};
struct Goods g[100];//所有登记过的物品
struct Goods g1[20];//当天登记的物品
int len=0;
int len1=0;

int type=-1;

void file_input()//读取文件
{
	int i=0;
	FILE *fo=fopen("goods.txt","r");
	while(6==fscanf(fo,"%s %s %s %s %s %s",g[i].name,g[i].ads,g[i].time,g[i].type,g[i].tt,g[i].flag))
	{
		if(strcmp(g[i].flag,"已认领")==0)
		{
			fscanf(fo,"%s %s %s",g[i].time1,g[i].id,g[i].phone);
		}
		i++;

	}
	len=i;
	fclose(fo);
}

void file_output()//保存文件
{
	int i;
	FILE *fo=fopen("goods.txt","w");
	for(i=0;i<len;i++)
	{
		fprintf(fo,"%s %s %s %s %s %s ",g[i].name,g[i].ads,g[i].time,g[i].type,g[i].tt,g[i].flag);
		if(strcmp(g[i].flag,"已认领")==0)
		{
			fprintf(fo,"%s %s %s",g[i].time1,g[i].id,g[i].phone);
		}
		fprintf(fo,"\n");
	}
	fclose(fo);
}

void file_output1()
{
	int i;
	FILE *fo;
	char filename[100];
	printf("请输入当天日期：");
	scanf("%s",filename);
	strcat(filename,".txt");
	fo=fopen(filename,"w");
	for(i=0;i<len1;i++)
	{
		fprintf(fo,"%s %s %s %s %s %s\n",g1[i].name,g1[i].ads,g1[i].time,g1[i].type,g1[i].tt,g1[i].flag);
		if(strcmp(g1[i].flag,"已认领")==0)
		{
			fprintf(fo,"%s %s %s",g[i].time1,g[i].id,g[i].phone);
		}
		fprintf(fo,"\n");
	}
	fclose(fo);
}

void show(struct Goods g)
{
	printf("名字：%s   遗失地点：%s   时间：%s   类型：%s   型号：%s\n",g.name,g.ads,g.time,g.type,g.tt);
	if(strcmp(g.flag,"已认领")==0)
	{
		printf("  认领状态：%s   认领人学号：%s   联系电话：%s\n",g.flag,g.id,g.phone);
	}
	else
	{
		printf("  认领状态：%s\n",g.flag);
	}
	printf("\n");
}

void op1()//登记
{
	int n;
	char psw[20];
	if(type==2)
	{
		printf("学生登记需要管理员同意！\n");
		printf("请输入管理员密码：");
		scanf("%s",psw);
		if(strcmp(psw,"admin")==0)
		{
			printf("密码正确！\n");
		}
		else
		{
			printf("密码错误！返回上一页！\n");
			return;
            //exit(0);
		}
	}
	printf("请输入您要登记的物品数量：");
	scanf("%d",&n);
	while(n--)
	{
		printf("请输入物品名：");
		scanf("%s",g[len].name);
		strcpy(g1[len1].name,g[len].name);
		printf("请输入遗失地点：");
		scanf("%s",g[len].ads);
		strcpy(g1[len1].ads,g[len].ads);
		printf("请输入遗失时间：");
		scanf("%s",g[len].time);
		strcpy(g1[len1].time,g[len].time);
		printf("请输入类型：");
		scanf("%s",g[len].type);
		strcpy(g1[len1].type,g[len].type);
		printf("请输入型号：");
		scanf("%s",g[len].tt);
		strcpy(g1[len1].tt,g[len].tt);

		strcpy(g1[len1].flag,"未认领");
		strcpy(g[len].flag,"未认领");

		len++;
		len1++;

		printf("该物品登记成功！\n\n");
	}
}

void op2()//查询
{
	int op=0;
	int i,f=0;
	char ads[20],time[20],type[20],tt[20];
	printf("1.按遗失地点查询\n");
	printf("2.按时间查询\n");
	printf("3.按物品种类查询\n");
	printf("4.按型号查询\n");
	printf("请输入您要进行的操作：");
	scanf("%d",&op);
	if(op==1)
	{
		printf("请输入要查询的遗失地点：");
		scanf("%s",ads);
		for(i=0;i<len;i++)
		{
			if(strcmp(g[i].ads,ads)==0)
			{
				f++;
				show(g[i]);
			}
		}
		if(f==0)
		{
			printf("没有查到该相关物品！\n");
		}
	}
	else if(op==2)
	{
		printf("请输入要查询的时间：");
		scanf("%s",time);
		for(i=0;i<len;i++)
		{
			if(strcmp(g[i].time,time)==0)
			{
				f++;
				show(g[i]);
			}
		}
		if(f==0)
		{
			printf("没有查到该相关物品！\n");
		}
	}
	else if(op==3)
	{
		printf("请输入要查询的物品种类：");
		scanf("%s",type);
		for(i=0;i<len;i++)
		{
			if(strcmp(g[i].type,type)==0)
			{
				f++;
				show(g[i]);
			}
		}
		if(f==0)
		{
			printf("没有查到该相关物品！\n");
		}
	}
	else if(op==4)
	{
		printf("请输入要查询的型号：");
		scanf("%s",tt);
		for(i=0;i<len;i++)
		{
			if(strcmp(g[i].tt,tt)==0)
			{
				f++;
				show(g[i]);
			}
		}
		if(f==0)
		{
			printf("没有查到该相关物品！\n");
		}
	}
	else
	{
		printf("输入错误！返回上一页\n");
	}

}
void op3()//按遗失时间排序
{
	int i,j;
	struct Goods t;
	printf("将按物品遗失时间进行排序！\n");
	for(i=0;i<len;i++)
		for(j=0;j<len-i-1;j++)
		{
			t=g[j];
			g[j]=g[j+1];
			g[j+1]=t;
		}

	printf("排序完毕！\n\n");
		for(i=0;i<len;i++)
		{
			show(g[i]);
		}
}
void op4()//物品认领
{
	char name[20];
	int i,f=0;
	printf("请输入您要认领的物品名称：");
	scanf("%s",name);
	for(i=0;i<len;i++)
	{
		if(strcmp(name,g[i].name)==0)
		{
			f++;
			printf("认领成功！\n");
			strcpy(g[i].flag,"已认领");
			printf("请输入认领时间：");
			scanf("%s",g[i].time);
			printf("请输入认领人学号：");
			scanf("%s",g[i].id);
			printf("请输入认领人联系方式：");
			scanf("%s",g[i].phone);
			break;
		}
	}
	if(f==0)
		printf("没有找到该物品！\n");

}
void op5()//物品拍卖
{
	int i,t=0;
	char time[20];//一年前的时间
	printf("请输入一年前的时间：");
	scanf("%s",time);
	for(i=0;i<len;i++)
	{
		if(strcmp(g[i].time,time)<0&&strcmp(g[i].flag,"未认领")==0)
		{
			if(t==0)
			{
				printf("要拍卖的拍卖品如下：\n");
			}
			t++;
			printf("第%d件拍卖品： ",t);
			show(g[i]);
		}
	}

}

void menu()
{
	int op=0;
	while(1)
	{		
		op=0;
		printf("1.登记物品\n");
		printf("2.查询物品\n");
		printf("3.排序\n");
		printf("4.物品认领\n");
		printf("5.物品拍卖\n");
		printf("0.退出\n");
		printf("请输入你要进行的操作：");
		scanf("%d",&op);
		if(op==1)
		{
			op1();
		}
		else if(op==2)
		{
			op2();
		}
		else if(op==3)
		{
			op3();
		}
		else if(op==4)
		{
			op4();
		}
		else if(op==5)
		{
			op5();
		}
		else if(op==0)
		{
            file_output1();
			printf("退出成功!\n");
			//file_output1();
			exit(0);
		}
		else
		{
			printf("输入错误！请重新输入！\n");
		}
		file_output();
	}
}

int main()
{
	int op;
	char user[20],psw[20];
	type=-1;
    //file_output1();
	file_input();
    
	while(1)
	{
		op=0;
		printf("1.工作人员登录\n");//用户名和密码都是admin
		printf("2.值日学生登录\n");//只要用户名和密码相同即可登录
		printf("0.退出\n");
		printf("请输入你要进行的操作：");
		scanf("%d",&op);
		if(op==1)
		{
			printf("请输入用户名：");
			scanf("%s",user);
			printf("请输入密码：");
			scanf("%s",psw);
			if(strcmp(user,"admin")==0&&strcmp(psw,"admin")==0)
			{
				menu();
				type=1;
			}
			else
			{
				printf("用户名或密码错误！请重新操作！\n");
			}
		}
		else if(op==2)
		{
			printf("请输入用户名：");
			scanf("%s",user);
			printf("请输入密码：");
			scanf("%s",psw);
			if(strcmp(user,psw)==0)
			{
                type=2;
				menu();
				
			}
			else
			{
				printf("用户名或密码错误！请重新操作！\n");
			}
		}
		else if(op==0)
		{
			printf("退出成功!\n");
			break;
		}
		else
		{
			printf("输入错误！请重新输入！\n");
		}
	}
    return 0;
}
