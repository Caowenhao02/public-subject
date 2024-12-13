#pragma once
#include"Tools.h"
#include"Point.h"
#include<vector>
using namespace std;

class Map
{
public:
	Map();
	void PrintMap();
private:
	vector<Point> GameMap;
};