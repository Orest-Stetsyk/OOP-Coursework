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
	void load(); //зберегти у файл дані про користувачів
public:
	DatabaseStorage();
	void save(); //загрузити з файла дані про користувачів
	vector<goodsInfo> getUserGoods(string name); //метод отримання товарів вибраного користувача
	void add(string userN, string name, date AddedDate, date storageDate, int weight, int volume, int office); //додавання товару
	bool remove(int num, string curUsername); //видалення товару
};
