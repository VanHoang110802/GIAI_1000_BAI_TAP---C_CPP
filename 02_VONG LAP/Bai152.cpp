Viết chương trình in bảng cửu chương ra màn hình.

#include <stdio.h>
#include <conio.h>
int main(){	
hoang:
	for(int i =1;i<=10;i++){
		printf("\n ");
		for(int j =1;j<=9;j++){
			printf("|%2d x %1d = %2d ", i,j,i*j);
		}
		printf("\n ");
	}
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
