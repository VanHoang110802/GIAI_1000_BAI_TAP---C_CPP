Liệt kê tất cả các mảng con trong mảng một chiều các số nguyên .
/*
mảng: 1 2 3 4 5 

các mảng con: 1       | 2       | 3      | 4    | 5
	      1 2     | 2 3     | 3 4    | 4 5
	      1 2 3   | 2 3 4   | 3 4 5
	      1 2 3 4 | 2 3 4 5
	      1 2 3 4 5
Ta cần phải xác định được độ dài mảng, rồi có vòng lặp duyệt các phần của của mảng lồng kèm vòng lặp duyệt các chiều dài của mảng, rồi từ đó đi liệt kê các phần tử theo chiều dài của mảng đã duyệt trước đó, ví dụ nếu mảng có chiều dài là 2 thì gồm có 4 mảng con.
*/
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
void LietKeTatCaMangCon(int a[], int n) {
	int ChieuDai;  // độ dài mảng con
	for (int i = 0; i < n; i++) {
		for (ChieuDai = i; ChieuDai <= n; ChieuDai++) {		// nếu bỏ vòng for này thì sao ? thì chương trình nó sẽ không hiểu chiều dài được khai báo như nào?
			for (int j = i; j < ChieuDai; j++) {
				printf("%d ", a[j]);
			}
			printf(" | ");		// ngăn cách mỗi mảng con ra 
		}
	}
}
int main(){
	int n, a[Max];
hoang:
	printf("\n");
	NhapDuLieu(n);
	NhapMang(a, n);
	printf("\n");
	XuatMang(a, n);
	printf("\n");
	LietKeTatCaMangCon(a, n);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if (lc == 'c' || lc == 'C') {
		goto hoang;
	}
	return 0;
}
