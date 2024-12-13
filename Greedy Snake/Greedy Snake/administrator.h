#include<iostream>
#include<fstream>
#include<iomanip>
#include"Allperson.h"
#include<conio.h>
#include"Person.h"
#include"Tools.h"
using namespace std;
class administrator:public Person,public Tools,public Allperson
{
public:
	void print();
	void ModifySpeed(int& speed_1, int& speed_2,
		int& speed_3, int& speed_4, int& key);

	void PrintUserInformation();
	void UpdataSpeed_txt(int speed_1, int speed_2,
		int speed_3, int speed_4);
};