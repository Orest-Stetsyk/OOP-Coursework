#pragma once

#include "global.h"
#include "DatabaseUsers.h"
#include "user.h"


class CUI
{
private:
	DatabaseUsers DatabaseSession;
public:
	void StartWindow(); //��������� ����
	void auth(); //���� �����������
	void newUser(); //���� ���������
};
