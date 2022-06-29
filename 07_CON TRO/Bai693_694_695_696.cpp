/*
Hãy tìm giá trị thỏa điều kiện toàn chữ số lẻ và là giá trị lớn nhất thỏa điều kiện ấy trong mảng một chiều các số nguyên 
(nếu mảng không có giá trị thỏa điều kiện trên thì hàm trả về giá trị 0).
1357 234 456 468 11		-> a[i] = 1357.


Cho mảng một chiều các số nguyên. Hãy viết hàm tìm giá trị lớn nhất trong mảng có dạng 5k . 
Nếu mảng không tồn tại giá trị dạng 5k thì hàm sẽ trả về giá trị 0.
179 1108 2002 125 75	-> a[i] = 125 (5^3).


Cho mảng một chiều các số nguyên. Hãy viết hàm tìm số chẵn lớn nhất nhỏ hơn mọi giá trị lẻ có trong mảng.


Cho mảng một chiều các số nguyên. Hãy viết hàm tìm số nguyên tố nhỏ nhất và lớn hơn mọi giá trị có trong mảng.
-> Đi kiểm tra xem 1 số trong mảng đó có là số nguyên tố hay không, rồi sau khi loại được các số không là nguyên tố, ta sẽ đi xét xem trong các số nt đó, số nào lớn nhất. 
Rồi ta có vòng lặp vô tận (chưa biết người dùng muốn nhập điểm dừng là bao nhiêu), so sánh các số tìm được với số nt lớn nhất đã tìm được ở trong mảng trên, xét các số tìm được 
-> nếu xét đó là số nguyên tố thì return luôn tránh chạy liên tục.


Cho mảng một chiều các số nguyên dương. Hãy viết hàm tìm ước chung lớn nhất của tất cả các phần tử trong mảng.


Cho mảng một chiều các số nguyên dương. Hãy viết hàm tìm bội chung nhỏ nhất của tất cả các phần tử trong mảng.
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
int TachSo(int n) 
{
	int temp = n;
	int dem = log10((double)temp);
	int sodao = 0;
	while (temp != 0) 
	{
		int chuso = temp % 10;
		temp /= 10;
		sodao += chuso * pow(10.0, dem--);
	}
	while (sodao != 0) 
	{
		int chuso = sodao % 10;
		sodao /= 10;
		if (chuso % 2 == 0) 
		{
			return 0;
		}
	}
	return 1;
}
template <typename vanhoang>
vanhoang GiaTriFullLeMax(vanhoang *a, int n) 
{
	int max;
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		if (TachSo(a[i]) == 1)
		{
			max = a[i];
			dem++;
			break;
		}
	}
	if (dem == 0)
	{
		return 0;
	}
	for (int i = 0; i < n; i++)
	{
		if (TachSo(a[i]) == 1)
		{
			if (a[i] > max) max = a[i];
		}
	}
	return max;
}

//------------------------------------------------------------------------
int KiemTraDang5K(int n) 
{
	if (n <= 1) return 1;
	while (n > 1) 
	{  // vòng lặp kết thúc khi n == 5
		if (n % 5 != 0)  return 0;// Có thể viết n % 5

		n /= 5;
	}
	return 1;
}
template <typename vanhoang>
vanhoang TimGiaTri5kLonNhat(vanhoang*a, int n)
{
	vanhoang max;
	int dem = 0;
	for (int i = 0; i < n; i++) 
	{
		if (KiemTraDang5K(a[i]) == 1) 
		{
			max = a[i];
			dem++;
			break;
		}
	}
	if (dem == 0) return 0;

	for (int i = 0; i < n; i++)
	{
		if (KiemTraDang5K(a[i]) == 1)
		{
			max = (max > a[i]) ? max : a[i];
		}
	}
	return max;
}

//------------------------------------------------------------------------
// trường hợp này thì ta sẽ đi xét ngược, xét số lẻ luôn trước rồi từ đó suy ra tìm chẵn.
template <typename vanhoang>
vanhoang TimViTriLeDauTien(vanhoang *a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		if (a[i] % 2 != 0)
		{
			return i;
		}
	}
	return -1;
}
template <typename vanhoang>
vanhoang TimChanMaxNhungNhoHonLe(vanhoang *a, int n)
{
	int ViTriDauTien = TimViTriLeDauTien(a, n);
	vanhoang MinLe = a[ViTriDauTien];

	for (int i = ViTriDauTien; i < n; i++) 
	{
		if (a[i] % 2 != 0 && a[i] < MinLe) 
		{
			MinLe = a[i];
		}
	}
	if (ViTriDauTien > -1)
	{
		return MinLe - 1;
	}
	else return 0;
}

//------------------------------------------------------------------------
int KiemTraSoNT(int n) 
{
	int temp = n, check = 1;
	if (temp < 2) 
	{
		check = 0;
	}
	else {
		if (temp > 2 && temp % 2 == 0) 
		{
			check = 0;
		}
		else 
		{
			for (int i = 2; i * i <= temp; i++) 
			{
				if (n % i == 0) 
				{
					check = 0;
					break;
				}
			}
		}
	}
	if (check == 1 && n >= 2) {
		return 1;
	}
	else return 0;
}
template <typename vanhoang>
vanhoang TimSoLonNhatTrongMang(vanhoang *a, int n)
{
	vanhoang max = a[0];
	for (int i = 1; i < n; i++)
	{
		if (a[i] > max) 
		{
			max = a[i];
		}
	}
	return max;
}
template <typename vanhoang>
vanhoang TimSoNTNhoNhatNhungLonHonCacGiaTriTrongMang(vanhoang *a, int n)
{
	vanhoang max = TimSoLonNhatTrongMang(a, n);
	for (int i = max + 1; ; i++) 
	{   // không cần điều kiện lặp vì chưa biết người dùng nhập số muốn tìm là bao nhiêu
		if (i > max) 
		{
			if (KiemTraSoNT(i)) 
			{
				return i;
			}
		}
	}
}

//------------------------------------------------------------------------
template <typename vanhoang>
vanhoang TimSoNhoNhat(vanhoang*a, int n)
{
	vanhoang min = a[0];
	for (int i = 1; i < n; i++)
	{
		if (a[i] < min)
		{
			min = a[i];       //min = (min < a[i])? min: a[i];
		}
	}
	return min;
}
template <typename vanhoang>
vanhoang KiemTraChiaHetChoUoc(vanhoang *a, int n, int UocSo)
{
	for (int i = 0; i < n; i++) 
	{
		if (a[i] % UocSo != 0) 
		{
			return 0;
		}
	}
	return 1;
}
template <typename vanhoang>
vanhoang TimUCLNCuaMang(vanhoang *a, int n)
{
	vanhoang min = TimSoNhoNhat(a, n);
	for (int i = min / 2; i > 0; i--) 
	{
		if (KiemTraChiaHetChoUoc(a, n, i))
		{
			return i;
		}
	}
	return min;
}
//------------------------------------------------------------------------

/*
BCNN(a, b) = a*b / UCLN(a,b)
hoặc dùng :__gcd trong thư viện #include <algorithm>
*/
int UCLN(int a, int b) 
{
	if (a == b) return a;
	if (a > b)
		UCLN(a - b, b);
	else
		UCLN(a, b - a);
}
int BCNN(int a, int b)
{
	return (a * b / UCLN(a, b));
}

template <typename vanhoang>
vanhoang TimBCNNCuaMang(vanhoang *a, int n)
{
	int temp = BCNN(a[0], a[1]);
	for (int i = 2; i < n; i++) 
	{
		temp = BCNN(temp, a[i]);
	}
	return temp;
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
	int tim = TimBCNNCuaMang(a, n);
	if (tim == 0)
	{
		cout << "\nNO!";
	}
	else cout << "\nYES: " << tim;
	
	delete[] a;
	return 0;
}
