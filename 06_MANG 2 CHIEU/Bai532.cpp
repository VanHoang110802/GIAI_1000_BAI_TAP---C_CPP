Đếm số lượng số hoàn thiện trên một hàng trong ma trận các số nguyên.

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


int KiemTraHoanThien(int n)
{
	int tong = 0;
	for(int i = 1; i < n; i++)
	{
		if(n % i == 0)
		{
			tong += i;
		}
	}
	if(tong == n)
	{
		return 1;
	}
	return 0;
}
int DemSoLuongSoHoanThienTren1Hang(int a[][MAX], int x, int cot)
{
	int dem = 0;
	for(int j = 0; j < cot; j++)
	{
		if(KiemTraHoanThien(a[x][j]) == 1)
		{
			dem++;
		}
	}
	return dem;
}
int main()
{
	int a[MAX][MAX], dong, cot;
	NhapMang(a, dong, cot);
	XuatMang(a, dong, cot);
	int x;
	do{
		printf("\nNhap vao dong x can dem: ");
		scanf("%d", &x);

		if(x < 0 || x > dong - 1)
		{
			printf("\nChi so dong x khong hop le. Xin kiem tra lai !\n");
		}
	}while(x < 0 || x > dong - 1);
	int dem = DemSoLuongSoHoanThienTren1Hang(a, x, cot);
	printf("\nSo luong so hoan thien tren dong %d la: %d", x, dem);
	return 0;
}
