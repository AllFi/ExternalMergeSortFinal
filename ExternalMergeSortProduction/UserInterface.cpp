#include "stdafx.h"
#include "UserInterface.h"
#include <iostream>
#include "FileManager.h"

using namespace std;

void UserInterface::initSession()
{
	const string menu = "0. �����\n1. ������������� ������������������\n";
	const string ch = "����������, �������� ����� --> ";
	cout << menu.c_str() << ch.c_str();
	int choise = -1;
	cin >> choise;
	while (choise < 0 || choise > 1) {
		cout << "�� ��������, ����������, ��������� --> ";
		cin >> choise;
	}
	while (callMethod(choise)) {
		system("pause");
		system("cls");
		cout << menu.c_str() << ch.c_str();
		cin >> choise;
		while (choise < 0 || choise > 1) {
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

bool UserInterface::callMethod(int choise)
{
	char* responceString[] = { "�������", "������ ���������", "���� �� ����������", "������ �������", "������ ����-���������" };
	Responce resp;
	switch (choise) {
	case 0: 
		return false;
	case 1:
		resp = callGenerate();
		if (resp == Success) {
			cout << "��������� �������!" << endl;
			return true;
		}
		else {
			cout << "��������� ����������� � �������: " << responceString[resp] << endl;
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
