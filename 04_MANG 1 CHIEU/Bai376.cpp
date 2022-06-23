Cho hai mảng số thực a,b.Đếm số lượng giá trị chỉ xuất hiện một trong hai mảng.

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
int DemPhanTuChiXuatHien1Trong2Mang(int a[], int b[], int na, int nb){
	int check, dem = 0;
	for (int i = 0; i < na; i++){
		check = 1;
		for (int j = 0; j < nb; j++){
			if (a[i] == b[j]){
				check = 0;
				break;
			}
		}
		if (check == 1){
			dem++;
		}
	}
	for (int i = 0; i < nb; i++){
		check = 1;
		for (int j = 0; j < na; j++){
			if (b[j] == a[i]){
				check = 0;
				break;
			}
		}
		if (check == 1){
			dem++;
		}
	}
	return dem;
}
int main(){
	int n,m, a[Max],b[Max];
hoang:
	printf("\n");
	NhapDuLieu(n);
	NhapMang(a, n);
	printf("\n");
	NhapDuLieu(m);
	NhapMang(b, m);
	printf("\nMang A:\n");
	XuatMang(a, n);
	printf("\nMang B:\n");
	XuatMang(b, m);
	printf("\n");
	int dem = DemPhanTuChiXuatHien1Trong2Mang(a, b,n,m);
	printf("\n-> %d", dem);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
