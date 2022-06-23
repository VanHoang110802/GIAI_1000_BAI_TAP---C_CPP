Hãy đếm số lượng chữ số của số nguyên dương n.
/*
n = 1234566
-> số có 7 chữ số. 
- Có 2 cách. 
-> cách 1: /10 rồi đếm, cho đến khi bằng 0 thì dừng lại, ta đc số lượng chữ số cần tìm.
-> cách 2: dùng công thức toán học log để tính sai số, từ sai số gần đúng thì được số lượng chữ số cần tìm.
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
		// cách 1: 
	int dem = 0, temp = n;
	while(temp != 0){
		temp /=10;
		dem++;
	}
		// cách 2: 
	/*
		// Nhớ include<math.h> để tính log10.
		int dem = log10((double)n) + 1;
	*/
	printf("So %d có %d chu so!",n, dem);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
