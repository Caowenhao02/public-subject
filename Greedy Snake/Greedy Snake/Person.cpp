#include"Person.h"
Person::Person()
{
	account = "empty";
	password = "empty";
	question = 0;
}
Person::Person(string a, string b, int c)
{
	account = a;
	password = b;
	score = c;
}

void Person::setaccount(string a)
{
	account = a;
}
void Person::setpassword(string a)
{
	password = a;
}
void Person::setscore(int a)
{
	score = a;
}
void Person::setname(string a)
{
	name = a;
}
void Person::setanswer(string a)
{
	answer = a;
}
void Person::setquestion(int a)
{
	question = a;
}

string Person::getname()
{
	return name;
}
string Person::getaccount()
{
	return account;
}
string Person::getpassword()
{
	return password;
}
int Person::getscore()
{
	return score;
}
string Person::getanswer()
{
	return answer;
}
int Person::getquestion()
{
	return question;
}