/*
Viết hàm sắp xếp các phần tử trên một dòng tăng dần từ trái sang phải.

Viết hàm sắp xếp các phần tử trên một dòng giảm dần từ trái sang phải.

Viết hàm sắp xếp các phần tử trên một cột tăng dần từ trên xuống dưới.

Viết hàm sắp xếp các phần tử trên một cột giảm dần từ trên xuống dưới.

Viết hàm xuất các giá trị chẵn trong ma trận các so nguyên theo thứ tự giảm dần.

Viết hàm xuất các số nguyên tố trong ma trận các số nguyên ra màn hình theo thứ tự tăng dần.
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
void HoanVi(int& a, int& b)
{
	a = a + b;
	b = a - b;
	a = a - b;
}

//-------------------------------------------------------------------------------------------------------
void SapXepPhanTuTren1DongTangDanTuTraiSangPhai(int **a, int dong, int cot, int x)
{
	for (int i = 0; i < cot - 1; i++)
	{
		for (int j = i + 1; j < cot; j++)
		{
			if (a[x][i] > a[x][j])
			{
				HoanVi(a[x][i], a[x][j]);
			}
		}
	}
}
//-------------------------------------------------------------------------------------------------------
void SapXepPhanTuTren1DongGiamDanTuTraiSangPhai(int **a, int dong, int cot, int x)
{
	for (int i = 0; i < cot - 1; i++)
	{
		for (int j = i + 1; j < cot; j++)
		{
			if (a[x][i] < a[x][j])
			{
				HoanVi(a[x][i], a[x][j]);
			}
		}
	}
}
//-------------------------------------------------------------------------------------------------------
/*
Đặt a = 0101, b = 0011
a = a ^ b = 0110
Lúc này a = 0110, b = 0011
b = b ^ a = 0101 = a
Lúc này a = 0110, b = 0101
a = a ^ b = 0011 = b
*/
void HoanVi2(int& a, int& b)
{
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}

void SapXepPhanTuTren1CotTangDanTuTrenXuongDuoi(int** a, int dong, int cot, int y)
{
	for (int i = 0; i < dong - 1; i++)
	{
		for (int j = i + 1; j < dong; j++)
		{
			if (a[i][y] > a[j][y])
			{
				HoanVi2(a[i][y], a[j][y]);
			}
		}
	}
}
//-------------------------------------------------------------------------------------------------------
void SapXepPhanTuTren1CotGiamDanTuTrenXuongDuoi(int** a, int dong, int cot, int y)
{
	for (int i = 0; i < dong - 1; i++)
	{
		for (int j = i + 1; j < dong; j++)
		{
			if (a[i][y] < a[j][y])
			{
				HoanVi2(a[i][y], a[j][y]);
			}
		}
	}
}
//-------------------------------------------------------------------------------------------------------
void XuatCacGiaTriChanTheoThuTuGiamDan(int** a, int dong, int cot)
{
	int *temp = new int[dong + cot];
	int idx = 0;
	for (int i = 0; i < dong; i++)
	{
		for (int j = 0; j < cot; j++)
		{
			if (a[i][j] % 2 == 0)
			{
				temp[idx++] = a[i][j];
			}
		}
	}
	for (int i = 0; i < idx - 1; i++)
	{
		for (int j = i + 1; j < idx; j++)
		{
			if (temp[i] < temp[j])
			{
				HoanVi2(temp[i], temp[j]);
			}
		}
	}
	cout << "\nXuat cac gia tri chan theo thu tu giam dan: \n";
	for (int i = 0; i < idx; i++)
	{
		cout <<  temp[i] << "  ";
	}
	delete[] temp;
}
//-----------------------------------------------------------------------------------------
int KiemTraNguyenTo(int n)
{
	if (n < 2)
	{
		return 0;
	}
	else if (n > 2)
	{
		if (n % 2 == 0)
		{
			return 0;
		}
		for (int i = 3; i <= sqrt((float)n); i += 2)
		{
			if (n % i == 0)
			{
				return 0;
			}
		}
	}
	return 1;
}
void XuatCacSoNguyenToTheoThuTuTangDan(int** a, int dong, int cot)
{
	int *temp = new int[dong+cot];
	int idx = 0;
	for (int i = 0; i < dong; i++)
	{
		for (int j = 0; j < cot; j++)
		{
			if (KiemTraNguyenTo(a[i][j]) == 1)
			{
				temp[idx++] = a[i][j];
			}
		}
	}
	for (int i = 0; i < idx - 1; i++)
	{
		for (int j = i + 1; j < idx; j++)
		{
			if (temp[i] > temp[j])
			{
				HoanVi2(temp[i], temp[j]);
			}
		}
	}
	cout << "\nXuat cac so nguyen to theo thu tu tang dan: \n";
	for (int i = 0; i < idx; i++)
	{
		cout << temp[i] << "  ";
	}
	delete[] temp;
}
int main()
{
	int sodong, socot;
	cout << "Nhap so dong: ";
	NhapDuLieu(sodong);
	cout << "Nhap so cot: ";
	NhapDuLieu(socot);
	int** a, x = 1;
	CapPhat(a, sodong, socot);
	NhapMang(a, sodong, socot);
	XuatMang(a, sodong, socot);
	cout << "\n\n";
	//SapXepPhanTuTren1DongTangDanTuTraiSangPhai(a, sodong, socot, x);
	//SapXepPhanTuTren1DongGiamDanTuTraiSangPhai(a, sodong, socot, x);
	//SapXepPhanTuTren1CotTangDanTuTrenXuongDuoi(a, sodong, socot, x);
	//SapXepPhanTuTren1CotGiamDanTuTrenXuongDuoi(a, sodong, socot, x);
	//XuatMang(a, sodong,socot);
	//XuatCacGiaTriChanTheoThuTuGiamDan(a, sodong, socot);
	XuatCacSoNguyenToTheoThuTuTangDan(a, sodong, socot);
	if (a != NULL)
	{
		ThuHoi(a, sodong);
	}
	return 0;
}
