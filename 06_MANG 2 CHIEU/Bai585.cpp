Dịch lên xoay vòng các hàng trong ma trận.
/*
dùng thêm mảng phụ, lưu lại hàng đầu, rồi gán từ trên xuống. Cuối cùng là gán mảng vào hàng cuối
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

void DichLenXoayVongCacHangTrongMaTran(int a[][MAX], int dong, int cot)
{
	// Gán mảng phụ vào hàng đầu
	int temp[MAX];
	for(int i = 0; i < cot; i++)
	{
		temp[i] = a[0][i];
	}

	// Gán từ trên xuống
	for(int i = 0; i < dong - 1; i++)
	{
		for(int j = 0; j < cot; j++)
		{
			a[i][j] = a[i + 1][j];
		}
	}
	// Dùng mảng phụ lưu lại hàng cuối
	for(int i = 0; i < cot; i++)
	{
		a[dong - 1][i] = temp[i];
	}
}

int main()
{
	int a[MAX][MAX], dong, cot;
	int cot1, cot2;
	NhapMang(a, dong, cot);
	XuatMang(a, dong, cot);
	DichLenXoayVongCacHangTrongMaTran(a, dong, cot);
	printf("\nMa tran sau khi dich len xoay vong cac hang: \n");
	XuatMang(a, dong, cot);
	return 0;
}
