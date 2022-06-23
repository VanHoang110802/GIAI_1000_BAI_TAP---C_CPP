Hãy kiểm tra mảng số nguyên có tồn tại hai giá trị 0 liên tiếp hay không ? .

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
int KiemTraCo2GiaTri0LienTiep(int a[], int n){
	int check = 0; 
	for (int i = 0; i < n; i++){
		if (a[i] == 0 && a[i + 1] == 0){
			check = 1;
			break;
		}
	}
	return check;
}
int main(){
	int n,a[Max];
hoang:
	NhapDuLieu(n);
	NhapMang(a, n);
	XuatMang(a, n);
	printf("\nKiem tra mang co 2 so 0 lien toi hay khong?\n1-CO\n0-KHONG CO");
	int kt = KiemTraCo2GiaTri0LienTiep(a, n);
	printf("\n\n%d", kt);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
