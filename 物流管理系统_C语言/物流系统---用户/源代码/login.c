/*登录：输入用户名口令完成登录*/
#include <stdio.h>
#include <windows.h>
void UserReg(); 
void Login();
struct Stuff
{
	char name[10];
	char password[20];
}stu;
void login()
{
	int selectNum;
	printf_s("\nRegistered and Login system\n\n");
	printf_s("1 UserReg\n");
	printf_s("2 Login\n");
	printf_s("3 Exit\n");
	scanf_s("%d",&selectNum);
	switch(selectNum)
	{
	case 1:UserReg();
		break;
	case 2:Login();
		break;
	case 3:printf("Exit Program!\n");
		exit(1);
		break;
	}
}
void UserReg()
{
	FILE *fp;
	char Linedata[50]={0},User[20],Pass[20];
	fp=fopen("D:\\file1.txt","a");
	printf_s("Registered Account:\n");
	printf_s("Please input your name:\n");
	fflush(stdin);
	gets(stu.name);
	printf("Please input your password:\n");
	fflush(stdin);
	gets(stu.password);
	strcpy(Linedata,stu.name);
	strcat(Linedata," ");
	strcat(Linedata,stu.password);
	strcat(Linedata,"\n");
	fputs(Linedata,fp);
	fclose(fp);
	printf("Registered Success!\n");
}
void Login()
{
	FILE *fp;
	int find=0;
	char Userstrcat[50]={0};
	char Userdata[50]={0};
	fp=fopen("D:\\file1.txt","r");
	printf("Login Account:\n");
	printf("Please input Username:\n");
	fflush(stdin);
	gets(stu.name);
	printf("Please input Password:\n");
	fflush(stdin);
	gets(stu.password);
	strcpy(Userstrcat,stu.name);
	strcat(Userstrcat," ");
	strcat(Userstrcat,stu.password);
	strcat(Userstrcat,"\n");
	while(!feof(fp))
	{
		fgets(Userdata,19,fp);
		if(strcmp(Userdata,Userstrcat)==0 )
		{
			printf("OK!Login Success!\n");
			printf("Welcome back,%s!\n",stu.name);
			find=1;
			break;
		}
	}
	if (!find)
	{
		printf("Username or Password incorrect!\n");
	}
	fclose(fp);
	getchar();
}