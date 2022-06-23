Hãy tính tích các chữ số của số nguyên dương n.
/*
n = 2346816
-> s = 2 * 3 * 4 * 6 * 8 * 1 * 6 = 6912
*/

#include<stdio.h>
#include<conio.h>
void NhapDuLieu(int &n){
	printf("Nhap so: ");
	scanf("%d", &n);
}
int TichChuSo(int n){
	int temp = n,s = 1;
	while(temp != 0){
		int cs = temp % 10;
		temp /=10;
		s*=cs;
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
	int tich = TichChuSo(n);
	printf("%d",tich);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim space de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if( lc == 32){
		goto hoang;
	}
	return 0;
}
