Viết chương trình tìm số nguyên dương m lớn nhất sao cho
1 + 2 + 3 + … + m < N.

#include<stdio.h>
#include<conio.h>
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
    	int S = 0;
   	int m = 0;
    	do{
        	m = m + 1;
        	S = S + m;
    	}while(S + m + 1 < n);
    	printf("\nSo nguyen duong m la %d", m);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
    	return 0;
}
