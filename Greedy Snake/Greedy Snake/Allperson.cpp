#include"Allperson.h"
Allperson::Allperson()
{
	ifstream ifs;
	ifs.open(ACCOUNT, ios::in);
	i = 0;
	for (; i < 1000; i++)
	{
		string id, pass, n, q, a;
		int s;
		if (ifs >> id >> pass >> n >> s)
		{
			allperson[i].setaccount(id);
			allperson[i].setpassword(pass);
			allperson[i].setname(n);
			allperson[i].setscore(s);
		}
		else break;
	}
	w = i;
	ifs.close();
}

void Allperson::create(string a, string b, string d, int c)
{
	allperson[i].setaccount(a);
	allperson[i].setpassword(b);
	allperson[i].setname(d);
	allperson[i].setscore(c);
	if (i < 999)
	{
		i++;
		w = i;
		write();
	}
	else cout << "�Ѵﵽ����˻�������";

}
//����һ���µ�Person��Ķ���,�����˻������롢���ơ�������Ĭ��Ϊ0��
//�Լ�����д��txt�ļ��ĺ�����֮��ʹ��ֻ��Ҫ������������Ϳ�����

void Allperson::write()
{
	ofstream ofs;
	ofs.open(ACCOUNT, ios::out);
	for (int k = 0; k < w; k++)
	{
		ofs << allperson[k].getaccount() << " " << allperson[k].getpassword() << " " << allperson[k].getname() << " "
			<< allperson[k].getscore() << endl;
	}
	ofs.close();
}
//���´�����Person�����д��account.txt�ļ�