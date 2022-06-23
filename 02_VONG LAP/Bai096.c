Tính S(n) = √𝑥n + √𝑥n−1 + √𝑥n−2 + ⋯ √𝑥2 + √𝑥 có n dấu căn.


#include<stdio.h>
#include<conio.h>
#include<math.h>
int main(){
hoang:
    int n;
    float x;
    do{
    	printf("Nhap x= ");
    	scanf("%f", &x);
    	if(x < 0){
        	printf("x khong hop le. Xin nhap lai !\n");
    	}
    }while(x < 0);
    do{
    	printf("Nhap n=  ");
    	scanf("%d", &n);
   		if(n < 1){
          	printf("n khong hop le. Xin nhap lai !\n");
      	}
    }while(n < 1);
   
    float s=sqrt(x);
	for(int i=2;i<=n;i++)
	{
		s=sqrt(pow(x,i)+s);
	}
	printf("Ket qua la: %.3f",s);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
    return 0;
}
