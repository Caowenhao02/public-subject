#pragma once
#ifndef PERSON
#define PERSON
#include<iostream>
#include<string>
using namespace std;

class Person
{
public:
	Person();
	Person(string, string, int);
	void setaccount(string);
	void setpassword(string);
	void setscore(int);
	void setname(string);
	void setquestion(int);
	void setanswer(string);

	string getanswer();
	int getquestion();
	string getname();
	string getaccount();
	string getpassword();
	int getscore();

	virtual void print() {}
	virtual void ModifySpeed(int&, int&, int&, int&, int&) {}
	virtual void PrintUserInformation() {}
private:
	string account, password, name;
	string answer;
	int score, question;
};
#endif