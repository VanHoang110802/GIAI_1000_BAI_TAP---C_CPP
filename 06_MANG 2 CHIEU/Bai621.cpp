Tính tổng các phần tử trên đường chéo phụ.

#include<stdio.h>
#include<conio.h>
#include<math.h>
#define MAX 100
void NhapMaTran(int a[][MAX], int &n)
{
	do
	{
		printf("\nNhap n: ");
		scanf("%d", &n);
		if(n < 1 || n > MAX)
		{
			printf("\nSo phan tu khong hop le. Xin kiem tra lai !\n");
		}
	}while(n < 1 || n > MAX);

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			printf("a[%d][%d] = ", i, j);
			scanf("%d", &a[i][j]);
		}
	}
}

void XuatMaTran(int a[][MAX], int n)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
}

int TinhTongCacPhanTuTrenDuongCheoPhu(int a[][MAX], int n)
{
	int S = 0;     
	for (int i = 0; i < n; i++)
	{
		S += a[i][n - 1 - i];
	}
	return S; 
}
int main()
{
	int a[MAX][MAX], n;
	NhapMaTran(a,n);
	XuatMaTran(a,n);
	int tong = TinhTongCacPhanTuTrenDuongCheoPhu(a, n);
	printf("\nTong cac phan tu tren duong cheo phu la: %d", tong);
	return 0;
}
