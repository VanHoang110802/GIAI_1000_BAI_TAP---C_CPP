Hãy kiểm tra số nguyên dương n có toàn chữ số lẻ hay không?
/*
n = 123456789 -> n không có toàn chữ số lẻ
n = 1357913-> n toàn chữ số lẻ
*/
#include <stdio.h>
#include<conio.h>
void NhapDuLieu(int &n){
	printf("Nhap so: ");
	scanf("%d", &n);
}
int KiemTraSo(int n){
	int temp = n, check = 1;
	while(temp != 0){
		int cs = temp % 10;
		temp /= 10;
		if(cs % 2 == 0){
			check = 0;
			break;
		}
	}
	if(check == 1){
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
	int kiemtra = KiemTraSo(n);
	if(kiemtra == 1){
		printf("n toan chu so le!");
	} else {
		printf("n co chu so chan!");
	}
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim space de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if( lc == 32){
		goto hoang;
	}
	return 0;
}
