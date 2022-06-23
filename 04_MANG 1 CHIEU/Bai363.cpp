Hãy cho biết sự tương quan giữa số lượng số chẵn và số lượng số lẻ trong mảng các số nguyên
/*
mảng: 1 2 3 4 5 -> có 3 lẻ, 2 chẵn, lẻ nhiều hơn -> trả về 1
mảng: 1 2 3 4 6 -> có 3 chẵn, 2 lẻ, chẵn nhiều hơn -> trả về -1
mảng: 1 2 3 4 5 6 -> có 3 chẵn 3 lẻ, số lượng bằng nhau -> trả về 0.
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#define Max 100
void NhapDuLieu(int& n) {
	do {
		printf("Nhap so luong phan tu: ");
		scanf("%d", &n);
		if (n<1||n>Max) {
			printf("So luong phan tu nhap khong hop le, xin hay kiem tra lai!\n");
		}
	} while (n<1||n>Max);
}
void NhapMang(int a[], int n) {
	for (int i = 0; i < n; ++i) {
		printf("a[%d]= ", i);
		scanf("%d", &a[i]);
	}
}
void XuatMang(int a[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d  ", a[i]);
	}
}
int SoSanhChanLe(int a[], int n){
	int demsochan = 0;
	for (int i = 0; i < n; i++){
		if (a[i] % 2 == 0){
			demsochan++;
		}
	}
	if (demsochan > n - demsochan){
		return -1;
	}
	else if (n - demsochan == demsochan){
		return 0;
	}
	return 1;
}
int main(){
	int n,a[Max];
hoang:
	NhapDuLieu(n);
	NhapMang(a, n);
	XuatMang(a, n);
	int ss = SoSanhChanLe(a, n);
	printf("\nSo sanh so luong so chan va so le: ");
	printf("\n1 - Le nhieu hon chan\n0 - So luong nhu nhau khong hon khong kem\n-1 - Chan nhieu hon le");
	printf("\n\n--> %d", ss);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
