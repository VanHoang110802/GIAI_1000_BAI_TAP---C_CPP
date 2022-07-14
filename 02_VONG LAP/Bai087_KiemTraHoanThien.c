Cho số nguyên dương n. Kiểm tra số dương n có phải là số hoàn thiện
hay không?
/*Số hoàn hảo (hay còn gọi là số hoàn chỉnh, số hoàn thiện hoặc số hoàn thành) là một số nguyên dương mà tổng các 
ước nguyên dương chính thức của nó (số nguyên dương bị nó chia hết ngoại trừ nó) bằng chính nó.

6: 1 + 2 + 3 = 6
28: 1 + 2 + 4 + 7 + 14 = 28
496: 1 + 2 + 4 + 8 + 16 + 31 + 62 + 124 + 248 = 496
8128: 1 + 2 + 4 + 8 + 16 + 32 + 64 + 127 + 254 + 508 + 1016 + 2032 + 4064 = 8128

đầu tiên ta có 1 biến tổng, tổng += i, rồi sau đó so sánh xem tông đó có bằng n ban đầu hay không? Nếu thỏa thì in 
nó là số hoàn hảo, còn không thì ngược lại.
*/
#include <stdio.h>
#include <conio.h>
int main(){
hoang:
	int n;
	do{
		printf("Nhap n= ");
		scanf("%d", &n);
		if(n<=0){
			printf("n > 0, xin hay kiem tra lai!\n");
		}
	}while(n<=0);
	int s = 0;
	for(int i =1 ;i<n;i++){
		if(n%i==0){
			s+=i;
		}
	}
	if(s== n){
		printf("Day la so hoan thien!");
	} else {
		printf("Day khong la so hoan thien!");
	}
	
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
