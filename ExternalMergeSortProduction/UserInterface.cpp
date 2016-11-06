#include "stdafx.h"
#include "UserInterface.h"
#include <iostream>
#include "FileManager.h"
#include "ExternalMergeSort.h"


using namespace std;

void UserInterface::initSession()
{
	appCore = new AppCore();
	const string ch = "����������, �������� ����� --> ";
	cout << menu.c_str() << ch.c_str();
	int choise = -1;
	cin >> choise;
	while (choise < 0 || choise > 3) {
		cout << "�� ��������, ����������, ��������� --> ";
		cin >> choise;
	}
	while (callMethod(choise)) {
		system("pause");
		system("cls");
		cout << menu.c_str() << ch.c_str();
		cin >> choise;
		while (choise < 0 || choise > 3) {
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
	return fileManager.generateSequence(size,SeqType(ch));
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
	return appCore->setSortParams(file, size, TypeOfSort(ch));
}

Responce UserInterface::callSort()
{	
	cout << "���������� ����������:" << endl;
	return appCore->externalSort();
}

bool UserInterface::callMethod(int choise)
{
	char* responceString[] = { "�������", "������ ���������", "���� �� ����������", "������ �������", "������ ����-���������",
	"�������� ���� � ���� ���������� ���������", "��������� ����� �����", "������ ��������� ������", "��������� �� ������ ��� ������ �������"};
	Responce resp;
	system("cls");
	switch (choise) {
	case 0: 
		return false;
	case 1:
		resp = callGenerate();
		if (resp == Success) {
			system("cls");
			cout << "��������� ������������������:\n����������: 100%\n" << "��������� �������!" << endl;
			return true;
		}
		else {
			cout << "��������� ����������� � �������: " << responceString[resp] << endl;
			return true;
		}
		break;
	case 2:
		resp = callSetParams();
		if (resp == Success) {
			system("cls");
			cout << "��������� ������� ������!" << endl;
			return true;
		}
		else {
			cout << "�� ������� ������ ���������! ������: " << responceString[resp] << endl;
			return true;
		}
		break;
	case 3:
		resp = callSort();
		if (resp == Success) {
			system("cls");
			cout << "������������������ ������� �������������!" << endl;
			return true;
		}
		else {
			cout << "�� ������� ������������� ������������������! ������: " << responceString[resp] << endl;
			return true;
		}
		break;
	}
}

UserInterface::UserInterface()
{
}


UserInterface::~UserInterface()
{
}
