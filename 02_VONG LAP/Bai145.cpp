Viết chương trình in ra tất cả các số lẻ nhỏ hơn 100 trừ các số 5, 7, 93.

#include <stdio.h>
#include <conio.h>
int main(){
hoang:
	for(int i = 0; i < 100;i++){
		if(i%2!=0 && i != 5 && i != 7 && i != 93){
			printf(" %d ", i);
		}
	}
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
