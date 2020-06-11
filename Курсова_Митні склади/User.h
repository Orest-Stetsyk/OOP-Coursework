#pragma once

#include "global.h"
#include "DatabaseStorage.h"

class user
{

private:
	string curUsername;
	unsigned int curOffice;
	vector<goodsInfo> curUserGoods;
	vector<string> offices = { "������", "���� ������", "�������", "�����������", "ϳ�����", "��������", "�������", "�������" };
	DatabaseStorage DatabaseSession;
public:
	user();
	user(string curUsername);
	void officeSelector();
	void mainMenu(); //������� ���� �����������
	void view(); //�������� ������ �����������
};
