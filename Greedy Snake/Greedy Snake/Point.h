#pragma once
#include"Tools.h"

class Point :public Tools
{
public:
	Point() {};
	Point(const int x, const int y) :x(x), y(y) {};
	void PrintSquare();
	void PrintCircular();
	void Clear();
	void ModifyPosition(int, int);
	int GetX();
	int GetY();
private:
	int x;
	int y;
};