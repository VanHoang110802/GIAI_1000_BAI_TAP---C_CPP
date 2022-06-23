Cho số nguyên dương n. Kiểm tra số nguyên dương n có phải là số
nguyên tố hay không?

#include<stdio.h>
void NhapDuLieu(int &n){
	printf("Nhap so: ");
	scanf("%d", &n);
}
int KiemTraSoNT(int n){
	int temp = n, check = 1;
	for (int i = 2; i * i <= temp; i++) {
		if (temp % i == 0) {
			check = 0;
			break;
		}
	}
	if (check == 1 && temp >= 2) {
		return 1;
	}
	return 0;
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
	int kiemtra = KiemTraSoNT(n);
	if(kiemtra == 1){
		printf("Day la so nguyen to!");
	} else {
		printf("Day khong la so nguyen to!");
	}
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim space de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if( lc == 32){
		goto hoang;
	}
	return 0;
}
