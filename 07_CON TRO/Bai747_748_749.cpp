/*

Hãy “dịch trái xoay vòng” các phần tử trong mảng.

Hãy “dịch phải xoay vòng” k lần các phần tử trong mảng.

Hãy biến đổi mảng bằng cách thay các giá trị lớn nhất bằng giá trị nhỏ nhất và ngược lại.

Hãy biến đổi mảng bằng cách thay tất cả các phần tử trong mảng bằng số nguyên gần nó nhất.

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
	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << "  ";
	}
}
//----------------------------------------------------------------------------------
/*
Ta sẽ giả sử: Mảng ban đầu là: 1 2 3 4 5 -> giờ dịch chuyển cách phần tử ra sao?
Dịch trái xoay vòng 1 lần -> 2 3 4 5 1 (1)
Dịch trái xoay vòng 2 lần -> 3 4 5 1 2
Dịch trái xoay vòng 3 lần -> 4 5 1 2 3
Dịch trái xoay vòng 4 lần -> 5 1 2 3 4
Dịch trái xoay vòng 5 lần -> 1 2 3 4 5
Dịch trái xoay vòng 6 lần -> quay trở về (1)
... cứ như thế xoay vòng theo số lần k đã nhập, và xoay phải như vậy.

Chẳng qua, đây chỉ là bài nâng cấp hơn của dạng hoán vị của 2 số, thay vì hoán vị 2 số thì ở đây ta sẽ hoán vị nhiều số trong 
mảng, ta dùng vòng lặp lồng vào trong hàm tìm hoán vị (hàm hoán vị thì quá đơn giản rồi, gán a qua biến phụ, rồi cho b = a, 
rồi gán b lại qua biến phụ là xong) của nhiều số, có 1 biến char, biến char này sẽ biểu thị cho việc nhấn 1 phím bát kì thì 
sẽ xoay trái hoặc xoay phải các phần tử trong mảng.
*/
void DichTrai(int *a, int n, int solandichtrai)
{
	/*
	temp = a;
	a = b;
	b = temp
	*/
	while (solandichtrai--)
	{
		int temp = a[0];
		for (int i = 0; i < n - 1; ++i)
		{
			a[i] = a[i + 1];
		}
		a[n - 1] = temp;
	}
}
//----------------------------------------------------------------------------------
void DichPhai(int* a, int n, int solandichphai)
{
	while (solandichphai--)
	{
		int temp = a[n - 1];
		for (int i = n - 1; i >= 0; --i)
		{
			a[i] = a[i - 1];
		}
		a[0] = temp;
	}
}
//----------------------------------------------------------------------------------
void TimMinMax(int *a, int n, int& max, int& min)
{
	max = a[0];
	min = a[0];
	for (int i = 1; i < n; i++) 
	{
		max = (a[i] > max) ? a[i] : max;
		min = (a[i] < min) ? a[i] : min;
	}
}

void DoiMaxBangMinVaNguocLai(int *a, int n, int max, int min) 
{
	for (int i = 0; i < n; i++) 
	{
		if (a[i] == max)
		{
			a[i] = min;
		}
		else if (a[i] == min)
		{
			a[i] = max;
		}
	}
}
//----------------------------------------------------------------------------------
/*
n = 6.9
phannguyen = (int)(6.9) = 6
phan le = 6.9 - 6 = 0.9
*/
template <typename vanhoang>
void ThaySoGanNhat(vanhoang& n)
{
	int phannguyen = (int)(n);
	float phanle = n - phannguyen;
	// làm tròn
	if (phanle <= 0.5)
	{
		n = (float)phannguyen;
	}
	else 
	{
		n = (float)phannguyen + 1;
	}
}
// Giống như làm tròn
template <typename vanhoang>
void ThayCacPhanTuTrongMangBangSoNguyenGanNoNhat(vanhoang*a, int n)
{
	for (int i = 0; i < n; i++) 
	{
		ThaySoGanNhat(a[i]);
	}
}
int main()
{
	int n;
	NhapDuLieu(n);
	float* a = new float[n];
	NhapMang(a, n);
	XuatMang(a, n);
	cout << "\n\n";
	//int k = 3;
	//DichTrai(a, n, k);
	//DichPhai(a, n, k);
	//DoiMaxBangMinVaNguocLai(a,n,k,1);
	ThayCacPhanTuTrongMangBangSoNguyenGanNoNhat(a, n);
	XuatMang(a, n);
	delete[]a;
	return 0;
}
