Dịch phải xoay vòng các cột trong ma trận.
/*
dùng thêm mảng phụ, lưu lại cột bên trái ngoài cùng, rồi gán từ trái qua phải. Cuối cùng là gán mảng vào cột cuối bên phải
*/

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

void DichPhaiXoayVongCacCotTrongMaTran(int a[][MAX], int dong, int cot)
{
	int temp[MAX];
	for(int i = 0; i < dong; i++)
	{
		temp[i] = a[i][cot - 1];	
	}
	for(int j = cot - 1; j > 0; j--)
	{
		for(int i = 0; i < dong; i++)
		{
			a[i][j] = a[i][j - 1];
		}
	}
	for(int i = 0; i < dong; i++)
	{
		a[i][0] = temp[i];
	}
}

int main()
{
	int a[MAX][MAX], dong, cot;
	int cot1, cot2;
	NhapMang(a, dong, cot);
	XuatMang(a, dong, cot);
	DichPhaiXoayVongCacCotTrongMaTran(a, dong, cot);
	printf("\nMa tran sau khi dich phai xoay vong cac cot: \n");
	XuatMang(a, dong, cot);
	return 0;
}
