Đếm tần suất xuất hiện của một giá trị x trong ma trận các số thực.

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
			printf("a[%d][%d] = ", i, j);
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

int DemTanSuatXuatHienCuaGiaTriX(float a[][MAX], int dong, int cot, float x)
{
	int dem = 0;
	for(int i = 0; i < dong; i++)
	{
		for(int j = 0; j < cot; j++)
		{
			if(a[i][j] == x)
			{
				dem++;
			}
		}
	}
	return dem;
}
int main()
{
	float x;
	float a[MAX][MAX];
	int dong, cot;
	NhapMang(a, dong, cot);
	XuatMang(a, dong, cot);
	printf("\nNhap x: ");
	scanf("%f", &x);
	int dem = DemTanSuatXuatHienCuaGiaTriX(a, dong, cot, x);
	printf("\n%f xuat hien %d lan",x, dem);
	return 0;
}
