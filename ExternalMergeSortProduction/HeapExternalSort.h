#pragma once
#include "ExternalMergeSort.h"

/*!
\brief ����� ������� ����������� ���������� ��������, ������������ ���������� ������������� ����������
\author Alexander Filippov
\date ������ 2016 ����

����������� �� ExternalMergeSort, ����������� ����� ���������� ����������, ������� ������������ ������������� ���������� ������������������.
*/
class HeapExternalSort :
	public ExternalMergeSort
{
private: 
	/*!
	\brief ��������� ������ �������� ��������
	\param[in] arr ����������� ������.
	\param[in] root �������� �������.
	\param[in] bottom ���������� �������.

	�������� ����� ������� ������� ������������� ����������, ������ �� ������������ ����������.
	*/
	void HeapExternalSort::siftDown(long long *arr, long long root, long long bottom);
	/*!
	\brief ��������� ������������������ ������ size ������� ������������� ����������.
	\param[in] arr ������, ������� ���������� �������������.
	\param[in] size ����� �������.

	����������� �����. ���������� � ������.
	��������� ������������������ ������ size ������� ������������� ����������.
	*/
	virtual void HeapExternalSort::sort(long long *numbers, long long array_size);
public:
	
	/*!
	\brief ������ ����������� ������.

	�������� ��������.
	*/
	HeapExternalSort();
	/*!
	\brief ������ ����������� ���������� ������.

	����������� ���������� ������.
	*/
	~HeapExternalSort();
};

