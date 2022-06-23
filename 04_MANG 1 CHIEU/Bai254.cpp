* Đề thi tốt nghiệp lần 2/267/SBT Thầy NTTMK 
*Viết chương trình nhập vào mảng số nguyên:
a> Xuất ra phần tử lớn nhất.
b> Sắp xếp mảng tăng dần.
c> Tính tổng 5 số lẻ đầu tiên của mảng,nếu số phần tử là số lẻ nhỏ hơn 5,thì tính
tổng các số lẻ của các phần tử mảng.
d> Xóa các phần tử trùng nhau của mảng (giữ lại phần tử đầu và xóa các phần tử
trùng sau đó).Ví dụ:Cho mảng A={4,5,3,5,6,7,8,7} thì kết quả sau khi xóa
A={4,5,3,6,7,8} .

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <conio.h>
#include<math.h>
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
// câu a:
void PhanTuLonNhat(int a[], int n){
	int max = a[0];
	int Co = 0;
	for (int i = 0; i < n; i++){
		if (a[i] > max){
			max = a[i];
			Co = 1;
		}
	}
	if (Co == 1) printf("\nSo lon nhat la: %d", max);
}

void HoanVi(int& x, int& y){
	int temp;
	temp = x;
	x = y;
	y = temp;
}
// câu b:
void SapXepTangDan(int a[], int n){
	int b[Max];
	printf("\nMang sau khi sap xep tang dan: ");
	for (int i = 0; i < n; i++) b[i] = a[i];
	int i, j;
	for (i = 0; i < n; i++){
		for (j = i + 1; j < n; j++){
			if (b[i] > b[j]) HoanVi(b[i], b[j]);
		}
		printf("%d ", b[i]);
	}
}
// câu c:
void TinhTong5SoLeDauTien(int a[], int n){
	int dem = 0, tong = 0;
	int Co = 0;
	for (int i = 0; i < n; i++){
		if (a[i] % 2 != 0){
			dem++;
			if (dem <= 5){
				Co = 1;
				tong += a[i];
			}
		}
	}
	if (Co == 1) printf("\nTong 5 so le dau tien la: %d", tong);
	else printf("\nTrong mang khong ton tai so le nen khong the tinh duoc!\n");
}

void Xoa(int a[], int& n, int k){
	for (int i = k; i < n; i++){
		a[i] = a[i + 1];
	}
	n--;
}
// câu d:
void XoaPhanTuTrungNhau(int a[], int& n){
	for (int i = 0; i < n - 1; i++){
		for (int j = i + 1; j < n; j++){
			if (a[i] == a[j]){
				Xoa(a, n, j);
				j--;
			}
		}
	}
}
int main() {
	int n, a[Max];
hoangdeptrai:
	NhapDuLieu(n);
	NhapMang(a, n);
	XuatMang(a, n);
	printf("\n");
	PhanTuLonNhat(a, n);
	SapXepTangDan(a, n);
	printf("\n");
	TinhTong5SoLeDauTien(a, n);
	printf("\n");
	XoaPhanTuTrungNhau(a, n);
	printf("\nMang sau khi xoa cac phan tu trung nhau la:  ");
	XuatMang(a, n);
	printf("\nBan co muon tiep tuc chuong trinh hay khong?Neu co xin hay bam c, neu khong bat phim bat ki de thoat\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoangdeptrai;
	}
	return 0;
}
