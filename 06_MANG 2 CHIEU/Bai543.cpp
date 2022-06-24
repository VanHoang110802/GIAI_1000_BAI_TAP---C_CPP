Kiểm tra ma trận có tồn tại số hoàn thiện hay không.

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

int KiemTraMaTranCoTonTaiSoHoanThien(int a[][MAX], int dong, int cot)
{
	int check = 0;
	for(int i = 0; i < dong; i++)
	{
		for(int j = 0; j < cot; j++)
		{
			if(KiemTraHoanThien(a[i][j]) == 1)
			{
				check = 1;
			}
		}
	}
	return check;
}
int main()
{
	int a[MAX][MAX], dong, cot;
	NhapMang(a, dong, cot);
	XuatMang(a, dong, cot);

	int kt = KiemTraMaTranCoTonTaiSoHoanThien(a, dong, cot);
	if(kt == 1)
	{
		printf("\nMa tran co ton tai so hoan thien");
	}
	else
	{
		printf("\nKhong tim thay");
	}
	return 0;
}
