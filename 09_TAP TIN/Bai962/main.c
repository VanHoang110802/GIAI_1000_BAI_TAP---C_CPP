/* 
- Dòng đầu tiên có số n tượng trưng cho số lượng các học sinh trong lớp
- Các dòng tiếp theo có n số cách nhau bởi khoảng trắng 
=> tượng trưng cho điểm số của các học sinh trong lớp.

-> Đọc dữ liệu vào chương trình và tìm ra xem học sinh điểm cao nhất là bao nhiêu rồi sắp xếp theo thứ tự tăng dần ?
Kết quả ghi vào file.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void HoanVi(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void SapXep(int* a, int n, char phanloai)
{
	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			if (phanloai == 't')
			{
				if (a[i] > a[j])
				{
					HoanVi(&a[i], &a[j]);
				}
			}
			else if (phanloai == 'g')
			{
				if (a[i] < a[j])
				{
					HoanVi(&a[i], &a[j]);
				}
			}
		}
	}
}

int main()
{
	
	FILE* FileIn; // Khai báo con trỏ File.

	// Cho con trỏ trở tới vùng nhớ chứa file INPUT.TXT
	FileIn = fopen("input.txt", "r");

	// Kiểm tra xem tập tin có tồn tại hay không ?
	if (!FileIn)
	{
		printf("\nKhong tim thay tap tin input.TXT ! Xin kiem tra lai !");
		return 0;
	}

	int soluong;
	fscanf(FileIn, "%d", &soluong);

	// Max là số đầu tiên.
	
	int* a = (int*)realloc(NULL, soluong * sizeof(int));
	int Max = a[0];

	for (int i = 0; i < soluong; ++i)
	{
		fscanf(FileIn, "%d", &a[i]);
	}
	for (int i = 0; i < soluong;++i)
	{
		if (a[i] > Max)
		{
			Max = a[i];
		}
	}
	// Đóng tập tin
	fclose(FileIn);
	SapXep(a, soluong, 't');
	

	// Mở file
	FILE* FileOut;
	FileOut = fopen("output.txt", "w"); // tự động tạo mới nếu chưa có.

	// Ghi file
	fprintf(FileOut, "\nMax = %d\n\n", Max);

	for (int i = 0; i < soluong; ++i)
	{
		fprintf(FileOut, "%d ",a[i]);
	}
	// Đóng file
	fclose(FileOut);
	free(a);
	return 0;
}
