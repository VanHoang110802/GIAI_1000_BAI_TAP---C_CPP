Liệt kê các dòng có chứa giá trị lớn nhất của ma trận trong ma trận các số thực.

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


int TimGiaTriMax(int a[][MAX], int cot, int dong) 
{ 
	int Max = a[0][0]; 
	for (int i = 0; i < dong; i++) 
	{ 
		for(int j = 0; j < cot; j++) 
		{ 
			Max = (Max > a[i][j]) ? Max : a[i][j]; 
		} 
	} 
	return Max; 
} 

void LietKeCacDongCoChuaMax(int a[][MAX], int dong, int cot)
{
	int Max = TimGiaTriMax(a, dong, cot); 
	for (int i = 0; i < dong; i++) 
	{ 
		for (int j = 0; j < cot; j++) 
		{ 
			if (a[i][j] == Max) 
			{ 
				printf("\nDong [%d] chua max: ", i); 
				for (j = 0; j < cot; j++) 
				{ 
					printf("%d ", a[i][j]); 
				} 
			} 
		} 
	}
}
int main()
{
	int a[MAX][MAX], dong, cot;
	NhapMang(a, dong, cot);
	XuatMang(a, dong, cot);
	LietKeCacDongCoChuaMax(a, dong, cot);
	return 0;
}