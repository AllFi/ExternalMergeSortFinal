#include "stdafx.h"
#include "UserInterface.h"
#include <iostream>
#include "FileManager.h"
#include "ExternalMergeSort.h"
#include <sstream>
#include "BubbleExternalSort.h"
#include "QuickExternalSort.h"
#include "HeapExternalSort.h"


using namespace std;

void UserInterface::initSession()
{
	char *respString[] = { "�������", "������ ���������", "���� �� ����������", "������ �������", "������ ����-���������",
		"�������� ���� � ���� ���������� ���������", "��������� ����� �����", "������ ��������� ������", "��������� �� ������ ��� ������ �������" };
	responceString = respString;
	const string ch = "����������, �������� ����� --> ";
	cout << "int=" << sizeof(int) << "long int = " << sizeof(long long) << endl;
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

void UserInterface::callGenerate() {
	cout << "��������� ������������������:" << endl;
	cout << "���������� ������� ������ ������������������: " << endl;
	long long size;
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
}

void UserInterface::callSetParams()
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
	long long size;
	cin >> size;
	while (size < 0) {
		cout << "�� ��������, ����������, ��������� --> ";
		cin >> size;
	}
	cout << "�������� ��� ���������� ����������:" << endl << "0. ���������� ���������\n1. ������� ����������\n2. ������������� ����������\n";
	int ch;
	cin >> ch;
	//Responce resp = appCore->setSortParams(file, size, TypeOfSort(ch));
	Responce resp = setParams(file, size, TypeOfSort(ch));
	if (resp == Success) {
		system("cls");
		cout << "��������� ������� ������!" << endl;
	}
	else {
		cout << "�� ������� ������ ���������! ������: " << responceString[resp] << endl;
	}
}

void UserInterface::callSort()
{	
	Responce resp;
	cout << "���������� ����������:" << endl;
	if (sort == nullptr) {
		resp = Responce::ParamsFail;
	} else
		resp = sort->externalSort();
	if (resp == Success) {
		system("cls");
		cout << "������������������ ������� ������������� �� " << sort->counter.getTimeInterval() << " �����������!" << endl;
	}
	else {
		cout << "�� ������� ������������� ������������������! ������: " << responceString[resp] << endl;
	}
}

void UserInterface::callEstimate()
{
	cout << "������ ������������� ����������:" << endl;
	Responce resp;
	if (sort == nullptr) {
		resp = Responce::ParamsFail;
	}
	else
		resp = sort->externalSort();
	if (resp == Success) {
		system("cls");
		cout << "������������������ ������� ������������� �� " << sort->counter.getTimeInterval() << " �����������!" << endl;
		cout << "���������� ������ � ������� � ����: " << sort->counter.getFileOp() << endl;
		cout << "���������� ���������: " << sort->counter.getComparsion() << endl;
		cout << "���������� ������������: " << sort->counter.getSwaps() << endl;
	}
	else {
		cout << "�� ������� ������������� ������������������! ������: " << responceString[resp] << endl;
	}
}

void UserInterface::callGetDependencies()
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
		long long size;
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
		for (long i = 100; i < 10000000; i = i * 10) {
			stringstream buf;
			buf << "input" << i << ".txt" << '\0';
			file = new FileManager(buf.str(), WriteOnly);
			file->generateSequence(i, SeqType::Worst);
		}
		system("cls");
		for (long i = 100; i < 10000000; i = i * 10) {
			stringstream buf;
			buf << "input" << i << ".txt" << '\0';
			string out("out.txt");
			file = new FileManager(buf.str(), out);
			if (size == 0) {
				resp = setParams(file, i, TypeOfSort(ch));
			} else
				resp = setParams(file, size, TypeOfSort(ch));
			if (resp != Success) {
				cout << "������! �� ������� ������ ���������!" << endl;
			}
			sort->setLog(WithOut);
			resp = sort->externalSort();
			if (resp != Success) {
				cout << "�� ������� ������������� ������������������! ������: " << responceString[resp] << endl;
			}
			cout << "������ ������� ������������������: " << i << endl;
			cout << "����� ����������: " << sort->counter.getTimeInterval() << endl;
			cout << "����� �������� � �������: " << sort->counter.getFileOp() << endl;
			cout << "����� ���������: " << sort->counter.getComparsion() << endl;
			cout << "����� ������������: " << sort->counter.getSwaps() << endl;
			cout << endl;
		}
		break;
	}
}

Responce UserInterface::setParams(FileManager * file, long long sizeOfSegments, TypeOfSort type)
{
	if (file->getState() != ReadAndWrite) {
		return Responce::FileManagerFail;
	}
	if (sizeOfSegments < 0) {
		return Responce::SizeError;
	}
	if (sizeOfSegments % 2 == 1) {
		return Responce::SizeError;
	}
	if (file->checkForEquality()) {
		return Responce::InputAndOutputIsEqual;
	}
	ExternalMergeSort *s = nullptr;
	switch (type) {
	case Bubble:
		s = new BubbleExternalSort();
		s->setParams(file, sizeOfSegments);
		break;
	case Quick:
		s = new QuickExternalSort();
		s->setParams(file, sizeOfSegments);
		break;
	case Heap:
		s = new HeapExternalSort();
		s->setParams(file, sizeOfSegments);
		break;
	}
	sort = s;
	return Responce::Success;
}

bool UserInterface::callMethod(int choise){
	system("cls");
	switch (choise) {
	case 0: 
		return false;
	case 1:
		callGenerate();
		break;
	case 2:
		callSetParams();
		break;
	case 3:
		callSort();
		break;
	case 4:
		callEstimate();
		break;
	case 5:
		callGetDependencies();
		break;
	}
	return true;
}

UserInterface::UserInterface()
{
	sort = nullptr;
}


UserInterface::~UserInterface()
{
}
