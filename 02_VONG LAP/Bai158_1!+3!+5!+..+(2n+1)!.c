Viết chương trình tính : 1! + 3! + 5 ! + ... + (2n+1)!

#include<stdio.h>
#include <conio.h>
#include<math.h>
int main(){
hoang:
	int n;
	do{
		printf("Nhap n= ");
		scanf("%d", &n);
		if(n<=0){
			printf("N nhap khong hop le, xin hay kiem tra lai!\n");
		}
	}while(n<=0);
	
	long long int s = 1, s2 = 1;
	for(int i=1;i<n;i++)
	{
		int temp = 2 * i + 1;		
		s *= temp * (temp - 1);	
		s2 += s;	
	}
	//printf("\n%d", s);
	printf("\n%lli", s2);	
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
