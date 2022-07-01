// đọc dữ liệu từ file input.txt rồi tìm max, mincủa 2 số a,b cách nhau 1 khoảng trắng. Sau đó ghi kết quả vào output.txt
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // thư viện hỗ trợ file 

int main()
{
	int a, b, MAX, MIN;
	FILE* f;
	// cho con trỏ trỏ tới vùng nhớ chứa file input.txt
	f = fopen("input.txt","r");
	// nếu không có file
	if (!f)
	{
		printf("\nKhong tim thay tap tin! Xin kiem tra lai\n");
		return 0;
	}
	fscanf(f,"%d %d", &a, &b);
	fclose(f);
	MAX = a > b ? a : b;
	MIN = a < b ? a : b;
	
	FILE* fo;
	fo = fopen("output.txt", "w");
	fprintf(fo,"MAX = %d\nMIN = %d", MAX, MIN);
	
	fclose(fo);
	return 0;
}
