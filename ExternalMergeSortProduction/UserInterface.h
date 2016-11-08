#pragma once
#include "Structures.h"
#include "AppCore.h"

class UserInterface
{
private:
	AppCore *appCore;
	const string menu = "0. �����\n1. ������������� ������������������\n2. ������ ��������� ����������\n3. ������������� ������������������\n4. ������� �������������� ����������\n";
	bool callMethod(int ch);
	Responce callGenerate();
	Responce callSetParams();
	Responce callSort();
	Responce callEstimate();
	char **responceString;
public:
	void initSession();
	UserInterface();
	~UserInterface();
};

