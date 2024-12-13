#include "Controllor.h"
#include<iostream>
#include<Windows.h>
#include<ctime>
#include<conio.h>
#include<iomanip>
using namespace std;

static int Score = 0;

void Controllor::DrawMap()
{
	SetWindowSize(41, 32);
	SetColor(3);
	Map map;
	map.PrintMap();

	SetCursorPosition(32, 1);
	cout << "Greedy Snake";
	SetCursorPosition(33, 2);
	cout << "贪吃蛇";
	SetCursorPosition(30, 4);
	cout << "难度：";
	SetCursorPosition(31, 6);
	switch (gg)
	{
	case 1:
		cout << "养老模式";
		break;
	case 2:
		cout << "普通模式";
		break;
	case 3:
		cout << "困难模式";
		break;
	case 4:
		cout << "地狱模式";
		break;
	default:
		break;
	}

	SetColor(12);
	SetCursorPosition(30, 10);
	cout << "得分：";
	SetCursorPosition(32, 11);
	cout << setw(7) << '0';

	SetColor(3);
	SetCursorPosition(31, 15);
	cout << " 方向键移动";
	SetCursorPosition(31, 18);
	cout << " ESC键暂停";
	
}

void Controllor::StartGame()
{
	if (getkeyvalue() == 6)
		return;

	srand(time(NULL));//随机数种子

	Snake snake;
	Food food;

	while (true)
	{
		DrawMap();
		snake.PrintSnake();
		food.DrawFood(snake);
		while (!snake.IsHit_self() && !snake.IsOverBoundary())
		{
			if (!snake.ChangeDirection())
				PrintMenuAndSelect();

			if (snake.IsGetFood(food))
			{
				snake.TailGrowth();
				UpdateScore();
				food.DrawFood(snake);
			}
			else
				snake.SnakeMove();
			Sleep(getspeed());
		}

		//更新分数
		if (Score > allperson[getkk()].getscore())
			allperson[getkk()].setscore(Score*gg);

		int p = PrintOverInterface();
		if (p == 0)
			break;
		else
		{
			Score = 0;
			snake.ReduceSnake();
			food.DeleteFood();
			DeleteOverInterface();
			system("cls");
			nandu();
		}
	}
	
	SetCursorPosition(15, 15);
}


int Controllor::PrintOverInterface()
{
	SetColor(3);

	allperson[getju()].setscore(Score);
	write();

	SetCursorPosition(10, 13);
	cout << "|------------------------|";

	Sleep(100);
	SetCursorPosition(10, 14);
	cout << "|  你的最终得分为:       |";

	Sleep(100);
	SetCursorPosition(10, 15);
	cout << "|";
	SetCursorPosition(16, 15);
	cout << Score;
	SetCursorPosition(22, 15);
	cout << " |";

	Sleep(100);
	SetCursorPosition(10, 16);
	cout << "|                        |";

	Sleep(100);
	SetCursorPosition(10, 17);
	cout << "| 再来(回车)  溜了(ESC)  |";

	Sleep(100);
	SetCursorPosition(10, 18);
	cout << "|------------------------|";

	int ch;
	int key = 0;
	while (ch = _getch())
	{
		switch (ch)
		{
		case 27:
			key = 0;
			return key;
		case 13:
			key = 1;
			return key;
		default:
			break;
		}
	}
}

void Controllor::DeleteOverInterface()
{
	SetCursorPosition(10, 13);
	cout << "                          ";

	SetCursorPosition(10, 14);
	cout << "                           ";

	SetCursorPosition(10, 15);
	cout << "                            ";

	SetCursorPosition(10, 16);
	cout << "                           ";

	SetCursorPosition(10, 17);
	cout << "                           ";

	SetCursorPosition(10, 18);
	cout << "                           ";
}

void Controllor::UpdateScore()
{
	Score += 10;
	SetColor(12);
	SetCursorPosition(32, 11);
	cout << setw(7) << Score;
}

int Controllor::PrintMenuAndSelect()
{
	SetColor(11);
	SetCursorPosition(32, 21);
	cout << "菜单：";
	Sleep(100);
	SetCursorPosition(34, 23);
	cout << "继续游戏";

	int ch;
	while (ch = _getch())
	{
		switch (ch)
		{
		case 13:
			SetCursorPosition(32, 21);
			cout << "      ";
			SetCursorPosition(34, 23);
			cout << "        ";
			return 1;
			break;
		default:
			break;
		}
	}
	return 1;
}