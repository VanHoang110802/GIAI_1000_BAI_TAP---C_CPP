/*
(*) Cho mảng một chiều các số nguyên. Hãy viết hàm tìm chữ số xuất hiện ít nhất trong mảng.

(*) Cho mảng số thực có nhiều hơn hai giá trị và các giá trị trong mảng khác nhau từng đôi một. 
Hãy viết hàm liệt kê tất cả các cặp giá trị (a,b) trong mảng thỏa điều kiện a <= b.

(*) Cho mảng số thực có nhiều hơn hai giá trị và các giá trị trong mảng khác nhau từng đôi một. 
Hãy viết hàm tìm hai giá trị gần nhau nhất trong mảng. 
Lưu ý: Mảng có các giá trị khác nhau từng đôi một còn có tên là mảng phân biệt.

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
/*
 Xử lý đi tìm chữ số xuất hiện ít nhất:
 Tách các chữ số mảng a (mảng ban đầu vừa mới nhập vào). Lúc này các chữ số của các phần tử trong mảng a đã được đưa vào mảng b. Đi tìm ra các chữ số phân biệt trong mảng b .
 Bước 1: Sắp mảng b tăng dần.
 Bước 2: 
Liệt kê ra các chữ số phân biệt bằng cách đưa các chữ số có trong mảng b vào 1 mảng mới là mảng c và xử lý trên mảng c.
Gán phần tử đầu tiên của mảng c chính là phần tử đầu tiên của mảng b.
Bắt đầu duyệt từ phần tử thứ 2 của mảng b .
Từ lúc này mảng c đã chứa các chữ số phân biệt.
Mỗi lần bằng nhau thì tăng biến đếm lên. Lưu giá trị biến đếm vào mảng d.

 Khởi tạo min là giá trị đầu tiên của mảng d.
 Số lượng phần tử của mảng d chính là số lượng các phần tử phân biệt của mảng b hay nói cách khác bằng đúng số lượng phần tử của mảng c
 nên ta đặt điều kiện t < dem.

 Tìm ra tần suất xuất hiện ít nhất.
 Khởi tạo lại vòng lặp cho phần tử của mảng c so sánh lại với mảng b với tần suất xuất hiện ít nhất đã được tìm ra ở trên.
 Mỗi lần bằng nhau thì tăng biến đếm lên. Nếu biến đếm bằng đúng min (tần suất xuất hiện ít nhất mà ta đã tìm ra ở trên ) thì sẽ in ra tất cả các chữ số có tần suất xuất hiện đó

-> in ra các chữ số có số lần xuất hiện ít nhất trong mảng .
*/
template <typename vanhoang>
void HoanVi(vanhoang& x, vanhoang& y)
{
	vanhoang temp = x;
	x = y;
	y = temp;
}
template <typename vanhoang>
void TimChuSoXuatItNhat(vanhoang *a, vanhoang* b, vanhoang* c, vanhoang* d, int n)
{
	int j = 0, l, k;
	int t = 0;
	for (int i = 0; i < n; ++i)
	{
		// chuyen cac chu so cua cac phan tu o mang a sang cho mang b
		while (a[i]!= 0) 
		{
			b[j] = a[i] % 10;
			a[i] /= 10;
			j++;
		}
	}

	// sap xep mang b theo chieu tang dan
	for (l = 0; l < j; ++l)
	{
		for (k = l + 1; k < j; ++k)
		{
			if (b[l] > b[k])
			{
				HoanVi(b[l], b[k]);
			}
		}
	}

	int dem = 1, m = 1;
	// vi phan tu dau tien khong co phan tu nao dang truoc no ca, nen ta se gan cho phan tu dau mang c = phan tu dau mang b
	c[0] = b[0];
	// duyet tu phan tu thu 2 cua mang, neu phan tu truoc do khac voi phan tu sau thi -> chuyen phan tu tu mang b sang mang c
	for (l = 1; l < j; ++l)
	{
		if (b[l] != b[l - 1])
		{
			dem++;
			c[m++] = b[l];
		}
	}

	// luc nay mang c da chua cac so phan biet roi
	for (int z = 0; z < dem; ++z)
	{
		int dem1 = 0;
		for (int u = 0; u < j; ++u)
		{
			// neu ma gap cac phan tu bang nhau
			if (c[z] == b[u])
			{
				dem1++;
			}
		}
		d[t++] = dem1; // luu gia tri bien dem vao mang d
	}
	int MIN = d[0]; //khoi tao mac dinh min la gia tri dau tien cua mang d
	
	// so luong phan tu cua mang d chinh la so luong phan tu phan biet cua mang b
	for (int t = 0; t < dem; ++t)
	{
		if (d[t] < MIN)
		{
			MIN = d[t];
		}
	}

	// tim ra tan suat xuat hien it nhat
	for (int h = 0; h < dem; ++h)
	{
		int dem1 = 0;
		for (int e = 0; e < j; ++e)
		{
			if (c[h] == b[e])
			{
				dem1++;
			}
		}
		if (dem1 == MIN)
		{
			cout << c[h] << " ";
		}
	}
}

//------------------------------------------------------------------------
template <typename vanhoang>
void LietKe(vanhoang* a, int n)
{
	cout << "\nCac cap gia tri (a, b thoa man dieu kien tren):";
	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			if (a[i] < a[j] || a[i] == a[j])
			{
				cout << "\n(" << a[i] << ", " << a[j] << ")";
			}
		}
	}
}

//------------------------------------------------------------------------
template <typename vanhoang>
void LietKe001(vanhoang *a, int n)
{
	int KCNganNhat = (abs)(a[0] - a[1]);
	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n - 1; ++j)
		{
			if ((abs)(a[i] - a[j]) < KCNganNhat)
			{
				KCNganNhat = (abs)(a[i] - a[j]);
			}
		}
	}
	cout << "\nNhung cap co gia tri gan nhau nhat: ";
	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n - 1; ++j)
		{
			if ((abs)(a[i] - a[j]) == KCNganNhat)
			{
				cout << "(" << a[i] << ", " << a[j] << ")";
			}
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
	/*
	int* a = new int[n];
	int* b = new int[n];
	int* c = new int[n];
	int* d = new int[n];
	NhapMang(a, n);
	XuatMang(a, n);
	cout << "\n";
	TimChuSoXuatItNhat(a, b, c, d, n);
	delete[] a;
	delete[] b;
	delete[] c;
	delete[] d;
	*/
	LietKe(a, n);
	LietKe001(a, n);
	
	delete[] a;
	return 0;
}
