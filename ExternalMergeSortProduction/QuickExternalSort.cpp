#include "stdafx.h"
#include "QuickExternalSort.h"
#define MAXSTACK 10000

void QuickExternalSort::sort(long int * mas, long long size)
{
	//run_sort(mas, 0, size-1);
	qSortI(mas, size);
}

QuickExternalSort::QuickExternalSort()
{
	
}


void QuickExternalSort::qSortI(long int *a, long long size) {

	long i, j; // ���������, ����������� � ����������
	long lb, ub; // ������� ������������ � ����� ���������

	long lbstack[MAXSTACK], ubstack[MAXSTACK]; // ���� ��������
											   // ������ ������ �������� ����� ��������,
											   // � ������: �����(lbstack) � ������(ubstack)
											   // ��������� ����������
	long stackpos = 1; // ������� ������� �����
	long ppos; // �������� �������
	long int pivot; // ������� �������
	long int temp;

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


int QuickExternalSort::run_sort(long int *mas, long long first, long long last) {
	long long pivot = 0;
	counter.incComparsion(1);
	if (first < last) {
		pivot = pivot_mas(mas, first, last);
		//run_sort(mas, first, pivot - 1);
		last = pivot - 1;
		run_sort(mas, pivot + 1, last);
	}
	return 1;
}

long int * QuickExternalSort::swap(long int *mas, long long x, long long y) {
	counter.incSwaps();
	long int buf = 0;
	buf = mas[x];
	mas[x] = mas[y];
	mas[y] = buf;
	return mas;
}

long long QuickExternalSort::pivot_mas(long int *mas, long long first, long long last) {
	long long PivotValue = mas[first];
	long long	PivotPoint = first;
	long long index = 0;
	for (index = first + 1; index <= last; index++) {
		counter.incComparsion(1);
		if (mas[index] < PivotValue) {
			PivotPoint = PivotPoint + 1;
			mas = swap(mas, PivotPoint, index);
		}
	}
	mas = swap(mas, first, PivotPoint); // �����������������������������������
	return PivotPoint;

}

QuickExternalSort::~QuickExternalSort()
{
}
