Cho mảng một chiều các số nguyên.Hãy viết hàm tìm số nguyên tố nhỏ nhất lớn hơn mọi giá trị có trong mảng.

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
void XuatMang(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d  ", a[i]);
    }
}
int KiemTraSoNT(int n) {
    int temp = n, check = 1;
    if (temp < 2) {
        check = 0;
    } else {
        if (temp > 2 && temp % 2 == 0) {
            check = 0;
        }
        else {
            for (int i = 2; i * i <= temp; i++) {
                if (n % i == 0) {
                    check = 0;
                    break;
                }
            }
        }
    }
    if (check == 1 && n >= 2) {
        return 1;
    }
    else return 0;
}
int TimSoLonNhatTrongMang(int a[], int n){
    int max = a[0];
    for (int i = 1; i < n; i++){
        if (a[i] > max){
            max = a[i];
        }
    }
    return max;
}
int TimSoNTNhoNhatNhungLonHonCacGiaTriTrongMang(int a[], int n) {
    int max = TimSoLonNhatTrongMang(a, n);
    for (int i = max + 1; ; i++) {   // không cần điều kiện lặp vì chưa biết người dùng nhập số muốn tìm là bao nhiêu
        if (i > max) {
            if (KiemTraSoNT(i)) {
                return i;
            }
        }
    }
}
int main() {
    int a[Max], n;
hoang:
    NhapDuLieu(n);
    NhapMang(a, n);
    XuatMang(a, n);
    int tim = TimSoNTNhoNhatNhungLonHonCacGiaTriTrongMang(a,n);
    printf("\nSo nguyen to nho nhat nhung lon hon cac gia tri trong mang: %d", tim);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
    return 0;
}
