Nhập 1 số nguyên dương n. Tính: S = 1! + 2! + … + n!

#include <stdio.h>
#include <conio.h>
int main(){
hoang:
	int n;
	printf("Nhap so n= ");
	scanf("%d", &n);
	int i,j,tong = 0;
	// S = 0 + 1*1
	// S = 1*1 + 1*2
	// S = 1*1 + 1*2 + 1*2*3
	// S = 1*1 + 1*2 + 1*2*3 + 1*2*3*4
	for(i=1;i<= n;i++){
		int tich = 1	// phải khai báo ở đây, khai báo bên ngoài sẽ bị sai
		for(j=1;j<=i;j++){
			tich *=j;
		}
		tong += tich;
	}
	printf("S = %d", tong);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
