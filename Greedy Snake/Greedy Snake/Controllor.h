#pragma once
#include"Map.h"
#include"Snake.h"
#include"Point.h"
#include"Food.h"
#include"Tools.h"
#include"start.h"

class Controllor :public Tools, public start
{
public:
	Controllor()
	{
		welcome();
	}
	void DrawMap();
	void StartGame();
	void UpdateScore();
	int PrintMenuAndSelect();
	int PrintOverInterface();
	void DeleteOverInterface();
};