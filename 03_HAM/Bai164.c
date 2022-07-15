Hàm trả về USCLN của 2 số nguyên.

#include<stdio.h>
#include<conio.h>
void NhapDuLieu(int &x){
	printf("Nhap so = ");
	scanf("%d", &x);
}
int TimUCLN(int a, int b){
	int ucln;
	int min = a< b > a:b;
	int max = a > b ? a:b;
	if(max % min == 0){
		ucln = min;
	} else {
		for(int i = min / 2; i>= 1; i--){
			if(min % i == 0 && max % i == 0){
				return i;
			}
		}
	}
	return min;
}
int main(){
hoang:
	int a,b;
	NhapDuLieu(a);
	NhapDuLieu(b);
	int tim = TimUCLN(a,b);
	printf("Ucln cua (%d, %d) la: %d",a,b,tim);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim space de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if( lc == 32){
		goto hoang;
	}
	return 0;
}
