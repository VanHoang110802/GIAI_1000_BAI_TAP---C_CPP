Tính S(n) = 𝑛+1√𝑛 + 𝑛√𝑛 − 1 + 3√2 + √1 có n dấu căn.

#include<stdio.h>
#include<conio.h>
#include<math.h>
int main(){
hoang:
    int n;
    do{
        printf("Nhap n= ");
        scanf("%d", &n);
        if(n < 1){
            printf("n phai >= 1. Xin nhap lai !\n");
        }
    }while(n < 1); 
    float s=sqrt(1.0);
	for(int i=2;i<=n;i++){
		s=pow(1.0*(i+s),1.0/(i+1));
	}
	printf("\nKet qua la: %.3f",s);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
    return 0;
}
