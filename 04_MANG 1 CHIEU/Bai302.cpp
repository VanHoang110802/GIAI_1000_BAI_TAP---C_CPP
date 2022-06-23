Cho mảng một chiều các số nguyên dương.Hãy viết hàm tìm ước chung lớn nhất của tất cả các phần tử trong mảng .

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
int TimSoNhoNhat(int a[], int n){
    int min = a[0];
    for (int i = 1; i < n; i++){
        if (a[i] < min)
        {
            min = a[i];       //min = (min < a[i])? min: a[i];
        }
    }
    return min;
}
int KiemTraChiaHetChoUoc(int a[], int n, int UocSo){
    for (int i = 0; i < n; i++){
        if (a[i] % UocSo != 0){
            return 0;
        }
    }
    return 1;
}
int TimUCLNCuaMang(int a[], int n){
    int min = TimSoNhoNhat(a, n);
    for (int i = min/2; i > 0; i--){
        if (KiemTraChiaHetChoUoc(a, n, i)) return i;
    }
    return min;
}
int main() {
    int a[Max], n;
hoang:
    NhapDuLieu(n);
    NhapMang(a, n);
    XuatMang(a, n);
    int tim = TimUCLNCuaMang(a,n);
    printf("\nUCLN cua cac phan tu trong mang: %d", tim);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
    return 0;
}
