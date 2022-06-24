Tìm số chính phương lớn nhất trong ma trận các số nguyên.

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

int KiemTraChinhPhuong(int n)
{
	return sqrt((float)n) == (int)sqrt((float)n);
}

int TimSoChinhPhuongDauTien(int a[][MAX], int dong, int cot)
{
	for(int i = 0; i < dong; i++)
	{
		for(int j = 0; j < cot; j++)
		{
			if(KiemTraChinhPhuong(a[i][j]) == 1)
			{
				return a[i][j];
			}
		}
	}
	return -1;
}

int TimSoChinhPhuongLonNhat(int a[][MAX], int dong, int cot)
{
	int SoChinhPhuongMax = TimSoChinhPhuongDauTien(a, dong, cot);
	if (SoChinhPhuongMax == -1) 
	{ 
		return -1; 
	} 
	for (int i = 0; i < dong;i++) 
	{ 
		for (int j = 0; j < cot; j++) 
		{ 
			if (KiemTraChinhPhuong(a[i][j]) == 1) 
			{ 
				SoChinhPhuongMax = (SoChinhPhuongMax > a[i][j]) ? SoChinhPhuongMax : a[i][j]; 
			} 
		} 
	} 
	return SoChinhPhuongMax; 
}
int main()
{
	int a[MAX][MAX], dong, cot;
	NhapMang(a, dong, cot);
	XuatMang(a, dong, cot);
	int SoChinhPhuongMax = TimSoChinhPhuongLonNhat(a, dong, cot);
	printf("\nSo chinh phuong lon nhat = %d", SoChinhPhuongMax);
	return 0;
}
