Liệt kê các dòng toàn âm trong ma trận các số thực.
Ví dụ: Cho ma trận
Chỉ số
0 -87 75 -62 54
1 46 40 33 28
2 -20 -18 -15 -10
Ví dụ: Các dòng toàn âm trong ma trận: 0, 2.

#include<stdio.h>
#include<conio.h>
#include<math.h>
#define MAX 100
void NhapMang(float a[][MAX], int &dong, int &cot)
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
			printf("\nNhap a[%d][%d] = ", i, j);
			scanf("%f", &a[i][j]);
		}
	}
}

void XuatMang(float a[][MAX], int dong, int cot)
{
	for(int i = 0; i < dong; i++)
	{
		for(int j = 0; j < cot; j++)
		{
			printf("%.3f ", a[i][j]);
		}
			printf("\n");
	}
}

void LietKeCacDongToanAm(float a[][MAX], int dong, int cot)
{
	int check;
	for(int i = 0; i < dong; i++)
	{
		check = 1;
		for(int j = 0; j < cot; j++)
		{
			if(a[i][j] > 0)
			{
				check = 0;
				break;
			}
		}
		if(check == 1)
		{
			printf("\nDong %d toan am: ", i);
			for(int j = 0; j < cot; j++)
			{
				printf("\%.3f ", a[i][j]);
			}
		}
	}
}
int main()
{
	float a[MAX][MAX];
	int dong, cot;
	NhapMang(a, dong, cot);
	XuatMang(a, dong, cot);
	LietKeCacDongToanAm(a, dong, cot);
	return 0;
}
