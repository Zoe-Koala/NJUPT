#include "error.h"
#include <stdio.h>
#include <stdlib.h>

//打印错误信息，并退出程序
void Error(const char* msg)
{
	if (NULL != msg)
		fprintf(stderr, "%s\n", msg);
	exit(-1);
}

//打印警告信息，但不退出程序
void Warning(const char* msg)
{
	if (NULL != msg)
		fprintf(stderr, "%s\n", msg);
}