#include "stdafx.h"
#include "UserInterface.h"
#include <iostream>
#include "FileManager.h"
#include "ExternalMergeSort.h"
#include <sstream>

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
	while (choise < 0 || choise > 5) {
		cout << "�� ��������, ����������, ��������� --> ";
		cin >> choise;
	}
	while (callMethod(choise)) {
		system("pause");
		system("cls");
		cout << menu.c_str() << ch.c_str();
		cin >> choise;
		while (choise < 0 || choise > 5) {
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

Responce UserInterface::callGetDependencies()
{
	cout << "��������� �����������: " << endl;
	cout << "�������� ���������� ��������������:\n0. ������ ������������������\n1. ������ ���������\n2. ��� ���������� ����������\n->>";
	int choise = -1;
	cin >> choise;
	while (choise < 0 || choise > 2) {
		cout << "�� ��������, ����������, ��������� --> ";
		cin >> choise;
	}
	switch (choise) {
	case 0:
		//FileManager *file = new FileManager(iFile, oFile);
		cout << "������� ������ ���������, 0 ���� ������ ��������� ����� ������� ������������������: ";
		int size;
		cin >> size;
		while (size < 0 || size >101) {
			cout << "�� ��������, ����������, ��������� --> ";
			cin >> size;
		}
		cout << "�������� ��� ���������� ����������:" << endl << "0. ���������� ���������\n1. ������� ����������\n2. ������������� ����������\n";
		int ch;
		cin >> ch;
		FileManager *file;
		Responce resp;
		for (long i = 100; i < 100000000; i = i * 10) {
			stringstream buf;
			buf << "input" << i << ".txt" << '\0';
			file = new FileManager(buf.str(), WriteOnly);
			file->generateSequence(i, SeqType::Worst);
		}
		system("cls");
		for (long i = 100; i < 100000000; i = i * 10) {
			stringstream buf;
			buf << "input" << i << ".txt" << '\0';
			string out("out.txt");
			file = new FileManager(buf.str(), out);
			if (size == 0) {
				resp = appCore->setSortParams(file, i, TypeOfSort(ch));
			} else
				resp = appCore->setSortParams(file, size, TypeOfSort(ch));
			if (resp != Success) {
				cout << "������! �� ������� ������ ���������!" << endl;
				return resp;
			}
			appCore->setLog(WithOut);
			resp = appCore->externalSort();
			if (resp != Success) {
				cout << "�� ������� ������������� ������������������! ������: " << responceString[resp] << endl;
				return resp;
			}
			cout << "������ ������� ������������������: " << i << endl;
			cout << "����� ����������: " << appCore->getCounter().getTimeInterval() << endl;
			cout << "����� �������� � �������: " << appCore->getCounter().getFileOp() << endl;
			cout << "����� ���������: " << appCore->getCounter().getComparsion() << endl;
			cout << "����� ������������: " << appCore->getCounter().getSwaps() << endl;
			cout << endl;
		}
		break;
	}
	return Success;
}

bool UserInterface::callMethod(int choise){
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
	case 5:
		resp = callGetDependencies();
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
