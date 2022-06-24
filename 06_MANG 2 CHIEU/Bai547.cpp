Kiểm tra một cột trong ma trận có giảm dần hay không.

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

int KiemTra1CotMaTranCoGiamDan(int a[][MAX], int dong, int y)
{
	int check = 1;
	for(int i = 0; i < dong - 1; i++)
	{
		for(int j = i + 1; j < dong; j++)
		{
			if(a[i][y] < a[j][y])
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
	int y;
	do{
		printf("\nNhap vao cot y can kiem tra: ");
		scanf("%d", &y);

		if(y < 0 || y > cot - 1)
		{
			printf("\nChi so dong x khong hop le. Xin kiem tra lai !\n");
		}
	}while(y < 0 || y > cot - 1);
	int kt = KiemTra1CotMaTranCoGiamDan(a, dong, y);
	if(kt == 1)
	{
		printf("\nCot %d giam", y);
	}
	else
	{
		printf("\nKhong thoa DK");
	}
	return 0;
}
