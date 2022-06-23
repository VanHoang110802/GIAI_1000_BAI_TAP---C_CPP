Cho mảng một chiều các số nguyên.Hãy viết hàm tìm giá trị lớn nhất trong mảng có dạng 5^k.Nếu mảng không tồn tại giá trị có dạng 5^k thì hàm sẽ trả về giá trị 0.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<conio.h>
#include <math.h>
#define Max 100
void NhapDuLieu(int& n) {
	do {
		printf("Nhap so luong phan tu: ");
		scanf("%d", &n);
		if (n<1 || n>Max) {
			printf("So luong phan tu nhap khong hop le!\n");
		}
	} while (n<1 || n>Max);
}
void NhapMang(int a[], int n) {
	for (int i = 0; i < n; i++) {
		printf("a[%d]= ", i);
		scanf("%d", &a[i]);
	}
}
void XuatMang(int a[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
}
int KiemTraDang5K(int n){
	if (n <= 1) return 1;
	while (n > 1) {  // vòng lặp kết thúc khi n == 5
		if (n % 5 != 0)  return 0;// Có thể viết n % 5
	
		n /= 5;
	}
	return 1;
}

int TimGiaTri5kLonNhat(int a[], int n){
	int max;
	int dem = 0;
	for (int i = 0; i < n; i++){
		if (KiemTraDang5K(a[i]) == 1){
			max = a[i];
			dem++;
			break;
		}
	}
	if (dem == 0) return 0;

	for (int i = 0; i < n; i++)
		if (KiemTraDang5K(a[i]) == 1) max = (max > a[i]) ? max : a[i];

	return max;
}
int main() {
	int a[Max], n;
hoang:
	NhapDuLieu(n);
	NhapMang(a, n);
	XuatMang(a, n);
	int tim = TimGiaTri5kLonNhat(a, n);
	printf("\nGia tri lon nhat co dang 5^k: %d", tim);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if (lc == 'c' || lc == 'C') {
		goto hoang;
	}
	return 0;
}
