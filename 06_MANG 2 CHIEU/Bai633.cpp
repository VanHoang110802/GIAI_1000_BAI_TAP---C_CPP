Đếm số lượng giá trị chẵn trong ma trận tam giác trên của ma trận vuông các số nguyên.

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

int DemSoChanMaTranTamGiacTrenDuongCheoChinh(int a[][MAX], int n)
{
	int dem = 0;
	for(int i = 0; i < n - 1; i++)
	{
		for(int j = i + 1; j < n; j++)
		{
			if(a[i][j] % 2 == 0)
			{
				dem++;
			}
		}
	}
	return dem;
}

int DemSoChanMaTranTamGiacTrenDuongCheoPhu(int a[][MAX], int n)
{
	int dem = 0;
	for(int i = 0; i < n - 1; i++)
	{
		for(int j = 0; j < n - 1 - i; j++)
		{
			if(a[i][j] % 2 == 0)
			{
				dem++;
			}
		}
	}
	return dem;
}
int main()
{
	int a[MAX][MAX], n;
	NhapMaTran(a,n);
	XuatMaTran(a,n);
	int dem = DemSoChanMaTranTamGiacTrenDuongCheoChinh(a, n);
	printf("\nSo luong so chan ma tran tam giac tren duong cheo chinh la: %d", dem);
	int dem2 = DemSoChanMaTranTamGiacTrenDuongCheoPhu(a, n);
	printf("\nSo luong so chan ma tran tam giac tren duong cheo phu la: %d", dem2);
	return 0;
}
