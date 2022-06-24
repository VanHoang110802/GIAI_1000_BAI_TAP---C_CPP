Tính tích hai ma trận.

#include<stdio.h>
#include<conio.h>
#include<math.h>
#define MAX 100

void NhapMaTran(int a[][MAX], int &dong, int &cot)
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

void XuatMaTran(int a[][MAX], int dong, int cot)
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

void TinhTich2MaTran(int a[][MAX], int b[][MAX], int t[][MAX], int donga, int cota, int cotb)
{
	for(int i = 0; i < donga; i++)
	{
		for(int j = 0; j < cotb; j++)
		{
			t[i][j] = 0;
			for(int k = 0; k < cota; k++)
			{
				t[i][j] += a[i][k] * b[k][j];
			}
		}
	}
}
int main()
{
	int a[MAX][MAX], b[MAX][MAX], t[MAX][MAX]; 
	int da, ca, cb; 
	do{
		printf("Nhap vao so dong ma tran a:"); scanf("%d", &da); 
	}while((da < 1 || da > MAX)  && printf("\nSo dong khong hop le!\n"));

	do{
		printf("Nhap vao so cot ma tran a:"); scanf("%d", &ca); 
	}while((ca < 1 || ca > MAX)  && printf("\nSo cot khong hop le!\n"));

	NhapMaTran(a, da, ca); 
	printf("A:\n"); XuatMaTran(a, da, ca); 
	do{
	printf("Nhap vao so cot cua ma tran b:"); scanf("%d", &cb); 
	}while((cb < 1 || cb > MAX)  && printf("\nSo cot khong hop le!\n"));
	NhapMaTran(b, ca, cb); 
	printf("Matrix B:\n"); XuatMaTran(b, ca, cb); 
	TinhTich2MaTran(a, b, t, da, ca, cb); 
	printf("Tich cua 2 ma tran la:\n"); XuatMaTran(t, da, cb); 
	return 0;
}
