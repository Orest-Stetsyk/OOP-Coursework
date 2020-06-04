#include "DatabaseStorage.h"

DatabaseStorage::DatabaseStorage()
{
	ifstream file("curId.txt"); //�������� �����
	string temp;
	file >> temp; //���������� ���������� id � �����
	curId = stoi(temp);
	file.close(); //�������� �����
}

void DatabaseStorage::load()
{
	int i = 0;
	goods.clear();
	string temp;
	vector <string> buff;
	ifstream file(fileNameG); //�������� �����
	while (file.eof() != 1) //������� ���������� ���� �� ���������� ����
	{
		file >> temp;
		buff = split(temp, div);
		goods.resize(goods.size() + 1); //����� ������ � ������
		goods[i].id = stoi(buff[0]);
		goods[i].userN = buff[1];
		goods[i].name = buff[2];
		goods[i].dateAdded.day = stoi(buff[3]);
		goods[i].dateAdded.month = stoi(buff[4]);
		goods[i].dateAdded.year = stoi(buff[5]);
		goods[i].storageDate.day = stoi(buff[6]);
		goods[i].storageDate.month = stoi(buff[7]);
		goods[i].storageDate.year = stoi(buff[8]);
		goods[i].weight = stoi(buff[9]);
		goods[i].volume = stoi(buff[10]);
		goods[i].office = stoi(buff[11]);
		i++;;
	}
	goods.pop_back();
	file.close(); //�������� �����
}

void DatabaseStorage::save()
{
	ofstream file(fileNameG); //�������� �����
	for (unsigned int i = 0; i < goods.size(); i++)
	{
		file << goods[i].id << div <<  //����� ������ � ����
			goods[i].userN << div <<
			goods[i].name << div <<
			goods[i].dateAdded.day << div <<
			goods[i].dateAdded.month << div <<
			goods[i].dateAdded.year << div <<
			goods[i].storageDate.day << div <<
			goods[i].storageDate.month << div <<
			goods[i].storageDate.year << div <<
			goods[i].weight << div <<
			goods[i].volume << div <<
			goods[i].office << endl;
	}
	file.close(); //�������� �����
	goods.clear();
}

vector<goodsInfo> DatabaseStorage::getUserGoods(string name) //����� ��������� ������ ��������� �����������
{
	load(); //������������ � ����� ����� ��� ������
	vector<goodsInfo> userGoods;
	for (unsigned int i = 0; i < goods.size(); i++)
	{
		if (goods[i].userN == name) //�������� �� ����� �������� ������ �����������
		{
			userGoods.push_back(goods[i]);
		}
	}
	return userGoods;
}

void DatabaseStorage::add(string userN, string name, date dateAdded, date storageDate, int weight, int volume, int office)
{
	ofstream file(fileNameG, ios_base::app); //�������� �����
	file << curId << div << //����� � ����� �����
		userN << div <<
		name << div <<
		dateAdded.day << div <<
		dateAdded.month << div <<
		dateAdded.year << div <<
		storageDate.day << div <<
		storageDate.month << div <<
		storageDate.year << div <<
		weight << div <<
		volume << div <<
		office << endl;
	file.close();
	curId++;
	ofstream fileNum("curId.txt");
	fileNum << curId;
	fileNum.close(); //�������� �����
}

bool DatabaseStorage::remove(int num, string curUsername)
{
	load();

	for (unsigned int i = 0; i < goods.size(); i++)
	{
		if (goods[i].userN == curUsername && goods[i].id == num) //�������� �� ����� �������� �����������
		{
			goods.erase(goods.begin() + i); //��������� ������ �� ID
			save();
			goods.clear();
			return 1;
		}
	}
	return 0;
}
