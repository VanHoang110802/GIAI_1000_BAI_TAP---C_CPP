Tìm ra số nguyên dương n nhỏ nhất sao cho 1+2+3+...+n >10000 .

#include<stdio.h>
#include<conio.h>
int TinhTong(){
	int S = 0;
    	int n = 0;
    	while(S <= 10000 ){
        	n++;
        	S = S + n;
        }
	return S;
}
int main(){
hoang:
    int n;
    int tong = TinhTong(n);
    printf("So n la %d", n);
    printf("\nTong = %d", tong);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim space de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if( lc == 32){
		goto hoang;
	}
    return 0;
}
