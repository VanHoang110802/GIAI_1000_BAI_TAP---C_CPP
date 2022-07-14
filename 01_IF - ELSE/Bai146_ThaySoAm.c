Viết chương trình nhập 3 số thực. Hãy thay tất cả các số âm bằng trị tuyệt đối của nó.

#include<stdio.h>
#include<conio.h>

int main()
{
hoang:
    float a, b, c;
    printf("Nhap a= ");
    scanf("%f", &a);
    printf("Nhap b= ");
    scanf("%f", &b);
    printf("Nhap c= ");
    scanf("%f", &c);

    if(a < 0)
     a = -a;
    if(b < 0)
     b = -b;
    if(c < 0)
     c = -c;

     printf("\na = %f", a);
     printf("\nb = %f", b);
     printf("\nc = %f", c);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
     return 0;
}
