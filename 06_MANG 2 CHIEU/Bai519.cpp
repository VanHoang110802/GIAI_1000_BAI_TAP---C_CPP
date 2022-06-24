Tính trung bình cộng các số dương trong ma trận các số thực.

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

float TinhTrungBinhCongCacSoDuong(float a[][MAX], int dong, int cot)
{
	float trungBinhCong, tong = 0, dem = 0;
	int n = dong * cot;
	for(int i = 0; i < n; i++)
	{
		if(a[i / cot][i % cot] > 0)
		{
			tong += a[i / cot][i % cot];
			dem++;
		}
	}
	return trungBinhCong = tong / dem;
}
int main()
{
	float a[MAX][MAX];
	int dong, cot;
	NhapMang(a, dong, cot);
	XuatMang(a, dong, cot);
	float tbc = TinhTrungBinhCongCacSoDuong(a, dong, cot);
	printf("\nTrung binh cong cac so duong trong mang la %.2f", tbc);
	return 0;
}
