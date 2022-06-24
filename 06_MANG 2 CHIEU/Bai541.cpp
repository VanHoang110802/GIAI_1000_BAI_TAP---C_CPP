Liệt kê các dòng trong ma trận các số thực thỏa mãn đồng thời các điều kiện sau: dòng có chứa giá trị âm, giá trị dương và giá trị 0 (phần tử trung hòa).

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

void LietKeCacDongCoGiaTriAmVaDuongVa0(int a[][MAX], int dong, int cot)
{
	int n = dong * cot;
	int i, j;
	for(i = 0; i < dong; i++)
	{
		if(n > 2)
		{
			int check[3] = {0};  // Tạo ra 1 mảng 3 giá trị đều là 0
			for (j = 0; j < cot; j++) 
			{ 
				if (a[i][j] < 0) 
				{ 
					check[0] = 1; 
				} 
				else if (a[i][j] == 0) 
				{ 
					check[1] = 1; 
				} 
				else if (a[i][j] > 0) 
				{ 
					check[2] = 1; 
				}
				if(check[0] + check[1] + check[2] == 3)
				{
					printf("\nDong a[%d] co ptu am, duong, 0", i); 
					break; 
				}
			}
		}
	}
}
int main()
{
	int a[MAX][MAX], dong, cot;
	NhapMang(a, dong, cot);
	XuatMang(a, dong, cot);
	LietKeCacDongCoGiaTriAmVaDuongVa0(a, dong, cot);
	return 0;
}
