#include"administrator.h"
void administrator::print()
{
	cout << "Administrator";
}
void administrator::ModifySpeed(int& speed_1, int& speed_2,
	int& speed_3, int& speed_4, int& key)
{
	SetCursorPosition(27, 10);
	cout << "�޸�ʱ������";

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

	int select;
	SetCursorPosition(33, 10 + 2 * key);
	cout << "�������޸ĵ�ֵ��";
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
	cout << "�޸ĳɹ���";

	UpdataSpeed_txt(speed_1, speed_2, speed_3, speed_4);
}
void administrator::PrintUserInformation()
{
	SetCursorPosition(5, 10);
	cout << "�����û���Ϣ��";
	SetCursorPosition(5, 11);
	cout << "�ǳ�";
	SetCursorPosition(10, 11);
	cout << "�˺�";
	SetCursorPosition(15, 11);
	cout << "����";
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