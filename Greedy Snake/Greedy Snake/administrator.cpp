#include"administrator.h"
void administrator::print()
{
	cout << "Administrator";
}
void administrator::ModifySpeed(int& speed_1, int& speed_2,
	int& speed_3, int& speed_4, int& key)
{
	SetCursorPosition(27, 10);
	cout << "修改时间间隔：";

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

	int select;
	SetCursorPosition(33, 10 + 2 * key);
	cout << "请输入修改的值：";
	cin >> select;
	switch (key)
	{
	case 1:
		speed_1 = select;
		break;
	case 2:
		speed_2 = select;
		break;
	case 3:
		speed_3 = select;
		break;
	case 4:
		speed_4 = select;
		break;
	default:
		break;
	}
	SetCursorPosition(27, 21);
	cout << "修改成功！";

	UpdataSpeed_txt(speed_1, speed_2, speed_3, speed_4);
}
void administrator::PrintUserInformation()
{
	SetCursorPosition(5, 10);
	cout << "所有用户信息：";
	SetCursorPosition(5, 11);
	cout << "昵称";
	SetCursorPosition(10, 11);
	cout << "账号";
	SetCursorPosition(15, 11);
	cout << "密码";
	for (int i = 1; i < w; i++)
	{
		SetCursorPosition(5, 11 + i);
		cout << allperson[i].getname();
		SetCursorPosition(10, 11 + i);
		cout << allperson[i].getaccount();
		SetCursorPosition(15, 11 + i);
		cout << allperson[i].getpassword();
	}
}
void administrator::UpdataSpeed_txt(int speed_1, int speed_2,
	int speed_3, int speed_4)
{
	ofstream ofs;
	ofs.open("speed.txt", ios::out);
	ofs << speed_1 << ' ' << speed_2 << ' ' << speed_3
		<< ' ' << speed_4 << ' ';
	ofs.close();
}