Liệt kê các dòng có nhiều số chẵn nhất trong ma trận số nguyên.

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

void LietKeCacDongCoNhieuSoChanNhat(int a[][MAX], int dong, int cot)
{
	int dem[MAX] = {0}; // Khởi tạo
	for(int i = 0; i < dong; i++)
	{
		for(int j = 0; j < cot; j++)
		{
			if(a[i][j] % 2 == 0)
			{
				dem[i]++;
			}
		}
	}
	// Tìm Max
	int Max = dem[0];
	for(int i = 1; i < dong; i++)
	{
		Max = (Max > dem[i]) ? Max : dem[i]; 
	}
	// Liệt kê dòng có nhiều số chẵn nhất
	for(int i = 0; i < dong; i++)
	{
		if(Max == dem[i])
		{
			printf("\nDong %d co so chan nhieu nhat: %d so chan", i, Max); 
		}
	}
}
int main()
{
	int a[MAX][MAX], dong, cot;
	NhapMang(a, dong, cot);
	XuatMang(a, dong, cot);
	LietKeCacDongCoNhieuSoChanNhat(a, dong, cot);
	return 0;
}
