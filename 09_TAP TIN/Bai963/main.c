#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void transFile(FILE* inFile, FILE* outFile)
{
	int ch;
	while (1)
	{
		ch = fgetc(inFile);
		if (!feof(inFile))
		{
			fputc(ch, outFile);
		}
		else
		{
			break;
		}
	}
}

int main()
{
	FILE* fpIn, * fpOut;
	const char* fname = "Data.txt"; 
	const char* fcopy = "DataCopy.txt";
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
	transFile(fpIn, fpOut);
	fclose(fpIn);
	fclose(fpOut);
	return 0;
}
