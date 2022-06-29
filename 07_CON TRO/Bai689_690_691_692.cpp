/*
Cho mảng một chiều các số nguyên, hãy tìm giá trị đầu tiên trong mảng nằm trong khoảng (x,y) cho trước. Nếu mảng không có giá trị thỏa điều kiện trên thì hàm trả về giá trị là x.
-> Ý là ta sẽ có mảng : 3 -10 5 7 12, x= 4, y = 10 -> cần tìm là 5,7. 
Vì mảng ta nhập từ bàn phím, nên là, xét nếu phần tử trong mảng mà > x và < y -> in ra phần tử đầu nằm trong đó. 

Cho mảng một chiều các số thực. Hãy viết hàm tìm một vị trí trong mảng thỏa hai điền kiện:có hai giá trị lân cận  và giá trị tại vị trí đó bằng tích hai giá trị lân cận.  Nếu mảng không tồn tại giá trị như vậy thì hàm trả về giá trị - 1.
-> Đầu cuối ta không xét (a[i] hện tại = a[i] trước đó * a[i] sau đó). 

Tìm số chính phương đầu tiên trong mảng một chiều các số nguyên.

Cho mảng một chiều các số nguyên, hãy viết hàm tìm giá trị đầu tiên trong mảng thỏa tính chất số gánh.(ví dụ: 12321).

Hãy tìm giá trị đầu tiên trong mảng một chiều các số nguyên có chữ số đầu tiên là chữ số lẻ.  Nếu trong mảng không tồn tại giá trị như vậy thì hàm sẽ trả về giá trị 0.

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
vanhoang TimDoanXY(vanhoang *a, int n, vanhoang x, vanhoang y)
{
	for (int i = 0; i < n; ++i)
	{
		if (a[i] > x && a[i] < y)
		{
			return a[i];
		}
	}
	return x;
}
//------------------------------------------------------------------------
template <typename vanhoang>
vanhoang TimGiaTriSoLanCan(vanhoang *a, int n)
{
	for (int i = 1; i < n - 1; i++) 
	{
		vanhoang tich = a[i - 1] * a[i + 1];
		if (tich == a[i]) 
		{
			return i;
		}
	}
	return -1;
}
//------------------------------------------------------------------------
template <typename vanhoang>
int KiemTraSoCP(vanhoang n)
{
	double kq = sqrt((double)n);
	if (kq == (int)kq) 
	{
		return 1;
	}
	else return 0;
}
template <typename vanhoang>
int TimSoCPDau(vanhoang *a, int n)
{
	int dem = 0, i;
	for (i = 0; i < n; ++i) 
	{
		if (KiemTraSoCP(a[i])) 
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
		for (i = 1; i < n; i++)
		{
			if (KiemTraSoCP(a[i]))
			{
				return a[i];
			}
		}
	}
}
//------------------------------------------------------------------------
template <typename vanhoang>
int KiemTraSoDoiXung(vanhoang n) {
	int temp = n;
	int dem = log10((double)temp);
	int sodaonguoc = 0;
	while (temp != 0)
	{
		int chuso = temp % 10;
		temp /= 10;
		sodaonguoc += chuso * pow(10.0, dem--);
	}
	if (n == sodaonguoc) {
		return 1;
	}
	else return 0;

}
template <typename vanhoang>
vanhoang TimSoDXDau(vanhoang*a, int n) {
	int dem = 0, i;
	for (i = 0; i < n; i++) {
		if (KiemTraSoDoiXung(a[i])) {
			dem++;
			break;
		}
	}
	if (dem == 0) {
		return 0;
	}
	else
	{
		for (i = 0; i < n; i++)
		{
			if (KiemTraSoDoiXung(a[i]))
			{
				return a[i];
			}
		}
	}
}
//------------------------------------------------------------------------
template <typename vanhoang>
int TachSo(vanhoang n) 
{
	int check = 0, temp = n;
	int dem = log10((double)temp);
	int sodao = 0;
	while (temp != 0) 
	{
		int chuso = temp % 10;
		temp /= 10;
		sodao += chuso * pow(10.0, dem--);
	}
	int chuso = sodao % 10;
	if (chuso % 2 == 0) 
	{
		return 0;
	}
	else return 1;
}
template <typename vanhoang>
vanhoang TimChuSoLeDauTien(vanhoang *a, int n) 
{
	for (int i = 0; i < n; i++) 
	{
		if (TachSo(a[i])) 
		{
			return a[i];
		}
	}
	return 0;
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
	//int x, y;
	//cout << "Nhap x = "; cin >> x;
	//cout << "Nhap y = "; cin >> y;
	int tim = TimChuSoLeDauTien(a, n);
	if (tim == 0)
	{
		cout << "\nNO!";
	}
	else cout << "\nYES: " << tim;
	
	delete[] a;
	return 0;
}
