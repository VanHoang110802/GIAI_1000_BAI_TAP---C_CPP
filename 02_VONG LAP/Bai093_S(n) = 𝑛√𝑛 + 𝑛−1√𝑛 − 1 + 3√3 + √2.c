TΓ­nh S(n) = πβπ + πβ1βπ β 1 + 3β3 + β2 cΓ³ n β 1 dαΊ₯u cΔn.

#include<stdio.h>
#include<conio.h>
#include<math.h>
int main()
{
hoang:
    int n;
    do
    {
        printf("Nhap n= ");
        scanf("%d", &n);

        if(n < 2)
        {
            printf("n phai >= 2. Xin nhap lai !\n");
        }
    }while(n < 2);
    int i = 3;
    float S = pow(2.0, 1.0/2);
    while(i <= n)
    {
        S = pow((i + S) * 1.0, 1.0/i);
        i++;
    }
    printf("Tong = %.3f", S);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
    return 0;
}
