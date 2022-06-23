Đếm xem số tự nhiên n có bao nhiêu chữ số.

#include <stdio.h>
#include <conio.h>
#include <math.h>
void NhapDuLieu(int &n){
	printf("Nhap so : ");
	scanf("%d", &n);
}
void DemChuSo(int n){
	int dem = log10((double)n)+1;
	printf("So co tat ca la: %d chu so",dem);
}
int main(){
hoang:
	int n;
	NhapDuLieu(n);
	DemChuSo(n);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim space de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if( lc == 32){
		goto hoang;
	}
	return 0;
}
