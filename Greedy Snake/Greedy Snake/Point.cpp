#include "Point.h"
#include<iostream>
using namespace std;
void Point::PrintSquare()
{
	SetCursorPosition(x, y);
	cout << "��";
}

void Point::PrintCircular()//���Բ��
{
	SetCursorPosition(x, y);
	std::cout << "��";
}

void Point::Clear()
{
	SetCursorPosition(x, y);
	cout << "  ";
}
void Point::ModifyPosition(int m_x, int m_y)
{
	x = m_x;
	y = m_y;
}
int Point::GetX()
{
	return x;
}
int Point::GetY()
{
	return y;
}