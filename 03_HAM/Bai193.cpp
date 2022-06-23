Viết chương trình tìm số nguyên dương m lớn nhất sao cho
1 + 2 + 3 + … + m < N.

#include<stdio.h>
#include<conio.h>
void NhapDuLieu(int &n){
	printf("Nhap n= ");
	scanf("%d",&n);
}
int TimM(int n){
	int S = 0;
   	int m = 0;
    	do{
        	m = m + 1;
        	S = S + m;
    	}while(S + m + 1 < n);
	return m;
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
    	int m = TimM(n);
    	printf("\nSo nguyen duong m la %d", m);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim space de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if( lc == 32){
		goto hoang;
	}
    	return 0;
}
