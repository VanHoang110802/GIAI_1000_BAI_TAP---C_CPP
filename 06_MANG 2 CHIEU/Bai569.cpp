Tìm số nguyên tố lớn nhất trong ma trận các số nguyên.

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

int KiemTraNguyenTo(int n)
{
	if(n < 2)
	{
		return 0;
	}
	else if(n > 2)
	{
		if(n % 2 == 0)
		{
			return 0;
		}
		for(int i = 3; i <= sqrt((float)n); i+= 2)
		{
			if(n % i == 0)
			{
				return 0;
			}
		}
	}
	return 1;
}

int TimSoNguyenToDauTien(int a[][MAX], int dong, int cot)
{
	for(int i = 0; i < dong; i++)
	{
		for(int j = 0; j < cot; j++)
		{
			if(KiemTraNguyenTo(a[i][j]) == 1)
			{
				return a[i][j];
			}
		}
	}
	return -1;
}

int TimSoNguyenToLonNhat(int a[][MAX], int dong, int cot)
{
	int SoNguyenToMax = TimSoNguyenToDauTien(a, dong, cot); 
	if (SoNguyenToMax == -1) 
	{ 
		return -1; 
	} 
	for (int i = 0; i < dong;i++) 
	{ 
		for (int j = 0; j < cot; j++) 
		{ 
			if (KiemTraNguyenTo(a[i][j]) == 1) 
			{ 
				SoNguyenToMax = (SoNguyenToMax > a[i][j]) ? SoNguyenToMax : a[i][j]; 
			} 
		} 
	} 
	return SoNguyenToMax; 
}
int main()
{
	int a[MAX][MAX], dong, cot;
	NhapMang(a, dong, cot);
	XuatMang(a, dong, cot);
	int SoNguyenToMax = TimSoNguyenToLonNhat(a, dong, cot);
	printf("\nSo nguyen to lon nhat trong ma tran la: %d", SoNguyenToMax);
	return 0;
}
