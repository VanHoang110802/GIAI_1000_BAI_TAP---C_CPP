Hãy thêm một giá trị x vào trong mảng tăng mà vẫn giữ nguyên tính đơn điệu tăng của mảng .

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
void HoanVi(int& a, int& b){
	int temp = a;
	a = b;
	b = temp;
}

void SapXepTangDan(int a[], int n){
	for (int i = 0; i < n; i++){
		for (int j = i + 1; j < n; j++){
			if (a[i] > a[j]){
				HoanVi(a[i], a[j]);
			}
		}
	}
}
/*
Cho chạy từ cuối về đầu, nếu thấy số nào lớn hơn x thì cho nó dịch về sau 1 vị trí.
*/
void ChenXVaoMangTang(int a[], int& n, int x){
	int i, j;
	for (i = 0; i < n; i++){
		if (x < a[i]){
			int temp = x;
			for (j = n; j > i; j--){
				a[j] = a[j - 1];
			}
			a[i] = temp;
			break;
		}
	} 
	a[n] = x;
	n++;
}
int main(){
	int n, a[Max],k;
hoang:
	printf("\n");
	NhapDuLieu(n);
	NhapMang(a, n);
	printf("\n");
	XuatMang(a, n);
	printf("\nNhap k= ");
	scanf("%d", &k);
	ChenXVaoMangTang(a,n,k);
	XuatMang(a, n);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
