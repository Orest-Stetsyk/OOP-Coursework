#pragma once

#include "global.h"

constexpr auto fileName = "users.txt";

class DatabaseUsers
{
private:
	struct userInfo
	{
		string username, password;
	};
	vector <userInfo> Data;
public:
	void load(); //��������� � ����� ��� ��� ������������
	void save(); //�������� � ���� ��� ��� ������������
	bool auth(string username, string password); //�����������
	bool newUser(string username, string password); //���������
};
