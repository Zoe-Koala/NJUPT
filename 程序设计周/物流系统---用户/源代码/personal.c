/*个人信息管理：修改密码等个人资料修改*/
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
	printf("请输入原始密码：\n");
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
			 printf("\t密码正确！\n");
			 printf("\t请输入新密码(八位)：\n");
			 gets(mima1);
     		 printf("\t请再次输入新密码（八位）：\n");
			 scanf("%s",mima2);
			 if(strcmp(mima1,mima2)==0)
			 {
				 printf("\t密码正确！\n请牢记密码！\n");
				 strcpy(stu.password,mima1);
				 rewind(fp);
				 fprintf(fp,"%s %s",stu.name,stu.password);
				 getch();
			 }
		     else
			 {
				 printf("\t两次密码不一样！修改失败：\n");
			 }
		}
		else
		{
			printf("密码错误！\n");
		}
	fclose(fp);
}