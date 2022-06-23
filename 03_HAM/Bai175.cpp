Lấy ra chữ số ở vị trí nào đó (tính từ trái sang phải) của một số tự nhiên.

vd: Nhập số tự nhiên: 1410
Bạn muốn lấy chữ số ở vị trí nào thứ:3
Chữ số ở vị trí thứ 3 (từ trái sang phải) của số 1410 là : 1

/*
Ta coi số trên giả sử là: abcd

tính từ trái sang phải thì:
a= 1 là vị trí 1
b= 4 là vị trí 2
c= 1 là vị trí 3
d= 0 là vị trí 4

tính từ phải sang trái thì:
vị trí 4 là a= 0
vị trí 3 là b= 1
vị trí 2 là c= 4
vị trí 1 là d= 1

ta thấy các vị trí tương ứng cộng lại với nhau luôn là 5, mà hiểu 5 chính là số chữ số + 1 
*/

#include<stdio.h>
#include<conio.h>
#include<math.h>
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
int TimLayChuSoTuTraiSangPhai(int n, int vitricantim){
	return TimLayChuSoTuPhaiSangTrai(n, log10((double)n) + 2 - vitricantim);
}

int main(){
	int n, vitricantim;
	NhapDuLieu(n, vitricantim);
	int tim1 = TimLayChuSoTuTraiSangPhai(n, vitricantim);
	printf("\n\nChu so tim duoc tu trai sang phai la: %d", tim1);
	return 0;
}
