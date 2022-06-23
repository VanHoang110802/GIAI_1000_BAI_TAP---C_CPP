Tính giá trị S = 1 - 2 + 3 - ... + (3n + 1)
1−2+3−...+(3n+1), nếu n chẵn
1−2+3−...−(3n+1), nếu n lẻ
​
#include <stdio.h>
#include<conio.h>
void NhapDuLieu(int &n){
	printf("Nhap so: ");
	scanf("%d", &n);
}
int TinhTong(int n){
	int s = 0;
	for(int i = 1 ; i <= 3*n+1 ; i++){
		if(i % 2 == 0){
			s = s - i;
		}else{
			s = s + i;
		}
	}
	return s;
}
int main()
{
hoang:
	int n ;
	do{
	NhapDuLieu(n);
	if(n<= 0){
		printf("n > 0. Xin hay nhap lai!\n");
	}
	}while(n<= 0);
	TinhTong(n);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim space de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if( lc == 32){
		goto hoang;
	}
	return 0;
}
