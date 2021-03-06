Kiểm tra một hàng ma trận có tăng dần hay không.

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

int KiemTra1HangMaTranCoTangDan(int a[][MAX], int x, int cot)
{
	int check = 1;
	for(int j = 0; j < cot - 1; j++)
	{
		for(int k = j + 1; k < cot; k++)
		{
			if(a[x][j] > a[x][k])
			{
				check = 0;
				break;
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
	int x;
	do{
		printf("\nNhap vao dong x can kiem tra ");
		scanf("%d", &x);

		if(x < 0 || x > dong - 1)
		{
			printf("\nChi so dong x khong hop le. Xin kiem tra lai !\n");
		}
	}while(x < 0 || x > dong - 1);

	int kt = KiemTra1HangMaTranCoTangDan(a, x, cot);
	if(kt == 1)
	{
		printf("\nHang %d tang dan", x);
	}
	else
	{
		printf("\nKhong thoa DK");
	}
	return 0;
}
