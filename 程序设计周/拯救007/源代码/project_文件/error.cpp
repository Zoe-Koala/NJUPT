#include "error.h"
#include <stdio.h>
#include <stdlib.h>

//��ӡ������Ϣ�����˳�����
void Error(const char* msg)
{
	if (NULL != msg)
		fprintf(stderr, "%s\n", msg);
	exit(-1);
}

//��ӡ������Ϣ�������˳�����
void Warning(const char* msg)
{
	if (NULL != msg)
		fprintf(stderr, "%s\n", msg);
}