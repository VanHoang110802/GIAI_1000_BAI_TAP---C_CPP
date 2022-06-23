Hãy trộn hai mảng tăng dần lại thành 1 mảng được sắp thứ tự tăng dần .

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
void SapXep(int a[], int n){
	for (int i = 0; i < n - 1; i++){
		for (int j = i + 1; j < n; j++){
			if (a[i] > a[j]){
				HoanVi(a[i], a[j]);
			}
		}
	}
}

void Tron2MangThanh1Mang(int a[], int b[], int c[], int na, int nb, int& nc){
	nc = na + nb;         // Số phần tử mảng cần gộp
	SapXep(a, na);       // Sắp xếp mảng a
	SapXep(b, nb);       // Sắp xếp mảng b
	int vitriA = 0, vitriB = 0;
	for (int i = 0; i < nc; i++) {      // Duyệt mảng cần gộp
		if (vitriA < na && vitriB < nb) {   // Kiểm tra từng vị trí trong mảng A và mảng B xem có lớn hơn số phần tử của từng mảng        
			if (a[vitriA] < b[vitriB]) {     // So sánh xem phần tử của mảng nào nhỏ hơn (ở đầy là mảng a)
				c[i] = a[vitriA++];          // Đổ mảng a vào mảng cần gộp
			} else {
				c[i] = b[vitriB++];             // Ngược lại thì đổ mảng b vào mảng cần gộp
			}
		}
		// Xét thêm
		else if (vitriB == nb) {        // Nếu mà vị trí b tăng bằng số phần tử mảng b
			c[i] = a[vitriA++];            // Chỉ còn mảng a để đổ vào mảng cần gộp
		} else{
			c[i] = b[vitriB++];
		}
	}
}
int main(){
	int n,m,k, a[Max],b[Max],c[Max];
hoang:
	printf("\n");
	NhapDuLieu(n);
	NhapMang(a, n);
	printf("\n");
	NhapDuLieu(m);
	NhapMang(b, m);
	printf("\n");
	XuatMang(a, n);
	printf("\n");
	XuatMang(b, m);
	printf("\n");
	Tron2MangThanh1Mang(a,b,c,n,m,k);
	printf("\n");
	XuatMang(c, k);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
