Lấy ra chữ số ở vị trí nào đó (tính từ phải sang trái) của một số tự nhiên.

vd: Nhập số tự nhiên: 1410
Bạn muốn lấy chữ số ở vị trí nào thứ:3
Chữ số ở vị trí thứ 3 (từ phải sang trái) của số 1410 là : 4

#include<stdio.h>
#include<conio.h>
void NhapDuLieu(int &n, int &vitricantim){
	printf("Nhap so : ");
	scanf("%d", &n);
	printf("Nhap vi tri can tim : ");
	scanf("%d", &vitricantim);
}
int TimLayChuSoTuPhaiSangTrai(int n, int vitricantim){
	int dem =0;
	while(n!=0){
		int chuso = n % 10;
		n/=10;
		dem++;
		if(vitricantim == dem ){
			return chuso;
		}
	}
	return -1;
}
int main(){
	int n, vitricantim;
	NhapDuLieu(n, vitricantim);
	int tim = TimLayChuSoTuPhaiSangTrai(n, vitricantim);
	printf("Chu so tim duoc la: %d", tim);
	return 0;
}
