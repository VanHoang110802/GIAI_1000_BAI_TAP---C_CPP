Hãy đếm số lượng giá trị trong mảng thỏa tính chất :"lớn hơn tất cả các giá trị đứng đằng trước nó".

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
int DemPhanTuLonNhatDungSau(int a[], int n){
	int dem = 0;
	for (int i = 1; i < n; i++){
		int check = 1;
		for (int j = 0; j < i; j++){
			if (a[i] < a[j] || a[i] == a[j]){
				check = 0;
			}
		}
		if (check == 1){
			dem++;
		}
	}
	return dem;
}
int main(){
	int n, a[Max];
hoang:
	NhapDuLieu(n);
	NhapMang(a, n);
	XuatMang(a, n);
	int dem = DemPhanTuLonNhatDungSau(a, n);
	printf("\nCo %d so luong thoa man.", dem);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
