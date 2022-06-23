Viết chương trình nhập vào hai số thực. Kiểm tra xem chúng có cùng
dấu hay không.

#include<stdio.h>
#include<conio.h>
int main(){
hoang:
    float a, b;
    printf("Nhap a= ");
    scanf("%f", &a);
    printf("Nhap b= ");
    scanf("%f", &b);

    if(a * b > 0)
        printf("%.3f va %.3f cung dau", a, b);
    else
        printf("%.3f va %.3f khong cung dau", a, b);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
    return 0;
}
