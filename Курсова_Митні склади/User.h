#pragma once

#include "global.h"
#include "DatabaseStorage.h"

class user
{

private:
	string curUsername;
	unsigned int curOffice;
	vector<goodsInfo> curUserGoods;
	vector<string> offices = { "Ягодин", "Рава Руська", "Ужгород", "Прикарпаття", "Пісочин", "Бачівськ", "Удрицьк", "Сновськ" };
	DatabaseStorage DatabaseSession;
public:
	user();
	user(string curUsername);
	void officeSelector();
	void mainMenu(); //головне меню користувача
	void view(); //перегляд товарів користувача
};
