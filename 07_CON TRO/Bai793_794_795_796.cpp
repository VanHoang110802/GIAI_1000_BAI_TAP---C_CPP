/*
Tính tổng các phần tử thuộc ma trận tam giác trên (không tính đường chéo) trong ma trận vuông các số thực.

Tính tổng các phần tử thuộc ma trận tam giác dưới (không tính đường chéo) trong ma trận vuông các số thực.

Tính tổng các phần tử trên đường chéo chính.

Tính tổng các phần tử trên đường chéo phụ.

Tính tổng các phần tử chẵn nằm trên biên của ma trận vuông các số nguyên.
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
void CapPhat(vanhoang**& a, int n)
{
	a = new vanhoang * [n];
	for (int i = 0; i < n; ++i)
	{
		a[i] = new vanhoang[n];
	}
}
template <typename vanhoang>
void NhapMaTran(vanhoang**a, int& n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "a[" << i << "][" << j << "]= ";
			cin >> a[i][j];
		}
	}
}
template <typename vanhoang>
void XuatMaTran(vanhoang**a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
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
int TinhTongCacPhanTuTamGiacTrenDuongCheoChinh(int **a, int n)
{
	int tong = 0;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			tong += a[i][j];
		}
	}
	return tong;
}
//-------------------------------------------------------------------------------------------------------
int TinhTongCacPhanTuTamGiacTrenDuongCheoPhu(int **a, int n)
{
	int tong = 0;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			tong += a[i][j];
		}
	}
	return tong;
}
//---------------------------------------------------------------------------------------------------
int TinhTongCacPhanTuTrenDuongCheoChinh(int **a, int n)
{
	int tong = 0;
	for (int i = 0; i < n; i++)
	{
		tong += a[i][i];
	}
	return tong;
}
//---------------------------------------------------------------------------------------------------
int TinhTongCacPhanTuTrenDuongCheoPhu(int **a, int n)
{
	int tong = 0;
	for (int i = 0; i < n; i++)
	{
		tong += a[i][n - 1 - i];
	}
	return tong;
}
//---------------------------------------------------------------------------------------------------
int TinhTongCacPhanTuChanNamTrenBien(int **a, int n)
{
	int tong = 0;
	// Duyệt 2 cột biên
	for (int i = 0; i < n; i++)
	{
		if (a[0][i] % 2 == 0)
		{
			tong += a[0][i];
		}
		if (a[n - 1][i] % 2 == 0)
		{
			tong += a[n - 1][i];
		}
	}
	// Duyệt 2 dòng biên bỏ qua các phần tử thuộc 2 cột đã duyệt
	for (int i = 1; i < n - 1; i++)
	{
		if (a[i][0] % 2 == 0)
		{
			tong += a[i][0];
		}
		if (a[i][n - 1] % 2 == 0)
		{
			tong += a[i][n - 1];
		}
	}
	return tong;
}
int main()
{
	int n;
	cout << "Nhap so dong & so cot: ";
	NhapDuLieu(n);
	int** a , x = 1;
	CapPhat(a, n);
	NhapMaTran(a, n);
	XuatMaTran(a, n);
	cout << "\n";
	//TinhTongCacPhanTuChanNamTrenBien(a, n);
	//TinhTongCacPhanTuTamGiacTrenDuongCheoChinh(a, n);
	//TinhTongCacPhanTuTamGiacTrenDuongCheoPhu(a, n);
	//TinhTongCacPhanTuTrenDuongCheoChinh(a, n);
	//TinhTongCacPhanTuTrenDuongCheoPhu(a, n);
	int t = TinhTongCacPhanTuTrenDuongCheoPhu(a, n);
	cout << t;
	if (a != NULL)
	{
		ThuHoi(a, n);
	}
	return 0;
}
