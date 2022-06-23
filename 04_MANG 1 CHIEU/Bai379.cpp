Hãy tìm một giá trị có số lần xuất hiện nhiều nhất trong mảng các số nguyên .

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
int TimTanSuatXuatHienMax(int a[], int n){
	int max = 1;  // 1 phần tử tối thiêu xuất hiện
	for (int i = 0; i < n; i++){
		int dem = 1; // Tính chính nó
		for (int j = i + 1; j < n; j++){
			if (a[i] == a[j]){
				dem++;
			}
		}
		if (dem > max){
			max = dem;
		}
	}
	return max;
}

int KiemTraBiTrung(int a[], int n, int x){
	for (int i = x - 1; i >= 0; i--){
		if (a[i] == a[x]){
			return 0; // Bị trùng
		}
	}
	return 1; // Không bị trùng
}

int DemTanSuatXuatHien(int a[], int n, int x){
	int dem = 1; // Tính luôn chính nó 
	for (int i = x + 1; i < n; i++){
		if (a[i] == a[x]){
			dem++;
		}
	}
	return dem;
}

void LietKeCacSoXuatHienNhieuNhat(int a[], int n){
	int TanSuatMax = TimTanSuatXuatHienMax(a, n);
	for (int i = 0; i < n; i++){
		int CheckTrung = KiemTraBiTrung(a, n, i);
		if (CheckTrung == 1) {		// chỉ xử lý khi không trùng
			int TanSuat = DemTanSuatXuatHien(a, n, i);
			if (TanSuat == TanSuatMax){
				printf("\nPhan tu xuat hien nhieu nhat la %d", a[i]);
			}
		}
	}
	printf("\n-> So lan xuat hien la: %d", TanSuatMax);
}
int main(){
	int n, a[Max];
hoang:
	NhapDuLieu(n);
	NhapMang(a, n);
	XuatMang(a, n);
	printf("\n");
	LietKeCacSoXuatHienNhieuNhat(a, n);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
