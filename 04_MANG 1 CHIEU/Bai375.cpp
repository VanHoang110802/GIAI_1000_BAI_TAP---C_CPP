Viết chương trình nhập mảng 1 chiều các số nguyên và in ra màn hình các giá trị phân biệt trong mảng kèm theo số lượng và tần suất xuất hiện của chúng trong dãy .
/*
Lưu Ý:Mỗi giá trị liệt kê tần suất 1 lần .
   Nhập mảng : 12 43 12 34 43 12 5 
   -> Các giá trị phân biệt trong mảng : 12 43 34 5 .
   -> Số lượng các giá trị phân biệt: 4 
   -> Gía trị 12 xuất hiện 3 lần 
   -> Gía trị 43 xuất hiện 2 lần 
   -> Gía trị 34 xuất hiện 1 lần 
   -> Gía trị 5  xuất hiện 1 lần 

- Để xuất ra các giá trị phân biệt trong mảng :Ta sắp xếp mảng tăng dần (hay giảm dần),sau đó đem phần tử đầu tiên (sau khi đã thực hiện sắp xếp) làm gốc,ta in ra trước phần tử a[0].Sau đó cho vòng lặp i chạy từ 1 đến < n . Đặt điều kiện nếu a[i] khác a[i-1].Nếu thỏa mãn -> in ra a[i] và biến đếm ban đầu khởi tạo bằng 1 (tại vì đã lấy phần tử a[0] làm gốc) bây giờ tiếp tục cộng tăng thêm 1 đơn vị.Cứ thế lặp lại cho đến hết.

- Để tính tần suất xuất hiện của các giá trị phân biệt : Ta khai báo một mảng b dùng để lưu các giá trị phân biệt vừa tìm được của mảng a ở câu trên vào.Khởi tạo biến dem1=0.Sau đó lần lượt đem so sánh từng phần tử của mảng b với mảng a .Nếu bằng nhau -> biến dem1 tăng thêm 1 đơn vị. Cứ lặp lại liên tục cho đến phần tử cuối cùng của mảng b . 
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
// Hàm Hoán Vị .
void HoanVi(int& x, int& y){
	int temp = x;
	x = y;
	y = temp;
}

// Hàm Sắp Xếp Mảng Tăng Dần .
void SapXepMangTangDan(int a[], int n){
	for (int i = 0; i < n - 1; i++){
		for (int j = i + 1; j < n; j++){
			if (a[i] > a[j]){
				HoanVi(a[i], a[j]);
			}
		}
	}
}

// Hàm Liệt Kê Và Tính Tần Suất Xuất Hiện Của Các Gía Trị Phân Biệt .
void LietKeVaTinhTanSuatXuatHienCuaCacGiaTriPhanBiet(int a[], int b[], int n){
	SapXepMangTangDan(a,n);
	int dem = 1, j = 1;
	printf("\nCac Gia Tri Phan Biet Trong Mang La:");
	printf(" %d ", a[0]); 	// In ra trước phần tử gốc a[0] .
	for (int i = 1; i < n; i++){
		b[0] = a[0]; 	// Gán phần tử đầu tiên của mảng b là phần tử gốc giá trị phân biệt đầu tiên .
		if (a[i] != a[i - 1]){
			printf("%d ", a[i]); 	// In ra các giá trị phân biệt trong mảng a .
			dem++; 		// Đếm số lượng các giá trị phân biệt .
			b[j++] = a[i]; 	// Đưa các giá trị phân biệt trong mảng a vào mảng b .
		}
	}
	printf("\nSo luong cac gia tri phan biet la: %d", dem); 	// Xuất ra số lượng các giá trị phân biệt trong mảng a .
	printf("\n");
	for (j = 0; j < dem; j++){
		int dem1 = 0; 	// Khởi tạo biến dem1=0 .
		for (int i = 0; i < n; i++){
			if (b[j] == a[i]){
				dem1++; 	// Với mỗi lần bằng nhau thì tăng biến dem1 lên 1 đơn vị .
			}
		}
		printf("\nTan Suat Xuat Hien Cua Phan Tu: %d La: %d", b[j], dem1); 	// Xuất ra tần suất xuất hiện của các giá trị phân biệt .
	}
}

int main(){
	int n, a[Max],b[Max];
hoang:
	printf("\n");
	NhapDuLieu(n);
	NhapMang(a, n);
	printf("\n");
	XuatMang(a, n);
	printf("\n");
	LietKeVaTinhTanSuatXuatHienCuaCacGiaTriPhanBiet(a, b,n);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
