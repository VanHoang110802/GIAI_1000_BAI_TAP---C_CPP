/*
Tạo 1 tập tin rồi cho vào tập tin 1 chuỗi bất kì. Hãy tạo 1 tập tin khác cũng có chứa chuỗi nhưng chuỗi đó là 1 chuỗi hoa. Còn nếu chuỗi đó là chuỗi hoa
rồi thì giữ nguyên
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<ctype.h>

void convertFile(FILE* inFile, FILE* outFile)
{
	int ch;
	while (1)
	{
		ch = fgetc(inFile);
		if (!feof(inFile))
		{
			ch = toupper(ch);
			fputc(ch, outFile);
		}
		else
			break;
	}
}

int main()
{
	FILE* fpIn, * fpOut;
	const char* fname = "Data.txt"; 
	const char* fcopy = "DataUpper.txt";
	fpIn = fopen(fname, "rt");
	if (fpIn == NULL)
	{
		printf("File %s not found!\n", fname);
		return 0;
	}
	fpOut = fopen(fcopy, "wt");
	if (fpOut == NULL)
	{
		printf("Can not open file %s!\n", fcopy);
		fclose(fpIn);
		return 0;
	}
	convertFile(fpIn, fpOut);
	fclose(fpIn);
	fclose(fpOut);
	return 0;
}
