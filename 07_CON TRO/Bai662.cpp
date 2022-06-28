#include<iostream>
using namespace std;

//a + i <=> &a[0 + i] ;

//*(a+i) <=> a[i]

void NhapMang(int* a, int n)
{
	for(int i = 0; i < n; i++)
	{
		cout << "a[" << i << "]= ";
		cin >> *(a + i);
	}
}

void XuatMang(int* a, int n)
{
	for(int i = 0; i < n; i++)
	{
		cout << *(a + i) << " ";
	}
}

int main()
{
	int *a = NULL;
	int n;
	do
  {
		cout << "Nhap so luong phan tu: ";
		cin >> n;
		if(n < 1)
			cout << "So luong la phai > 0!\n";
	}while(n < 1);
	a = new int[n];	// Xin cấp phát n ô nhớ kiểu int ở vùng nhớ HEAP
	NhapMang(a, n);
	XuatMang(a, n);
	if(a != NULL)
	{
		delete[] a;	// Thu hồi n ô nhớ vừa xin cấp phát trước đó 
	}
	return 0;
}
