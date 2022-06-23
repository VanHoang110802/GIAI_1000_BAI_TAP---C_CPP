Tính S(n) = 1 + 1*2 + 1*2*3 + ⋯ + 1 *2* 3 * … * 𝑛 
#include<stdio.h>
#include<conio.h>
void NhapDuLieu(int &n){
	printf("Nhap so: ");
	scanf("%d", &n);
}
int TinhTong(int n){
	int tong = 0;
	for(int i = 1; i <= n;i++){
		int tich = 1;
		for(int j = 1;j <= i;j++){
			tich *= j;
		}
		tong += tich;
	}
	return tong;
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
	int tong = TinhTong(n);
	printf("%d",tong);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim space de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if( lc == 32){
		goto hoang;
	}
	return 0;
}
