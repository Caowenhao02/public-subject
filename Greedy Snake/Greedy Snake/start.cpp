#include"start.h"
#include"tool.h"
#include<vector>
#include<windows.h>
#include <conio.h>
using namespace std;

void start::welcome()
{
	system("cls");
	cout << endl;
	SetWindowSize(50, 30);
	system("color 03");
	SetCursorPosition(12, 4);
	cout << "         ****************************";
	SetCursorPosition(12, 5);
	cout << "         **                        **";
	SetCursorPosition(12, 6);
	cout << "         **     ��ӭ����̰����!    **";
	SetCursorPosition(12, 7);
	cout << "         **                        **";
	SetCursorPosition(12, 8);
	cout << "         ****************************";
	SetCursorPosition(26, 13);
	cout << "�밴�����ѡ�񣬰��س���ȷ��";
	SetCursorPosition(32, 15);
	cout << "��¼";
	SetCursorPosition(31, 16);
	cout << "ע���˺�";
	SetCursorPosition(31, 17);
	cout << "�޸�����";
	SetCursorPosition(31, 18);
	cout << "�ο�ģʽ";
	SetCursorPosition(31, 19);
	cout << "�˳���Ϸ";
	cout << endl;


	/*���·����ѡ��ģ��*/
	int ch;
	key = 1;
	bool flag = false;
	SetCursorPosition(32, 15);
	SetColor(4);
	cout << "��¼";
	SetCursorPosition(0, 21);
	while ((ch = _getch()))
	{
		switch (ch)
		{
		case 72://UP�Ϸ����
			if (key > 1)//����ʱѡ����Ϊ��һ��ʱ��UP�Ϸ������Ч
			{
				switch (key)
				{
				case 2:
					SetCursorPosition(32, 15);//����ѡ�������ñ���ɫ
					SetColor(4);
					cout << "��¼";

					SetCursorPosition(31, 16);//����ѡ����ȡ���ұ���ɫ
					SetColor(3);
					cout << "ע���˺�";

					--key;
					break;
				case 3:
					SetCursorPosition(31, 16);
					SetColor(4);
					cout << "ע���˺�";

					SetCursorPosition(31, 17);
					SetColor(3);
					cout << "�޸�����";

					--key;
					break;
				
				case 5:
					SetCursorPosition(31, 17);
					SetColor(4);
					cout << "�޸�����";

					SetCursorPosition(31, 18);
					SetColor(3);
					cout << "�ο�ģʽ";

					key -= 2;
					break;
				case 6:
					SetCursorPosition(31, 18);
					SetColor(4);
					cout << "�ο�ģʽ";

					SetCursorPosition(31, 19);
					SetColor(3);
					cout << "�˳���Ϸ";

					--key;
					break;
				}
			}
			break;

		case 80://DOWN�·����
			if (key < 6)
			{
				switch (key)
				{
				case 1:
					SetCursorPosition(31, 16);
					SetColor(4);
					cout << "ע���˺�";
					SetCursorPosition(32, 15);
					SetColor(3);
					cout << "��¼";

					++key;
					break;
				case 2:
					SetCursorPosition(31, 17);
					SetColor(4);
					cout << "�޸�����";
					SetCursorPosition(31, 16);
					SetColor(3);
					cout << "ע���˺�";

					key += 2;
					break;
				case 4:
					SetCursorPosition(31, 18);
					SetColor(4);
					cout << "�ο�ģʽ";
					SetCursorPosition(31, 17);
					SetColor(3);
					cout << "�޸�����";

					++key;
					break;
				case 5:
					SetCursorPosition(31, 19);
					SetColor(4);
					cout << "�˳���Ϸ";
					SetCursorPosition(31, 18);
					SetColor(3);
					cout << "�ο�ģʽ";

					++key;
					break;
				}
			}
			break;

		case 13://Enter�س���
			flag = true;
			break;
		default://��Ч����
			break;
		}
		if (flag) break;//����Enter�س���ȷ�ϣ��˳��������ѭ��

		SetCursorPosition(0, 21);//������������½ǣ�����ر���˸Ӱ����Ϸ����
	}

	o = key;
	operate(o);
}

int start::getspeed()
{
	return speed;
}

void start::nandu()
{
	SetWindowSize(50, 30);

	ifstream ifs;
	ifs.open("speed.txt", ios::in);
	ifs >> speed_1;
	ifs >> speed_2;
	ifs >> speed_3;
	ifs >> speed_4;
	ifs.close();

	system("cls");

	SetCursorPosition(32, 12);
	cout << "�ƶ�ʱ������" << speed_1 << "ms";
	SetCursorPosition(32, 14);
	cout << "�ƶ�ʱ������" << speed_2 << "ms";
	SetCursorPosition(32, 16);
	cout << "�ƶ�ʱ������" << speed_3 << "ms";
	SetCursorPosition(32, 18);
	cout << "�ƶ�ʱ������" << speed_4 << "ms";

	administrator ad;
	person1 pe;
	vector<Person*>arr(2);
	arr[0] = &ad;
	arr[1] = &pe;
	if (ju == 0)
	{
		SetCursorPosition(8, 14);
		arr[1]->print();
	}
	else
	{
		SetCursorPosition(8, 14);
		arr[0]->print();
	}
	SetColor(3);
	SetCursorPosition(15, 5);
	std::cout << "��ѡ����Ϸ�Ѷȣ�";
	SetCursorPosition(13, 7);
	std::cout << "(���¼�ѡ��,�س�ȷ��)";
	SetCursorPosition(27, 12);
	SetColor(4);//��һ��ѡ�����ñ���ɫ�Ա�ʾ��ǰѡ��
	std::cout << "����ģʽ";
	SetCursorPosition(27, 14);
	SetColor(3);
	std::cout << "��ͨģʽ";
	SetCursorPosition(27, 16);
	std::cout << "����ģʽ";
	SetCursorPosition(27, 18);
	std::cout << "����ģʽ";
	SetCursorPosition(0, 21);

	/*���·����ѡ��ģ��*/
	int ch;
	key = 1;
	bool flag = false;
	while ((ch = _getch()))
	{
		switch (ch)
		{
		case 72://UP�Ϸ����
			if (key > 1)//����ʱѡ����Ϊ��һ��ʱ��UP�Ϸ������Ч
			{
				switch (key)
				{
				case 2:
					SetCursorPosition(27, 12);//����ѡ�������ñ���ɫ
					SetColor(4);
					cout << "����ģʽ";

					SetCursorPosition(27, 14);//����ѡ����ȡ���ұ���ɫ
					SetColor(3);
					cout << "��ͨģʽ";

					--key;
					break;
				case 3:
					SetCursorPosition(27, 14);
					SetColor(4);
					cout << "��ͨģʽ";

					SetCursorPosition(27, 16);
					SetColor(3);
					cout << "����ģʽ";

					--key;
					break;
				case 4:
					SetCursorPosition(27, 16);
					SetColor(4);
					cout << "����ģʽ";

					SetCursorPosition(27, 18);
					SetColor(3);
					cout << "����ģʽ";

					--key;
					break;
				}
			}
			break;

		case 80://DOWN�·����
			if (key < 4)
			{
				switch (key)
				{
				case 1:
					SetCursorPosition(27, 14);
					SetColor(4);
					cout << "��ͨģʽ";
					SetCursorPosition(27, 12);
					SetColor(3);
					cout << "����ģʽ";

					++key;
					break;
				case 2:
					SetCursorPosition(27, 16);
					SetColor(4);
					cout << "����ģʽ";
					SetCursorPosition(27, 14);
					SetColor(3);
					cout << "��ͨģʽ";

					++key;
					break;
				case 3:
					SetCursorPosition(27, 18);
					SetColor(4);
					cout << "����ģʽ";
					SetCursorPosition(27, 16);
					SetColor(3);
					cout << "����ģʽ";

					++key;
					break;
				}
			}
			break;

		case 13://Enter�س���
			flag = true;
			break;
		default://��Ч����
			break;
		}
		if (flag) break;//����Enter�س���ȷ�ϣ��˳��������ѭ��

		SetCursorPosition(0, 21);//������������½ǣ�����ر���˸Ӱ����Ϸ����
	}
	gg = key;
	switch (key)//������ѡѡ�������ߵ��ƶ��ٶȣ�speedֵԽС���ٶ�Խ��
	{
	case 1:
		speed = speed_1;
		break;
	case 2:
		speed = speed_2;
		break;
	case 3:
		speed = speed_3;
		break;
	case 4:
		speed = speed_4;
		break;
	default:
		break;
	}
}

int start::operate(int a)
{
	system("cls");
	system("color 03");
	if (o == 1)
	{
		if (login())
			nandu();
		return 1;
	}
	else if (o == 2)
	{
		enroll();
		return 1;
	}
	else if (o == 4)
	{
		if (change())
			nandu();
		return 1;
	}
	else if (o == 3)
	{
		if (forgetpasswpord())
			nandu();
		return 1;
	}
	else if (o == 5)
	{
		tourist();
		nandu();
		return 1;
	}
	else return 0;
}

void start::convert()
{
	welcome();
}

int start::login()
{
	system("cls");
	int q = 0;
	setposition(4, 20);
	int n = 0;
	string a;
	setposition(2, 20);
	cout << "�������˺ţ�";
	cin >> a;
	accounts = a;
	setposition(1, 20);
	cout << "���������룺";
	cin >> a;
	passwords = a;

	int l = 1000;
	int k = 0;
	for (; k < 1000; k++)
	{
		if (accounts == allperson[k].getaccount())
		{
			l = k;
			if (allperson[k].getquestion() == 5)
			{
				system("cls");
				SetCursorPosition(7, 8);
				cout << "���ź����������Ѿ�û�м�����¼�Ļ�������" << endl;
				allperson[k].setquestion(5);
				SetCursorPosition(13, 9);
				system("pause");
				convert();
				return 0;
			}
		}
		if (accounts == allperson[k].getaccount() && passwords == allperson[k].getpassword())
		{
			kk = k;
			setposition(2, 23);
			cout << "��¼�ɹ���";
			ju = 0;
			if (allperson[k].getaccount() == "Administrator")
			{
				q = 2;
				ju = 1;
			}
			break;
		}
	}

	if (k != 1000 && q != 2)
	{
		i = k;
		if (allperson[l].getquestion() != 5)
		{
			setposition(2, 18);
			play = true;
			return 1;
		}
	}

	if (k == 1000 && l != 1000)
	{
		if (allperson[l].getquestion() < 4)
		{
			setposition(2, 23);
			cout << "��¼ʧ��";
			setposition(2, 16);
			cout << "��������ȷ���˻�������" << endl << endl << endl;
			allperson[l].setquestion(allperson[l].getquestion() + 1);
			SetCursorPosition(11, 15);
			system("pause");
			welcome();
			return 0;
		}
		else
		{
			system("cls");
			SetCursorPosition(7, 8);
			cout << "���ź����������Ѿ�û�м�����¼�Ļ�������" << endl;
			allperson[l].setquestion(5);
			SetCursorPosition(13, 9);
			system("pause");
			q = 1;
			convert();
			return 0;
		}
	}
	else if (q != 2)
	{
		setposition(2, 16);
		cout << "��������ȷ���˻�������" << endl << endl << endl;
		SetCursorPosition(11, 15);
		system("pause");
		welcome();
		return 0;
	}

	if (q == 2)
	{
		setposition(2, 18);
		system("pause");
		system("cls");
		administrator ad;
		person1 pe;
		vector<Person*>arr(2);
		arr[0] = &ad;
		arr[1] = &pe;
		if (ju == 0)
		{
			SetCursorPosition(8, 14);
			arr[1]->print();
		}
		else
		{
			SetCursorPosition(27, 6);
			arr[0]->print();
			arr[0]->PrintUserInformation();
			arr[0]->ModifySpeed(speed_1, speed_2, speed_3, speed_4, key);
		}

		SetCursorPosition(27, 25);
		system("pause");
		q = 0;
		welcome();
		return 0;
	}
}

int start::enroll()
{
	string a, b, c, d;
	string e, f, g;
	int m = 1;
	SetCursorPosition(12, 4);
	cout << "���������˻���:";
	cin >> a;
	SetCursorPosition(12, 5);
	cout << "������������Ŷ:";
	cin >> b;
	SetCursorPosition(12, 6);
	cout << "����һ�Σ����Ͼͺ�:";
	cin >> c;

	for (; m == 1;)
	{
		int k = 0;
		for (; k < 1000; k++)
		{
			if (a == allperson[k].getaccount())
			{
				m = 2;
			}
		}
		if (m == 1)
			break;
		else
		{
			m = 1;
			setposition(2, 16);
			cout << "�ܿ�ϧ�������˻��ѱ�ע�ᣬ���������룺";
			cin >> a;
		}
	}


	if (b != c)
	{
		for (;;)
		{
			setposition(2, 19);
			cout << "��������������벻һ�£�����������" << endl;
			setposition(1, 19);
			cout << "��������������:";
			cin >> b;
			setposition(1, 19);
			cout << "���ٴ����룺";
			cin >> c;
			if (b == c)
				break;
			else continue;
		}
	}
	cout << endl;
	setposition(2, 24);
	cout << "�������Լ�ȡ�����ְɣ�";
	cin >> d;
	/*setposition(2, 12);
	cout << "Ϊ��������������������һ����룬���������ı������⣺";
	getline(cin, e);
	setposition(2, 27);
	cout << "������𰸣�";
	cin >> f;
	setposition(1, 27);
	cout << "���ٴ����룺";
	cin >> g;

	if (f != g)
	{
		for (;;)
		{
			setposition(2, 19);
			cout << "����������Ĵ𰸲�һ�£�����������" << endl;
			setposition(2, 25);
			cout << "���������Ĵ�:";
			cin >> f;
			setposition(1, 25);
			cout << "���ٴ����룺";
			cin >> g;
			if (f == g)
				break;
			else continue;
		}
	}*/
	setposition(4, 25);
	cout << "��ϲ����ע��ɹ���" << endl << endl;
	create(a, b, d, 0);
	nandu();
	return 1;
}

int start::forgetpasswpord()
{
	static int p = 0;
	if (p == 0)
	{
		p = 1;
		system("cls");
		SetColor(3);
		string a, c;
		int b;
		int m = 1;
		setposition(4, 24);
		cout << "�����������˻���";
		cin >> a;
		for (; m == 1;)
		{
			int k = 0;
			for (; k < 1000; k++)
			{
				if (a == allperson[k].getaccount())
				{
					m = 2;
					i = k;
					break;
				}
			}
			if (m == 2)
				break;
			else
			{
				setposition(2, 24);
				cout << "��������˻�������" << endl;

				SetCursorPosition(30, 10);
				cout << "��������";

				SetCursorPosition(30, 11);
				cout << "����������";
				SetCursorPosition(30, 10);
				SetColor(4);
				cout << "��������";

				int ch;
				key = 1;
				bool flag = false;

				while ((ch = _getch()))
				{
					switch (ch)
					{
					case 80://����
						if (key < 2)
						{
							SetCursorPosition(30, 10);
							SetColor(3);
							cout << "��������";

							SetCursorPosition(30, 11);
							SetColor(4);
							cout << "����������";
							key++;
						}
						break;

					case 72://����
						if (key > 1)
						{
							SetCursorPosition(30, 10);
							SetColor(4);
							cout << "��������";
							SetCursorPosition(30, 11);
							SetColor(3);
							cout << "����������";
							key--;
						}
						break;

					case 13:
						flag = true;
						break;

					default:
						break;

					}
					if (flag == true)
						break;

					SetCursorPosition(0, 14);
				}
				if (key == 1)
				{
					p = 0;
					forgetpasswpord();
					m = 4;
					break;
				}
				else
				{
					m = 3;
					break;
				}
			}

		}
		if (m == 3)
		{
			welcome();
			return 0;
		}
		else if (m == 4)
			return 1;
		else
		{
			int n = 0;
			for (; n < 5; n++)
			{
				setposition(2, 24);
				cout << "��������Ϊ��" << allperson[i].getquestion() << endl;
				setposition(1, 24);
				cout << "����������𰸣�";
				cin >> c;

				if (c == allperson[i].getanswer())
				{
					p = 0;
					setposition(3, 24);
					cout << "��������Ϊ��" << allperson[i].getpassword() << endl << endl << endl;
					SetCursorPosition(30, 10);
					SetColor(4);
					cout << "�޸�����";
					SetColor(3);
					SetCursorPosition(30, 11);
					cout << "������Ϸ";
					int ch;
					key = 1;
					bool flag = false;

					while ((ch = _getch()))
					{
						switch (ch)
						{
						case 80://����
							if (key < 2)
							{
								SetCursorPosition(30, 10);
								SetColor(3);
								cout << "�޸�����";

								SetCursorPosition(30, 11);
								SetColor(4);
								cout << "������Ϸ";
								key++;
							}
							break;

						case 72://����
							if (key > 1)
							{
								SetCursorPosition(30, 10);
								SetColor(4);
								cout << "�޸�����";
								SetCursorPosition(30, 11);
								SetColor(3);
								cout << "������Ϸ";
								key--;
							}
							break;

						case 13:
							flag = true;
							break;


						default:
							break;

						}
						if (flag == true)
							break;

						SetCursorPosition(0, 14);
					}

					if (key == 1)
					{
						system("cls");
						change(1);
						return 1;
					}
					else
					{
						return 1;
					}
				}

				else
				{
					if (n < 4)
					{
						setposition(4, 28);
						cout << "�𰸴���";
						setposition(2, 19);
						cout << "������ " << 4 - n << " �λ��ᣬ�ٺú���һ���" << endl << endl;
					}

					else
					{
						system("cls");
						setposition(3, 39);
						cout << "�һ�ʧ��";
						setposition(2, 24);
						cout << "���ź����������Ѿ�û�м�������Ļ�������" << endl;
						p = 1;
						setposition(3, 34);
						system("pause");
						welcome();
					}
				}
			}
		}

		if (p == 0)
			return 1;
		else return 0;
	}

	else
	{
		setposition(5, 20);
		cout << "�������һ�����ʧ�ܣ�����������" << endl;
		setposition(2, 25);
		system("pause");
		system("cls");
		convert();
		return 0;
	}
}

int start::tourist()
{
	play = true;
	ts = 0;
	return 1;
}

int start::change(int k)
{
	static int y = 0;
	if (y == 0)
	{
		y = 1;
		string a, b;
		if (k == 1)
		{
			do
			{
				static int u = 0;
				if (u > 0)
				{
					setposition(2, 11);
					cout << "��������������һ�£�����������";
				}
				u++;
				setposition(4, 17);
				cout << "���������������룺";
				cin >> a;
				setposition(1, 20);
				cout << "���ٴ����룺";
				cin >> b;
			} while (a != b);

			allperson[i].setpassword(a);
			write();
			setposition(4, 23);
			cout << "�޸ĳɹ���";
			setposition(3, 19);
			system("pause");
			return 0;
		}
		else
		{
			int n = 0;
			for (; n < 5; n++)
			{
				string a, b;
				setposition(5, 20);
				cout << "�������˺ţ�";
				cin >> a;
				setposition(1, 20);
				cout << "���������룺";
				cin >> b;
				cout << endl;

				int k = 0;
				for (; k < 1000; k++)
				{
					if (a == allperson[k].getaccount() && b == allperson[k].getpassword())
					{
						setposition(1, 23);
						cout << "������ȷ��";
						y = 0;
						break;
					}
				}
				if (k != 1000)
				{
					i = k;
					break;
				}
				if (k == 1000)
				{
					if (n < 4)
					{
						setposition(1, 23);
						cout << "����ʧ��";
						setposition(3, 13);
						cout << "������ " << 4 - n << " �λ��ᣬ�ٺú���һ���";
					}


					else
					{
						system("cls");
						setposition(3, 29);
						cout << "��¼ʧ��";
						setposition(3, 13);
						cout << "���ź����������Ѿ�û���޸�����Ļ�������" << endl;
						k = 3;
						setposition(3, 25);
						system("pause");
						welcome();
						return 0;
					}
				}
			}
			if (n < 5)
			{
				do
				{
					static int u = 0;
					if (u > 0)
					{
						setposition(2, 11);
						cout << "��������������һ�£�����������";
					}
					u++;
					setposition(4, 17);
					cout << "���������������룺";
					cin >> a;
					setposition(1, 20);
					cout << "���ٴ����룺";
					cin >> b;
				} while (a != b);
				allperson[i].setpassword(a);
				write();
				setposition(3, 23);
				cout << "�޸ĳɹ���";
				setposition(3, 19);
				system("pause");
				return 1;
			}
		}
	}

	else
	{
		setposition(5, 20);
		cout << "�������޸�����ʧ�ܣ�����������" << endl;
		setposition(2, 25);
		system("pause");
		system("cls");
		convert();
		return 0;
	}
}

int start::getkk()
{
	return kk;
}