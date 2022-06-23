Cho số nguyên dương n. Kiểm tra số nguyên dương n có phải là số
chính phương hay không
#include<stdio.h>
#include<conio.h>
#include <math.h>
void NhapDuLieu(int &n){
	printf("Nhap so: ");
	scanf("%d", &n);
}
void KiemTraSoCP(int n){
	double kq = sqrt((double)n);
	if (n > 0) {
		if (kq == (int)kq) {
			printf("Day la so chinh phuong");
		}
		else {
			printf("Day khong la so chinh phuong");
		}
	}
	else {
		printf("So nhap khong hop le, n > 0");
	}
}
int main(){
hoang:
	int n;
	do{
	NhapDuLieu(n);
	if(n<= 0){
		printf("n > 0. Xin hay nhap lai!\n");
	}
	}while(n<= 0);
	KiemTraSoCP(n);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim space de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if( lc == 32){
		goto hoang;
	}
	return 0;
}
