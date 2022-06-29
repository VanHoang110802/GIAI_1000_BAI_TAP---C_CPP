Tìm “vị trí số hoàn thiện cuối cùng” trong mảng một chiều các số nguyên. Nếu mảng không có số hoàn thiện thì trả về - 1.

#include <iostream>
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
vanhoang TimViTriSHTCuoiCung(vanhoang* a, int n)
{
	for (int i = n - 1; i >= 0;--i)
	{
		if (KiemTraSHT(a[i]))
		{
			return i;
		}
	}
	return -1;
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
	int vt = TimViTriSHTCuoiCung(a, n);
	if (vt == -1)
	{
		cout << "\nKhong tim thay!";
	}
	else cout << "\nVi tri so hoan thien cuoi cung trong mang: " << vt;
	delete[] a;
	return 0;
}
