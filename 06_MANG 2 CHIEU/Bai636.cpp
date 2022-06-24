Kiểm tra ma trận có đối xứng qua đường chéo phụ hay không.

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

int KiemTraMaTranCoDoiXungQuaDuongCheoPhu(int a[][MAX], int n)
{
	int check = 1;
	for(int i = 0; i < n - 1; i++)
	{
		for(int j = 0; j < n - 1 - i; j++)
		{
			if(a[i][j] != a[n - 1 - j][n - 1 - i])
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
	int a[MAX][MAX], n;
	NhapMaTran(a,n);
	XuatMaTran(a,n);
	int kt = KiemTraMaTranCoDoiXungQuaDuongCheoPhu(a, n);
	if(kt == 1)
	{
		printf("\nMa tran doi xung qua duong cheo Phu!");
	}
	else
	{
		printf("\nKhoa thoa DK");
	}
	return 0;
}
