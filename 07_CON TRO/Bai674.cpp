Tìm “số chẵn cuối cùng” trong mảng một chiều các số nguyên. Nếu mảng không có giá trị chẵn thì trả về -1.

#include <iostream>
using namespace std;

void NhapMang(int *a, int n)
{
	for(int i = 0; i < n; ++i)
	{
		cout << "a[" << i << "] = ";
		cin >> a[i];
	}
}

void XuatMang(int *a, int n)
{
	for(int i = 0; i < n; ++i)
	{
		cout << a[i] << " ";
	}
}

int TimChanCuoi(int *a, int n)
{
	
	for(int i = n -1; i >= 0; --i)
	{
		if (a[i] % 2 == 0)
		{
			return a[i];
		}
	}
	return -1;
}

int main()
{
	int n;

	do{
		cout << "\nNhap so luong phan tu: ";
		cin >> n;

		if(n < 1)
		{
			cout << "\nSo luong phan tu khong hop le. Xin kiem tra lai !\n";
		}
	}while(n < 1);

	int *a = new int[n]; // Cấp phát.

	NhapMang(a, n);
	XuatMang(a, n);

	int Tim = TimChanCuoi(a, n);
	delete[] a; // Giải phóng mảng con trỏ.
	if (Tim == -1)
	{
		cout << "\nKhong co so chan nao trong mang!";
		return 0;
	}
	cout << "\nSo chan cuoi cung co trong mang: " << Tim;
	return 0;
}
