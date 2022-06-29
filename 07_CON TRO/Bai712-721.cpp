/*

Tính tổng các giá trị dương trong mảng một chiều các số thực.

Tính tổng các giá trị có chữ số đầu tiên là chữ số lẻ trong mảng một chiều các số nguyên.

Tính tổng các giá trị có chữ số hàng chục là chữ số 5 có trong mảng một chiều các số nguyên.

Tính tổng các giá trị lớn hơn giá trị đứng liền trước nó trong mảng một chiều các số thực

Tính tổng các giá trị lớn hơn trị tuyệt đối của giá trị đứng liền sau nó trong mảng một chiều các số thực

Tính tổng các giá trị lớn hơn các giá trị xung quanh trong mảng một chiều các số thực.

Tính tổng các phần tử "cực trị" trong mảng.
Một phần tử được gọi là cực trị khi nó lớn hơn hoặc nhỏ hơn các phần tử xung quanh nó

Tính tổng các giá trị chính phương trong mảng một chiều các số nguyên.

Tính tổng các giá trị đối xứng trong mảng một chiều các số nguyên

Tính tổng các giá trị có chữ số đầu tiên là chữ số chẵn trong mảng các số nguyên.
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
//-------------------------------------------------------------------------
template <typename vanhoang>
vanhoang TinhTongCacSoDuong(vanhoang* a, int n)
{
	vanhoang s = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] > 0)
		{
			s += a[i];
		}
	}
	return s;
}
//-------------------------------------------------------------------------

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
vanhoang TinhTongCacChuSoDau(vanhoang *a, int n)
{
	vanhoang s = 0;
	for (int i = 0; i < n; i++)
	{
		if (TachSo(a[i]))
		{
			s += a[i];
		}
	}
	return s;
}
//-------------------------------------------------------------------------
template <typename vanhoang>
vanhoang TimSoHangChucLa5(vanhoang n) 
{
	n = abs(n);			// nếu n âm :vv
	n = n / 10;
	int hangchuc = n % 10;
	if (hangchuc == 5)
	{
		return 1;
	}
	return 0;
}
template <typename vanhoang>
vanhoang TinhTongSoHangChucLa5(vanhoang *a, int n)
{
	vanhoang Tong = 0;
	for (int i = 0; i < n; i++) 
	{
		if (TimSoHangChucLa5(a[i]) == 1) 
		{
			Tong += a[i];
		}
	}
	return Tong;
}
//-------------------------------------------------------------------------
template <typename vanhoang>
vanhoang TongCacPhanTuLonHonPhanTuDungLienTruocNo(vanhoang *a, int n) {
	vanhoang s = 0;
	for (int i = 0; i < n; i++) 
	{
		if (a[i] > a[i - 1]) 
		{
			s += a[i];
		}
	}
	return s;
}
//-------------------------------------------------------------------------
template <typename vanhoang>
vanhoang TongTTDcacphantulonhonphantudunglientruocno(vanhoang *a, int n) {
	vanhoang s = 0;
	for (int i = 0; i < n; i++) 
	{
		if (a[i] > fabs(a[i - 1])) 
		{
			s += a[i];
		}
	}
	return s;
}
//-------------------------------------------------------------------------
template <typename vanhoang>
vanhoang TinhTongCacPhanTuLonHonPhanTuXungQuanh(vanhoang *a, int n)
{
	vanhoang Tong = 0;
	for (int i = 0; i < n; i++) 
	{
		if (i == 0 && a[i] > a[i + 1]) 
		{  // phần tử đầu tiên
			Tong += a[i];
		}
		else if (i != 0 && a[i] > a[i + 1] && a[i] > a[i - 1]) 
		{    // các phần tử ở giữa
			Tong += a[i];
		}
		else if (i == n - 1 && a[i] > a[i - 1]) 
		{    // phần tử cuối cùng
			Tong += a[i];
		}
	}
	return Tong;
}
//-------------------------------------------------------------------------
template <typename vanhoang>
vanhoang TinhTongCacPhanTuCucTri(vanhoang *a, int n) 
{
	vanhoang Tong = 0;
	for (int i = 0; i < n; i++) 
	{
		if (i == 0 && a[i] != a[i + 1]) 
		{			// xét số ở đầu
			Tong += a[i];
		}
		else if (i == n - 1 && a[i] != a[i - 1]) 
		{		// xét số đuôi
			Tong += a[i];
		}
		else if ((a[i] < a[i + 1] && a[i] < a[i - 1]) || (a[i] > a[i + 1] && a[i] > a[i - 1])) 
		{
			Tong += a[i];
		}
	}
	return Tong;
}
//-------------------------------------------------------------------------
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
vanhoang TinhTongSoCP(vanhoang *a, int n) {
	vanhoang s = 0;
	for (int i = 0; i < n; i++) 
	{
		if (KiemTraSoCP(a[i])) s += a[i];
	}
	return s;
}
//-------------------------------------------------------------------------
int KiemTraSoDX(int n)
{
	int temp = n;
	int dem = log10((double)temp);
	int sodaonguoc = 0;
	while (temp != 0)
	{
		int chuso = temp % 10;
		temp /= 10;
		sodaonguoc += chuso * pow(10.0, dem--);
	}
	if (n == sodaonguoc) 
	{
		return 1;
	}
	else return 0;
}
template <typename vanhoang>
vanhoang TinhTongSoDX(vanhoang *a, int n) 
{
	vanhoang s = 0;
	for (int i = 0; i < n; i++)
	{
		if (KiemTraSoDX(a[i])) s += a[i];
	}
	return s;
}
//-------------------------------------------------------------------------
int KiemTraChuSoDauChan(int n) 
{
	while (n >= 10) 
	{
		n /= 10;
	}
	if (n % 2 == 0) 
	{
		return 1;
	}
	return 0;
}
template <typename vanhoang>
vanhoang TinhTongCacSoChuSoDauChan(vanhoang *a, int n) {
	vanhoang s = 0;
	for (int i = 0; i < n; i++) 
	{
		if (KiemTraChuSoDauChan(a[i])) 
		{
			s += a[i];
		}
	}
	return s;
}

int main() 
{
	int n;
	NhapDuLieu(n);
	int* a = new int[n];
	NhapMang(a, n);
	XuatMang(a, n);
	cout << "\n\n";

	//TinhTongCacSoDuong(a, n);
	//TinhTongCacChuSoDau(a, n);
	//TinhTongSoHangChucLa5(a, n);
	//TongCacPhanTuLonHonPhanTuDungLienTruocNo(a, n);
	//TongTTDcacphantulonhonphantudunglientruocno(a, n);
	//TinhTongCacPhanTuLonHonPhanTuXungQuanh(a, n);
	//TinhTongCacPhanTuCucTri(a, n);
	//TinhTongSoCP(a, n);
	//TinhTongSoDX(a, n);
	//TinhTongCacSoChuSoDauChan(a, n);
	
	int tinh = TinhTongCacSoChuSoDauChan(a, n);
	cout << tinh;
	delete[] a;
	return 0;
}
