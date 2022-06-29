/*
(*)Viết chương trình nhập vào mảng số nguyên và số nguyên k(1 <= k <= số lượng các giá trị phân biệt trong mảng).
Tìm số hạng lớn thứ k của mảng .

Mảng: 1 2 5 2 3 10 4 2 2 5 10 4 3
-> Sau khi loại phần tử trùng: 1 2 5 3 10 4
-> có 6 phần tử phân biệt -> 1 <= k <= 6
- nếu nhập k = 1 -> phần tử lớn thứ nhất là 10
- nếu nhập k = 2 -> phần tử lớn thứ nhất là 5
- nếu nhập k = 3 -> phần tử lớn thứ nhất là 4
- nếu nhập k = 4 -> phần tử lớn thứ nhất là 3
- nếu nhập k = 5 -> phần tử lớn thứ nhất là 2
- nếu nhập k = 6 -> phần tử lớn thứ nhất là 1

Đầu tiên ta cần tách từ mảng a ban đầu ra những phần tử phân biệt có trong mảng và sắp xếp chúng tăng dần và lưu vào 1 mảng mới gọi là mảng b .
Để làm được điều đó đầu tiên ta sắp xếp mảng a tăng dần và lưu trước giá trị a[0] vào mảng b . (a[0]=b[0])
Khởi tạo biến đếm =1 (do đã lưu trước 1 phần tử vào mảng b).
Sau đó ta cho vòng lặp for i chạy từ 1 -> <n . Đặt trường hợp a[i]!=a[i-1] ,nếu thỏa thì biến đếm tăng lên và lưu giá trị thỏa vào mảng b .
Sau đó in ra mảng b chính là mảng chứa các giá trị phân biệt của mảng a .
Thì số hạng lớn thứ k chính là giá trị b[dem-k] . Lưu ý:1<=k<=dem .

B1: Tạo mảng mới chứa mảng phân biệt ban đầu
B2: Sắp xếp mảng chứa phần tử phân biệt tăng dần
B3: Nhập vào k(1<= k <=số lượng phần tử phân biệt của mảng mới) và phần tử lớn thứ k lúc này là a[k-1]

*/
#include<iostream>
using namespace std;

void NhapDuLieu(int& n) 
{
	do 
	{
		cout << "\nNhap so luong phan tu: ";
		cin >> n;
		if (n<1) 
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
		cout << "a[" << i << "]= ";
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
void HoanVi(int& a, int& b) 
{
	int temp = a;
	a = b;
	b = temp;
}
template <typename vanhoang>
void SapMangTangDan(vanhoang *a, int n, vanhoang k)
{
	for (int i = 0; i < n - 1; i++) 
	{
		for (int j = i + 1; j < n; j++) 
		{
			if (a[i] > a[j]) 
			{
				HoanVi(a[i], a[j]);
			}
		}
	}
}
template <typename vanhoang>
void TimSoHangLonThuK(vanhoang *a, vanhoang *b, int n, vanhoang k) 
{
	int dem = 1, j = 1;
	SapMangTangDan(a, n, k);		// sắp xếp lại mảng theo thứ tự tăng dần
	b[0] = a[0];				// Lưu giá trị đầu tiên của mảng a vào mảng b .
	for (int i = 1; i < n; i++) 
	{
		if (a[i] != a[i - 1]) 
		{
			dem++;			// Biến đếm tăng lên khi nhận được giá trị phân biệt .
			b[j++] = a[i];		// Lưu giá trị phân biệt vào mảng b .
		}
	}
	if (k <= dem) 
	{
		cout << "So hang lon thu "<< k <<" la: " << b[dem - k];
	}
	else if (k > dem) {
		cout << "Khong ton tai so hang lon thu " <<  k;
	}
}
int main() {
	int n,k;
	NhapDuLieu(n);
	int* a = new int[n];
	int* b = new int[n];
	NhapMang(a, n);
	XuatMang(a, n);
	cout << "\nNhap so hang thu k = ";
	cin >> k;
	TimSoHangLonThuK(a, b, n, k);
	delete[] a;
	delete[] b;
	return 0;
}
