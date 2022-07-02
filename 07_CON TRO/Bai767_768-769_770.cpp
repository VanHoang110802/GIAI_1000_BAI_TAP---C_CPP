/*
Kiểm tra ma trận có tồn tại số dương hay không.

Kiểm tra ma trận có tồn tại số hoàn thiện hay không.

Kiểm tra một hàng ma trận có tăng dần hay không.

Kiểm tra một cột trong ma trận có giảm dần hay không.

Kiểm tra các giá trị trong ma trận có giảm dần theo dòng và cột hay không.
Ví dụ: Ma trận sau đây giảm dần theo hàng và cột.
87 75 62 54
46 40 33 28
20 18 15 10

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
int KiemTraMaTranCoTonTaiSoDuong(int **a, int dong, int cot)
{
	int check = 0;
	for (int i = 0; i < dong; ++i)
	{
		for (int j = 0; j < cot; ++j)
		{
			if (a[i][j] > 0)
			{
				check = 1;
			}
		}
	}
	return check;
}
//--------------------------------------------------------------------------------------------------------
int KiemTraHoanThien(int n)
{
	int tong = 0;
	for (int i = 1; i < n; ++i)
	{
		if (n % i == 0)
		{
			tong += i;
		}
	}
	if (tong == n)
	{
		return 1;
	}
	return 0;
}

int KiemTraMaTranCoTonTaiSoHoanThien(int **a, int dong, int cot)
{
	int check = 0;
	for (int i = 0; i < dong; ++i)
	{
		for (int j = 0; j < cot; ++j)
		{
			if (KiemTraHoanThien(a[i][j]) == 1)
			{
				check = 1;
			}
		}
	}
	return check;
}
//-----------------------------------------------------------------------------------------------
int KiemTra1HangMaTranCoTangDan(int **a, int x, int cot)
{
	int check = 1;
	for (int j = 0; j < cot; ++j)
	{
		for (int k = 1; k < cot; ++k)
		{
			if (a[x][j] > a[x][k])
			{
				check = 0;
				break;
			}
		}
	}
	return check;
}
//--------------------------------------------------------------------------------------------
int KiemTra1CotMaTranCoGiamDan(int **a, int dong, int y)
{
	int check = 1;
	for (int i = 0; i < dong - 1; ++i)
	{
		for (int j = i + 1; j < dong; ++j)
		{
			if (a[i][y] < a[j][y])
			{
				check = 0;
				break;
			}
		}
	}
	return check;
}
//-----------------------------------------------------------------------------------------
int Check1DongMaTranCoGiamDan(int **a, int x, int cot)
{
	int check = 1;
	for (int j = 0; j < cot - 1; ++j)
	{
		for (int i = j + 1; i < cot; ++i)
		{
			if (a[x][j] < a[x][i])
			{
				check = 0;
				break;
			}
		}
	}
	return check;
}
int Check1CotMaTranCoGiamDan(int **a, int dong, int y)
{
	int check = 1;
	for (int i = 0; i < dong - 1; ++i)
	{
		for (int j = i + 1; j < dong; ++j)
		{
			if (a[i][y] < a[j][y])
			{
				check = 0;
				break;
			}
		}
	}
	return check;
}
int KiemTraMaTranCoGiamDanTheoDongVaCot(int **a, int dong, int cot)
{
	int check = 1;
	for (int i = 0; i < dong; ++i)
	{
		for (int j = 0; j < cot; ++j)
		{
			if (Check1DongMaTranCoGiamDan(a, i, cot) == 0 || Check1CotMaTranCoGiamDan(a, j, dong) == 0)
			{
				check = 0;
				break;
			}
		}
	}
	return check;
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
	//KiemTraMaTranCoTonTaiSoDuong(a, sodong, socot);
	//KiemTraMaTranCoTonTaiSoHoanThien(a, sodong, socot);
	//KiemTra1HangMaTranCoTangDan(a, x, socot);
	//KiemTra1CotMaTranCoGiamDan(a, sodong, x);
	//KiemTraMaTranCoGiamDanTheoDongVaCot(a, sodong, socot);
	int kt = KiemTraMaTranCoGiamDanTheoDongVaCot(a, sodong, socot);
	cout << "\n\n" << kt;
	if (a != NULL)
	{
		//ThuHoi(&a, sodong);
		ThuHoi(a, sodong);
	}
	return 0;
}
