In tất cả các số nguyên dương lẻ nhỏ hơn 100.
/*
n = 1,3,5,7,11,...99.
*/
#include <stdio.h>
#include <conio.h>
int main(){
hoang:
	for(int i = 0; i < 100;i++){
		if(i%2!=0){
			printf(" %d ", i);
		}
	}
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
