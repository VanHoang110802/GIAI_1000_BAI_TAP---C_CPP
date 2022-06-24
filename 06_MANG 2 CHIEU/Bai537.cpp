Đếm số lượng giá trị có trong ma trận các số thực. Lưu ý: Nếu có k phần tử (k >= 1) trong ma trận bằng nhau thì ta chỉ tính là 1.

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

int DemSoLuongCacGiaTriPhanBiet(float a[][MAX], int dong, int cot)
{
	int n = dong * cot;
	int dem = 0, flag;
	for(int i = 0; i < n; i++)
	{
		flag = 1;
		for(int j = i + 1; j < n; j++)
		{
			if(a[j / cot][j % cot] == a[i / cot][i % cot])
			{
				flag = 0;
				break;
			}
		}
		if(flag == 1)
		{
			dem++;
		}
	}
	return dem;
}
int main()
{
	float a[MAX][MAX];
	int dong, cot;
	NhapMang(a, dong, cot);
	XuatMang(a, dong, cot);
	int dem = DemSoLuongCacGiaTriPhanBiet(a, dong, cot);
	printf("\nSo phan tu phan biet trong ma tran la: %d", dem);
	return 0;
}
