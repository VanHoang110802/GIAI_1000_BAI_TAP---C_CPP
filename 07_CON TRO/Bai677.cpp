Hãy tìm “vị trí giá trị dương nhỏ nhất” trong mảng một chiều các số thực. Nếu mảng không có giá trị dương thì trả về -1 nhằm mô tả không có vị trí nào thỏa điều kiện.

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
vanhoang TimViTriDuongMin(vanhoang* a, int n)
{
	vanhoang min;
	int vitri = -1, dem = 0, i = 0;
	for (i; i < n;++i)
	{
		if (a[i] > 0)
		{
			vitri = i;
			dem++;
			break;
		}
	}
	if (dem == 0)
	{
		return vitri;
	}
	else
	{
		min = a[i];		// gán số âm vừa tìm được vị trí ở bên trên vào cho max 
		for (i = 0; i < n; i++)
		{
			if ((a[i] > 0) && (a[i] < min))
			{
				vitri = i;
			}
		}
	}
	return vitri;
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
	int vt = TimViTriDuongMin(a, n);
	if (vt == -1)
	{
		cout << "\nKhong tim thay!";
	}
	else cout << "\nVi tri so duong nho nhat: " << vt;
	delete[] a;
	return 0;
}
