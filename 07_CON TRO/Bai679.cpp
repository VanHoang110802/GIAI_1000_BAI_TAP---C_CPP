Tìm “số chẵn đầu tiên” trong mảng các số nguyên. Nếu mảng không có giá trị chẵn thì sẽ trả về - 1.

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
vanhoang TimChanDau(vanhoang* a, int n)
{
	int i = 0;
	for (i; i < n;++i)
	{
		if (a[i] % 2 == 0)
		{
			return a[i];
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
	int tim = TimChanDau(a, n);
	if (tim == -1)
	{
		cout << "\nMang khong co chan dau tien!";
	}
	else cout << "\nSo chan dau tien: " << tim;
	delete[] a;
	return 0;
}
