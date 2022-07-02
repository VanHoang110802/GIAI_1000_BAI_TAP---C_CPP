/*
Đếm số lượng cặp giá trị đối xứng nhau qua đường chéo chính.

Đếm số lượng dòng giảm trong ma trận.

Đếm số lượng giá trị dương trên đường chéo chính trỏng ma trận vuông các số thực.

Đếm số lượng giá trị âm trên đường chéo phụ trong ma trận vuông các số thực.

Đếm số lượng giá trị chẵn trong ma trận tam giác trên của ma trận vuông các số nguyên.
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
int DemCapGiaTriDoiXungQuaDuongCheoChinh(int **a, int n)
{
	int dem = 0;
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (a[i][j] == a[j][i])
			{
				dem++;
			}
		}
	}
	return dem;
}
//-------------------------------------------------------------------------------------------------------
int KiemTraDongGiam(int *a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		if (a[i] < a[i + 1])
		{
			return 0;
		}
	}
	return 1;
}

int DemSoLuongDongGiam(int **a, int n)
{
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		if (KiemTraDongGiam(a[i], n) == 1)
		{
			dem++;
		}
	}
	return dem;
}
//-------------------------------------------------------------------------------------------------------
int DemSoLuongSoDuongTrenDuongCheoChinh(int **a, int n)
{
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i][i] > 0)
		{
			dem++;
		}
	}
	return dem;
}
//-------------------------------------------------------------------------------------------------------
int DemSoLuongSoAmTrenDuongCheoPhu(int **a, int n)
{
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i][n - 1 - i] < 0)
		{
			dem++;
		}
	}
	return dem;
}
//--------------------------------------------------------------------------------------------------------
int DemSoChanMaTranTamGiacTrenDuongCheoChinh(int **a, int n)
{
	int dem = 0;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i][j] % 2 == 0)
			{
				dem++;
			}
		}
	}
	return dem;
}
//--------------------------------------------------------------------------------------------------------
int DemSoChanMaTranTamGiacTrenDuongCheoPhu(int **a, int n)
{
	int dem = 0;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (a[i][j] % 2 == 0)
			{
				dem++;
			}
		}
	}
	return dem;
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
	//DemCapGiaTriDoiXungQuaDuongCheoChinh(a, n);
	//DemSoLuongDongGiam(a, n);
	//DemSoLuongSoDuongTrenDuongCheoChinh(a,n);
	//DemSoLuongSoAmTrenDuongCheoPhu(a,n);
	//DemSoChanMaTranTamGiacTrenDuongCheoChinh(a,n);
	//DemSoChanMaTranTamGiacTrenDuongCheoPhu(a,n);
	int dem = DemSoChanMaTranTamGiacTrenDuongCheoPhu(a, n);
	cout << dem;
	if (a != NULL)
	{
		ThuHoi(a, n);
	}
	return 0;
}
