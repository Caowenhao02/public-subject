#ifndef START
#define START

#include<iostream>
#include<string>
#include<windows.h>
#include"Allperson.h"
#include"administrator.h"
#include"person1.h"
using namespace std;
class start :public Allperson
{
public:
	void welcome();
	int operate(int);
	void convert();
	int login();
	int enroll();
	int forgetpasswpord();
	int tourist();
	void nandu();
	int getspeed();
	int change(int = 0);
	int getkeyvalue()
	{
		return key;
	}
	int getju()
	{
		return ju;
	}
	int gg;
	int getkk();
private:
	string accounts, passwords;
	int o, ts, key, speed, ju, kk;
	bool play = false;
	int speed_1 = 135;
	int speed_2 = 100;
	int speed_3 = 60;
	int speed_4 = 30;
};

#endif