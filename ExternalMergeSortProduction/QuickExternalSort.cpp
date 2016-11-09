#include "stdafx.h"
#include "QuickExternalSort.h"
#define MAXSTACK 100000

void QuickExternalSort::sort(long long * mas, long long size)
{
	//run_sort(mas, 0, size-1);
	qSortI(mas, size);
}

QuickExternalSort::QuickExternalSort()
{
	
}


void QuickExternalSort::qSortI(long long *a, long long size) {

	long long i, j; // ���������, ����������� � ����������
	long long lb, ub; // ������� ������������ � ����� ���������

	long long lbstack[MAXSTACK], ubstack[MAXSTACK]; // ���� ��������
											   // ������ ������ �������� ����� ��������,
											   // � ������: �����(lbstack) � ������(ubstack)
											   // ��������� ����������
	long long stackpos = 1; // ������� ������� �����
	long long ppos; // �������� �������
	long long pivot; // ������� �������
	long long temp;

	lbstack[1] = 0;
	ubstack[1] = size - 1;

	do {
		// ����� ������� lb � ub �������� ������� �� �����.
		lb = lbstack[stackpos];
		ub = ubstack[stackpos];
		stackpos--;

		do {
			// ��� 1. ���������� �� �������� pivot
			ppos = (lb + ub) >> 1;
			i = lb; j = ub; pivot = a[ppos];
			do {
				while (a[i] < pivot) i++;
				while (pivot < a[j]) j--;
				counter.incComparsion(1);
				if (i <= j) {
					counter.incSwaps();
					temp = a[i]; a[i] = a[j]; a[j] = temp;
					i++; j--;
				}
			} while (i <= j);

			// ������ ��������� i ��������� �� ������ ������� ����������,
			// j - �� ����� ������ (��. ����������� ����), lb ? j ? i ? ub.
			// �������� ������, ����� ��������� i ��� j ������� �� ������� �������

			// ���� 2, 3. ���������� ������� ����� � ���� � ������� lb,ub
			counter.incComparsion(1);
			if (i < ppos) { // ������ ����� ������
				counter.incComparsion(1);
				if (i < ub) { // ���� � ��� ������ 1 �������� - �����
					stackpos++; // �����������, ������ � ����
					lbstack[stackpos] = i;
					ubstack[stackpos] = ub;
				}
				ub = j; // ��������� �������� ����������
						// ����� �������� � ����� ������
			}
			else { // ����� ����� ������
				counter.incComparsion(1);
				if (j > lb) {
					stackpos++;
					lbstack[stackpos] = lb;
					ubstack[stackpos] = j;
				}
				lb = i;
			}
		} while (lb < ub); // ���� � ������� ����� ����� 1 ��������
	} while (stackpos != 0); // ���� ���� ������� � �����
}

QuickExternalSort::~QuickExternalSort()
{
}
