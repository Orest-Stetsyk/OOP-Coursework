#include "global.h"
#include "CUI.h"


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	CUI session;
	session.StartWindow();
	return 0;
}

