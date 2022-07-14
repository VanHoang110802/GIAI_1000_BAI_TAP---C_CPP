Hãy kiểm tra số nguyên dương n có toàn chữ số chẵn hay không?
/*
n = 123456789 -> n có chữ số lẻ
n = 626486-> n toàn chữ số chẵn
*/
#include <stdio.h>
#include <conio.h>
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
	int temp = n, check = 1;
	while(temp != 0){
		int cs = temp % 10;
		temp /= 10;
		if(cs % 2 != 0){
			check = 0;
			break;
		}
	}
	if(check == 1){
		printf("n toan chu so chan!");
	} else {
		printf("n co chu so le!");
	}
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
