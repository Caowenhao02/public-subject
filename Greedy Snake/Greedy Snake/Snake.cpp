#include "Snake.h"
#include<conio.h>
Snake::Snake()//初始化蛇
{
	snake.push_back(Point(8, 5));
	snake.push_back(Point(8, 6));
	snake.push_back(Point(8, 7));
	direction = DOWN;
}

void Snake::TailGrowth()//deque尾部增长
{
	switch (direction)
	{
	case UP:
		snake.push_back(Point(snake.back().GetX(), snake.back().GetY() - 1));
		break;
	case DOWN:
		snake.push_back(Point(snake.back().GetX(), snake.back().GetY() + 1));
		break;
	case LEFT:
		snake.push_back(Point(snake.back().GetX() - 1, snake.back().GetY()));
		break;
	case RIGHT:
		snake.push_back(Point(snake.back().GetX() + 1, snake.back().GetY()));
		break;
	default:
		break;
	}
	snake.back().PrintCircular();
}

void Snake::PrintSnake()//显示初始的蛇
{
	SetColor(14);
	for (int i = 0; i < snake.size(); i++)
	{
		snake[i].PrintCircular();
	}
}
	
void Snake::SnakeMove()//蛇移动
{
	SetColor(14);
	TailGrowth();
	snake.front().Clear();
	snake.pop_front();
}

bool Snake::ChangeDirection()//改变方向
{
	char ch;
	if (_kbhit())
	{
		ch = _getch();
		switch (ch)
		{
		case -32:
			ch = _getch();
			switch (ch)
			{
			case 72:
				if (direction != DOWN)//如果方向与当前运动方向相反，无效
					direction = UP;
				break;
			case 80:
				if (direction != UP)
					direction = DOWN;
				break;
			case 75:
				if (direction != RIGHT)
					direction = LEFT;
				break;
			case 77:
				if (direction != LEFT)
					direction = RIGHT;
				break;
			default:
				break;
			}
			return true;

		case 27://ESC
			return false;
		default:
			return true;
		}
	}
	return true;
}


// int x_game = 28  游戏界面宽度
// int y_game = 32  游戏界面长度
bool Snake::IsOverBoundary()//越界判断
{
	bool flag = false;
	if (snake.back().GetX() == 0
		|| snake.back().GetX() == 27
		|| snake.back().GetY() == 0
		|| snake.back().GetY() == 31)
		flag = true;
	return flag;
}
bool Snake::IsHit_self()//如果尾部坐标与其他部位坐标相同则装上
{
	for (int i = 0; i < snake.size() - 1; i++)
		if (snake[i].GetX() == snake.back().GetX()
			&& snake[i].GetY() == snake.back().GetY())
			return true;
	return false;
}

bool Snake::IsGetFood(Food& food)
{
	if (snake.back().GetX() == food.x&&snake.back().GetY() == food.y)
		return true;
	return false;
}

void Snake::ReduceSnake()
{
	snake.back().PrintSquare();
	for (int i = 0; i < snake.size() - 1; i++)
		snake[i].Clear();
	snake.clear();
	snake.push_back(Point(8, 5));
	snake.push_back(Point(8, 6));
	snake.push_back(Point(8, 7));
	direction = DOWN;
}

bool Snake::operator==(Food& food)
{
	if (snake.back().GetX() == food.x&&snake.back().GetY() == food.y)
		return true;
	return false;
}