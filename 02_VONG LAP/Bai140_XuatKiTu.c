Hãy sử dụng vòng lặp for để xuất tất cả các ký tự A tới Z.
#include <stdio.h>
#include <conio.h>
int main(){
hoang:
	for(int i = 65;i< 91;i++){
		printf("%c",i);
	}
	return 0;
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
}
