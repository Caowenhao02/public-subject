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
	cout << "         **     欢迎来到贪吃蛇!    **";
	SetCursorPosition(12, 7);
	cout << "         **                        **";
	SetCursorPosition(12, 8);
	cout << "         ****************************";
	SetCursorPosition(26, 13);
	cout << "请按方向键选择，按回车键确认";
	SetCursorPosition(32, 15);
	cout << "登录";
	SetCursorPosition(31, 16);
	cout << "注册账号";
	SetCursorPosition(31, 17);
	cout << "修改密码";
	SetCursorPosition(31, 18);
	cout << "游客模式";
	SetCursorPosition(31, 19);
	cout << "退出游戏";
	cout << endl;


	/*上下方向键选择模块*/
	int ch;
	key = 1;
	bool flag = false;
	SetCursorPosition(32, 15);
	SetColor(4);
	cout << "登录";
	SetCursorPosition(0, 21);
	while ((ch = _getch()))
	{
		switch (ch)
		{
		case 72://UP上方向键
			if (key > 1)//当此时选中项为第一项时，UP上方向键无效
			{
				switch (key)
				{
				case 2:
					SetCursorPosition(32, 15);//给待选中项设置背景色
					SetColor(4);
					cout << "登录";

					SetCursorPosition(31, 16);//将已选中项取消我背景色
					SetColor(3);
					cout << "注册账号";

					--key;
					break;
				case 3:
					SetCursorPosition(31, 16);
					SetColor(4);
					cout << "注册账号";

					SetCursorPosition(31, 17);
					SetColor(3);
					cout << "修改密码";

					--key;
					break;
				
				case 5:
					SetCursorPosition(31, 17);
					SetColor(4);
					cout << "修改密码";

					SetCursorPosition(31, 18);
					SetColor(3);
					cout << "游客模式";

					key -= 2;
					break;
				case 6:
					SetCursorPosition(31, 18);
					SetColor(4);
					cout << "游客模式";

					SetCursorPosition(31, 19);
					SetColor(3);
					cout << "退出游戏";

					--key;
					break;
				}
			}
			break;

		case 80://DOWN下方向键
			if (key < 6)
			{
				switch (key)
				{
				case 1:
					SetCursorPosition(31, 16);
					SetColor(4);
					cout << "注册账号";
					SetCursorPosition(32, 15);
					SetColor(3);
					cout << "登录";

					++key;
					break;
				case 2:
					SetCursorPosition(31, 17);
					SetColor(4);
					cout << "修改密码";
					SetCursorPosition(31, 16);
					SetColor(3);
					cout << "注册账号";

					key += 2;
					break;
				case 4:
					SetCursorPosition(31, 18);
					SetColor(4);
					cout << "游客模式";
					SetCursorPosition(31, 17);
					SetColor(3);
					cout << "修改密码";

					++key;
					break;
				case 5:
					SetCursorPosition(31, 19);
					SetColor(4);
					cout << "退出游戏";
					SetCursorPosition(31, 18);
					SetColor(3);
					cout << "游客模式";

					++key;
					break;
				}
			}
			break;

		case 13://Enter回车键
			flag = true;
			break;
		default://无效按键
			break;
		}
		if (flag) break;//输入Enter回车键确认，退出检查输入循环

		SetCursorPosition(0, 21);//将光标置于左下角，避免关标闪烁影响游戏体验
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
	cout << "移动时间间隔：" << speed_1 << "ms";
	SetCursorPosition(32, 14);
	cout << "移动时间间隔：" << speed_2 << "ms";
	SetCursorPosition(32, 16);
	cout << "移动时间间隔：" << speed_3 << "ms";
	SetCursorPosition(32, 18);
	cout << "移动时间间隔：" << speed_4 << "ms";

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
	std::cout << "请选择游戏难度：";
	SetCursorPosition(13, 7);
	std::cout << "(上下键选择,回车确认)";
	SetCursorPosition(27, 12);
	SetColor(4);//第一个选项设置背景色以表示当前选中
	std::cout << "养老模式";
	SetCursorPosition(27, 14);
	SetColor(3);
	std::cout << "普通模式";
	SetCursorPosition(27, 16);
	std::cout << "困难模式";
	SetCursorPosition(27, 18);
	std::cout << "地狱模式";
	SetCursorPosition(0, 21);

	/*上下方向键选择模块*/
	int ch;
	key = 1;
	bool flag = false;
	while ((ch = _getch()))
	{
		switch (ch)
		{
		case 72://UP上方向键
			if (key > 1)//当此时选中项为第一项时，UP上方向键无效
			{
				switch (key)
				{
				case 2:
					SetCursorPosition(27, 12);//给待选中项设置背景色
					SetColor(4);
					cout << "养老模式";

					SetCursorPosition(27, 14);//将已选中项取消我背景色
					SetColor(3);
					cout << "普通模式";

					--key;
					break;
				case 3:
					SetCursorPosition(27, 14);
					SetColor(4);
					cout << "普通模式";

					SetCursorPosition(27, 16);
					SetColor(3);
					cout << "困难模式";

					--key;
					break;
				case 4:
					SetCursorPosition(27, 16);
					SetColor(4);
					cout << "困难模式";

					SetCursorPosition(27, 18);
					SetColor(3);
					cout << "地狱模式";

					--key;
					break;
				}
			}
			break;

		case 80://DOWN下方向键
			if (key < 4)
			{
				switch (key)
				{
				case 1:
					SetCursorPosition(27, 14);
					SetColor(4);
					cout << "普通模式";
					SetCursorPosition(27, 12);
					SetColor(3);
					cout << "养老模式";

					++key;
					break;
				case 2:
					SetCursorPosition(27, 16);
					SetColor(4);
					cout << "困难模式";
					SetCursorPosition(27, 14);
					SetColor(3);
					cout << "普通模式";

					++key;
					break;
				case 3:
					SetCursorPosition(27, 18);
					SetColor(4);
					cout << "地狱模式";
					SetCursorPosition(27, 16);
					SetColor(3);
					cout << "困难模式";

					++key;
					break;
				}
			}
			break;

		case 13://Enter回车键
			flag = true;
			break;
		default://无效按键
			break;
		}
		if (flag) break;//输入Enter回车键确认，退出检查输入循环

		SetCursorPosition(0, 21);//将光标置于左下角，避免关标闪烁影响游戏体验
	}
	gg = key;
	switch (key)//根据所选选项设置蛇的移动速度，speed值越小，速度越快
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
	cout << "请输入账号：";
	cin >> a;
	accounts = a;
	setposition(1, 20);
	cout << "请输入密码：";
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
				cout << "很遗憾，您今天已经没有继续登录的机会了呢" << endl;
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
			cout << "登录成功！";
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
			cout << "登录失败";
			setposition(2, 16);
			cout << "请输入正确的账户或密码" << endl << endl << endl;
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
			cout << "很遗憾，您今天已经没有继续登录的机会了呢" << endl;
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
		cout << "请输入正确的账户或密码" << endl << endl << endl;
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
	cout << "创建您的账户吧:";
	cin >> a;
	SetCursorPosition(12, 5);
	cout << "还有您的密码哦:";
	cin >> b;
	SetCursorPosition(12, 6);
	cout << "再来一次，马上就好:";
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
			cout << "很可惜，您的账户已被注册，请重新输入：";
			cin >> a;
		}
	}


	if (b != c)
	{
		for (;;)
		{
			setposition(2, 19);
			cout << "您两次输入的密码不一致，请重新输入" << endl;
			setposition(1, 19);
			cout << "请输入您的密码:";
			cin >> b;
			setposition(1, 19);
			cout << "请再次输入：";
			cin >> c;
			if (b == c)
				break;
			else continue;
		}
	}
	cout << endl;
	setposition(2, 24);
	cout << "请您给自己取个名字吧：";
	cin >> d;
	/*setposition(2, 12);
	cout << "为了让您在忘记密码后能找回密码，请输入您的保密问题：";
	getline(cin, e);
	setposition(2, 27);
	cout << "请输入答案：";
	cin >> f;
	setposition(1, 27);
	cout << "请再次输入：";
	cin >> g;

	if (f != g)
	{
		for (;;)
		{
			setposition(2, 19);
			cout << "您两次输入的答案不一致，请重新输入" << endl;
			setposition(2, 25);
			cout << "请输入您的答案:";
			cin >> f;
			setposition(1, 25);
			cout << "请再次输入：";
			cin >> g;
			if (f == g)
				break;
			else continue;
		}
	}*/
	setposition(4, 25);
	cout << "恭喜您，注册成功！" << endl << endl;
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
		cout << "请输入您的账户：";
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
				cout << "您输入的账户不存在" << endl;

				SetCursorPosition(30, 10);
				cout << "重新输入";

				SetCursorPosition(30, 11);
				cout << "返回主界面";
				SetCursorPosition(30, 10);
				SetColor(4);
				cout << "重新输入";

				int ch;
				key = 1;
				bool flag = false;

				while ((ch = _getch()))
				{
					switch (ch)
					{
					case 80://向下
						if (key < 2)
						{
							SetCursorPosition(30, 10);
							SetColor(3);
							cout << "重新输入";

							SetCursorPosition(30, 11);
							SetColor(4);
							cout << "返回主界面";
							key++;
						}
						break;

					case 72://向上
						if (key > 1)
						{
							SetCursorPosition(30, 10);
							SetColor(4);
							cout << "重新输入";
							SetCursorPosition(30, 11);
							SetColor(3);
							cout << "返回主界面";
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
				cout << "您的问题为：" << allperson[i].getquestion() << endl;
				setposition(1, 24);
				cout << "请输入问题答案：";
				cin >> c;

				if (c == allperson[i].getanswer())
				{
					p = 0;
					setposition(3, 24);
					cout << "您的密码为：" << allperson[i].getpassword() << endl << endl << endl;
					SetCursorPosition(30, 10);
					SetColor(4);
					cout << "修改密码";
					SetColor(3);
					SetCursorPosition(30, 11);
					cout << "进入游戏";
					int ch;
					key = 1;
					bool flag = false;

					while ((ch = _getch()))
					{
						switch (ch)
						{
						case 80://向下
							if (key < 2)
							{
								SetCursorPosition(30, 10);
								SetColor(3);
								cout << "修改密码";

								SetCursorPosition(30, 11);
								SetColor(4);
								cout << "进入游戏";
								key++;
							}
							break;

						case 72://向上
							if (key > 1)
							{
								SetCursorPosition(30, 10);
								SetColor(4);
								cout << "修改密码";
								SetCursorPosition(30, 11);
								SetColor(3);
								cout << "进入游戏";
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
						cout << "答案错误";
						setposition(2, 19);
						cout << "您还有 " << 4 - n << " 次机会，再好好想一想吧" << endl << endl;
					}

					else
					{
						system("cls");
						setposition(3, 39);
						cout << "找回失败";
						setposition(2, 24);
						cout << "很遗憾，您今天已经没有继续输入的机会了呢" << endl;
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
		cout << "您今天找回密码失败，请明天再来" << endl;
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
					cout << "您两次输入结果不一致，请重新输入";
				}
				u++;
				setposition(4, 17);
				cout << "请输入您的新密码：";
				cin >> a;
				setposition(1, 20);
				cout << "请再次输入：";
				cin >> b;
			} while (a != b);

			allperson[i].setpassword(a);
			write();
			setposition(4, 23);
			cout << "修改成功！";
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
				cout << "请输入账号：";
				cin >> a;
				setposition(1, 20);
				cout << "请输入密码：";
				cin >> b;
				cout << endl;

				int k = 0;
				for (; k < 1000; k++)
				{
					if (a == allperson[k].getaccount() && b == allperson[k].getpassword())
					{
						setposition(1, 23);
						cout << "输入正确！";
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
						cout << "输入失败";
						setposition(3, 13);
						cout << "您还有 " << 4 - n << " 次机会，再好好想一想吧";
					}


					else
					{
						system("cls");
						setposition(3, 29);
						cout << "登录失败";
						setposition(3, 13);
						cout << "很遗憾，您今天已经没有修改密码的机会了呢" << endl;
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
						cout << "您两次输入结果不一致，请重新输入";
					}
					u++;
					setposition(4, 17);
					cout << "请输入您的新密码：";
					cin >> a;
					setposition(1, 20);
					cout << "请再次输入：";
					cin >> b;
				} while (a != b);
				allperson[i].setpassword(a);
				write();
				setposition(3, 23);
				cout << "修改成功！";
				setposition(3, 19);
				system("pause");
				return 1;
			}
		}
	}

	else
	{
		setposition(5, 20);
		cout << "您今天修改密码失败，请明天再来" << endl;
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