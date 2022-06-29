/*
Hãy tìm giá trị trong mảng các số thực “xa giá trị x nhất”.
Ví dụ:
24 45 23 13 43 -12
Giá trị x = 15
Khoảng cách từ x = 15 tới các phần tử khác trong mảng là:
9 30 8 2 28 27 -> lấy giá trị tuyệt đối không được âm.
Giá trị trong mảng xa giá trị x nhất: 45
 
Hãy tìm một vị trí trong mảng một chiều các số thực mà giá trị tại vị trí
đó là giá trị “gần giá trị x nhất”.
Ví dụ:
24 45 23 13 43 -12
Giá trị x = 15
Khoảng cách từ x = 15 tới các phần tử khác trong mảng là:
9 30 8 2 28 27 -> lấy giá trị tuyệt đối không được âm.
Giá trị trong mảng xa giá trị x nhất: 13

Cho mảng một chiều các số thực, hãy tìm đoạn [a,b] sao cho đoạn này chứa tất cả các giá trị trong mảng.

Cho mảng một chiều các số thực, hãy tìm giá trị x sao cho đoạn [-x,x] chứa tất cả các giá trị trong mảng.

*/
#include <iostream>
#include <cmath>
using namespace std;
template <typename vanhoang>
void NhapMang(vanhoang *a, int n)
{
	for (int i = 0; i < n;++i)
	{
		cout << "a[" << i << "]= ";
		cin >> a[i];
	}
}

template <typename vanhoang>
void XuatMang(vanhoang* a, int n)
{
	for (int i = 0; i < n;++i)
	{
		cout << a[i] << " ";
	}
}
//------------------------------------------------------------------------
template <typename vanhoang>
vanhoang TimSoXaGiaTriXNhat(vanhoang* a, int n, vanhoang x)
{
	vanhoang MAX = fabs(a[0] - x);
	int vitri = 0;
	cout << MAX << "  ";
	for (int i = 1; i < n; ++i)
	{
		cout << fabs(a[i] - x) << "  ";
		if (fabs(a[i] - x) > MAX)
		{
			MAX = fabs(a[i] - x);
			vitri = i;
		}
	}
	return a[vitri];
}
//------------------------------------------------------------------------
template <typename vanhoang>
vanhoang TimSoGanGiaTriXNhat(vanhoang* a, int n, vanhoang x)
{
	vanhoang MIN = fabs(a[0] - x);
	int vitri = 0;
	cout << MIN << "  ";
	for (int i = 1; i < n; ++i)
	{
		cout << fabs(a[i] - x) << "  ";
		if (fabs(a[i] - x) < MIN)
		{
			MIN = fabs(a[i] - x);
			vitri = i;
		}
	}
	return a[vitri];
}
//------------------------------------------------------------------------
// tim min max thôi, min = a, max = b
template <typename vanhoang>
void TimKhoangAB(vanhoang *a, int n) 
{
	vanhoang min = a[0], max = a[0];
	for (int i = 0; i < n; i++) 
	{
		if (a[i] < min) 
		{
			min = a[i];
		}
		if (a[i] > max) 
		{
			max = a[i];
		}
	}
	cout << "\n-> Cac phan tu co trong mang nam trong doan ["<< min <<", " << max << "].";
}
//------------------------------------------------------------------------
// tim min max thôi.
template <typename vanhoang>
void TimKhoangXX(vanhoang *a, int n) {
	vanhoang max = a[0];
	for (int i = 0; i < n; i++) 
	{
		if (fabs(a[i]) > max) 
		{
			max = fabs(a[i]);
		}
	}
	cout << "\n-> Cac phan tu co trong mang nam trong [-"<< max<< ", " << max <<"].";
}
int main()
{
	int n;
	do
	{
		cout << "\nNhap so luong phan tu: ";
		cin >> n;

		if (n < 1)
		{
			cout << "\nSo luong phan tu nhap khong hop le! Xin hay nhap lai!\n";
		}
	} while (n < 1);
	int* a = new int[n];
	NhapMang(a, n);
	XuatMang(a, n);
	cout << "\n";
	/*
	int tim = TimSoGanGiaTriXNhat(a, n, 15);
	if (tim == 0)
	{
		cout << "\nNO!";
	}
	else cout << "\nYES: " << tim;
	*/
	TimKhoangXX(a, n);
	delete[] a;
	return 0;
}
