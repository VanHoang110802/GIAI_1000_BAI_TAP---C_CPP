Cho mảng một chiều các số nguyên.Hãy viết hàm tìm số chẵn lớn nhất nhỏ hơn mọi giá trị lẻ có trong mảng.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<conio.h>
#define Max 100
void NhapDuLieu(int& n) {
    do {
        printf("Nhap so luong phan tu: ");
        scanf("%d", &n);
        if (n<1||n>Max) {
            printf("Phan tu nhap khong hop le, xin hay kiem tra lai!\n");
        }
    } while (n<1||n>Max);
}
void NhapMang(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("a[%d]= ", i);
        scanf("%d", &a[i]);
    }
}
void XuatMang(int a[], int n){
    for (int i = 0; i < n; i++) {
        printf("%d  ", a[i]);
    }
}
int TimViTriLeDauTien(int a[], int n){
    for (int i = 0; i < n; i++){
        if (a[i] % 2 != 0){
            return i;
        }
    }
    return -1;
}
int TimSoLeNhoNhat(int a[], int n){
    int ViTriDauTien = TimViTriLeDauTien(a, n);
    int MinLe = a[ViTriDauTien];

    for (int i = ViTriDauTien + 1; i < n; i++){
        if (a[i] % 2 != 0 && a[i] < MinLe) {
            MinLe = a[i];
        }
    }
    if (ViTriDauTien > -1) return MinLe - 1;
     else return 0;
}

int main() {
    int a[Max], n;
hoang:
    NhapDuLieu(n);
    NhapMang(a, n);
    XuatMang(a, n);
    int tim = TimSoLeNhoNhat(a, n);
    printf("\nSo chan lon nhat ma nho hon so le la: %d", tim);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
    return 0;
}
