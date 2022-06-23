Hãy kiểm tra mảng số nguyên có thỏa mãn tính chất sau không : "Mảng không có tồn tại số hoàn thiện lớn hơn 256".Nếu thỏa trả về 1,nếu không trả về 0 .

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
int KiemTraHoanThien(int n){
	int s = 0, temp = n;
	for (int i = 1; i < temp; i++){
		if (temp % i == 0){
			s += i;
		}
	}
	if (s == n){
		return 1;
	}
	else return 0;
}
int KiemTraMangKhongCoSoHoanThienLonHon256(int a[], int n)
{
	int check = 0;
	for (int i = 0; i < n; i++){
		if (KiemTraHoanThien(a[i]) == 1 && a[i] < 256){
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
	printf("\nKiem tra mang co gia tri hoan thien > 256 hay khong?\n1-CO\n0-KHONG CO\n");
	int kt = KiemTraMangKhongCoSoHoanThienLonHon256(a, n);
	printf("\n%d", kt);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
