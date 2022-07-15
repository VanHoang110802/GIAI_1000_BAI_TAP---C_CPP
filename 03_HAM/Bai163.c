Bài tập chương Câu lệnh lặp. Hàm nhận vào một
số nguyên dương n và thực hiện:
a. S = 1 + 2 + … + n

#include<stdio.h>
#include<conio.h>
int TinhTong(int n){
	int s = 0;
	for(int i = 1;i<=n;i++){
		s+= i;
	}
	return s;
}
int main(){
hoang:
	int n;
	do{
		printf("Nhap n= ");
		scanf("%d", &n);
		if(n<=0){
			printf("n>0, xin hay kiem tra lai!\n");
		}
	}while(n<=0);
	int tinh = TinhTong(n);
	printf("Tong = %d", tinh);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim space de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if( lc == 32){
		goto hoang;
	}
	return 0;
}

		-----------------------
b. S = 1^2 + 2^2 + … + n^2

#include <stdio.h>
#include <conio.h>
int TinhTong(int n){
	int s = 0;
	for(int i =1;i<=n;i++){
		s+=i*i;
	}
	return s;
}
int main(){
hoang:
	int n;
	do{
		printf("Nhap n= ");
		scanf("%d", &n);
		if(n<=0){
			printf("n>0, xin hay kiem tra lai!\n");
		}
	}while(n<=0);
	int tinh = TinhTong(n);
	printf("Tong = %d", tinh);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim space de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if( lc == 32){
		goto hoang;
	}
	return 0;
}

		-------------------------
c. S = 1 + 1/2 + … + 1/n

#include<stdio.h>
#include<conio.h>
float TinhTong(int n){
	float s = 0;
	for(int i =1;i<=n;i++){
		s+= 1.0 / i;
	}
	return s;
}
int main(){	
hoang:
	int n;
	do{
		printf("Nhap n= ");
		scanf("%d", &n);
		if(n<=0){
			printf("n>0, xin hay kiem tra lai!\n");
		}
	}while(n<=0);
	float tinh = TinhTong(n);
	printf("Tong = %.3f", tinh);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim space de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if( lc == 32){
		goto hoang;
	}
	return 0;
}

		---------------------
d. S = 1 * 2 * … * n

#include <stdio.h>
#include <conio.h>
int TinhTich(int n){
	int s = 1;
	for(int i =1;i<=n;i++){
		s*=i;
	}
	return s;
}
int main(){
hoang:
	int n;
	do{
		printf("Nhap n= ");
		scanf("%d", &n);
		if(n<=0){
			printf("n>0, xin hay kiem tra lai!\n");
		}
	}while(n<=0);
	int tich = TinhTich(n);
	printf("Tong = %d", tich);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim space de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if( lc == 32){
		goto hoang;
	}
	return 0;
}

		---------------------
e. S = 1! + 2! + … + n!

#include <stdio.h>
#include <conio.h>
int TinhTich(int n){
	int s = 1,s2 = 0;
	for(int i =1;i<=n;i++){
		s*=i;
		s2 += s;
	}
	return s2;
}
int main(){
hoang:
	int n;
	do{
		printf("Nhap n= ");
		scanf("%d", &n);
		if(n<=0){
			printf("n>0, xin hay kiem tra lai!\n");
		}
	}while(n<=0);
	int tich = TinhTich(n);
	printf("Tong = %d", tich);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim space de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if( lc == 32){
		goto hoang;
	}
	return 0;
}
