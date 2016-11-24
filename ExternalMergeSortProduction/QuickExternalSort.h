#pragma once
#include "ExternalMergeSort.h"

/*!
\brief ����� ������� ����������� ���������� ��������, ������������ ���������� ������� ����������.
\author Alexander Filippov
\date ������ 2016 ����

����������� �� ExternalMergeSort, ����������� ����� ���������� ����������, ������� ������������ ������� ���������� ������������������.
*/
class QuickExternalSort :
	public ExternalMergeSort
{
private:
	/*!
	\brief ��������� ������������������ ������ size ������� ������� ���������� ����������� �������.
	\param[in] arr ������, ������� ���������� �������������.
	\param[in] size ����� �������.

	��������� ������������������ ������ size ������� ������� ����������.
	*/
	void QuickExternalSort::qSortI(long long *arr, long long size);
	/*!
	\brief ��������� ������������������ ������ size ������� ������� ����������.
	\param[in] arr ������, ������� ���������� �������������.
	\param[in] size ����� �������.

	����������� �����. ���������� � ������.
	������� qSortI(...), ������� ��������� ������������������ ������ size ������� ������� ����������.
	*/
	virtual void QuickExternalSort::sort(long long *arr, long long size);
public:
	/*!
	\brief ������ ����������� ������.

	�������� ��������.
	*/
	QuickExternalSort();
	/*!
	\brief ������ ����������� ���������� ������.

	����������� ���������� ������.
	*/
	~QuickExternalSort();
};

