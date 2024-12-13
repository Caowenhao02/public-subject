#pragma once
#ifndef ALLPERSON
#define ALLPERSON
#define ACCOUNT "account.txt"
#define number 1000
#include<vector>
#include<fstream>
#include"Person.h"

class Allperson :public Person
{
public:
	Allperson();
	void create(string, string, string, int = 0);
	void write();

protected:
	Person* allperson = new Person[number];
	int i, w;
};
#endif