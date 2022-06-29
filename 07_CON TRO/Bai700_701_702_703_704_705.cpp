/*
Hãy liệt kê các số âm trong mảng một chiều các số thực.

Hãy liệt kê các số giá trị trong mảng một chiều các sô thực thuộc đoạn [x,y] cho trước.

Hãy liệt kê các số có giá trị chẵn trong mảng một chiều các số nguyên thuộc đoạn [x,y] cho trước (x, y là các số nguyên).

Hãy liệt kê các giá trị trong mảng mà thỏa điều kiện lớn hơn trị tuyệt đối của giá trị đứng liền sau nó.

Hãy liệt kê các giá trị trong mảng mà thỏa điều kiện nhỏ hơn trị tuyệt đối của giá trị đứng liền sau nó và lớn hơn giá trị đứng liền trước nó.

Hãy viết hàm liệt kê các giá trị chẵn có ít nhất một lân cận cũng là giá trị chẵn.

Cho mảng một chiều các số thực. Hãy viết hàm liệt kê tất cả các giá trị trong mảng có ít nhất một lân cận trái dấu với nó.

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
void LKSoAm(vanhoang* a, int n)
{
	int dem = 0;
	for (int i = 0; i < n; ++i)
	{
		if (a[i] < 0)
		{
			dem++;
			break;
		}
	}
	if (dem == 0)
	{
		cout << "Khong co so am trong mang!";
	}
	else
	{
		for (int i = 0; i < n; ++i)
		{
			if (a[i] < 0)
			{
				cout << a[i] << " ";
			}
		}

	}
}
//------------------------------------------------------------------------
template <typename vanhoang>
void LietKeTrongDoanXY(vanhoang *a, int n, vanhoang x, vanhoang y)
{
	for (int i = 0; i < n; i++) 
	{
		if (x <= a[i] && a[i] <= y) 
		{
			cout << a[i] << " ";
		}
	}
}
//------------------------------------------------------------------------
template <typename vanhoang>
void LietKeChanTrongDoanXY(vanhoang*a, int n, int x, int y)
{
	for (int i = 0; i < n; i++) 
	{
		if (a[i] % 2 == 0 && x <= a[i] && a[i] <= y) 
		{
			cout << a[i] << " ";
		}
	}
}
//------------------------------------------------------------------------
template <typename vanhoang>
void LietKe002(vanhoang *a, int n)
{
	printf("\nCac gia tri thoa man: ");
	for (int i = 0; i < n - 1; i++) 
	{
		if (a[i] > fabs(a[i + 1])) 
		{
			cout << a[i] << " ";
		}
	}
}
//------------------------------------------------------------------------
template <typename vanhoang>
void LietKe003(vanhoang *a, int n)
{
	int check = 0;
	cout << "\nCac gia tri thoa man: ";
	for (int i = 0; i < n; i++) 
	{
		if (a[i] % 2 == 0 && (a[i - 1] % 2 == 0 || a[i + 1] % 2 == 0)) 
		{
			check = 1;
			cout << a[i] << " ";
		}
	}
	if (check == 0)
		cout << "0";
}
//------------------------------------------------------------------------
template <typename vanhoang>
void LietKe004(vanhoang *a, int n) 
{
	cout << "\nCac gia tri trong mang co it nhat 1 phan tu lan can trai dau voi no la: ";
	for (int i = 1; i < n - 1; i++) 
	{
		int b = a[i] * a[i - 1];
		int c = a[i] * a[i + 1];
		if (b < 0 || c < 0)
			cout << a[i] << "  ";
		else cout << "\n0"; break;
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
	//LKSoAm(a, n);
	//LietKeTrongDoanXY(a, n, 1, 5);
	//LietKeChanTrongDoanXY(a, n, 2, 8);
	//LietKe002(a, n);
	//LietKe003(a, n);
	LietKe004(a, n);
	delete[] a;
	return 0;
}
