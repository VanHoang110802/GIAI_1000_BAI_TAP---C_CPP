Liệt kê tất cả các ước số của số nguyên dương n.
/*
n = 10 -> ước số là những số nó có thể chia hết được: 1,2,5,10.
*/
#include <stdio.h>
#include<conio.h>
void NhapDuLieu(int &n){
	printf("Nhap so: ");
	scanf("%d", &n);
}
void LietKe(int n){
	for(int i =1; i <= n;i++){
		if(n % i == 0){
			printf(" %d ", i);
		}
	}
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
	LietKe(n);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim space de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if( lc == 32){
		goto hoang;
	}
	return 0;
}
