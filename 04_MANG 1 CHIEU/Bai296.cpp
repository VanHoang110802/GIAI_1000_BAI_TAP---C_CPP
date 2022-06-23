Hãy tìm giá trị đầu tiên trong mảng một chiều các số nguyên có chữ số đầu tiên là chữ số lẻ.Nếu mảng không tồn tại giá trị như vậy thì hàm sẽ trả về giá trị 0.
/*
-> xét 1 số bất kì, rồi lấy số đó chia cho 10^(số chữ số -1) thì sẽ được chữ số đầu tiên, chữ số đầu tiên là lẻ thì xong bài :vv.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<conio.h>
#include<math.h>
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
int TachSo(int n) {
    int check = 0, temp = n;
    int dem = log10((double)temp);
    int sodao = 0;
    while (temp != 0) {
        int chuso = temp % 10;
        temp /= 10;
        sodao += chuso * pow(10.0, dem--);
    }
    int chuso = sodao % 10;
    if (chuso % 2 == 0) {
        return 0;
    }
    else return 1;
}
int TimChuSoLeDauTien(int a[], int n) {
    for (int i = 0; i < n; i++) {
        if (TachSo(a[i])) {
            return a[i];
        }
    }
    return 0;
}
int main() {
    int a[Max], n;
hoang:
    NhapDuLieu(n);
    NhapMang(a, n);
    XuatMang(a, n);
    int tim = TimChuSoLeDauTien(a, n);
    printf("\nGia tri thoa man yeu cau de bai: %d", tim);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
    return 0;
}
