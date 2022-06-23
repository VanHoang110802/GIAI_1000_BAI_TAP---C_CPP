Cho hai mảng a,b.Liệt kê các giá trị chỉ xuất hiện 1 trong 2 mảng.

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
void LietKePhanTuXuatHien1Trong2Mang(int a[], int b[], int n, int m){
	int i, j, check;
	for (i = 0; i < n; i++){
		check = 1;
		for (j = 0; j < m; j++){
			if (a[i] == b[j]){
				check = 0;
				printf("Trong mang A co phan tu a[%d] = %d nam trong mang B\n", i, a[i]);
				break;
			}
		}
		if (check == 1) printf("Trong mang A co phan tu a[%d] = %d khong nam trong mang B\n", i,a[i]);
	}
	for (i = 0; i < m; i++){
		check = 1;
		for (j = 0; j < n; j++){
			if (b[i] == a[j]){
				check = 0;
				printf("Trong mang B co phan tu a[%d] = %d nam trong mang A\n", i, b[i]);
				break;
			}
		}
		if (check == 1) printf("Trong mang B co phan tu a[%d] = %d khong nam trong mang A\n",i, b[i]);
	}
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
	printf("\n\n");
	LietKePhanTuXuatHien1Trong2Mang(a, b,n,m);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
