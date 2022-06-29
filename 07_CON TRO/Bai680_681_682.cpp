/*
Tìm “số nguyên tố đầu tiên” trong mảng một chiều các số nguyên. 
Nếu mảng không có số nguyên tố thì trả về -1.

Tìm “số hoàn thiện đầu tiên” trong mảng một chiều các số nguyên. 
Nếu mảng không có số hoàn thiện thì trả về -1.

Tìm giá trị âm đầu tiên trong mảng một chiều các sô thực. 
Nếu mảng không có giá trị âm thì trả về giá trị không âm là 1.
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
template <typename vanhoang>
vanhoang KiemTraSoNT(vanhoang n) 
{
	if (n < 2)
	{
		return 0;
	}
	else 
	{
		if (n != 2 && n % 2 == 0) 
		{
			return 0;
		}
		for (int i = 3; i <= (int)sqrt((double)n); i += 2)
		{
			if (n % i == 0) 
			{
				return 0;
			}
		}
	}
	return 1;
}
template <typename vanhoang>
vanhoang TimNTDauTien(vanhoang *a, int n) 
{
	for (int i = 0; i < n; i++)
	{
		if (KiemTraSoNT(a[i]))
		{
			return a[i];
		}
	}
	return -1;
}
template <typename vanhoang>
vanhoang KiemTraSHT(vanhoang n)
{
	int temp = 0;
	for (vanhoang i = 1; i <= n / 2; ++i)
	{
		if (n % i == 0)
		{
			temp += i;
		}
	}
	if (temp == n && temp != 0)
	{
		return 1;
	}
	else return 0;
}
template <typename vanhoang>
vanhoang TimSHTDauTien(vanhoang* a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		if (KiemTraSHT(a[i]))
		{
			return a[i];
		}
	}
	return -1;
}
template <typename vanhoang>
vanhoang TimAmDauTien(vanhoang* a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		if (a[i] < 0)
		{
			return a[i];
		}
	}
	return 1;
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
	int tim1 = TimSHTDauTien(a, n);
	if (tim1 == -1)
	{
		cout << "\nNO!";
	}
	else cout << "\nYES: " << tim1;

	int tim = TimNTDauTien(a, n);
	if (tim == -1)
	{
		cout << "\nNO!";
	}
	else cout << "\nYES: " << tim;

	int tim2 = TimAmDauTien(a, n);
	if (tim2 == 1)
	{
		cout << "\nNO!";
	}
	else cout << "\nYES: " << tim2;

	delete[] a;
	return 0;
}
