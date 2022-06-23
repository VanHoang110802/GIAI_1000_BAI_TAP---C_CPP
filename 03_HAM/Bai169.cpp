Tìm các số nguyên tố nhỏ hơn một số nguyên dương n cho trước.

vd: Nhập số nguyên dương: 11
Các số nguyên tố nhỏ hơn 11 là: 2 3 5 7

#include<stdio.h>
#include<conio.h>
#include<math.h>
void NhapDuLieu(int &x){
	printf("Nhap so = ");
	scanf("%d", &x);
}
int KiemTraNguyenTo(int n){
	if(n < 2){
		return 0;
	}
	else {
		if(n!= 2 && n % 2 == 0){
			return 0;
		}
		for(int i =3;i<= (int)sqrt((double)n);i+=2){
			if(n%i == 0){
				return 0;
			}
		}
	}
	return 1;
}
void LietKeCacSoNguyenTo(int n){
	for(int i = 1; i< n; i++){
		if(KiemTraNguyenTo(i) == 1){
			printf("%d ",i);
		}
	}
}
int main(){
hoang:
	int n;
	NhapDuLieu(n);
	LietKeCacSoNguyenTo(n);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim space de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if( lc == 32){
		goto hoang;
	}
	return 0;
}
