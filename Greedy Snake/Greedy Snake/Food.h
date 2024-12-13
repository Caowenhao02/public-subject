#pragma once
#include"Point.h"
#include"Snake.h"

class Snake;
class Food :public Point
{
	friend class Snake;
public:
	void DrawFood(Snake&);
	void DeleteFood();
private:
	int x;
	int y;
};