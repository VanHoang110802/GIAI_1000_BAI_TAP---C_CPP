Viết chương trình nhập vào hai số thực. Kiểm tra xem chúng có cùng
dấu hay không.

#include<stdio.h>
#include<conio.h>
void NhapDuLieu(float &n){
	printf("Nhap so: ");
	scanf("%f", &n);
}
void XetDau(int a, int b){
	 if(a * b > 0)
        printf("%.3f va %.3f cung dau", a, b);
    else
        printf("%.3f va %.3f khong cung dau", a, b);
}
int main(){
hoang:
    float a, b;
    NhapDuLieu(a);
	NhapDuLieu(b);
	XetDau(a,b);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim space de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if( lc == 32){
		goto hoang;
	}
    return 0;
}
