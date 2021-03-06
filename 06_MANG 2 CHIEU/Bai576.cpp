Liệt kê các dòng có tổng dòng lớn nhất trong ma trận.

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

int TinhTong(int a[], int cot)
{
	int Tong = 0;
	for(int i = 0; i < cot; i++)
	{
		Tong += a[i];
	}
	return Tong;
}

void LietKeCacDongCoTongLonNhat(int a[][MAX], int dong, int cot)
{
	int b[MAX];
	for(int i = 0; i < dong; i++)
	{
		b[i] = TinhTong(a[i], cot);
	}
	// Tổng Max
	int Max = b[0];
	for(int i = 1; i < dong; i++)
	{
		Max = (Max > b[i]) ? Max : b[i];
	}
	// Liệt kê tổng Max
	for(int i = 0; i < dong; i++)
	{
		if(Max == b[i])
		{
			printf("\nDong %d co tong phan tu lon nhat la: %d", i, Max); 
		}
	}
}
int main()
{
	int a[MAX][MAX], dong, cot;
	NhapMang(a, dong, cot);
	XuatMang(a, dong, cot);
	LietKeCacDongCoTongLonNhat(a, dong, cot);
	return 0;
}
