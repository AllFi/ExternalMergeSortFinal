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
	\brief ������� ��������� ����� �������.
	
	����������� �������� begTime ������� ����� ������ ������ ���������.
	*/
	void setBegTime();
	/*!
	\brief ������� �������� ����� �������.
	/return ���������� ����� ����������� ����� ��������� begTime � endTime.
	
	����������� �������� endTime ������� ����� ������ ������ ���������.
	*/
	long long setEndTime();
	/*!
	\brief ��������� ���������� ���������.
	/return ���������� ����� ����������� ����� ��������� begTime � endTime.

	������������ ��������� �������� � ������������� ������ ��������� �� ������� begTime �� ������� endTime.
	*/
	long long getTimeInterval();
	/*!
	\brief ���������� �������� ������������.
	
	����������� �� ������� ������� ������������, ����������� ��������� swaps.
	*/
	void incSwaps();
	/*!
	\brief ��������� �������� ������������.
	/return ����� ������������, ���������� ��������� swaps.

	�������� ����� ������������, ���������� ��������� swaps.
	*/
	long long getSwaps();
	/*!
	\brief ���������� �������� ���������.
	\param[in] n �����, �� ������� ����� ������������� ������� ���������.
	
	����������� ������� ������������, ���������� ��������� comparsion, �� n.
	*/
	void incComparsion(long long n);
	/*!
	\brief ��������� �������� ���������.
	/return ����� ���������, ���������� ��������� comparsion.

	�������� ����� ���������, ���������� ��������� comparsion.
	*/
	long long getComparsion();
	/*!
	\brief ���������� �������� ����� �������� � �������.
	\param[in] n �����, �� ������� ����� ������������� ������� �������� � �������.
	
	����������� �� n ������� ����� �������� � �������, ���������� ��������� fileOp. ��� ���������� � ������ ������ ���������������
	������ ����� �� ����� � ������ ����� � ����.
	*/
	void incFileOp(long long n);
	/*!
	\brief ��������� �������� �������� ��������.
	/return ����� �������� ��������, ���������� ��������� fileOp.

	�������� ����� �������� ��������, ���������� ��������� fileOp.
	*/
	long long getFileOp();
	/*!
	\brief ��������� ��������.
	
	�������� ��� ��������, ����������� ���� ��������� 0.
	*/
	void clear();
	~Counter();
};

