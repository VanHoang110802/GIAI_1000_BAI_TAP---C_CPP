Viết chương trình tìm số lớn nhất trong ba số thực a, b, c.

#include<stdio.h>
#include<conio.h>

int main()
{
hoang:
    float a, b, c, max;
    printf("Nhap a= ");
    scanf("%f", &a);

    printf("Nhap b= ");
    scanf("%f", &b);

    printf("Nhap c= ");
    scanf("%f", &c);

    max = a;
    if(max < b)
        max = b;
    if(max < c)
        max = c;

    printf("So lon nhat trong 3 so %.3f, %.3f, %.3f, la: %.3f", a, b, c, max);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
    return 0;

}
