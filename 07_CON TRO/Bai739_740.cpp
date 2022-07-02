/*
Hãy trộn hai mảng tăng dần lại thành 1 mảng được sắp thứ tự tăng dần.

Cho hai mảng tăng dần. Hãy trộn hai mảng lại thành một mảng được sắp thứ tự giảm dần.
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
void HoanVi(int& a, int& b) 
{
	int temp = a;
	a = b;
	b = temp;
}
void SapXep(int *a, int n) 
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

void Tron2MangThanh1Mang(int *a, int *b, int *c, int na, int nb, int& nc)
{
	nc = na + nb;         // Số phần tử mảng cần gộp
	SapXep(a, na);       // Sắp xếp mảng a
	SapXep(b, nb);       // Sắp xếp mảng b
	int vitriA = 0, vitriB = 0;
	for (int i = 0; i < nc; i++) 
	{      // Duyệt mảng cần gộp
		if (vitriA < na && vitriB < nb) 
		{   // Kiểm tra từng vị trí trong mảng A và mảng B xem có lớn hơn số phần tử của từng mảng        
			if (a[vitriA] < b[vitriB]) 
			{     // So sánh xem phần tử của mảng nào nhỏ hơn (ở đầy là mảng a)
				c[i] = a[vitriA++];          // Đổ mảng a vào mảng cần gộp
			}
			else 
			{
				c[i] = b[vitriB++];             // Ngược lại thì đổ mảng b vào mảng cần gộp
			}
		}
		// Xét thêm
		else if (vitriB == nb) 
		{        // Nếu mà vị trí b tăng bằng số phần tử mảng b
			c[i] = a[vitriA++];            // Chỉ còn mảng a để đổ vào mảng cần gộp
		}
		else 
		{
			c[i] = b[vitriB++];
		}
	}
}
//--------------------------------------------------------------------------------
void SapXep1(int *a, int n) 
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

void Tron2MangTangThanh1MangGiam(int *a, int *b, int *c, int na, int nb, int& nc) 
{
	nc = na + nb;         // Số phần tử mảng cần gộp
	SapXep1(a, na);       // Sắp xếp mảng a tăng
	SapXep1(b, nb);       // Sắp xếp mảng b tăng
	int vitriA = na - 1, vitriB = nb - 1;   // Chỉ số bắt đầu từ cuối mảng
	for (int i = 0; i < nc; i++)
	{     // Duyệt mảng cần gộp
		if (vitriA >= 0 && vitriB >= 0) 
		{ // Kiểm tra từng vị trí trong mảng A và mảng B xem có lớn hơn 0        
			if (a[vitriA] > b[vitriB])
			{    // So sánh xem phần tử của mảng nào lớn hơn (ở đầy là mảng a)
				c[i] = a[vitriA--];          // Đổ mảng a vào mảng cần gộp
			}
			else 
			{
				c[i] = b[vitriB--];             // Ngược lại thì đổ mảng b vào mảng cần gộp
			}
		}
		// Xét thêm
		else if (vitriB < 0) 
		{         // Nếu mà vị trí b tăng nhỏ hơn 0
			c[i] = a[vitriA--];            // Chỉ còn mảng a để đổ vào mảng cần gộp
		}
		else 
		{
			c[i] = b[vitriB--];
		}
	}
}
int main()
{
	int n, m, k;
	NhapDuLieu(n);
	int* a = new int[n];
	NhapMang(a, n);
	NhapDuLieu(m);
	int* b = new int[m];
	NhapMang(b, m);
	k = n + m;
	int* c = new int[k];
	XuatMang(a, n);
	cout << "\n\n";
	XuatMang(b, m);
	cout << "\n\n";
	//Tron2MangThanh1Mang(a, b, c, n, m, k);
	Tron2MangTangThanh1MangGiam(a, b, c, n, m, k);
	XuatMang(c, k);
	delete[]a;
	delete[]b;
	delete[]c;
	return 0;
}
