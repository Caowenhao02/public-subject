#include"tool.h"
#include<iostream>
#include <windows.h>
#include <stdio.h>
using namespace std;

void SetWindowSize(int cols, int lines)
{
	char cmd[30];
	sprintf_s(cmd, "mode con cols=%d lines=%d", cols * 2, lines);
	system(cmd);
}

void setposition(int a, int b)
{
	for (int i = 0; i < a - 1; i++)
	{
		cout << endl;
	}
	for (int i = 0; i < b - 1; i++)
	{
		cout << " ";
	}
}

void SetBackColor()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
		FOREGROUND_BLUE |
		BACKGROUND_RED |
		BACKGROUND_GREEN |
		BACKGROUND_RED);
}

void SetCursorPosition(int x, int y)
{
	COORD position;
	position.X = x * 2;
	position.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

void SetColor(int colorID)//设置文本颜色
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorID);
}