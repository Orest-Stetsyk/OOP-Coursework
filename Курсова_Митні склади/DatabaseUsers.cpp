#include "DatabaseUsers.h"


void DatabaseUsers::load()
{
	int i = 0;
	Data.clear();
	string temp;
	vector <string> buff;
	ifstream file(fileName); //відкриття файлу
	while (file.eof() != 1) //читання построково поки не закінчиться файл
	{
		file >> temp;
		buff = split(temp, udiv);
		Data.resize(Data.size() + 1); //запис данних у вектор
		Data[i].username = buff[0];
		Data[i].password = buff[1];
		i++;;
	}
	Data.pop_back();
	file.close(); //закриття файлу
}

void DatabaseUsers::save()
{
	ofstream file(fileName); //відкриття файлу
	for (unsigned int i = 0; i < Data.size(); i++)
	{
		file << Data[i].username << udiv << Data[i].password << endl; //запис данних у файл
	}
	file.close(); //закриття файлу
	Data.clear();
}

bool DatabaseUsers::auth(string username, string password)
{
	system("cls"); //очищення екрану
	load();
	bool correct = 0;
	for (unsigned int i = 0; i < Data.size(); i++)
	{
		if (Data[i].username == username && Data[i].password == password)
		{
			correct = 1;
			break;
		}
	}
	Data.clear();
	return correct;
}

bool DatabaseUsers::newUser(string username, string password)
{
	system("cls"); //очищення екрану
	load();
	bool available = 0;
	for (unsigned int i = 0; i < Data.size(); i++)
	{
		if (Data[i].username == username) //перевірка на наявність імені користувача
		{

			available = 1;
			break;
		}
	}
	Data.clear();
	if (available == 0)
	{
		ofstream file(fileName, ios_base::app); //відкриття файлу
		file << username << udiv << password << endl;
		file.close(); //закриття файлу
	}
	return available;
}
