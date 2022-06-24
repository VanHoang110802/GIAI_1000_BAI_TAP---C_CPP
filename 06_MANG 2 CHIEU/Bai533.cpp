Đếm số lượng số âm trên một cột trong ma trận các số thực.

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

int DemSoLuongSoAmTren1Cot(float a[][MAX], int dong, int y)
{
	int dem = 0;
	for(int i = 0; i < dong; i++)
	{
		if(a[i][y] < 0)
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

	int y;
	do{
		printf("\nNhap vao cot y can dem: ");
		scanf("%d", &y);

		if(y < 0 || y > cot - 1)
		{
			printf("\nChi so cot y khong hop le. Xin kiem tra lai !\n");
		}
	}while(y < 0 || y > cot - 1);

	int dem = DemSoLuongSoAmTren1Cot(a, dong, y);
	printf("\nSo luong so am tren cot %d la: %d", y, dem);
	return 0;
}
