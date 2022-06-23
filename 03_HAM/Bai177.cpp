Liệt kê tất cả các số có 3 chữ số sao cho tổng lập phương của các chữ số bằng chính số đó
#include<stdio.h>
#include<conio.h>
#include<math.h>

void NhapDuLieu(int &n){
	printf("Nhap n= ");
	scanf("%d", &n);
}
int KiemTraTongLapPhuongCacCS(int n){
	int temp = n, s = 0;
	while( temp != 0){
		int chuso1 = temp % 10;
		temp/=10;
		s += pow(chuso1,3);
	}
	if(s == n){
		return 1;
	}
	return 0;
}
void LietKe(int n){
	for(int i = 100; i< n;i++){
		ifKiemTraTongLapPhuongCacCS(i)){
			printf("%d ", i);
		}
	}
}
int main(){
hoang:
	int n;
	NhapDuLieu(n);
	LietKe(n);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim space de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if( lc == 32){
		goto hoang;
	}
	return 0;
}
