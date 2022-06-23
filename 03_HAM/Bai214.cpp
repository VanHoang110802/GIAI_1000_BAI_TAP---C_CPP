Cho số nguyên dương n. Tính tổng các ước số nhỏ hơn chính nó.
#include<stdio.h>
#include<conio.h>
void NhapDuLieu(int &n){
	printf("Nhap so: ");
	scanf("%d", &n);
}
int TongCacUoc(int n){
	int s = 0;
	for(int i =1; i < n;i++){
		if(n % i == 0){
			s+=i;
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
	int tong = TongCacUoc(n);
	printf("%d", tong );
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim space de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if( lc == 32){
		goto hoang;
	}
	return 0;
}
