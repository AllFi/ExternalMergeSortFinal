#include "stdafx.h"
#include "UserInterface.h"
#include <iostream>
#include "FileManager.h"
#include "ExternalMergeSort.h"
#include <sstream>
#include "BubbleExternalSort.h"
#include "QuickExternalSort.h"
#include "HeapExternalSort.h"


//matrix_tim
#include <conio.h>
using namespace std;

void UserInterface::matrixTime() {
	string matr("matrix");
	string buf;
	cin.clear();
	cin >> buf;
	int f=0,i;
	i = 0;
	if (buf == matr) {
		char mas[6] = { '0','0' ,'0' ,'0' ,'0', '0' };
		system("cls");
		system("color 02");
		while (true) {
			cout << 10 + rand() % 90 << " ";
			if (_kbhit()) {
				if (i > 4) {
					for (int j = 0; j < 5; j++) {
						mas[j] = mas[j + 1];
					}
					i = 5;
				}
				mas[i] = _getch();
				i++;
			}
			if (mas[0] == matr.c_str()[0] && 
				mas[1] == matr.c_str()[1] && 
				mas[2] == matr.c_str()[2] && 
				mas[3] == matr.c_str()[3] && 
				mas[4] == matr.c_str()[4] && 
				mas[5] == matr.c_str()[5])
				break;
		}
		system("color 08");
		cout << "Bye!" << endl;
		system("cls");
	}
}

void UserInterface::initSession()
{
	const string ch = "����������, �������� ����� --> ";
	
	cout << menu.c_str() << ch.c_str();
	int choise = -1;
	cin >> choise;
	while (choise < 0 || choise > 5) {
		matrixTime();
		cout << "�� ��������, ����������, ��������� --> ";
		cin >> choise;
	}
	while (callMethod(choise)) {
		system("pause");
		system("cls");
		cout << menu.c_str() << ch.c_str();
		cin >> choise;
		while (choise < 0 || choise > 5) {
			matrixTime();
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
		matrixTime();
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
		matrixTime();
		cout << "�� ��������, ����������, ��������� --> ";
		cin >> ch;
	}
	FileManager fileManager(file, WriteOnly);
	Response resp = fileManager.generateSequence(size,SeqType(ch));
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
		matrixTime();
		cout << "�� ��������, ����������, ��������� --> ";
		cin >> size;
	}
	cout << "�������� ��� ���������� ����������:" << endl << "0. ���������� ���������\n1. ������� ����������\n2. ������������� ����������\n";
	int ch;
	cin >> ch;
	while (ch < 0 || ch > 2) {
		matrixTime();
		cout << "�� ��������, ����������, ��������� --> ";
		cin >> ch;
	}
	Response resp = setParams(file, size, TypeOfSort(ch));
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
	Response resp;
	cout << "���������� ����������:" << endl;
	if (sort == nullptr) {
		resp = Response::ParamsFail;
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
	Response resp;
	if (sort == nullptr) {
		resp = Response::ParamsFail;
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

void UserInterface::callGetDependenceSize() {
	cout << "��������� ����������� �� ������� ������������������: " << endl;
	cout << "������� ������ ��������� � ��������� �� ������� ������������������:  ";
	int size;
	cin >> size;
	while (size < 1 || size >100) {
		matrixTime();
		cout << "�� ��������, ����������, ��������� --> ";
		cin >> size;
	}
	cout << "�������� ��� ���������� ����������:" << endl << "0. ���������� ���������\n1. ������� ����������\n2. ������������� ����������\n";
	int ch;
	cin >> ch;
	while (ch < 0 || ch > 2) {
		matrixTime();
		cout << "�� ��������, ����������, ��������� --> ";
		cin >> ch;
	}
	FileManager *file;
	Response resp;
	for (long i = 100; i < 1000000; i = i * 10) {
		stringstream buf;
		buf << "input" << i << ".txt" << '\0';
		file = new FileManager(buf.str(), WriteOnly);
		file->generateSequence(i, SeqType::Worst);
	}
	system("cls");
	long long sizeOfS;
	for (long i = 100; i < 1000000; i = i * 10) {
		stringstream buf;
		buf << "input" << i << ".txt" << '\0';
		string out("out.txt");
		file = new FileManager(buf.str(), out);
		sizeOfS = i / 100 *size;
		resp = setParams(file, sizeOfS, TypeOfSort(ch));
		if (resp != Success) {
			cout << "������ ������� ������������������: " << i << endl;
			cout << "�� ������� ������ ���������! ������: " << responceString[resp] <<   endl << endl;
			continue;
		}
		sort->setLog(WithOut);
		resp = sort->externalSort();
		if (resp != Success) {
			cout << "������ ������� ������������������: " << i << endl;
			cout << "�� ������� ������������� ������������������! ������: " << responceString[resp] << endl;
			continue;
		}
		cout << "������ ������� ������������������: " << i << endl;
		cout << "����� ����������: " << sort->counter.getTimeInterval() << endl;
		cout << "����� �������� � �������: " << sort->counter.getFileOp() << endl;
		cout << "����� ���������: " << sort->counter.getComparsion() << endl;
		cout << "����� ������������: " << sort->counter.getSwaps() << endl;
		cout << endl;
	}
}

void UserInterface::callGetDependenceSizeOfSegments() {
	cout << "��������� ����������� �� ������� ���������:" << endl;
	stringstream buf;
	cout << "������� ������ �������� ������������������: ";
	long long size;
	cin >> size;

	while (size < 0) {
		matrixTime();
		cout << "�� ��������, ����������, ��������� --> ";
		cin >> size;
	}
	cout << "�������� ��� ���������� ����������:" << endl << "0. ���������� ���������\n1. ������� ����������\n2. ������������� ����������\n";
	int ch;
	cin >> ch;
	while (ch < 0 || ch > 2) {
		matrixTime();
		cout << "�� ��������, ����������, ��������� --> ";
		cin >> ch;
	}
	buf << "input" << size << ".txt" << '\0';
	FileManager *file;
	file = new FileManager(buf.str(), WriteOnly);
	file->generateSequence(size, SeqType::Worst);
	system("cls");
	string out("out.txt");
	file = new FileManager(buf.str(), out);
	Response resp;
	for (long long i = 100; i <= size; i = i * 10) {
		 resp = setParams(file, i, TypeOfSort(ch));
		 if (resp != Success) {
			 cout << "������ ���������: " << i << endl;
			 cout << "�� ������� ������ ���������! ������: " << responceString[resp] << endl << endl;
			 continue;
		 }
		 sort->setLog(WithOut);
		 sort->externalSort();
		 if (resp != Success) {
			 cout << "������ ���������: " << i << endl;
			 cout << "�� ������� ������������� ������������������! ������: " << responceString[resp] << endl;
			 continue;
		 }
		 cout << "������ ���������: " << i << endl;
		 cout << "����� ����������: " << sort->counter.getTimeInterval() << endl;
		 cout << "����� �������� � �������: " << sort->counter.getFileOp() << endl;
		 cout << "����� ���������: " << sort->counter.getComparsion() << endl;
		 cout << "����� ������������: " << sort->counter.getSwaps() << endl;
		 cout << endl;
	}
}

void UserInterface::callGetDependenceType()
{
	cout << "��������� ����������� �� ���� ����������: " << endl;
	cout << "������� ������ �������� ������������������: ";
	long long size;
	cin >> size;
	while (size < 0 ) {
		matrixTime();
		cout << "�� ��������, ����������, ��������� --> ";
		cin >> size;
	}
	cout << "������� ������ ���������: ";
	long long sizeOfSegments;
	cin >> sizeOfSegments;
	while (sizeOfSegments < 0 || sizeOfSegments > size) {
		matrixTime();
		cout << "�� ��������, ����������, ��������� --> ";
		cin >> size;
	}
	FileManager *file;
	stringstream buf;
	buf << "input" << size << ".txt" << '\0';
	Response resp;
	file = new FileManager(buf.str(), WriteOnly);
	resp = file->generateSequence(size, SeqType::Worst);
	
	if (resp != Success) {
		cout << "������! �� ������� ������������� ������������������!" << endl;
	}
	string out("out.txt");
	file = new FileManager(buf.str(), out);
	for (int i = 0; i < 3; i++) {
		resp = setParams(file, sizeOfSegments, TypeOfSort(i));
		if (resp != Success) {
			cout << "��� ����������: " << i << endl;
			cout << "�� ������� ������ ���������! ������: " << responceString[resp] << endl << endl;
			continue;
		}
		sort->setLog(WithOut);
		sort->externalSort();
		if (resp != Success) {
			cout << "��� ����������: " << i << endl;
			cout << "�� ������� ������������� ������������������! ������: " << responceString[resp] << endl;
			continue;
		}
		sort->setLog(WithOut);
		cout << "��� ����������: " << TypeOfSort(i) << endl;
		cout << "����� ����������: " << sort->counter.getTimeInterval() << endl;
		cout << "����� �������� � �������: " << sort->counter.getFileOp() << endl;
		cout << "����� ���������: " << sort->counter.getComparsion() << endl;
		cout << "����� ������������: " << sort->counter.getSwaps() << endl;
		cout << endl;
	}
}

void UserInterface::callGetDependencies()
{
	cout << "��������� �����������: " << endl;
	cout << "�������� ���������� ��������������:\n0. ������ ������������������\n1. ������ ���������\n2. ��� ���������� ����������\n->>";
	int choise = -1;
	cin >> choise;
	while (choise < 0 || choise > 2) {
		matrixTime();
		cout << "�� ��������, ����������, ��������� --> ";
		cin >> choise;
	}
	switch (choise) {
	case 0: 
		callGetDependenceSize();
		break;
	case 1:
		callGetDependenceSizeOfSegments();
		break;
	case 2:
		callGetDependenceType();
		break;
	}
}

Response UserInterface::setParams(FileManager * file, long long sizeOfSegments, TypeOfSort type)
{
	if (file->getState() != ReadAndWrite) {
		return Response::FileManagerFail;
	}
	if (sizeOfSegments < 0) {
		return Response::SizeError;
	}
	if (sizeOfSegments % 2 == 1) {
		return Response::SizeError;
	}
	if (file->checkForEquality()) {
		return Response::InputAndOutputIsEqual;
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
	return Response::Success;
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
