#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include "head.h"
int main()
{   
	//首页界面
	int i=1,n;
	printf("*********************************************\n");
	printf(" \n");
    printf("            ");printf("物流系统——用户\n");
	printf(" \n");
	printf("*********************************************\n");
	getchar();
	system("cls");
	login();
	getchar();
	system("cls");
	while(i)
	{
	    printf("购买产品、生成订单·········1\n");
	    printf("查询订单、显示订单·········2\n");
	    printf("统计购物费用············3\n");
	    printf("个人信息管理············4\n");
	    printf("请输入您所需要执行的操作：");
	    scanf("%d",&n);
	    switch(n)
	    {
	    case 1:
	     	order();
		    break;
	    case 2:
		inquiry();
		    break;
	    case 3:
		    count();
		    break;
	    case 4:
	    	personal();
	 	    break;
	    }
		printf("你是否要继续操作？\n");
		printf("否（0）\t是（1）\n");
		scanf("%d",&i);
		system("cls");
	}
	expand();
	return 0;
}