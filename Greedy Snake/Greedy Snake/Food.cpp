#include "Food.h"
#include<cstdlib>
#include<iostream>
using namespace std;

void Food::DrawFood(Snake& csnake)
{
	while (true)
	{

		// int x_game = 28   游戏界面宽度
		// int y_game = 32   游戏界面长度

		//食物出现范围 x：1~27  y：1~31
		int tem_x = 1 + rand() % 26;
		int tem_y = 1 + rand() % 30;

		bool flag = false;
		for (int i = 0; i < csnake.snake.size(); i++)
			if (tem_x == csnake.snake[i].GetX()
				&& tem_y == csnake.snake[i].GetY())
			{
				flag = true;
				break;
			}

		if (flag)
			continue;
		x = tem_x;
		y = tem_y;

		SetColor(5);
		SetCursorPosition(tem_x, tem_y);
		cout << "★";
		break;
	}
}
void Food::DeleteFood()
{
	SetCursorPosition(x, y);
	cout << "  ";
}