#pragma once

#include "global.h"

constexpr auto fileNameG = "goods.txt";

struct date {
	int day, month, year;
};
struct goodsInfo {
	int id, weight, volume, office;
	string name, userN;
	date dateAdded, storageDate;
};

class DatabaseStorage
{
private:
	vector<goodsInfo> goods;
	int curId;
	void load(); //�������� � ���� ��� ��� ������������
public:
	DatabaseStorage();
	void save(); //��������� � ����� ��� ��� ������������
	vector<goodsInfo> getUserGoods(string name); //����� ��������� ������ ��������� �����������
	void add(string userN, string name, date AddedDate, date storageDate, int weight, int volume, int office); //��������� ������
	bool remove(int num, string curUsername); //��������� ������
};
