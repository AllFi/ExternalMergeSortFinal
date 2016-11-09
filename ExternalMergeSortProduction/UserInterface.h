#pragma once
#include "Structures.h"
#include "ExternalMergeSort.h"

class UserInterface
{
private:
	ExternalMergeSort *sort;
	const string menu = "0. �����\n1. ������������� ������������������\n2. ������ ��������� ����������\n3. ������������� ������������������\n4. ������� �������������� ����������\n5. ��������� ������������\n";
	const char *responceString[9] = { "�������", "������ ���������", "���� �� ����������", "������ �������", "������ ����-���������",
		"�������� ���� � ���� ���������� ���������", "��������� ����� �����", "������ ��������� ������", "��������� �� ������ ��� ������ �������" };
	bool callMethod(int ch);
	void callGenerate();
	void callSetParams();
	void callSort();
	void callEstimate();
	void callGetDependencies();
	Responce setParams(FileManager *file, long long sizeOfSegments, TypeOfSort type);
	void getDependenceSize();
	void getDependenceSizeOfSegments();
	void getDependenceType();
public:
	void initSession();
	UserInterface();
	~UserInterface();
};

