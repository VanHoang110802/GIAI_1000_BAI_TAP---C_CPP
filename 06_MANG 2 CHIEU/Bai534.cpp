Đếm số lượng số dương trên biên ma trận trong ma trận các số thực.
Ví dụ: cho ma trận
-34 45 -23 -24 52
 12 -11 21 -56 -75
 78 47 45 31 -34
-94 -34 22 76 74

#include<stdio.h>
#include<conio.h>
#include<math.h>
#define MAX 100
void NhapMang(float a[][MAX], int &dong, int &cot)
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
			scanf("%f", &a[i][j]);
		}
	}
}

void XuatMang(float a[][MAX], int dong, int cot)
{
	for(int i = 0; i < dong; i++)
	{
		for(int j = 0; j < cot; j++)
		{
			printf("%.3f ", a[i][j]);
		}
			printf("\n");
	}
}

int DemSoLuongSoDuongTrenBien(float a[][MAX], int dong, int cot)
{
	int dem = 0;
	// đếm các giá trị dương trên biên dòng
	for(int j = 0; j < cot; j++)
	{
		if(a[0][j] > 0)
		{
			dem++;
		}
		if(a[cot - 1][j] > 0)
		{
			dem++;
		}
	}
	// đếm các giá trị dương trên biên cột
	for(int i = 1; i < dong - 1; i++)
	{
		if(a[i][0] > 0)
		{
			dem++;
		}
		if(a[i][dong - 1] > 0)
		{
			dem++;
		}
	}
	return dem;
}
int main()
{
	float a[MAX][MAX];
	int dong, cot;
	NhapMang(a, dong, cot);
	XuatMang(a, dong, cot);
	int dem = DemSoLuongSoDuongTrenBien(a, dong, cot);
	printf("\nSo luong so duong tren bien la: %d", dem);
	return 0;
}
