#include "Map.h"
#include<Windows.h>
Map::Map()//地图初始化
{
	int x_game = 28;  //游戏界面宽度
	int y_game = 32;  //游戏界面长度
	//T.SetWindowSize(41, 32)  窗口大小
	for (int y = 0; y < y_game; y++)
		for (int x = 0; x < x_game; x++)
		{
			if (y == 0 || y == y_game - 1)
				GameMap.push_back(Point(x, y));
			else if (x == 0 || x == x_game - 1)
				GameMap.push_back(Point(x, y));
		}
	/*GameMap.push_back(Point(1, 1));
	GameMap.push_back(Point(2, 1));
	GameMap.push_back(Point(3, 1));
	GameMap.push_back(Point(4, 1));
	GameMap.push_back(Point(5, 1));
	GameMap.push_back(Point(6, 1));
	GameMap.push_back(Point(7, 1));
	GameMap.push_back(Point(8, 1));
	GameMap.push_back(Point(9, 1));
	GameMap.push_back(Point(10, 1));
	GameMap.push_back(Point(11, 1));
	GameMap.push_back(Point(12, 1));
	GameMap.push_back(Point(13, 1));
	GameMap.push_back(Point(14, 1));
	GameMap.push_back(Point(15, 1));
	GameMap.push_back(Point(16, 1));
	GameMap.push_back(Point(17, 1));
	GameMap.push_back(Point(18, 1));
	GameMap.push_back(Point(19, 1));
	GameMap.push_back(Point(20, 1));
	GameMap.push_back(Point(21, 1));
	GameMap.push_back(Point(22, 1));
	GameMap.push_back(Point(23, 1));
	GameMap.push_back(Point(24, 1));
	GameMap.push_back(Point(25, 1));
	GameMap.push_back(Point(26, 1));
	GameMap.push_back(Point(27, 1));
	GameMap.push_back(Point(28, 1));
	GameMap.push_back(Point(29, 1));
	GameMap.push_back(Point(30, 1));
	GameMap.push_back(Point(1, 2));
	GameMap.push_back(Point(30, 2));
	GameMap.push_back(Point(1, 3));
	GameMap.push_back(Point(30, 3));
	GameMap.push_back(Point(1, 4));
	GameMap.push_back(Point(30, 4));
	GameMap.push_back(Point(1, 5));
	GameMap.push_back(Point(30, 5));
	GameMap.push_back(Point(1, 6));
	GameMap.push_back(Point(30, 6));
	GameMap.push_back(Point(1, 7));
	GameMap.push_back(Point(30, 7));
	GameMap.push_back(Point(1, 8));
	GameMap.push_back(Point(30, 8));
	GameMap.push_back(Point(1, 9));
	GameMap.push_back(Point(30, 9));
	GameMap.push_back(Point(1, 10));
	GameMap.push_back(Point(30, 10));
	GameMap.push_back(Point(1, 11));
	GameMap.push_back(Point(30, 11));
	GameMap.push_back(Point(1, 12));
	GameMap.push_back(Point(30, 12));
	GameMap.push_back(Point(1, 13));
	GameMap.push_back(Point(30, 13));
	GameMap.push_back(Point(1, 14));
	GameMap.push_back(Point(30, 14));
	GameMap.push_back(Point(1, 15));
	GameMap.push_back(Point(30, 15));
	GameMap.push_back(Point(1, 16));
	GameMap.push_back(Point(30, 16));
	GameMap.push_back(Point(1, 17));
	GameMap.push_back(Point(30, 17));
	GameMap.push_back(Point(1, 18));
	GameMap.push_back(Point(30, 18));
	GameMap.push_back(Point(1, 19));
	GameMap.push_back(Point(30, 19));
	GameMap.push_back(Point(1, 20));
	GameMap.push_back(Point(30, 20));
	GameMap.push_back(Point(1, 21));
	GameMap.push_back(Point(30, 21));
	GameMap.push_back(Point(1, 22));
	GameMap.push_back(Point(30, 22));
	GameMap.push_back(Point(1, 23));
	GameMap.push_back(Point(30, 23));
	GameMap.push_back(Point(1, 24));
	GameMap.push_back(Point(30, 24));
	GameMap.push_back(Point(1, 25));
	GameMap.push_back(Point(30, 25));
	GameMap.push_back(Point(1, 26));
	GameMap.push_back(Point(30, 26));
	GameMap.push_back(Point(1, 27));
	GameMap.push_back(Point(30, 27));
	GameMap.push_back(Point(1, 28));
	GameMap.push_back(Point(30, 28));
	GameMap.push_back(Point(1, 29));
	GameMap.push_back(Point(30, 29));
	GameMap.push_back(Point(1, 30));
	GameMap.push_back(Point(2, 30));
	GameMap.push_back(Point(3, 30));
	GameMap.push_back(Point(4, 30));
	GameMap.push_back(Point(5, 30));
	GameMap.push_back(Point(6, 30));
	GameMap.push_back(Point(7, 30));
	GameMap.push_back(Point(8, 30));
	GameMap.push_back(Point(9, 30));
	GameMap.push_back(Point(10, 30));
	GameMap.push_back(Point(11, 30));
	GameMap.push_back(Point(12, 30));
	GameMap.push_back(Point(13, 30));
	GameMap.push_back(Point(14, 30));
	GameMap.push_back(Point(15, 30));
	GameMap.push_back(Point(16, 30));
	GameMap.push_back(Point(17, 30));
	GameMap.push_back(Point(18, 30));
	GameMap.push_back(Point(19, 30));
	GameMap.push_back(Point(20, 30));
	GameMap.push_back(Point(21, 30));
	GameMap.push_back(Point(22, 30));
	GameMap.push_back(Point(23, 30));
	GameMap.push_back(Point(24, 30));
	GameMap.push_back(Point(25, 30));
	GameMap.push_back(Point(26, 30));
	GameMap.push_back(Point(27, 30));
	GameMap.push_back(Point(28, 30));
	GameMap.push_back(Point(29, 30));
	GameMap.push_back(Point(30, 30));*/
}

void Map::PrintMap()//画出地图
{
	for (int i = 0; i < GameMap.size(); i++)
	{
		GameMap[i].PrintSquare();
		Sleep(10);
	}
}