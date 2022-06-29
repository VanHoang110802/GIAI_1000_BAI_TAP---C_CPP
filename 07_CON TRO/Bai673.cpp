Tìm “giá trị dương đầu tiên” trong mảng một chiều các số thực. Nếu mảng không có giá trị dương thì trả về -1.

#include <stdio.h>
#include <stdlib.h>

void NhapMang(float *&a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("a[%d] = ", i);
		scanf_s("%f", &a[i]);
	}
}
void XuatMang(float*a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%.2f ", a[i]);
	}
}
float TimDuongDau(float *a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		if (a[i] > 0)
		{
			return a[i];
		}
	}
	return -1;
}
int main()
{
	int n;
	do
	{
		printf("\nNhap so luong phan tu: ");
		scanf_s("%d", &n);
		if (n < 1)
		{
			printf("\nSo luong phan tu nhap khong hop le! Xin hay nhap lai!\n");
		}
	} while (n < 1);
	float* a = (float*)realloc(NULL, n * sizeof(float));
	NhapMang(a, n);
	XuatMang(a, n);
	float kq = TimDuongDau(a, n);
	free(a);
	if (kq == -1)
	{
		printf("\nMang khong co so duong nao!");
		return 0;
	}
	printf("\nSo duong dau tien co trong mang la: %.2f", kq);
	
	return 0;
}
