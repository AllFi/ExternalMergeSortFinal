#pragma once
#include "Structures.h"

class UserInterface
{
private:
	const string menu = "0. �����\n1. ������������� ������������������\n2. ������ ��������� ����������\n";
	bool callMethod(int ch);
	Responce callGenerate();
	Responce callSetParams();
public:
	void initSession();
	UserInterface();
	~UserInterface();
};

