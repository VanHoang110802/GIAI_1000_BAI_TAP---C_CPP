Tính tổng tất cả “ước số chẵn” của số nguyên dương n.
#include<stdio.h>
#include<conio.h>
void NhapDuLieu(int &n){
	printf("Nhap so: ");
	scanf("%d", &n);
}
int TongUocChan(int n){
	int s =0;
	for(int i =1; i <= n;i++){
		if(n % i == 0){
			if(i % 2 == 0){
				s+=i;
			}
		}
	}
	return s;
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
	int tong = TongUocChan(n);
	printf("%d", tong);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim space de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if( lc == 32){
		goto hoang;
	}
	return 0;
}
