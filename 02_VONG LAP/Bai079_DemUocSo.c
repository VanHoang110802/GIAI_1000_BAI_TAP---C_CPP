Đếm số lượng “ước số” của số nguyên dương n.

/*
n = 20 -> ước số là những số nó có thể chia hết được: 1,2,4,5,10,20.
cứ mỗi lần xét được 1 ước, tăng đếm lên 1 -> in ra màn hình số lần đã đếm được.
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
	int dem = 0;
	for(int i =1; i <= n;i++){
		if(n % i == 0){
			dem++;
		}
	}
	printf("So %d co tat ca %d uoc!",n, dem);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
