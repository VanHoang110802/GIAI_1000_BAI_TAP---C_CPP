Tìm chữ số xuất hiện nhiều nhất trong ma trận các số nguyên.
Ví dụ : cho ma trận
34 45 23 24 52
78 47 45 31 34
94 34 22 76 74
Chữ số xuất hiện nhiều nhất : 4

#include<stdio.h>
#include<conio.h>
#include<math.h>
#define MAX 100
void NhapMang(int a[][MAX], int &dong, int &cot)
{
	//Nhập số dòng
	do
	{
		printf("\nNhap vao so dong: ");
		scanf("%d",&dong);

		if(dong < 1 || dong > MAX)
		{
			printf("\nSo dong khong hop le. Xin kiem tra lai!\n");
		}

	}while(dong < 1 || dong > MAX);

	//Nhập số cột
	do
	{
		printf("\nNhap vao so cot: ");
		scanf("%d",&cot);

		if(cot < 1 || cot > MAX)
		{
			printf("\nSo cot khong hop le. Xin kiem tra lai!\n");

		}

	}while(cot < 1 || cot > MAX);
	for(int i = 0; i < dong; i++)
	{
		for(int j = 0; j < cot; j++)
		{
			printf("a[%d][%d] = ", i, j);
			scanf("%d", &a[i][j]);
		}
	}
}

void XuatMang(int a[][MAX], int dong, int cot)
{
	for(int i = 0; i < dong; i++)
	{
		for(int j = 0; j < cot; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}

void TachChuSo(int n, int b[])
{
	int ChuSo;
	n = abs(n);
	do
	{
		ChuSo = n % 10;
		b[ChuSo]++;
		n /= 10;
	}while(n > 0);
}

void TimCacChuSoXuatHienNhieuNhat(int a[][MAX], int dong, int cot)
{
	int b[10] = {0};
	for(int i = 0; i < dong; i++)
	{
		for(int j = 0; j < cot; j++)
		{
			TachChuSo(a[i][j], b);
		}
	}
	int ChuSoXuatHienNhieuNhat = 0;
	for(int i = 0; i < 10; i++)
	{
		if(b[ChuSoXuatHienNhieuNhat] < b[i])
		{
			ChuSoXuatHienNhieuNhat = i;
		}
	}
	printf("\nCac chu so xuat hien nhieu nhat: ");
	for(int i = 0; i < 10; i++)
	{
		if(b[ChuSoXuatHienNhieuNhat] == b[i])
		{
			printf("%d ", i);
		}
	}
}
int main()
{
	int a[MAX][MAX], dong, cot;
	NhapMang(a, dong, cot);
	XuatMang(a, dong, cot);
	TimCacChuSoXuatHienNhieuNhat(a, dong, cot);
	return 0;
}
