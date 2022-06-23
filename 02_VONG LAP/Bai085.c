Tìm ước số lẻ lớn nhất của số nguyên dương n. Ví dụ n = 100 ước lẻ
lớn nhất của 100 là 25.
/*
Ta xét n/2 trở về thôi, còn từ n/2 đổ lên chắc chắn không tìm được ước số của nó rồi.
n = 500 -> n = 500/2 = 250 -> ước số lẻ: 1, 5, 25, 125. -> ước số lẻ lớn cần tìm 125. 
*/

#include <stdio.h>
#include <conio.h>
int main(){
hoang:
	int n;
	do{
		printf("Nhap n= ");
		scanf("%d", &n);
		if(n <=0){
			printf("n > 0, xin hay nhap lai!\n");
		}
	}while(n<=0);
	for(int i =n / 2; i >= 1;i--){
		if(n % i == 0){
			if(i % 2 != 0){
				printf("%d",i);
				break;
			}
		}
	}
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}  
