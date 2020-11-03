#pragma once
#include <easyx.h>			// 引用图形库头文件
#include <conio.h>
#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "Graph.h"
#include "Deque.h"
#include "error.h"
#define width 760
#define height 600
//#define step_length 20

Graph read_case(FILE* InFile, int num, Vertex* Bank, Deque D);
void write_result(FILE* OutFile, Vertex Bank, Graph G, Deque D);
int graph_draw();