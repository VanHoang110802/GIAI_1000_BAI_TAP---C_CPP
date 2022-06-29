/*
Hãy liệt kê các vị trí mà giá trị tại đó là giá trị lớn nhất trong mảng một chiều các số thực.

Hãy liệt kê các vị trí mà giá trị tại đó là số nguyên tố trong mảng một chiều các số nguyên.

Hãy liệt kê các vị trí mà giá trị tại vị trí đó là số chính phương trong mảng một chiều các số nguyên.

Hãy liệt kê các vị trí trong mảng một chiều các số thực mà giá trị tại vị trí đó bằng giá trị âm đầu tiên trong mảng.

Hãy liệt kê các giá trị trong mảng một chiều các số nguyên tố có chữ số đầu tiên là chữ số lẻ.

Hãy liệt kê các giá trị cực đại trong mảng một chiều các số thực. Một phần tử được gọi là cực đại khi lớn hơn các phần tử lân cận.
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
void LietKe001(vanhoang *a, int n) 
{
	cout << "\nCac vi tri la gia tri lon nhat: ";
	float max = a[0];
	for (int i = 0; i < n; i++) 
	{
		if (a[i] > max) 
		{
			max = a[i];
		}
	}
	for (int i = 0; i < n; i++) 
	{
		if (a[i] == max) 
		{
			cout <<  i << "  ";
		}
	}
}
//------------------------------------------------------------------------
int KiemTraSoNT(int n) 
{
	int temp = n;
	if (temp < 2) 
	{
		return 0;
	}
	else 
	{
		if (temp > 2 && temp % 2 == 0) 
		{
			return 0;
		}
		else 
		{
			for (int i = 2; i * i <= temp; i++) 
			{
				if (temp % i == 0) 
				{
					return 0;
				}
			}
		}
	}
	return 1;
}
template <typename vanhoang>
void LietKe002(vanhoang *a, int n) 
{
	cout << "\nCac vi tri ma tai do la so nguyen to: ";
	for (int i = 0; i < n; i++) 
	{
		if (KiemTraSoNT(a[i])) 
		{
			cout << i << "  ";
		}
	}
}
//------------------------------------------------------------------------
int KiemTraSoCP(int n) 
{
	int temp = n;
	double kq = sqrt((double)temp);
	if (kq == (int)kq) 
	{
		return 1;
	}
	else return 0;
}
template <typename vanhoang>
void LietKe003(vanhoang *a, int n)
{
	cout << "\nCac vi tri ma tai do la so chinh phuong: ";
	for (int i = 0; i < n; i++) 
	{
		if (KiemTraSoCP(a[i])) {
			cout << i << "  ";
		}
	}
}
//------------------------------------------------------------------------
template <typename vanhoang>
void LietKe004(vanhoang *a, int n) 
{
	int dem = 0, i;
	cout << "\nCac vi tri thoa man de bai: ";
	for (i = 0; i < n; i++) 
	{
		if (a[i] < 0) 
		{
			dem++;
			break;
		}
	}
	if (dem == 0) 
	{
		cout << "0";
	}
	else 
	{
		float temp = a[i];
		for (i = i + 1; i < n; i++) 
		{
			if (a[i] == temp) 
			{
				cout << i << "  ";
			}
		}
	}
}
//------------------------------------------------------------------------
int TachSo(int n) 
{
	int temp = n;
	int chuso1 = temp / 10;
	if (chuso1 % 2 == 0) 
	{
		return 0;
	}
	else return 1;
}
template <typename vanhoang>
void LietKe005(vanhoang *a, int n) 
{
	cout << "\nCac gia tri thoa man de bai: ";
	for (int i = 0; i < n; i++)
	{
		if (TachSo(a[i]))
		{
			cout << a[i] << "  ";
		}
	}
}
//------------------------------------------------------------------------
template <typename vanhoang>
void LietKeCacGiaTriCucDai(vanhoang *a, int n) 
{
	printf("\nCac gia tri thoa man de bai: ");
	for (int i = 0; i < n - 1; i++) 
	{
		if (a[i] > a[i + 1] && a[i - 1] < a[i])
		{
			cout <<  a[i] << "  ";
		}
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
	cout << "\n";
	//LietKe001(a, n);
	//LietKe002(a, n);
	//LietKe003(a, n);
	//LietKe004(a, n);
	//LietKe005(a, n);
	LietKeCacGiaTriCucDai(a, n);
	delete[] a;
	return 0;
}
