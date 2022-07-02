/*

Hãy xóa tất cả các phần tử có giá trị trùng với x.

Hãy xóa tất cả các phần tử trùng nhau trong mảng và chỉ giữ lại duy nhất một phần tử .

Hãy xóa tất cả các phần tử có tần suất xuất hiện trong mảng nhiều hơn một lần.

*/
#include <iostream>
using namespace std;
template <typename vanhoang>
void NhapDuLieu(vanhoang& n)
{
	do 
	{
		cout << "Nhap so luong phan tu: ";
		cin >> n;
		if (n<1) 
		{
			cout << "\nSo luong phan tu nhap khong hop le, xin hay kiem tra lai!\n";
		}
	} while (n<1);
}
template <typename vanhoang>
void NhapMang(vanhoang *a, int n)
{
	for (int i = 0; i < n; ++i) 
	{
		cout << "a[" << i<<"] = ";
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
//----------------------------------------------------------------------------------
void Xoa1PhanTu(int *a, int& n, int ViTriXoa) 
{
	for (int i = ViTriXoa; i < n; i++)
	{
		a[i] = a[i + 1];
	}
	n--;
}
void XoaCacPhanTuTrungVoiX(int *a, int& n, int x) 
{
	for (int i = 0; i < n; i++) 
	{
		if ((a[i]) == x) 
		{
			Xoa1PhanTu(a, n, i);
			i--;
		}
	}
}
//---------------------------------------------------------------------------------
void XoaCacPhanTuTrungNhau(int *a, int& n) 
{
	for (int i = 0; i < n; i++) 
	{
		for (int j = i + 1; j < n; j++) 
		{
			if (a[i] == a[j])
			{
				Xoa1PhanTu(a, n, j);
				j--;
			}
		}
	}
}
//--------------------------------------------------------------------------------
void XoaCacPhanTuXuatHienNhieuHon1Lan(int *a, int& n) 
{
	for (int i = 0; i < n - 1; i++) 
	{
		int check = 0;
		for (int j = i + 1; j < n; j++) 
		{
			if (a[i] == a[j])
			{
				Xoa1PhanTu(a, n, j);
				j--;
				check = 1;
			}
		}
		if (check == 1) 
		{
			Xoa1PhanTu(a, n, i); // Xóa luôn chính nó
			i--;
		}
	}
}
int main()
{
	int n;
	NhapDuLieu(n);
	int* a = new int[n];
	NhapMang(a, n);
	XuatMang(a, n);
	cout << "\n\n";
	//int x;
	//cout << "\nNhap x = ";
	//cin >> x;
	//XoaCacPhanTuTrungVoiX(a, n, x);
	//XoaCacPhanTuTrungNhau(a, n);
	XoaCacPhanTuXuatHienNhieuHon1Lan(a, n);
	XuatMang(a, n);
	delete[]a;
	return 0;
}
