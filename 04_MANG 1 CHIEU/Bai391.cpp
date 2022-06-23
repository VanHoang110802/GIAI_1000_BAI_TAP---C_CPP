Viết chương trình thực hiện các yêu cầu sau:Nhập mảng n số nguyên từ bàn phím sao cho khi nhập xong các phần tử trong mảng được sắp theo thứ tự tăng dần . (không sắp xếp sau khi nhập) (nhập bảo toàn)
/*
nhập mảng : 1 2 3 4 5 6 -> hợp lệ
nhập mảng : 1 3 2 4 1 6 -> lỗi
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
	printf("\nNhap vao a[0]= ");
	scanf("%d", &a[0]);
	printf("\n(Luu y: Chuong trinh chi cho phep phan tu tiep theo phai lon hon hoac bang phan tu lien truoc no)\n ");
	for (int i = 1; i < n; i++){
	hoangdeptrai:
		printf("\nNhap vao a[%d]= ", i);
		scanf("%d", &a[i]);
		if (a[i] < a[i - 1]){
			printf("\nSo ban nhap khong hop le!Xin vui long nhap lai!");
			goto hoangdeptrai;
		}
	}
}
void XuatMang(int a[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d  ", a[i]);
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
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
