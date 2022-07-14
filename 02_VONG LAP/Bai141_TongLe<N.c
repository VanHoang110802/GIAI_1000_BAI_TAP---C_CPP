Viết chương trình tính tổng các giá trị lẻ nguyên dương nhỏ hơn N.
/*
n = 1234567890
-> s = 1 + 3 + 5 + 7 + 9 = 25
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
	int temp = n,tong = 0;
	for(int i = 1; i < n;i++){
		if(i%2!=0){
			tong +=i;
		}
	}
	printf("Tong cac gia tri le la %d ",tong);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
