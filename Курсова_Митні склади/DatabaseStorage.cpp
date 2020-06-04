#include "DatabaseStorage.h"

DatabaseStorage::DatabaseStorage()
{
	ifstream file("curId.txt"); //відкриття файлу
	string temp;
	file >> temp; //зчитування останнього id з файлу
	curId = stoi(temp);
	file.close(); //закриття файлу
}

void DatabaseStorage::load()
{
	int i = 0;
	goods.clear();
	string temp;
	vector <string> buff;
	ifstream file(fileNameG); //відкриття файлу
	while (file.eof() != 1) //читання построково поки не закінчиться файл
	{
		file >> temp;
		buff = split(temp, div);
		goods.resize(goods.size() + 1); //запис данних у вектор
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
	file.close(); //закриття файлу
}

void DatabaseStorage::save()
{
	ofstream file(fileNameG); //відкриття файлу
	for (unsigned int i = 0; i < goods.size(); i++)
	{
		file << goods[i].id << div <<  //запис данних у файл
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
	file.close(); //закриття файлу
	goods.clear();
}

vector<goodsInfo> DatabaseStorage::getUserGoods(string name) //метод отримання товарів вибраного користувача
{
	load(); //завантаження з файлу даних про товари
	vector<goodsInfo> userGoods;
	for (unsigned int i = 0; i < goods.size(); i++)
	{
		if (goods[i].userN == name) //перевірка чи товар належить даному користувачу
		{
			userGoods.push_back(goods[i]);
		}
	}
	return userGoods;
}

void DatabaseStorage::add(string userN, string name, date dateAdded, date storageDate, int weight, int volume, int office)
{
	ofstream file(fileNameG, ios_base::app); //відкриття файлу
	file << curId << div << //запис в кінець файлу
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
	fileNum.close(); //закриття файлу
}

bool DatabaseStorage::remove(int num, string curUsername)
{
	load();

	for (unsigned int i = 0; i < goods.size(); i++)
	{
		if (goods[i].userN == curUsername && goods[i].id == num) //перевірка чи товар належить користувачу
		{
			goods.erase(goods.begin() + i); //видалення товару за ID
			save();
			goods.clear();
			return 1;
		}
	}
	return 0;
}
