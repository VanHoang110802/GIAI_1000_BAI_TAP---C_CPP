Viết hàm tính S = x^y .

#include <stdio.h>
#include<conio.h>
#include <math.h>
void NhapDuLieu(int &n){
	printf("Nhap so: ");
	scanf("%d", &n);
}
itn TinhMu(int x, int y){
	int S;
	S = pow(x,y);
	return S;
}
int main(){
hoang:
	int x,y;
	NhapDuLieu(x);
	do{
	NhapDuLieu(y);
	if(y<= 0){
		printf("y > 0. Xin hay nhap lai!\n");
	}
	}while(y<= 0);
	int tinh = TinhMu(x,y);
	printf("S = %d", tinh);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim space de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if( lc == 32){
		goto hoang;
	}
	return 0;
}
