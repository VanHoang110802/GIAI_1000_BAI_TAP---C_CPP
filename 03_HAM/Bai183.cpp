Viết chương trình phân tích một số nguyên N thành tích của các thừa số nguyên tố.
vd: 18 = 3 * 3 * 2

#include <stdio.h>
#include <conio.h>
void NhapDuLieu(int &n){
	printf("nhap so n: ");
    	scanf("%d",&n);
}
void InCacThuaSoNguyenTo(int n){
	printf("%d = ", n);
	int i = 2;
	while(n >= 2){		// vì số nguyên tố min = 2 rồi.
		if(n % i ==0){
			printf("%d", i);
			n/=i;
			if(n >= i){
				printf(" * ");
			}
		} 
		else i++;
	}
}
int main(){
hoang:
    int n;
    NhapDuLieu(n);
    InCacThuaSoNguyenTo(n);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim space de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if( lc == 32){
		goto hoang;
	}
    return 0;
}
