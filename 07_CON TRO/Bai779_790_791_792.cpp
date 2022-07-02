/*
Xoay ma trận một góc 90 độ.

Xoay ma trận một góc 180 độ.

Xoay ma trận một góc 270 độ.

Chiếu gương ma trận theo trục dọc.

Chiếu gương ma trận theo trục ngang.
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
void ThuHoi(vanhoang**& a, int sodong)
{
	for (int i = 0; i < sodong; ++i)
	{
		delete a[i];
	}
	delete[]a;
}
//-------------------------------------------------------------------------------------------------------
/*
1 2 3        7 4 1
4 5 6   ->	 8 5 2
7 8 9		 9 6 3

Nhận thấy rằng hàng đã chuyển thành cột và ngược lại, ta nghĩ ngay đến công thức B[i][j] = A[j][i]
Nhưng đây là công thức quen thuộc của ma trận chuyển vị, kết quả khi chuyển vị như sau
1 4 7
2 5 8
3 6 9

So với kết quả đích, ta thấy C chỉ khác B ở thứ tự các cột, nghĩa là cột (j) của C là cột (n - 1 - j) của B
C[i][j] = B[i][n - 1 - j] = A[n - 1 - j][i]
*/
void XoayMaTran1Goc90DoTheoChieuKimDongHo(int **a, int dong, int cot)
{
	int **c;
	CapPhat(c, dong, cot);
	for (int i = 0; i < dong; i++)
	{
		for (int j = 0; j < cot; j++)
		{
			c[i][j] = a[cot - 1 - j][i];
			cout << c[i][j] <<"\t";
		}
		cout << "\n";
	}
	ThuHoi(c, dong);
}
//-------------------------------------------------------------------------------------------------------
// Xoay 180 độ thì quay 90 độ 2 lần.
void XoayMaTran1Goc180DoTheoChieuKimDongHo(int **a, int dong, int cot)
{
	int** c;
	CapPhat(c, dong, cot);
	for (int i = 0; i < dong; i++)
	{
		for (int j = 0; j < cot; j++)
		{
			c[i][j] = a[cot - 1 - j][i];
		}
	}

	int** d;
	CapPhat(d, dong, cot);
	for (int i = 0; i < dong; i++)
	{
		for (int j = 0; j < cot; j++)
		{
			d[i][j] = c[cot - 1 - j][i];
			cout << d[i][j] << "\t";
		}
		cout << "\n";
	}
	ThuHoi(c, dong);
	ThuHoi(d, dong);
}
//-------------------------------------------------------------------------------------------------------
// Xoay 180 độ thì quay 90 độ 3 lần.
void XoayMaTran1Goc270DoTheoChieuKimDongHo(int **a, int dong, int cot)
{
	int** c;
	CapPhat(c, dong, cot);
	for (int i = 0; i < dong; i++)
	{
		for (int j = 0; j < cot; j++)
		{
			c[i][j] = a[cot - 1 - j][i];
		}
	}
	int** d;
	CapPhat(d, dong, cot);
	for (int i = 0; i < dong; i++)
	{
		for (int j = 0; j < cot; j++)
		{
			d[i][j] = c[cot - 1 - j][i];
		}
	}
	int** e;
	CapPhat(e, dong, cot);
	for (int i = 0; i < dong; i++)
	{
		for (int j = 0; j < cot; j++)
		{
			e[i][j] = d[cot - 1 - j][i];
			cout << e[i][j] << "\t";
		}
		cout << "\n";
	}
	ThuHoi(c, dong);
	ThuHoi(d, dong);
	ThuHoi(e, dong);
}
//---------------------------------------------------------------------------------------
void ChieuGuongMaTranTheoTrucDoc(int **a, int dong, int cot)
{
	for (int i = 0; i < dong; i++)
	{
		for (int j = cot - 1; j >= 0; j--)
		{
			cout <<  a[i][j] << "  ";
		}
		cout << "\n";
	}
}
//-----------------------------------------------------------------------------------------
void ChieuGuongMaTranTheoTrucNgang(int **a, int dong, int cot)
{
	for (int i = dong - 1; i >= 0; i--)
	{
		for (int j = 0; j < cot; j++)
		{
			cout << a[i][j] << "  ";
		}
		cout << "\n";
	}
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

	//XoayMaTran1Goc90DoTheoChieuKimDongHo(a, sodong, socot);
	//XoayMaTran1Goc180DoTheoChieuKimDongHo(a, sodong, socot);
	//XoayMaTran1Goc270DoTheoChieuKimDongHo(a, sodong, socot);
	//ChieuGuongMaTranTheoTrucDoc(a, sodong, socot);
	ChieuGuongMaTranTheoTrucNgang(a, sodong, socot);
	if (a != NULL)
	{
		//ThuHoi(&a, sodong);
		ThuHoi(a, sodong);
	}
	return 0;
}
