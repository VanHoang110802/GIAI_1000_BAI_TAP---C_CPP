/*

Hoán vị hai dòng trên ma trận.

Hoán vị hai cột trên ma trận.
*/

#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

void NhapDuLieu(int& n)
{
	do
	{
		cin >> n;
		if (n < 1)
		{
			cout << "\nSo luong phan tu nhap khong hop le, xin hay nhap lai!\n";
		}
	} while (n < 1);
}
template <typename vanhoang>
void CapPhat(vanhoang**& a, int sodong, int socot)
{
	a = new vanhoang * [sodong];
	for (int i = 0; i < sodong; ++i)
	{
		a[i] = new vanhoang[socot];
	}
}
template <typename vanhoang>
void NhapMang(vanhoang** a, int sodong, int socot)
{
	for (int i = 0; i < sodong; ++i)
	{
		for (int j = 0; j < socot; ++j)
		{
			cout << "a[" << i << "][" << j << "]= ";
			cin >> a[i][j];
		}
	}
}
template <typename vanhoang>
void XuatMang(vanhoang** a, int sodong, int socot)
{
	for (int i = 0; i < sodong; ++i)
	{
		for (int j = 0; j < socot; ++j)
		{
			cout << a[i][j] << "\t";
		}
		cout << endl;
	}
}
//-------------------------------------------------------------------------------------------------------
void HoanVi(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void HoanVi2Dong(int **a, int dong, int cot, int dong1, int dong2)
{
	if ((dong1 >= 0 && dong1 < dong) && (dong2 >= 0 && dong2 < dong))
	{
		for (int j = 0; j < cot; j++)
		{
			HoanVi(a[dong1][j], a[dong2][j]);
		}
	}
}
//--------------------------------------------------------------------------------------------
void HoanVi2Cot(int **a, int dong, int cot, int cot1, int cot2)
{
	if ((cot1 >= 0 && cot1 < cot) && (cot2 >= 0 && cot2 < cot))
	{
		for (int i = 0; i < dong; i++)
		{
			HoanVi(a[i][cot1], a[i][cot2]);
		}
	}
}
/*
void ThuHoi(int*** a, int sodong)
{
	for (int i = 0; i < sodong; ++i)
	{
		delete (*a)[i];
	}
	delete[](*a);
}
*/
template <typename vanhoang>
void ThuHoi(vanhoang**& a, int sodong)
{
	for (int i = 0; i < sodong; ++i)
	{
		delete a[i];
	}
	delete[]a;
}
int main()
{
	int sodong, socot;
	cout << "Nhap so dong: ";
	NhapDuLieu(sodong);
	cout << "Nhap so cot: ";
	NhapDuLieu(socot);
	int** a , x = 1;
	CapPhat(a, sodong, socot);
	NhapMang(a, sodong, socot);
	XuatMang(a, sodong, socot);
	cout << "\n\n";
	//HoanVi2Dong(a, sodong, socot, 0, 1);
	//XuatMang(a, sodong, socot);
	
	HoanVi2Cot(a, sodong, socot, 0, 1);
	XuatMang(a, sodong, socot);
	if (a != NULL)
	{
		//ThuHoi(&a, sodong);
		ThuHoi(a, sodong);
	}
	return 0;
}
