#include "Snake.h"
#include<conio.h>
Snake::Snake()//��ʼ����
{
	snake.push_back(Point(8, 5));
	snake.push_back(Point(8, 6));
	snake.push_back(Point(8, 7));
	direction = DOWN;
}

void Snake::TailGrowth()//dequeβ������
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

void Snake::PrintSnake()//��ʾ��ʼ����
{
	SetColor(14);
	for (int i = 0; i < snake.size(); i++)
	{
		snake[i].PrintCircular();
	}
}
	
void Snake::SnakeMove()//���ƶ�
{
	SetColor(14);
	TailGrowth();
	snake.front().Clear();
	snake.pop_front();
}

bool Snake::ChangeDirection()//�ı䷽��
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
				if (direction != DOWN)//��������뵱ǰ�˶������෴����Ч
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


// int x_game = 28  ��Ϸ������
// int y_game = 32  ��Ϸ���泤��
bool Snake::IsOverBoundary()//Խ���ж�
{
	bool flag = false;
	if (snake.back().GetX() == 0
		|| snake.back().GetX() == 27
		|| snake.back().GetY() == 0
		|| snake.back().GetY() == 31)
		flag = true;
	return flag;
}
bool Snake::IsHit_self()//���β��������������λ������ͬ��װ��
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