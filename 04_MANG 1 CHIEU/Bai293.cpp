Cho mảng một chiều các số thực.Hãy viết hàm tìm một vị trí trong mảng thỏa hai điều kiện:Có hai giá trị lân cận và giá trị tại vị trí đó bằng tích hai giá trị lân cận.Nếu như mảng không tồn tại giá trị như vậy thì hàm trả về giá trị -1.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<conio.h>
#define Max 100
void NhapDuLieu(float& n) {
	do {
		printf("Nhap so luong phan tu: ");
		scanf("%f", &n);
		if (n<1||n>Max) {
			printf("So luong phan tu nhap khong hop le!\n");
		}
	} while (n<1||n>Max);
}
void NhapMang(float a[], float n) {
	for (int i = 0; i < n; i++) {
		printf("a[%d]= ", i);
		scanf("%f", &a[i]);
	}
}
void XuatMang(float a[], float n) {
	for (int i = 0; i < n; i++) {
		printf("%.2f  ", a[i]);
	}
}
float TimGiaTriSoLanCan(float a[], float n) {
	for (int i = 1; i < n - 1; i++) {
		float tich = a[i - 1] * a[i + 1];
		if (tich == a[i]) {
			return i;
		}
	}
	return -1;
}
int main() {
	float a[Max], n;
hoang:
	NhapDuLieu(n);
	NhapMang(a, n);
	XuatMang(a, n);
	printf("\n");
	float tim = TimGiaTriSoLanCan(a, n);
	printf("\nVi tri thoa man dieu kien de bai: %.2f",tim);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
