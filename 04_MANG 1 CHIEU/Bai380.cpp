Hãy liệt kê các giá trị có số lần xuất hiện nhiều nhất trong mảng các số nguyên .

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
// Hàm hoán vị .
void HoanVi(int& x, int& y)
{
	int temp = x;
	x = y;
	y = temp;
}

// Hàm sắp mảng tăng dần bằng thuật toán Interchange Sort .
void SapMangTangDan(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] > a[j])
			{
				HoanVi(a[i], a[j]);
			}
		}
	}
}
// Hàm xử lý dữ liệu .
void LietKeGiaTriXuatHienNhieuNhat(int a[], int b[], int c[], int n){
	int dem = 1, j = 1;
	int l = 0;
	b[0] = a[0]; // Khởi tạo phần tử đầu tiên của mảng b bằng phần tử đầu tiên của mảng a .
	for (int i = 1; i < n; i++){
		if (a[i] != a[i - 1]){
			dem++;
			b[j++] = a[i]; // Đưa các giá trị phân biệt của mảng a vào trong mảng b .
		}
	}
	for (int j = 0; j < dem; j++){
		int dem1 = 0;
		for (int i = 0; i < n; i++){
			if (b[j] == a[i]) { // So sánh các phần tử của mảng b với mảng a ban đầu .
				dem1++; // Mỗi lần các phần tử trong mảng b bằng với mảng a thì tăng biến đếm lên . Mục đích liệt kê ra tần suất xuất hiện của các phần tử có trong mảng,mỗi phần tử liệt kê 1 lần .
			}
		}
		c[l++] = dem1; // Lưu các tần suất xuất hiện của các phần tử phân biệt vào trong một mảng c .
	}
	int max = c[0]; // Khởi tạo max = phần tử đầu tiên của mảng c .
	for (int l = 1; l < dem; l++) { // Số lượng phần tử của mảng c chính là số lượng các phần tử phân biệt của mảng a và cũng chính là số lượng phần của mảng b nên ta cho điều kiện l < dem .
		if (c[l] > max){
			max = c[l]; // Tìm ra tần suất xuất hiện lớn nhất .
		}
	}
	// Khởi tạo lại vòng lặp cho phần tử của mảng b so sánh lại với mảng a với dữ liệu tần suất xuất hiện nhiều nhất đã được xác định ở trên .
	for (int j = 0; j < dem; j++){
		int dem1 = 0;
		for (int i = 0; i < n; i++){
			if (b[j] == a[i]){
				dem1++; // Mỗi lần bằng nhau thì tăng biến đếm lên .
			}
		}
		if (dem1 == max) {// Nếu biến đếm bằng đúng max (tần suất xuất hiện nhiều nhất mà ta đã tìm ra ở trên ) thì sẽ đi in ra tất cả các phần tử thỏa điều kiện đó .
			printf("->%d", b[j]); // In ra tất cả các phần tử mà có số lần xuất hiện lớn nhất . Nếu có nhiều hơn 1 phần tử thỏa điều kiện đó thì in ra hết tất cả luôn .
		}
	}
}
int main(){
	int n, a[Max],b[Max], c[Max];
hoang:
	printf("\n");
	NhapDuLieu(n);
	NhapMang(a, n);
	printf("\n");
	XuatMang(a, n);
	printf("\n");
	LietKeGiaTriXuatHienNhieuNhat(a, b,c,n);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
