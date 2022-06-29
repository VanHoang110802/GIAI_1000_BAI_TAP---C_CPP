/*
Tìm “giá trị âm lớn nhất” trong mảng các số thực. 
Nếu mảng không có giá trị âm thì trả về 0.

Tìm “số nguyên tố lớn nhất” trong mảng một chiều các số nguyên.
Nếu mảng không có số nguyên tố thì trả về 0.

Tìm “hoàn thiện nhỏ nhất” trong mảng một chiều các số nguyên.
Nếu mảng không có số hoàn thiện thì trả về 0.

Tìm “giá trị chẵn nhỏ nhất” trong mảng một chiều các số nguyên.
Nếu mảng không có giá trị chẵn thì trả về -1.

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
vanhoang TimAmMax(vanhoang* a, int n)
{
	int dem = 0, i = 0;
	vanhoang max;
	for (i; i < n; ++i)
	{
		if (a[i] < 0)
		{
			dem++;
			break;
		}
	}
	if (dem == 0)
	{
		return 0;
	}
	else
	{
		max = a[i];
		for (i = 0; i < n; ++i)
		{
			if (a[i] < 0 && a[i] > max)
			{
				max = a[i];
			}
		}
		return max;
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
vanhoang TimSoNTMax(vanhoang* a, int n)
{
	vanhoang max = 0;
	for (int i = 0; i < n; i++)
	{
		if (KiemTraSoNT(a[i]) && a[i] > max)
		{
			max = a[i];
		}
	}
	return max;
}
//------------------------------------------------------------------------
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
vanhoang TimSoSHTMin(vanhoang* a, int n)
{
	vanhoang dem = 0, Min;
	int i;
	for (i = 0; i < n; ++i)
	{
		if (KiemTraSHT(a[i]))
		{
			dem++;
			break;
		}
	}
	if (dem == 0)
	{
		return 0;
	}
	else
	{
		Min = a[i];
		for (i = 0; i < n; ++i)
		{
			if (KiemTraSHT(a[i]) && a[i] < Min)
			{
				Min = a[i];
			}
		}
		return Min;
	}
}
//------------------------------------------------------------------------
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
//------------------------------------------------------------------------
template <typename vanhoang>
vanhoang TimChanMin(vanhoang* a, int n)
{
	vanhoang dem = 0, Min;
	int i;
	for (i = 0; i < n; ++i)
	{
		if (a[i] % 2 == 0)
		{
			dem++;
			break;
		}
	}
	if (dem == 0)
	{
		return 0;
	}
	else
	{
		Min = a[i];
		for (i = 0; i < n; ++i)
		{
			if (a[i] % 2 == 0 && a[i] < Min)
			{
				Min = a[i];
			}
		}
		return Min;
	}
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
	int tim = TimChanMin(a, n);
	if (tim == 0)
	{
		cout << "\nNO!";
	}
	else cout << "\nYES: " << tim;

	delete[] a;
	return 0;
}
