#include "stdafx.h"
#include "UserInterface.h"
#include <iostream>
#include "FileManager.h"
#include "ExternalMergeSort.h"


using namespace std;

void UserInterface::initSession()
{
	char *respString[] = { "�������", "������ ���������", "���� �� ����������", "������ �������", "������ ����-���������",
		"�������� ���� � ���� ���������� ���������", "��������� ����� �����", "������ ��������� ������", "��������� �� ������ ��� ������ �������" };
	responceString = respString;
	appCore = new AppCore();
	const string ch = "����������, �������� ����� --> ";
	cout << menu.c_str() << ch.c_str();
	int choise = -1;
	cin >> choise;
	while (choise < 0 || choise > 4) {
		cout << "�� ��������, ����������, ��������� --> ";
		cin >> choise;
	}
	while (callMethod(choise)) {
		system("pause");
		system("cls");
		cout << menu.c_str() << ch.c_str();
		cin >> choise;
		while (choise < 0 || choise > 4) {
			cout << "�� ��������, ����������, ��������� --> ";
			cin >> choise;
		}
	}
}

Responce UserInterface::callGenerate() {
	cout << "��������� ������������������:" << endl;
	cout << "���������� ������� ������ ������������������: " << endl;
	int size;
	cin >> size;
	while (size < 0) {
		cout << "�� ��������, ����������, ��������� --> ";
		cin >> size;
	}
	cout << "���������� ������� ���� � ����� ��������� ������������������" << endl;
	char buf[50];
	cin >> buf;
	string file(buf);
	cout << "���������� �������� ��� ������������������: " << endl << "0. ������ ������������������\n1. ������� ������\n2. ������ ������\n";
	int ch;
	cin >> ch;
	while (ch < 0 || ch > 2) {
		cout << "�� ��������, ����������, ��������� --> ";
		cin >> ch;
	}
	FileManager fileManager(file, WriteOnly);
	Responce resp = fileManager.generateSequence(size,SeqType(ch));
	if (resp == Success) {
		system("cls");
		cout << "��������� ������������������:\n����������: 100%\n" << "��������� �������!" << endl;
	}
	else {
		cout << "��������� ����������� � �������: " << responceString[resp] << endl;
	}
	return resp;
}

Responce UserInterface::callSetParams()
{
	cout << "����������� ���������� ����������: " << endl;
	cout << "������� ���� � �������� ������������������:" << endl;
	char buf[50];
	cin >> buf;
	string iFile(buf);
	cout << "������� ���� ����� ����������:" << endl;
	cin >> buf;
	string oFile(buf);
	FileManager *file = new FileManager(iFile, oFile);
	cout << "������� ������ ���������: ";
	int size;
	cin >> size;
	while (size < 0) {
		cout << "�� ��������, ����������, ��������� --> ";
		cin >> size;
	}
	cout << "�������� ��� ���������� ����������:" << endl << "0. ���������� ���������\n1. ������� ����������\n2. ������������� ����������\n";
	int ch;
	cin >> ch;
	Responce resp = appCore->setSortParams(file, size, TypeOfSort(ch));
	if (resp == Success) {
		system("cls");
		cout << "��������� ������� ������!" << endl;
	}
	else {
		cout << "�� ������� ������ ���������! ������: " << responceString[resp] << endl;
	}
	return resp;
}

Responce UserInterface::callSort()
{	
	cout << "���������� ����������:" << endl;
	Responce resp = appCore->externalSort();
	if (resp == Success) {
		system("cls");
		cout << "������������������ ������� ������������� �� " << appCore->getCounter().getTimeInterval() << " �����������!" << endl;
	}
	else {
		cout << "�� ������� ������������� ������������������! ������: " << responceString[resp] << endl;
	}
	return resp;
}

Responce UserInterface::callEstimate()
{
	cout << "������ ������������� ����������:" << endl;
	Responce resp = appCore->externalSort();
	if (resp == Success) {
		system("cls");
		cout << "������������������ ������� ������������� �� " << appCore->getCounter().getTimeInterval() << " �����������!" << endl;
		cout << "���������� ������ � ������� � ����: " << appCore->getCounter().getFileOp() << endl;
		cout << "���������� ���������: " << appCore->getCounter().getComparsion() << endl;
		cout << "���������� ������������: " << appCore->getCounter().getSwaps() << endl;
	}
	else {
		cout << "�� ������� ������������� ������������������! ������: " << responceString[resp] << endl;
	}
	return resp;
}

bool UserInterface::callMethod(int choise)
{
	Responce resp;
	system("cls");
	switch (choise) {
	case 0: 
		return false;
	case 1:
		resp = callGenerate();
		break;
	case 2:
		resp = callSetParams();
		break;
	case 3:
		resp = callSort();
		break;
	case 4:
		resp = callEstimate();
		break;
	}
	return true;
}

UserInterface::UserInterface()
{
}


UserInterface::~UserInterface()
{
}
