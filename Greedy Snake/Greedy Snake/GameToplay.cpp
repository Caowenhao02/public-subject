#include<iostream>
#include<conio.h>
#include"Controllor.h"
#include<string>
#include"start.h"
using namespace std;

int main()
{
	Controllor C;
	C.StartGame();
	C.SetCursorPosition(11, 30);
	system("pause");
	
}