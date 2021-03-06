Tìm giá trị lớn nhất trên một dòng trong ma trận các số thực.

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


void TimGiaTriLonNhatTren1Dong(int a[][100], int dong, int cot) 
{ 
	for (int i = 0; i < dong;i++) 
	{ 
		int Max = a[i][0]; 
		for (int j = 0; j < cot; j++) 
		{ 
			Max = (Max > a[i][j]) ? Max : a[i][j]; 
		} 
		printf("\nDong: %d: ", i) ; 
		printf("Gia tri max: %d", Max); 
	} 
} 
int main()
{
	int a[MAX][MAX], dong, cot;
	NhapMang(a, dong, cot);
	XuatMang(a, dong, cot);
	TimGiaTriLonNhatTren1Dong(a, dong, cot);
	return 0;
}
