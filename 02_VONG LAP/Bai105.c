Cho số nguyên dương n. Hãy tìm chữ số đầu tiên của n.
/*
n = 23587 -> chữ số đầu tiên n = 2.
*/
#include <stdio.h>
#include <conio.h>
#include <math.h>
int main(){
hoang:
	int n;
	do{
		printf("Nhap n= ");
		scanf("%d",&n);
		if(n<=0){
			printf("n > 0, xin hay kiem tra lai!\n");
		}
	}while(n<=0);
	int temp = n,soluongchuso =0;
	while(temp !=0){
		int cs = temp % 10;
		temp /= 10;
		soluongchuso++;
	}
	temp = n;
	int cs = temp/ pow(10.0, --soluongchuso);
	printf("Chu so dau cu so %d la: %d",n,cs);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
