Đếm số chữ số trong ma trận các số nguyên dương.

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

int DemSoLuongChuSo(int n)
{
	int sochuso = n == 0 ? 1 : (int)log10((float)n) + 1;
	return sochuso;
}

int DemSoLuongChuSoTrongMaTran(int a[][MAX], int dong, int cot)
{
	int dem = 0;
	for(int i = 0; i < dong; i++)
	{
		for(int j = 0; j < cot; j++)
		{
			int sochuso = DemSoLuongChuSo(a[i][j]);
			dem += sochuso;
		}
	}
	return dem;
}
int main()
{
	int a[MAX][MAX], dong, cot;
	NhapMang(a, dong, cot);
	XuatMang(a, dong, cot);
	int dem = DemSoLuongChuSoTrongMaTran(a, dong, cot);
	printf("\nSo chu so trong ma tran la: %d", dem);
	return 0;
}
