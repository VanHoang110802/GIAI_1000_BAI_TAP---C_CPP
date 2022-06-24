Cho ma trận các số thực A (m x n). Hãy xây dựng ma trận B(m x n) từ ma trận A sao cho B[i][j] = lớn nhất của dòng i và cột j trong ma trận A.

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
			printf("\nNhap a[%d][%d] = ", i, j);
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

int TimPhanTuLonNhatDongICotJ(int a[][MAX], int dong, int cot, int i, int j)
{
	int Max = a[i][0];
	// Tìm phần tử lớn nhất dòng i
	for(int k = 1; k < dong; k++)
	{
		Max = (Max < a[i][k]) ? a[i][k] : Max;
	}
	// Tìm phần tử lớn nhất cột j
	for(int k = 0; k < cot; k++)
	{
		Max = (Max < a[k][j]) ? a[k][j] : Max;
	}
	return Max;
}

void XayDungMaTranB(int a[][MAX], int dong, int cot, int b[][MAX])
{
	for(int i = 0; i < dong; i++)
	{
		for(int j = 0; j < cot; j++)
		{
			b[i][j] = TimPhanTuLonNhatDongICotJ(a, dong, cot, i, j);
		}
	}
}
int main()
{
	int a[MAX][MAX],b[MAX][MAX], dong, cot;
	NhapMang(a, dong, cot);
	XuatMang(a, dong, cot);
	XayDungMaTranB(a, dong, cot, b);
	printf("\nMa tran b[i][j] = lon nhat dong i, cot j cua ma tran A \n");
	XuatMang(b, dong, cot);
	return 0;
}
