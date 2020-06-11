#include "user.h"

user::user()
{
}

user::user(string curUsername)
{
	this->curUsername = curUsername;
}

void user::officeSelector()
{
	system("cls"); //�������� ������
	cout << "������� ������ �����:" << endl;
	cout << "1. " << offices[0] << endl;
	cout << "2. " << offices[1] << endl;
	cout << "3. " << offices[2] << endl;
	cout << "4. " << offices[3] << endl;
	cout << "5. " << offices[4] << endl;
	cout << "6. " << offices[5] << endl;
	cout << "7. " << offices[6] << endl;
	cout << "8. " << offices[7] << endl;
	unsigned int k;
	cin >> k;
	if (k == 0 or k > 8)
	{
		cout << "������ ������ �� ����" << endl;
		system("pause");
		officeSelector();
	}
	else
	{
		curOffice = k - 1;
	}
	mainMenu();
}

void user::mainMenu()
{
	system("cls"); //�������� ������
	cout << "������� ��:" << endl;
	cout << "1. ������ �����" << endl;
	cout << "2. ����������� ������" << endl;
	cout << "3. �������� �����" << endl;
	cout << "4. �����" << endl;
	int ch;
	cin >> ch;
	switch (ch)
	{
	case 1:
	{
		system("cls"); //�������� ������
		string name;
		date dateAdded, storageDate;
		int weight, volume;

		time_t t = time(0); //��������� ������� ����
		tm* now = localtime(&t);
		dateAdded.year = now->tm_year + 1900;
		dateAdded.month = now->tm_mon + 1;
		dateAdded.day = now->tm_mday;
		storageDate.year = dateAdded.year + 2;
		storageDate.month = dateAdded.month;
		storageDate.day = dateAdded.day;

		cout << "������ ����� ������: " << endl;
		cin >> name;
		cout << "������ ���� ������: " << endl;
		cin >> weight;
		cout << "������ ��'�� ������: " << endl;
		cin >> volume;

		DatabaseSession.add(curUsername, name, dateAdded, storageDate, weight, volume, curOffice); //��������� ������
		mainMenu();
		break;
	}
	case 2:
	{
		system("cls"); //�������� ������

		view(); //�������� ������

		system("pause");
		mainMenu();
		break;
	}
	case 3:
	{
		system("cls"); //�������� ������
		view();
		cout << "������ ID ������ ��� ������ ��������: ";
		int id;
		cin >> id;
		if (DatabaseSession.remove(id, curUsername) == 0) //�������� �� ����� �������� �����������
		{
			cout << "�� �� ��� �����" << endl;
		}
		system("pause");
		mainMenu();
		break;
	}
	case 4:
	{
		exit(0);
		break;
	}
	default:
		mainMenu();
	}
}

void user::view()
{
	vector<goodsInfo> userGoods = DatabaseSession.getUserGoods(curUsername);
	cout << setw(4) << "ID" << setw(20) << "��'�" << setw(20) << "���� ���������" << setw(30) << "���� ���������� ���������" << setw(10) << "����" << setw(10) << "��'��" << setw(15) << "�����" << endl; //���� �� ����� ����� ��� ������
	if (userGoods.empty() == 0) //�������� �� ���������� �� ������
	{
		for (unsigned int i = 0; i < userGoods.size(); i++)
		{
			cout << setw(4) << userGoods[i].id << setw(20) <<
				userGoods[i].name << setw(13) <<
				userGoods[i].dateAdded.day << "." <<
				userGoods[i].dateAdded.month << "." <<
				userGoods[i].dateAdded.year << setw(23) <<
				userGoods[i].storageDate.day << "." <<
				userGoods[i].storageDate.month << "." <<
				userGoods[i].storageDate.year << setw(8) <<
				userGoods[i].weight << "��" << setw(9) <<
				userGoods[i].volume << "�" << setw(15) <<
				offices[userGoods[i].office] << endl;
		}
	}
}
