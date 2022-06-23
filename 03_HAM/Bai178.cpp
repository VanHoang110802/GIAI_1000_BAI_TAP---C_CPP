Kiểm tra số nguyên 4 byte có dạng 2^k hay không ? Biết k sẽ là 1 số bất kỳ nào đó bắt đầu từ 0 -->
vd1: Nhập số 4 => 4 thỏa có dạng là 2^2.
vd2: Nhập số 5 => 5 không thỏa.

#include<stdio.h>
#include<conio.h>
#include<math.h>

void NhapDuLieu(int &n){
	printf("Nhap so can tim co dang mu 2: ");
	scanf("%d", &n);
}
int KiemTraDangMuK(int n){
	float ketqua = log10((double)n) / log10(2.0);
	if(ketqua == (int)ketqua){
		return 1;
	} 
	return 0;
}
int main(){	
hoang:
	int n;
	NhapDuLieu(n);
	int kiemtra = KiemTraDangMuK(n);
	if(kiemtra == 1){
		printf("Co dang 2^k");
	} else {
		printf("Khong co dang 2^k");
	}
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim space de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if( lc == 32){
		goto hoang;
	}
	return 0;
}
