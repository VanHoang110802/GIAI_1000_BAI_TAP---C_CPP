Hãy liệt kê các giá trị xuất hiện trong mảng một chiều các số nguyên đúng một lần .
/*
Nếu phần tử nào bị trùng thì sẽ bỏ qua, không cần đếm lần nữa.
mảng: 1 2 3 3 2 4 5 3 2 1 4 5
-> 1 2 3 4 5
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
int KiemTraBiTrung(int a[], int n, int ViTri){
	for (int i = ViTri - 1; i >= 0; i--){
		if (a[i] == a[ViTri]){
			return 0;  // bị trùng
		}
	}
	return 1;         // không bị trùng
}
// Đếm xem từ vị trí hiện tại trở về sau có bao nhiêu phần tử bị trùng
int DemSoLuongPhanTuTrung(int a[], int n, int ViTri){
	int dem = 1;
	for (int i = ViTri + 1; i < n; i++){
		if (a[i] == a[ViTri]){
			dem++;
		}
	}
	return dem;
}
void LietKeCacGiaTriXuatHienDung1Lan(int a[], int n){
	for (int i = 0; i < n; i++){
		int CheckTrung = KiemTraBiTrung(a, n, i);
		if (CheckTrung == 1){
			int dem = DemSoLuongPhanTuTrung(a, n, i);
			if (dem == 1){
				printf("%d ", a[i]);
			}
		}
	}
}

int main(){
	int n, a[Max];
hoang:
	NhapDuLieu(n);
	NhapMang(a, n);
	XuatMang(a, n);
	printf("\n");
	LietKeCacGiaTriXuatHienDung1Lan(a, n);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
