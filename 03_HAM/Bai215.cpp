Cho số nguyên dương n. Kiểm tra số dương n có phải là số hoàn thiện
hay không?
/*Số hoàn hảo (hay còn gọi là số hoàn chỉnh, số hoàn thiện hoặc số hoàn thành) là một số nguyên dương mà tổng các 
ước nguyên dương chính thức của nó (số nguyên dương bị nó chia hết ngoại trừ nó) bằng chính nó.

#include<stdio.h>
#include<conio.h>
void NhapDuLieu(int &n){
	printf("Nhap so: ");
	scanf("%d", &n);
}
int KiemTraSoHoanHao(int n){
	int s = 0;
	for(int i =1 ;i<n;i++){
		if(n%i==0){
			s+=i;
		}
	}
	if(s== n){
		return 1;
	} 
	return 0;
}
int main(){
hoang:
	int n;
	do{
	NhapDuLieu(n);
	if(n<= 0){
		printf("n > 0. Xin hay nhap lai!\n");
	}
	}while(n<= 0);
	int kiemtra = KiemTraSoHoanHao(n);
	if(kiemtra == 1){
		printf("Day la so hoan thien!");
	} else {
		printf("Day khong la so hoan thien!");
	}
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim space de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if( lc == 32){
		goto hoang;
	}
	return 0;
}
