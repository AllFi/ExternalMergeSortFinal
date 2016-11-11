#pragma once
#include <ctime>

using namespace std;


/*!
\brief ����� �������.
\author Alexander Filippov
\date ������ 2016 ����

�����, ���������� �� ������� ������������� ����������.
*/
class Counter
{
private:
	/*!
	\brief ��������� �����.

	����� ������ ��������� �� ������ ������ ����������.
	*/
	long long begTime;
	/*!
	\brief �������� �����.

	����� ������ ��������� �� ������ ���������� ����������.
	*/
	long long endTime;
	/*!
	\brief ����� ���������.

	*/
	long long comparsion;
	/*!
	\brief ����� �������� � �������.
	����� ������� � ���� � ������ �� ����� �����.
	*/
	long long fileOp;
	/*!
	\brief ����� ������������.
	������� ������������ ������ � ������ ���������� ����������, �.�. ��� � �� ����� ������.
	*/
	long long swaps;
public:
	/*!
	\brief ������ ����������� ������.
	�������� �������.
	*/
	Counter();
	/*!
	
	\brief ����� ������������ ������.
	\param[in] ch ����� ������������
	\return ������ �������� - ���� true, �� ���������� ������ ���������, ���� ���, �� ����� �� ������������ �����.
	*/
	void setBegTime();
	long setEndTime();
	long getTimeInterval();
	void incSwaps();
	long getSwaps();
	void incComparsion(long long n);
	long getComparsion();
	void incFileOp(long long n);
	long getFileOp();
	void clear();
	~Counter();
};

