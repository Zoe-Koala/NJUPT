#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Goods
{
	char name[20];//��Ʒ����
	char ads[20];//��ʧ�ص�
	char time[20];//ʱ��
	char type[20];//����
	char tt[20];//�ͺ�
	char flag[20];//����״̬
	char time1[20];//����ʱ��
	char id[20];//������ѧ��
	char phone[20];//�������ֻ�
};
struct Goods g[100];//���еǼǹ�����Ʒ
struct Goods g1[20];//����Ǽǵ���Ʒ
int len=0;
int len1=0;

int type=-1;

void file_input()//��ȡ�ļ�
{
	int i=0;
	FILE *fo=fopen("goods.txt","r");
	while(6==fscanf(fo,"%s %s %s %s %s %s",g[i].name,g[i].ads,g[i].time,g[i].type,g[i].tt,g[i].flag))
	{
		if(strcmp(g[i].flag,"������")==0)
		{
			fscanf(fo,"%s %s %s",g[i].time1,g[i].id,g[i].phone);
		}
		i++;

	}
	len=i;
	fclose(fo);
}

void file_output()//�����ļ�
{
	int i;
	FILE *fo=fopen("goods.txt","w");
	for(i=0;i<len;i++)
	{
		fprintf(fo,"%s %s %s %s %s %s ",g[i].name,g[i].ads,g[i].time,g[i].type,g[i].tt,g[i].flag);
		if(strcmp(g[i].flag,"������")==0)
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
	printf("�����뵱�����ڣ�");
	scanf("%s",filename);
	strcat(filename,".txt");
	fo=fopen(filename,"w");
	for(i=0;i<len1;i++)
	{
		fprintf(fo,"%s %s %s %s %s %s\n",g1[i].name,g1[i].ads,g1[i].time,g1[i].type,g1[i].tt,g1[i].flag);
		if(strcmp(g1[i].flag,"������")==0)
		{
			fprintf(fo,"%s %s %s",g[i].time1,g[i].id,g[i].phone);
		}
		fprintf(fo,"\n");
	}
	fclose(fo);
}

void show(struct Goods g)
{
	printf("���֣�%s   ��ʧ�ص㣺%s   ʱ�䣺%s   ���ͣ�%s   �ͺţ�%s\n",g.name,g.ads,g.time,g.type,g.tt);
	if(strcmp(g.flag,"������")==0)
	{
		printf("  ����״̬��%s   ������ѧ�ţ�%s   ��ϵ�绰��%s\n",g.flag,g.id,g.phone);
	}
	else
	{
		printf("  ����״̬��%s\n",g.flag);
	}
	printf("\n");
}

void op1()//�Ǽ�
{
	int n;
	char psw[20];
	if(type==2)
	{
		printf("ѧ���Ǽ���Ҫ����Աͬ�⣡\n");
		printf("���������Ա���룺");
		scanf("%s",psw);
		if(strcmp(psw,"admin")==0)
		{
			printf("������ȷ��\n");
		}
		else
		{
			printf("������󣡷�����һҳ��\n");
			return;
            //exit(0);
		}
	}
	printf("��������Ҫ�Ǽǵ���Ʒ������");
	scanf("%d",&n);
	while(n--)
	{
		printf("��������Ʒ����");
		scanf("%s",g[len].name);
		strcpy(g1[len1].name,g[len].name);
		printf("��������ʧ�ص㣺");
		scanf("%s",g[len].ads);
		strcpy(g1[len1].ads,g[len].ads);
		printf("��������ʧʱ�䣺");
		scanf("%s",g[len].time);
		strcpy(g1[len1].time,g[len].time);
		printf("���������ͣ�");
		scanf("%s",g[len].type);
		strcpy(g1[len1].type,g[len].type);
		printf("�������ͺţ�");
		scanf("%s",g[len].tt);
		strcpy(g1[len1].tt,g[len].tt);

		strcpy(g1[len1].flag,"δ����");
		strcpy(g[len].flag,"δ����");

		len++;
		len1++;

		printf("����Ʒ�Ǽǳɹ���\n\n");
	}
}

void op2()//��ѯ
{
	int op=0;
	int i,f=0;
	char ads[20],time[20],type[20],tt[20];
	printf("1.����ʧ�ص��ѯ\n");
	printf("2.��ʱ���ѯ\n");
	printf("3.����Ʒ�����ѯ\n");
	printf("4.���ͺŲ�ѯ\n");
	printf("��������Ҫ���еĲ�����");
	scanf("%d",&op);
	if(op==1)
	{
		printf("������Ҫ��ѯ����ʧ�ص㣺");
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
			printf("û�в鵽�������Ʒ��\n");
		}
	}
	else if(op==2)
	{
		printf("������Ҫ��ѯ��ʱ�䣺");
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
			printf("û�в鵽�������Ʒ��\n");
		}
	}
	else if(op==3)
	{
		printf("������Ҫ��ѯ����Ʒ���ࣺ");
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
			printf("û�в鵽�������Ʒ��\n");
		}
	}
	else if(op==4)
	{
		printf("������Ҫ��ѯ���ͺţ�");
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
			printf("û�в鵽�������Ʒ��\n");
		}
	}
	else
	{
		printf("������󣡷�����һҳ\n");
	}

}
void op3()//����ʧʱ������
{
	int i,j;
	struct Goods t;
	printf("������Ʒ��ʧʱ���������\n");
	for(i=0;i<len;i++)
		for(j=0;j<len-i-1;j++)
		{
			t=g[j];
			g[j]=g[j+1];
			g[j+1]=t;
		}

	printf("������ϣ�\n\n");
		for(i=0;i<len;i++)
		{
			show(g[i]);
		}
}
void op4()//��Ʒ����
{
	char name[20];
	int i,f=0;
	printf("��������Ҫ�������Ʒ���ƣ�");
	scanf("%s",name);
	for(i=0;i<len;i++)
	{
		if(strcmp(name,g[i].name)==0)
		{
			f++;
			printf("����ɹ���\n");
			strcpy(g[i].flag,"������");
			printf("����������ʱ�䣺");
			scanf("%s",g[i].time);
			printf("������������ѧ�ţ�");
			scanf("%s",g[i].id);
			printf("��������������ϵ��ʽ��");
			scanf("%s",g[i].phone);
			break;
		}
	}
	if(f==0)
		printf("û���ҵ�����Ʒ��\n");

}
void op5()//��Ʒ����
{
	int i,t=0;
	char time[20];//һ��ǰ��ʱ��
	printf("������һ��ǰ��ʱ�䣺");
	scanf("%s",time);
	for(i=0;i<len;i++)
	{
		if(strcmp(g[i].time,time)<0&&strcmp(g[i].flag,"δ����")==0)
		{
			if(t==0)
			{
				printf("Ҫ����������Ʒ���£�\n");
			}
			t++;
			printf("��%d������Ʒ�� ",t);
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
		printf("1.�Ǽ���Ʒ\n");
		printf("2.��ѯ��Ʒ\n");
		printf("3.����\n");
		printf("4.��Ʒ����\n");
		printf("5.��Ʒ����\n");
		printf("0.�˳�\n");
		printf("��������Ҫ���еĲ�����");
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
			printf("�˳��ɹ�!\n");
			//file_output1();
			exit(0);
		}
		else
		{
			printf("����������������룡\n");
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
		printf("1.������Ա��¼\n");//�û��������붼��admin
		printf("2.ֵ��ѧ����¼\n");//ֻҪ�û�����������ͬ���ɵ�¼
		printf("0.�˳�\n");
		printf("��������Ҫ���еĲ�����");
		scanf("%d",&op);
		if(op==1)
		{
			printf("�������û�����");
			scanf("%s",user);
			printf("���������룺");
			scanf("%s",psw);
			if(strcmp(user,"admin")==0&&strcmp(psw,"admin")==0)
			{
				menu();
				type=1;
			}
			else
			{
				printf("�û�����������������²�����\n");
			}
		}
		else if(op==2)
		{
			printf("�������û�����");
			scanf("%s",user);
			printf("���������룺");
			scanf("%s",psw);
			if(strcmp(user,psw)==0)
			{
                type=2;
				menu();
				
			}
			else
			{
				printf("�û�����������������²�����\n");
			}
		}
		else if(op==0)
		{
			printf("�˳��ɹ�!\n");
			break;
		}
		else
		{
			printf("����������������룡\n");
		}
	}
    return 0;
}
