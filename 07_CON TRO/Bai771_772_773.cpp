/*
Liệt kê chỉ số các dòng chứa toàn giá trị chẵn trong ma trận các số nguyên.

Liệt kê các dòng có chứa số nguyên tố trong ma trận các số nguyên.

Liệt kê các cột trong ma trận các số nguyên có chứa số chính phương.

Liệt kê các dòng trong ma trận các số thực thỏa mãn đồng thời các điều kiện sau: dòng có chứa giá trị âm, giá trị dương và giá trị 0 (phần tử trung hòa).

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
void LietKeChiSoCacDongChuaToanGiaTriChan(int **a, int dong, int cot)
{
	int check;
	for (int i = 0; i < dong; i++)
	{
		check = 1;
		for (int j = 0; j < cot; j++)
		{
			if (a[i][j] % 2 != 0)
			{
				check = 0;
				break;
			}
		}
		if (check == 1)
		{
			cout << "\nDong a["<<i<<"] toan chan.";
		}
	}
}
//-------------------------------------------------------------------------------------------------------
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
void LietKeDongChuaSoNguyenTo(int **a, int dong, int cot)
{
	int check;
	for (int i = 0; i < dong; i++)
	{
		check = 0;
		for (int j = 0; j < cot; j++)
		{
			if (KiemTraNguyenTo(a[i][j]) == 1)
			{
				check = 1;
				break;
			}
		}
		if (check == 1)
		{
			cout << "\nDong a["<<i<<"] co chua so nguyen to.";
		}
	}
}
//-------------------------------------------------------------------------------------------------------
int KiemTraChinhPhuong(int n)
{
	return sqrt((float)n) == (int)sqrt((float)n);
}
void LietKeCotChuaSoChinhPhuong(int **a, int dong, int cot)
{
	int check, i, j;
	for (i = 0; i < dong; i++)
	{
		check = 0;
		for (j = 0; j < cot; j++)
		{
			if (KiemTraChinhPhuong(a[i][j]) == 1)
			{
				check = 1;
				break;
			}
		}
		if (check == 1)
		{
			cout << "\nCot a["<<j<<"] co chua so chinh phuong.";
		}
	}
}
//------------------------------------------------------------------------------------------
void LietKeCacDongCoGiaTriAmVaDuongVa0(int **a, int dong, int cot)
{
	int n = dong * cot;
	int i, j;
	for (i = 0; i < dong; i++)
	{
		if (n > 2)
		{
			int check[3] = { 0 };  // Tạo ra 1 mảng 3 giá trị đều là 0
			for (j = 0; j < cot; j++)
			{
				if (a[i][j] < 0)
				{
					check[0] = 1;
				}
				else if (a[i][j] == 0)
				{
					check[1] = 1;
				}
				else if (a[i][j] > 0)
				{
					check[2] = 1;
				}
				if (check[0] + check[1] + check[2] == 3)
				{
					cout << "\nDong a["<<i<<"] co ptu am, duong, 0";
					break;
				}
			}
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
	//LietKeDongChuaSoNguyenTo(a, sodong, socot);
	//LietKeCotChuaSoChinhPhuong(a, sodong, socot);
	//LietKeChiSoCacDongChuaToanGiaTriChan(a, sodong, socot);
	LietKeCacDongCoGiaTriAmVaDuongVa0(a, sodong, socot);

	if (a != NULL)
	{
		//ThuHoi(&a, sodong);
		ThuHoi(a, sodong);
	}
	return 0;
}
