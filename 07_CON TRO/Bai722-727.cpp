/*
Tính trung bình cộng các số nguyên tố trong mảng một chiều các số nguyên .

Tính trung bình cộng các số dương trong mảng một chiều các số thực .

Tính trung bình cộng các giá trị lớn hơn giá trị x trong mảng một chiều các số thực .

Tính trung bình nhân các số dương trong mảng một chiều các số thực . 

Tính khoảng cách trung bình giữa các giá trị trong mảng

Hãy kiểm tra mảng số nguyên có tồn tại giá trị 0 hay không ? Nếu không tồn tại giá trị 0 trả về giá trị 0,ngược lại trả về 1
*/
#include <iostream> 
using namespace std;

void NhapDuLieu(int& n) 
{
	do 
	{
		cout << "Nhap so luong phan tu: ";
		cin >> n;
		if (n<1 ) 
		{
			cout << "\nSo luong phan tu nhap khong hop le!\n";
		}
	} while (n<1);
}
template <typename vanhoang>
void NhapMang(vanhoang *a, int n)
{
	for (int i = 0; i < n; i++) 
	{
		cout << "a["<< i<<"] = ";
		cin >> a[i];
	}
}
template <typename vanhoang>
void XuatMang(vanhoang *a, int n) 
{
	for (int i = 0; i < n; i++) 
	{
		cout << a[i] << "  ";
	}
}
//--------------------------------------------------------------------------------
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
vanhoang TinhTBCSoNT(vanhoang *a, int n)
{
	int dem = 0;
	vanhoang s1 = 0, s2;
	for (int i = 0; i < n; i++)
	{
		if (KiemTraSoNT(a[i])) 
		{
			dem++;
			s1 += a[i];
		}
	}
	return s2 = s1 / dem;
}
//--------------------------------------------------------------------------------
template <typename vanhoang>
vanhoang TinhTBCSoDuong(vanhoang *a, int n) 
{
	int dem = 0;
	vanhoang s1 = 0, s2;
	for (int i = 0; i < n; i++) 
	{
		if (a[i] > 0) 
		{
			dem++;
			s1 += a[i];
		}
	}
	return s2 = s1 / dem;
}
//--------------------------------------------------------------------------------
template <typename vanhoang>
vanhoang TinhTBC(vanhoang *a, int n, vanhoang z) 
{
	vanhoang s = 0, s1;
	int dem = 1;
	for (int i = 0; i < n; i++) 
	{
		if (a[i] > z)
		{
			dem++;
			s += a[i];

		}
	}
	return s1 = s / dem;
}
//--------------------------------------------------------------------------------
template <typename vanhoang>
vanhoang TinhTBNCacSoDuong(vanhoang *a, int n)
{
	vanhoang tich = 1;
	float dem = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] > 0) 
		{
			tich *= a[i];
			dem++;
		}
	}
	if (dem == 0)
	{
		printf("\nMang khong co so thoa yeu cau");
		return 0;
	}
	return pow(tich, 1.0 / dem);
}
//--------------------------------------------------------------------------------
template <typename vanhoang>
vanhoang TinhKCTBGiuaCacGiaTriTrongMang(vanhoang *a, int n)
{
	vanhoang s = 0;
	int dem = 0;
	for (int i = 0; i < n; i++) 
	{
		for (int j = i + 1; j < n; j++)
		{
			s += fabs(a[i] - a[i + 1]);
			dem++;
		}
	}
	return pow(s, 1.0 / dem);
}
//--------------------------------------------------------------------------------
template <typename vanhoang>
vanhoang KiemTraMang(vanhoang *a, int n)
{
	for (int i = 0; i < n; i++) 
	{
		if (a[i] == 0)
		{
			return 1;
		}
	}
	return 0;
}

int main() 
{
	int n;
	NhapDuLieu(n);
	int* a = new int[n];
	NhapMang(a, n);
	XuatMang(a, n);
	cout << "\n\n";
	//TinhTBCSoNT(a, n);
	//TinhTBCSoDuong(a, n);
	//int x = 5;
	//TinhTBC(a, n, x);
	//TinhTBNCacSoDuong(a, n);
	//TinhKCTBGiuaCacGiaTriTrongMang(a, n);
	//KiemTraMang(a, n);
	//int tinh = KiemTraMang(a, n);
	//cout << "\n" << tinh;
	int kt = KiemTraMang(a, n);
	if (kt == 0)
	{
		cout << "\nMANG KHONG CO SO 0!";
	}
	else cout << "\nMANG CO TON TAI SO 0!";
	delete[] a;
	return 0;
}
