#pragma once
#include"Point.h"
#include"Food.h"
#include<deque>
using namespace std;

class Food;
class Snake :public Point
{
	friend class Food;
	enum Direction { UP, DOWN, LEFT, RIGHT };
public:
	Snake();
	void TailGrowth();
	void PrintSnake();
	void SnakeMove();
	bool ChangeDirection();
	bool IsOverBoundary();
	bool IsHit_self();
	bool IsGetFood(Food&);
	void ReduceSnake();
	bool operator==(Food&);
private:
	deque<Point> snake;
	Direction direction;
};