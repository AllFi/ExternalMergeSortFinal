#pragma once
#include "ExternalMergeSort.h"

/*!
\brief ����� ������� ����������� ���������� ��������, ������������ ���������� ����������� ����������.
\author Alexander Filippov
\date ������ 2016 ����

����������� �� ExternalMergeSort, ����������� ����� ���������� ����������, ������� ������������ ����������� ���������� ������������������.
*/
class BubbleExternalSort :
	public ExternalMergeSort
{
private:
	/*!
	\brief ��������� ������������������ ������ size ������� ����������� ����������.
	\param[in] arr ������, ������� ���������� �������������.
	\param[in] size ����� �������.

	����������� �����. ���������� � ������.
	��������� ������������������ ������ size ������� ����������� ����������.
	*/
	virtual void sort(long long *arr, long long size);
public:
	
	/*!
	\brief ������ ����������� ������.

	�������� ��������.
	*/
	BubbleExternalSort();
	/*!
	\brief ������ ����������� ���������� ������.

	����������� ���������� ������.
	*/
	~BubbleExternalSort();
};

