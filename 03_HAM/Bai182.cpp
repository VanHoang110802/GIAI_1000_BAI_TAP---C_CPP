Nhập vào 1 chữ số nguyên dương n,hãy tính:
a/ Đếm số lượng chữ số của nó.
b/ Liệt kê tất cả các chữ số của nó.
c/ Tính tổng tất cả các chữ số của nó.
d/ Tính tích tất cả các chữ số của nó.
e/ Liệt kê và đếm số lượng các chữ số lẻ của nó.
f/ Liệt kê và đếm số lượng các chữ số chẵn của nó.

#include<stdio.h>
#include<conio.h>
#include<math.h>
void NhapDuLieu(int &n){
	printf("Nhap so: ");
	scanf("%d", &n);
}
void DemSo(int n){
	int dem = log10((double)n) + 1;
	printf("\nSo co tat ca la %d chu so!", dem);
}
void LietKe(int n){
	printf("\n\nLiet ke: ");
	while(n!= 0){
		int chuso = n % 10;
		n/=10;
		printf("%d ", chuso);
	}
}
int TinhTong(int n){
	int s = 0;
	while(n!= 0){
		int chuso = n % 10;
		n/=10;
		s+= chuso;
	}
	return s;
}
int TinhTich(int n){
	int s = 1;
	while(n!= 0){
		int chuso = n % 10;
		n/=10;
		s*= chuso;
	}
	return s;
}
void LietKeSoLe(int n){
	printf("\n\nCac so le la: ");
	int dem = 0;
	while(n!= 0){
		int chuso = n % 10;
		n/=10;
		if(chuso %2 !=0) {
			dem++;
			printf("%d ", chuso);
		}
	}
	printf("\nSo co tat ca %d so le!", dem);
}
void LietKeSoChan(int n){
	printf("\n\nCac so chan la: ");
	int dem = 0;
	while(n!= 0){
		int chuso = n % 10;
		n/=10;
		if(chuso %2 ==0){
			dem++;
			printf("%d ", chuso);
		}
	}
	printf("\nSo co tat ca %d so chan!", dem);
}
int main(){
hoang:
	int n;
	NhapDuLieu(n);
	DemSo(n);
	LietKe(n);
	int tong = TinhTong(n);
	printf("\n\nTong = %d", tong);
	int tich = TinhTich(n);
	printf("\nTich = %d", tich);
	LietKeSoLe(n);
	LietKeSoChan(n);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim space de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if( lc == 32){
		goto hoang;
	}
	return 0;
}
