Tính S(n) = 𝑛√𝑛 + 𝑛−1√𝑛 − 1 + 3√3 + √2 có n – 1 dấu căn.

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
