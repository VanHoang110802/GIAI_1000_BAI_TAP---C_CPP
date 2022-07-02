/*
Cho ma trận các số thực A(m x n). 
Hãy xây dựng ma trận B(m x n) từ ma trận A sao cho B[i][j] = abs(A[i][j]).

Cho ma trận các số thực A (m x n). 
Hãy xây dựng ma trận B(m x n) từ ma trận A sao cho B[i][j] = lớn nhất của dòng i và cột j trong ma trận A.
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
template <typename vanhoang>
void ThuHoi(vanhoang**& a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		delete a[i];
	}
	delete[]a;
}
//-------------------------------------------------------------------------------------------------------

void XayDungMaTranB(int **a, int dong, int cot, int **b)
{
	for (int i = 0; i < dong; i++)
	{
		for (int j = 0; j < cot; j++)
		{
			b[i][j] = abs(a[i][j]);
		}
	}
}
//------------------------------------------------------------------------------------------------------
int TimPhanTuLonNhatDongICotJ(int **a, int dong, int cot, int i, int j)
{
	int Max = a[i][0];
	// Tìm phần tử lớn nhất dòng i
	for (int k = 1; k < dong; k++)
	{
		Max = (Max < a[i][k]) ? a[i][k] : Max;
	}
	// Tìm phần tử lớn nhất cột j
	for (int k = 0; k < cot; k++)
	{
		Max = (Max < a[k][j]) ? a[k][j] : Max;
	}
	return Max;
}

void XayDungMaTranB_1(int **a, int dong, int cot, int **b)
{
	for (int i = 0; i < dong; i++)
	{
		for (int j = 0; j < cot; j++)
		{
			b[i][j] = TimPhanTuLonNhatDongICotJ(a, dong, cot, i, j);
		}
	}
}

int main()
{
	int sodong, socot;
	cout << "Nhap so dong: ";
	NhapDuLieu(sodong);
	cout << "Nhap so cot: ";
	NhapDuLieu(socot);
	int** a;
	CapPhat(a, sodong, socot);
	NhapMang(a, sodong, socot);
	int** b;
	CapPhat(b, sodong, socot);
	//XayDungMaTranB(a, sodong, socot, b);
	XayDungMaTranB_1(a,sodong, socot, b);
	cout << "\n\n";
	XuatMang(a, sodong, socot);
	cout << "\n\n";
	XuatMang(b, sodong, socot);
	
	if (a != NULL)
	{
		
		ThuHoi(a, sodong);
	}
	if (b != NULL)
	{
		
		ThuHoi(b, sodong);
	}
	return 0;
}
