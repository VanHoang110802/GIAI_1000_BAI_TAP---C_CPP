Cho hai mảng a và b.Hãy cho biết mảng b có phải là hoán vị của mảng a hay không ? .
/*
nếu số lượng phần tử không bằng nhau thì không phải luôn
còn nếu số lượng bằng nhau thì ta sẽ sắp xếp các phần tử theo hoặc tăng dần hoặc giảm dần, rồi so sánh xem các phần tử trong 2 mang sau khi sắp xếp đó, nếu có 1 phần tử nào khác nhau thì cũng kết luận là cũng không phải luôn.
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
void HoanVi(int& a, int& b){
	int temp = a;
	a = b;
	b = temp;
}
void SapXepTangDan(int a[], int n){
	for (int i = 0; i < n - 1; i++){
		for (int j = i + 1; j < n; j++){
			if (a[i] > a[j]){
				HoanVi(a[i], a[j]);
			}
		}
	}
}

int KiemTraBCoPhaiLaHoanViCuaA(int a[], int b[], int na, int nb){
	if (na != nb){      // Số lượng phần tử phải bằng nhau
		return 0;
	}
	SapXepTangDan(a, na);           // Sắp xếp mảng a
	SapXepTangDan(b, nb);           // Sắp xếp mảng b
	for (int i = 0; i < na; i++){
		if (a[i] != b[i]){
			return 0;
		}
	}
	return 1;
}
int main(){
	int na,nb, a[Max],b[Max];
hoang:
	printf("\n");
	NhapDuLieu(na);
	NhapMang(a, na);
	printf("\n");
	NhapDuLieu(nb);
	NhapMang(b, nb);
	printf("\nMang A: ");
	XuatMang(a, na);
	printf("\nMang B: ");
	XuatMang(b, nb);
	printf("\n");
	int kt = KiemTraBCoPhaiLaHoanViCuaA(a,b,na,nb);
	if (kt == 1) printf("Yes");
	else printf("No");
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
