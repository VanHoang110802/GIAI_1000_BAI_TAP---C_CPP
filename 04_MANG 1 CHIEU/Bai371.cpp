Hãy liệt kê tần suất xuất hiện của các giá trị xuất hiện trong mảng . (Lưu ý:Mỗi giá trị liệt kê một lần) .
/*
Mảng: 1 2 5 2 3 10 4 2 2 5 10 4 3
-> có 6 phần tử phân biệt
- phần tử 1 xuất hiện 1 lần 
- phần tử 2 xuất hiện 4 lần 
- phần tử 5 xuất hiện 2 lần 
- phần tử 3 xuất hiện 2 lần 
- phần tử 10 xuất hiện 2 lần 
- phần tử 4 xuất hiện 2 lần 

Từ 1 vị trí i hiện tại sẽ lùi về trước đó (i - 1) để kiểm tra xem có bị trùng chưa? Nếu có thì sẽ không xét i hiện tại mà xét sang lần lặp khác, nếu không bị trùng thì từ vị trí i hiện tại sẽ lui về đằng sau nó (i+1) để đếm xem có bao nhiêu giá trị đó xuất hiện và cuối cùng in kết quả đếm ra.

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
			printf("So luong phan tu nhap khong hop le!\n");
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
//hàm từ vị trí hiện tại xét lùi xuống, để xét xem phần tử đó có bị trùng hay không?
int KiemTraBiTrung(int a[], int n, int vitridangxet) {
	for (int i = vitridangxet - 1; i >= 0; i--) {
		if (a[i] == a[vitridangxet]) {
			return 1;
		}
	}
	return 0;
}
// hàm đếm vị trí hiện tại lùi xuống về cuối mảng để đếm xem phần tử đó xuất hiện bao nhiêu lần
int DemSoLanXuatHien(int a[], int n, int vitridangxet) {
	int dem = 1;
	for (int i = vitridangxet + 1; i < n; i++) {
		if (a[i] == a[vitridangxet]) {
			dem++;
		}
	}
	return dem;
}
void GiaoHop2Ham(int a[], int n) {
	for (int i = 0; i < n; i++) {
		int check = KiemTraBiTrung(a, n, i);
		if (check == 1) {
			continue;
		}
		int dem = DemSoLanXuatHien(a, n, i);
		printf("\nPhan tu %d xuat hien %d", a[i], dem);
	}
}
int main(){
	int a[Max], n;
hoang:
	NhapDuLieu(n);
	NhapMang(a, n);
	XuatMang(a, n);
	printf("\n");
	GiaoHop2Ham(a, n);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
