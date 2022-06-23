Hãy tìm giá trị thỏa điều kiện toàn chữ số lẻ và là giá trị lớn nhất thỏa điều kiện ấy trong mảng một chiều các số nguyên (nếu mảng không có giá trị nào thỏa điều kiện như trên thì hàm sẽ trả về giá trị 0).
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
    int temp = n;
    int dem = log10((double)temp);
    int sodao = 0;
    while (temp != 0) {
        int chuso = temp % 10;
        temp /= 10;
        sodao += chuso * pow(10.0, dem--);
    }
    while (sodao != 0) {
        int chuso = sodao % 10;
        sodao /= 10;
        if (chuso % 2 == 0) {
            return 0;
        }
    }
    return 1;
}
int GiaTriFullLeMax(int a[], int n) {
    int max;
    int dem = 0;
    for (int i = 0; i < n; i++)
    {
        if (TachSo(a[i]) == 1)
        {
            max = a[i]; 
            dem++; 
            break;  
        }
    }
    if (dem == 0)
    {
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        if (TachSo(a[i]) == 1)
        {
            if (a[i] > max) max = a[i];
        }
    }
    return max;
}

int main() {
    int a[Max], n;
hoang:
    NhapDuLieu(n);
    NhapMang(a, n);
    XuatMang(a, n);
    int tim = GiaTriFullLeMax(a, n);
    printf("\nGia tri thoa man: %d", tim);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
    return 0;
}
