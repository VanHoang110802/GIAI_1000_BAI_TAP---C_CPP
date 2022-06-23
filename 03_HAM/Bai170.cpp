Kiểm tra xem một số nguyên dương n có phải là số hoàn hảo hay không? (Số hoàn hảo là số có tổng tất cả các 
ước số nhỏ hơn nó bằng chính nó).

vd: Số 6 có các ước nhỏ hơn nó là: 1, 2, 3
và 1 + 2 + 3 = 6
=> 6 là số hoàn hảo

#include<stdio.h>
#include<conio.h>
#include<math.h>
void NhapDuLieu(int &x){
	printf("Nhap so = ");
	scanf("%d", &x);
}
int KiemTraSoHoanHao(int n){
	int s = 0;
	for(int i = n/2;i>= 1;i--){
		if(n % i == 0){
			s+=i;
		}
	}
	if(n == s){
		return 1;
	} 
	return 0;
}
int main(){
hoang:
	int n;
	NhapDuLieu(n);
	int kiemtra = KiemTraSoHoanHao(n);
	if(kiemtra == 1){
		printf("Day la so hoan hao!");
	} else printf("Day khong la so hoan hao");
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim space de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if( lc == 32){
		goto hoang;
	}
	return 0;
}
