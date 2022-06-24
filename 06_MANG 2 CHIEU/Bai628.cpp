Đếm số lượng cặp giá trị đối xứng nhau qua đường chéo chính.

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

int DemCapGiaTriDoiXungQuaDuongCheoChinh(int a[][MAX], int n)
{
	int dem = 0;
	for(int i = 1; i < n; i++)
	{
		for(int j = 0; j < i; j++)
		{
			if(a[i][j] == a[j][i])
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
	int dem = DemCapGiaTriDoiXungQuaDuongCheoChinh(a, n);
	printf("\nSo cap gia tri doi xung qua duong cheo chinh la: %d", dem);
	return 0;
}
