Cho mảng một chiều các số nguyên . Hãy viết hàm tìm chữ số xuất hiện ít nhất trong mảng .

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#define Max 100
void NhapDuLieu(int& n){
	do {
		printf("Nhap so luong phan tu: ");
		scanf("%d", &n);
		if (n<1||n>Max) {
			printf("Phan tu nhap khong hop le, xin hay kiem tra lai!\n");
		}
	} while (n<1||n>Max);
}
void NhapMang(int a[], int n){
	for (int i = 0; i < n; i++) {
		printf("a[%d]= ", i);
		scanf("%d", &a[i]);
	}
}
void XuatMang(int a[], int n){
	for (int i = 0; i < n; i++) {
		printf("%d  ", a[i]);
	}
}

// Hàm hoán vị .
void HoanVi(int& x, int& y){
	int temp = x;
	x = y;
	y = temp;
}

/*
 Hàm xử lý đi tìm chữ số xuất hiện ít nhất:
 Tách các chữ số mảng a(mảng ban đầu vừa mới nhập vào).
 Lúc này các chữ số của các phần tử trong mảng a đã được đưa vào mảng b. Đi tìm ra các chữ số phân biệt trong mảng b .
 Bước 1: Sắp mảng b tăng dần.
 Bước 2: Liệt kê ra các chữ số phân biệt bằng cách đưa các chữ số có trong mảng b vào 1 mảng mới là mảng c và xử lý trên mảng c.
	Gán phần tử đầu tiên của mảng c chính là phần tử đầu tiên của mảng b.
	Bắt đầu duyệt từ phần tử thứ 2 của mảng b .
	Từ lúc này mảng c đã chứa các chữ số phân biệt.
	Mỗi lần bằng nhau thì tăng biến đếm lên. Lưu giá trị biến đếm vào mảng d.

 Khởi tạo min là giá trị đầu tiên của mảng d.
 Số lượng phần tử của mảng d chính là số lượng các phần tử phân biệt của mảng b hay nói cách khác bằng đúng số lượng phần tử của mảng c
 nên ta đặt điều kiện t < dem.

 Tìm ra tần suất xuất hiện ít nhất. 
 Khởi tạo lại vòng lặp cho phần tử của mảng c so sánh lại với mảng b với tần suất xuất hiện ít nhất đã được tìm ra ở trên.
 Mỗi lần bằng nhau thì tăng biến đếm lên. Nếu biến đếm bằng đúng min (tần suất xuất hiện ít nhất mà ta đã tìm ra ở trên ) thì sẽ in ra tất cả các chữ số có tần suất xuất hiện đó  

	-> in ra các chữ số có số lần xuất hiện ít nhất trong mảng .
*/
int TimChuSoXuatItNhat(int a[], int b[], int c[], int d[], int n){
	int j = 0, l, k;
	int t = 0;
	for (int i = 0; i < n; i++){
		while (a[i] != 0){
			b[j] = a[i] % 10;
			a[i] = a[i] / 10;
			j++;
		}
	}
	
	for (l = 0; l < j; l++){
		for (k = l + 1; k < j; k++){
			if (b[l] > b[k]){
				HoanVi(b[l], b[k]);
			}
		}
	}
	
	int dem = 1, m = 1;
	c[0] = b[0]; 
	for (l = 1; l < j; l++){	// Bắt đầu duyệt từ phần tử thứ 2 của mảng b .
		if (b[l] != b[l - 1]){
			dem++;
			c[m++] = b[l];
		}
	}
	// Từ lúc này mảng c đã chứa các chữ số phân biệt .
	for (int m = 0; m < dem; m++){
		int dem1 = 0;
		for (int l = 0; l < j; l++){
			if (c[m] == b[l]){
				dem1++; // Mỗi lần bằng nhau thì tăng biến đếm lên .
			}
		}
		d[t++] = dem1; // Lưu giá trị biến đếm vào mảng d .
	}
	int min = d[0]; // Khởi tạo min là giá trị đầu tiên của mảng d .
	for (int t = 0; t < dem; t++){ // Số lượng phần tử của mảng d chính là số lượng các phần tử phân biệt của mảng b
		if (d[t] < min){
			min = d[t]; // Tìm ra tần suất xuất hiện ít nhất .
		}
	}
	// Tìm ra tần suất xuất hiện ít nhất 
	for (int m = 0; m < dem; m++){
		int dem1 = 0;
		for (int l = 0; l < j; l++){
			if (c[m] == b[l]){
				dem1++; 
			}
		}
		if (dem1 == min){
			return c[m]; 
		}
	}
}
int main(){
	int a[Max], b[Max], c[Max], d[Max], n;
hoang:
	NhapDuLieu(n);
	NhapMang(a, n);
	XuatMang(a, n);
	printf("\n");
	int tim = TimChuSoXuatItNhat(a, b, c, d, n);
	printf("Chu so xuat hien it nhat trong mang: %d ", tim);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
