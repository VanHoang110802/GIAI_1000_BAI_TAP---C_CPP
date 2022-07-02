/*
Viết hàm đếm số lượng số dương trong ma trận các số thực.

Đếm tần suất xuất hiện của một giá trị x trong ma trận các số thực.

Đếm số chữ số trong ma trận các số nguyên dương.

Đếm số lượng số dương trên một hàng trong ma trận các số thực.

Đếm số lượng số âm trên một cột trong ma trận các số thực.

Đếm số lượng số dương trên biên ma trận trong ma trận các số thực.
Ví dụ: cho ma trận
-34 45 -23 -24 52
12 -11 21 -56 -75
78 47 45 31 -34
-94 -34 22 76 74
*/
#include <iostream>
#include <cstdlib>
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
	for (int i = 0; i < sodong; i++)
	{
		a[i] = new vanhoang[socot];
	}
}
template <typename vanhoang>
void NhapMang(vanhoang** a, int sodong, int socot)
{
	for (int i = 0; i < sodong; i++)
	{
		for (int j = 0; j < socot; j++)
		{
			cout << "a[" << i << "][" << j << "]= ";
			cin >> a[i][j];
		}
	}
}
template <typename vanhoang>
void XuatMang(vanhoang** a, int sodong, int socot)
{
	for (int i = 0; i < sodong; i++)
	{
		for (int j = 0; j < socot; j++)
		{
			cout << a[i][j] << "\t";
		}
		cout << endl;
	}
}
//-------------------------------------------------------------------------------------------------------
template <typename vanhoang>
int DemSoLuongCacSoDuong(vanhoang **a, int dong, int cot)
{
	int dem = 0;
	for (int i = 0; i < dong; ++i)
	{
		for (int j = 0; j < cot; ++j)
		{
			if (a[i][j] > 0)
			{
				dem++;
			}
		}
	}
	return dem;
}
//-------------------------------------------------------------------------------------------------------
template <typename vanhoang>
int DemTanXuatX(vanhoang** a, int dong, int cot, int x)
{
	int dem = 0;
	for (int i = 0; i < dong; ++i)
	{
		for (int j = 0; j < cot; ++j)
		{
			if (a[i][j] == x)
			{
				dem++;
			}
		}
	}
	return dem;
}
//------------------------------------------------------------------------------------------
int DemSoLuongChuSo(int n)
{
	int sochuso = n == 0 ? 1 : (int)log10((float)n) + 1;
	return sochuso;
}

int DemSoLuongChuSoTrongMaTran(int **a, int dong, int cot)
{
	int dem = 0;
	for (int i = 0; i < dong; i++)
	{
		for (int j = 0; j < cot; j++)
		{
			int sochuso = DemSoLuongChuSo(a[i][j]);
			dem += sochuso;
		}
	}
	return dem;
}
//------------------------------------------------------------------------------------------
int DemSoLuongSoDuongTren1Dong(float **a, int x, int cot)
{
	int dem = 0;
	for (int j = 0; j < cot; j++)
	{
		if (a[x][j] > 0)
		{
			dem++;
		}
	}
	return dem;
}
//------------------------------------------------------------------------------------------
int DemSoLuongSoAmTren1Cot(float **a, int dong, int y)
{
	int dem = 0;
	for (int i = 0; i < dong; i++)
	{
		if (a[i][y] < 0)
		{
			dem++;
		}
	}
	return dem;
}
//-----------------------------------------------------------------------------------------
int DemSoLuongSoDuongTrenBien(float **a, int dong, int cot)
{
	int dem = 0;
	// đếm các giá trị dương trên biên dòng
	for (int j = 0; j < cot; j++)
	{
		if (a[0][j] > 0)
		{
			dem++;
		}
		if (a[cot - 1][j] > 0)
		{
			dem++;
		}
	}
	// đếm các giá trị dương trên biên cột
	for (int i = 1; i < dong - 1; i++)
	{
		if (a[i][0] > 0)
		{
			dem++;
		}
		if (a[i][dong - 1] > 0)
		{
			dem++;
		}
	}
	return dem;
}

/*
void ThuHoi(int*** a, int sodong)
{
	for (int i = 0; i < sodong; i++)
	{
		delete (*a)[i];
	}
	delete[](*a);
}
*/
template <typename vanhoang>
void ThuHoi(vanhoang**& a, int sodong)
{
	for (int i = 0; i < sodong; i++)
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
	int** a;
	CapPhat(a, sodong, socot);
	NhapMang(a, sodong, socot);
	XuatMang(a, sodong, socot);
	//DemSoLuongCacSoDuong(a, sodong, socot);
	int x = 1;
	//DemTanXuatX(a, sodong, socot,x);
	//DemSoLuongSoDuongTren1Dong(a, x, socot);
	//DemSoLuongSoAmTren1Cot(a, sodong, x);
	//DemSoLuongSoDuongTrenBien(a, sodong, socot);
	//DemSoLuongChuSoTrongMaTran(a, sodong, socot);
	int dem = DemSoLuongChuSoTrongMaTran(a, sodong, socot);
	cout << "\n\n" << dem;
	if (a != NULL)
	{
		//ThuHoi(&a, sodong);
		ThuHoi(a, sodong);
	}
	return 0;
}
