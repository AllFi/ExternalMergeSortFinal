#include "stdafx.h"
#include "HeapExternalSort.h"


HeapExternalSort::HeapExternalSort()
{
}


void HeapExternalSort::iswap(long int &n1, long int &n2)
{
	long int temp = n1;
	n1 = n2;
	n2 = temp;
}

void HeapExternalSort::sort(long int*  a, long long n)
{   //������������� ���������� ������� heap.
	int sh = 0; //��������
	bool b = false;
	for (;;)
	{
		b = false;
		for (int i = 0; i < n; i++)
		{
			if (i * 2 + 2 + sh < n)
			{
				if ((a[i + sh] > /*<*/ a[i * 2 + 1 + sh]) || (a[i + sh] > /*<*/ a[i * 2 + 2 + sh]))
				{
					if (a[i * 2 + 1 + sh] < /*>*/ a[i * 2 + 2 + sh])
					{
						iswap(a[i + sh], a[i * 2 + 1 + sh]);
						b = true;
					}
					else if (a[i * 2 + 2 + sh] < /*>*/ a[i * 2 + 1 + sh])
					{
						iswap(a[i + sh], a[i * 2 + 2 + sh]);
						b = true;
					}
				}
				//�������������� �������� ��� ��������� ���� ���������
				//� ������� ���� �������� ����� ������������� ��������
				//��������� ����� ���� �� ���� ���������
				if (a[i * 2 + 2 + sh] < /*>*/ a[i * 2 + 1 + sh])
				{
					iswap(a[i * 2 + 1 + sh], a[i * 2 + 2 + sh]);
					b = true;
				}
			}
			else if (i * 2 + 1 + sh < n)
			{
				if (a[i + sh] > /*<*/ a[i * 2 + 1 + sh])
				{
					iswap(a[i + sh], a[i * 2 + 1 + sh]);
					b = true;
				}
			}
		}
		if (!b) sh++; //�������� �������������, ����� �� ������� �����
					  //����������� ������ ������
		if (sh + 2 == n) break;
	}  //����� ����������
}



HeapExternalSort::~HeapExternalSort()
{
}
