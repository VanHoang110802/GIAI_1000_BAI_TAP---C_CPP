Tìm số nguyên dương n nhỏ nhất sao cho 1 + 2 + … + n > 10000.

#include<stdio.h>
#include<conio.h>
int main(){
hoang:
    int S = 0;
    int n = 0;
    while(S < 10000){
        n++;
        S = S + n;
    }
    printf("Tong la %d", S);
    printf("\nSo n la %d", n);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
    return 0;
}
