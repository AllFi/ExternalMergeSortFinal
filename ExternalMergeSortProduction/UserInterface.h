#pragma once
#include "Structures.h"
#include "ExternalMergeSort.h"

class UserInterface
{
private:
	ExternalMergeSort *sort;
	const string menu = "0. �����\n1. ������������� ������������������\n2. ������ ��������� ����������\n3. ������������� ������������������\n4. ������� �������������� ����������\n5. ��������� ������������\n";
	bool callMethod(int ch);
	void callGenerate();
	void callSetParams();
	void callSort();
	void callEstimate();
	void callGetDependencies();
	char **responceString;
	Responce setParams(FileManager *file, long long sizeOfSegments, TypeOfSort type);
public:
	void initSession();
	UserInterface();
	~UserInterface();
};

