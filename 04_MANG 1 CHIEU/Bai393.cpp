Nhập vào 1 mảng A các số nguyên và sắp xếp mảng A trên theo quy luật: 
	+ Các số dương (nếu có) ở đầu mảng và có thứ tự giảm dần. 
	+ Các số âm (nếu có) ở cuối mảng và có thứ tự tăng dần .

/* Ý Tưởng : Đầu tiên ta tách ra các phần tử dương và số lượng các phần tử dương trong mảng A và lưu vào 1 mảng mới (trong bài này là mảng C),tiếp đó ta tách ra các phần tử âm và số lượng các phần tử âm trong mảng A và lưu vào 1 mảng mới (trong bài này là mảng D) . Sau đó ta làm theo đúng đề bài sắp xếp các phần tử dương theo thứ tự giảm dần => tức là sắp xếp mảng dương(mảng C) giảm dần,sắp xếp các phần tử âm (mảng D) theo thứ tự tăng dần . Sau đó ta khởi tạo ra 1 mảng F để ghép 2 mảng C & D lại, theo đúng trình tự thì sẽ ghép mảng C vào mảng F trước, sau đó sẽ đến lượt ghép mảng D vào mảng F . Thế là xong bài */

/* Trong bài này thì chỉ cần xuất ra mảng F thỏa đúng điều kiện đề bài cho nhưng ta vẫn nên xuất ra mảng C & D để kiếm tra tính chính xác của việc ghép các mảng . */

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
// Hàm hoán vị.
void HoanVi(int& x, int& y){
	int temp = x;
	x = y;
	y = temp;
}
// Hàm tách ra phần tử dương lưu vào mảng C,phần tử lẻ âm lưu vào mảng D
void TachDuongVaAm(int a[], int c[], int d[], int n){
	int j = 0, k = 0;
	for (int i = 0; i < n; i++){
		if (a[i] >= 0){
			c[j++] = a[i];
		}
		else{
			d[k++] = a[i];
		}
	}
}
// Hàm trả về số lượng các phần tử dương trong mảng C .
int SoLuongPhanTuMangC(int a[], int n){
	int dem = 0;
	for (int i = 0; i < n; i++){
		if (a[i] >= 0){
			dem++;
		}
	}
	return dem;
}
// Hàm trả về số lượng các phần tử âm trong mảng D .
int SoLuongPhanTuMangD(int a[], int n){
	int dem1 = 0;
	for (int i = 0; i < n; i++){
		if (a[i] < 0){
			dem1++;
		}
	}
	return dem1;
}
// Hàm sắp mảng C chứa các phần tử dương giảm dần .
void SapMangCGiamDan(int c[], int dem){
	for (int i = 0; i < dem - 1; i++){
		for (int j = i + 1; j < dem; j++){
			if (c[i] < c[j]){
				HoanVi(c[i], c[j]);
			}
		}
	}
}
// Hàm sắp mảng D chứa các phần tử âm tăng dần .
void SapMangDTangDan(int d[], int dem1){
	for (int i = 0; i < dem1 - 1; i++){
		for (int j = i + 1; j < dem1; j++){
			if (d[i] > d[j]){
				HoanVi(d[i], d[j]);
			}
		}
	}
}
// Hàm ghép chung 2 mảng C & D vào chung 1 mảng F theo đúng trình tự thì ghép mảng C vào trước & mảng D vào sau .
void MangF(int f[], int c[], int d[], int dem, int dem1){
	int l = 0;
	for (int j = 0; j < dem; j++){
		f[l++] = c[j];
	}
	for (int k = 0; k < dem1; k++){
		f[l++] = d[k];
	}
}
int main() {
	int n, a[Max], c[Max], d[Max], f[Max];
hoang:
	NhapDuLieu(n);
	NhapMang(a, n);
	printf("\n");
	XuatMang(a, n);
	printf("\n");
	int s = SoLuongPhanTuMangC(a, n);
	int s1 = SoLuongPhanTuMangD(a, n);
	TachDuongVaAm(a, c, d, n);
	SapMangCGiamDan(c, s);
	printf("\nMang C chua cac phan tu duong cua mang A va sap giam dan :\n");
	XuatMang(c, s);
	printf("\n");
	SapMangDTangDan(d, s1);
	printf("\nMang D chua cac phan tu am cua mang A va sap tang dan :\n");
	XuatMang(d, s1);
	printf("\n");
	MangF(f, c, d, s, s1);
	printf("\nMang F ghep cac phan tu cua 2 mang C & D :\n");
	XuatMang(f, n);
	printf("\nBan co muon tiep tuc nua voi chuong trinh khong? Neu co bam c de tiep tuc, bam phim bat ki de thoat!\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		//system("cls");
		goto hoang;
	}
	return 0;
}
