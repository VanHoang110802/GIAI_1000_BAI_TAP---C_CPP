Kiểm tra số nguyên 4 byte có dạng a^k hay không ? với a là số nhập vào từ bàn phím (2 <= a <= 9). Biết k sẽ 
là 1 số bất kỳ nào đó bắt đầu từ 0 -->
vd1: Nhập số 4 và a = 3 => không thỏa
vd2: Nhập số 4 và a = 2 => thỏa

#include<stdio.h>
#include<conio.h>
#include<math.h>

void NhapDuLieu(int &n, int &a){
	printf("Nhap so can tim mu: ");
	scanf("%d", &n);
	printf("Nhap so mu: ");
	scanf("%d", &a);
}
int KiemTraDangMuK(int n, int a){
	float ketqua = log10((double)n) / log10(a);
	if(ketqua == (int)ketqua){
		return 1;
	} 
	return 0;
}
int main(){	
hoang:
	int n,a;
	NhapDuLieu(n,a);
	int kiemtra = KiemTraDangMuK(n,a);
	if(kiemtra == 1){
		printf("Co dang a^k");
	} else {
		printf("Khong co dang a^k");
	}
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim space de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if( lc == 32){
		goto hoang;
	}
	return 0;
}
