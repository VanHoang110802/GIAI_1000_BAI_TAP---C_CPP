/*
Viết chương trình kiểm tra tập tin đó xem:
- Đã tồn tại hay chưa?
- Chỉ được đọc hay chỉ được ghi hay được cả 2 ?
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>

int KiemTraFileCoTonTai(const char* fname)
{
	FILE* fp = fopen(fname, "rb");
	if (fp == NULL)
	{
		return 0;
	}
	fclose(fp);
	return 1;
}

int KiemTraFileCoDocDuoc(const char* fname)
{
	FILE* fp = fopen(fname, "r + b");
	if (fp == NULL)
	{
		return 1;
	}
	fclose(fp);
	return 0;
}
void CheckFile(const char* fname)
{
	if (KiemTraFileCoTonTai(fname))
	{
		printf("File %s dang ton tai.\n", fname);
		if (KiemTraFileCoDocDuoc(fname))
		{
			printf("File %s chi co the doc\n", fname);
		}
		else
		{
			printf("File %s co the ghi va doc\n", fname);
		}
	}
	else
	{
		printf("File %s khong tim thay\n", fname);
	}
}
int main()
{
	const char* fname1 = "Result.txt"; 
	const char* fname2 = "Data.txt";
	const char* fname3 = "WELCOME.txt";
	CheckFile(fname1);
	CheckFile(fname2);
	CheckFile(fname3);

	return 0;
}
