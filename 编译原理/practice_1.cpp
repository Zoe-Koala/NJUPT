//#define _CRT_SECURE_NO_DEPRECATE；
//#define _CRT_SECURE_NO_WARNINGS；
//#pragma warning(disable:4996)；
//#include<string.h>
//#include<iostream>
//#include<fstream>
//using namespace std;
//
//bool DIGIT(char A)
//{
//	if (A >= '0' && A <= '9')
//		return true;
//	else
//		return false;
//}
//
//bool zimu(char A)
//{
//	if ((A >= 'A' && A <= 'Z') || (A >= 'a' && A <= 'z'))
//		return true;
//	return false;
//}
//
//bool REAERVE(char* a)
//{
//	if (strcmp(a, "if") == 0)
//	{
//		cout << "(1,'" << a << "' )" << endl;
//		return true;
//	}
//	if (strcmp(a, "int") == 0)
//	{
//		cout << "(1,'" << a << "' )" << endl;
//		return true;
//	}
//	if (strcmp(a, "for") == 0)
//	{
//		cout << "(1,'" << a << "' )" << endl;
//		return true;
//	}
//	if (strcmp(a, "while") == 0)
//	{
//		cout << "(1,'" << a << "' )" << endl;
//		return true;
//	}
//	if (strcmp(a, "do") == 0)
//	{
//		cout << "(1,'" << a << "' )" << endl;
//		return true;
//	}
//	if (strcmp(a, "return") == 0)
//	{
//		cout << "(1,'" << a << "' )" << endl;
//		return true;
//	}
//	if (strcmp(a, "back") == 0)
//	{
//		cout << "(1,'" << a << "' )" << endl;
//		return true;
//	}
//	if (strcmp(a, "continue") == 0)
//	{
//		cout << "(1,'" << a << "' )" << endl;
//		return true;
//	}
//	if (strcmp(a, "main") == 0)
//	{
//		cout << "(1,'" << a << "' )" << endl;
//		return true;
//	}
//	return false;
//}
//
//int main()
//{
//	char a;
//	FILE* f;
//	char CHAR;
//	char TOKEN[120];
//	f = fopen("ceshi.txt", "w");
//	if (f == NULL)
//	{
//		cout << "cannot creat file" << endl;
//		exit(0);
//	}
//	cout << "please input code(to the end of #)" << endl;
//	while ((a = getchar()) != '#')
//			fputc(a, f);
//	fclose(f);
//	cout << "over" << endl;
//
//	f = fopen("ceshi.txt", "r");
//	
//	while (CHAR = fgetc(f) != EOF)
//	{
//		while (CHAR != ' ')
//		{
//			if (zimu(CHAR))
//			{
//				int k = 0;
//				do {
//					TOKEN[k] = CHAR;
//					k++;
//				} while ((CHAR = fgetc(f)) != EOF && CHAR != ' ' && zimu(CHAR));
//				if (DIGIT(CHAR))
//				{
//					do {
//						TOKEN[k] = CHAR;
//						k++;
//					} while ((CHAR = fgetc(f)) != EOF && CHAR != ' ' && DIGIT(CHAR));
//				}
//				TOKEN[k] = '\0';
//				if(!(REAERVE(TOKEN)))
//					cout << "(2,'" << TOKEN << "' )" << endl;
//			}
//
//			if (DIGIT(CHAR))
//			{
//				int i = 0;
//				do {
//					TOKEN[i] = CHAR;
//					i++;
//				}while ((CHAR = fgetc(f)) != EOF && CHAR != ' ' && DIGIT(CHAR));
//				TOKEN[i] = '\0';
//				if (!REAERVE(TOKEN))
//					cout << "(3,'" << TOKEN << "' )" << endl;
//			}
//			if (CHAR == '+' || CHAR == '-' || CHAR == '*' || CHAR == '/' || CHAR == '>' || CHAR == '<' || CHAR == '=')
//				cout << "(4,'" << CHAR << "' )" << endl;
//			if (CHAR == ',' || CHAR == ';' || CHAR == '(' || CHAR == ')' || CHAR == '{' || CHAR == '}')
//				cout << "(5,'" << CHAR << "' )" << endl;
//			break;	
//		}
//	}
//	fclose(f);
//	return 0;
//}
//

#define _CRT_SECURE_NO_DEPRECATE；
#define _CRT_SECURE_NO_WARNINGS；
#pragma warning(disable:4996)；
#include <string>
#include <iostream>
#include <fstream>
#include <set>
using namespace std;

const int maxLineNum = 100;
set<string> key;             //关键字
char ch;                     //当前读取字符
int col, maxcol;             // col 读取当前行位置，当前行最大长度
ifstream readfile;           //文件输入流
char line[maxLineNum];       //读取文件一行
char identifier[maxLineNum]; //保留读取标识符或者关键字
void init();                 //进行初始化工作
int getsym();                //进行词法分析
int getch();                 //读取一个字符

int main()
{
    char a;
    FILE* f;
	f = fopen("ceshi.txt", "w");
	if (f == NULL)
	{
		cout << "cannot creat file" << endl;
		exit(0);
	}
	cout << "please input code(to the end of #)" << endl;
	while ((a = getchar()) != '#')
			fputc(a, f);
	fclose(f);
	cout << "over" << endl;

    readfile.open("ceshi.txt");
    if (readfile.is_open() == false)
    {
        cout << "文件不存在";
        return 0;
    }
    init();
    col = maxcol = 0;
    ch = ' ';
    while (getsym())
        ;
    return 0;
}

void init()
{
    key.insert("const");
    key.insert("do");
    key.insert("while");
    key.insert("if");
    key.insert("else");
    key.insert("for");
    key.insert("int");
    key.insert("char");
    key.insert("return");
    key.insert("void");
    key.insert("read");
    key.insert("write");
}

int getch()
{
    if (col == maxcol)
    {
        if (readfile.peek() == EOF)
        {
            return -1;
        }
        maxcol = col = 0;
        ch = ' ';
        while (ch != '\n')
        {
            if (readfile.peek() == EOF)
            {
                line[maxcol] = 0;
                break;
            }
            readfile.get(ch);
            line[maxcol++] = ch;
        }
    }
    ch = line[col++];
    return 0;
}

int getsym()
{
    int i, j, k, num;
    while (ch == ' ' || ch == 10 || ch == 13 || ch == 9)
    {
        if (getch() == -1)
            return 0;
    }
    if (isalpha(ch))
    {
        k = 0;
        while (isalpha(ch) || isdigit(ch))
        {
            identifier[k] = ch;
            k++;
            if (getch() == -1)
                return 0;
        }
        identifier[k] = 0;
        if (key.find(string(identifier)) == key.end())
        {
            cout << "标识符 (3 , '" << identifier << "')\n";
        }
        else
        {
            cout << "关键字 (1 , '" << identifier << "')\n";
        }
    }
    else
    {
        if (isdigit(ch))
        {
            k = num = 0;
            while (isdigit(ch))
            {
                num = num * 10 + ch - '0';
                k++;
                if (getch() == -1)
                    return 0;
            }
            if (isalpha(ch) || ch == '_') {
                cout << "非法标识符 (6,'" << num << ch << "')\n";
            }
            else {
                cout << "整数 (2 , '" << num << "')\n";
            }
        }
        else
        {
            if (ch == '<')
            {
                if (getch() == -1)
                    return 0;
                if (ch == '=')
                {
                    cout << "运算符 (4 , '<=')\n";
                    if (getch() == -1)
                        return 0;
                }
                else
                {
                    cout << "运算符 (4 , '<')\n";
                }
            }
            else if (ch == '>')
            {
                if (getch() == -1)
                    return 0;
                if (ch == '=')
                {
                    cout << "运算符 (4 , '>=')\n";
                    if (getch() == -1)
                        return 0;
                }
                else
                {
                    cout << "运算符 (4 , '>')\n";
                }
            }
            else
            {
                if (ch == '+')
                {
                    cout << "运算符 (4 , '+')\n";
                }
                else if (ch == '-')
                {
                    cout << "运算符 (4 , '-')\n";
                }
                else if (ch == '*')
                {
                    cout << "运算符 (4 , '*')\n";
                }
                else if (ch == '/')
                {
                    cout << "运算符 (4 , '/')\n";
                }
                else if (ch == '=')
                {
                    cout << "运算符 (4 , '=')\n";
                }
                else if (ch == '(')
                {
                    cout << "运算符 (4 , '(')\n";
                }
                else if (ch == ')')
                {
                    cout << "运算符 (4 , ')')\n";
                }
                else if (ch == '.')
                {
                    cout << "运算符 (4 , '.')\n";
                }
                else if (ch == ',')
                {
                    cout << "分界符 (5 , ',')\n";
                }
                else if (ch == ';')
                {
                    cout << "分界符 (5 , ';')\n";
                }
                else if (ch == '{')
                {
                    cout << "分界符 (5 , '{')\n";
                }
                else if (ch == '}')
                {
                    cout << "分界符 (5 , '}')\n";
                }
                else
                {
                    cout << ch << " error!请检查代码是否拼写正确！";
                    return 0;
                }
                if (getch() == -1)
                    return 0;
            }
        }
    }
    return 1;
}
