Áp dụng nâng cao Thuật Toán Sắp Xếp :  
Cho dãy số nguyên A như sau : 12 2 15 -3 8 5 1 -8 6 0 4 15 . 
Yêu Cầu : 
1 . Sắp xếp dãy trên tăng dần . 
2 . Suy ra số lớn thứ 3 trong dãy . 
3 . Suy ra số lượng phần tử lớn nhất trong dãy . 
4 . Sắp xếp dãy trên theo thứ tự giá trị tuyệt đối tăng dần . 
5 . Sắp xếp dãy trên theo quy luật sau : 
	+ Các số dương (nếu có) ở đầu mảng và có thứ tự giảm dần . 
	+ Các số âm (nếu có) ở cuối mảng và có thứ tự tăng dần . 
6 . Sắp xếp dãy trên theo quy luật sau: 
	+ Các số chẵn (nếu có) ở đầu mảng và có thứ tự tăng dần . 
	+ Các số lẻ (nếu có) ở cuối mảng và có thứ tự giảm dần .

/* 
Câu 1: Thì dùng thuật toán sờ léc ti sờn sọt để sắp xếp (Selection Sort) :vv

Câu 2 :Nếu đề bài đã cho là tìm số lớn thứ 3 thì mảng phải có ít nhất 3 phần tử khác nhau trong mảng.Nếu không thỏa được điều kiện đó thì chương trình sẽ không tính và báo lỗi.Nếu thỏa điều kiện đó thì đi tính.Đầu tiên ta đi sắp xếp mảng tăng dần.Sau khi đã sắp xếp tăng dần thì ta tìm ra vị trí đầu tiên của phần tử lớn nhất trong mảng ký hiệu là vt1. Sau đó cho vòng lặp chạy từ 0 -> <vt1 => a[vt1-1] sẽ là số lớn thứ 2 và tiếp tục tìm ra vị trí xuất hiện đầu tiên của số lớn thứ 2 đó ký hiệu là vt2 . Cho tiếp vòng lặp chạy từ 0 -> < vt2 => a[vt2-1] chính là số lớn thứ 3 trong mảng. 

Câu 3: Tìm max, max lớn thứ 2 -> max 3 cần tìm.

Câu 4: Nhớ cài include<math.h> để xài abs rồi tánh.

Câu 5: Đầu tiên ta tách ra các phần tử dương và số lượng các phần tử dương trong mảng A và lưu vào 1 mảng mới (trong bài này là mảng C),tiếp đó ta tách ra các phần tử âm và số lượng các phần tử âm trong mảng A và lưu vào 1 mảng mới (trong bài này là mảng D) . Sau đó ta làm theo đúng đề bài sắp xếp các phần tử dương theo thứ tự giảm dần => tức là sắp xếp mảng C giảm dần,sắp xếp các phần tử âm theo thứ tự tăng dần => tức là sắp xếp mảng D tăng dần . Sau đó ta khởi tạo ra 1 mảng F để ghép 2 mảng C & D lại theo đúng trình tự thì sẽ ghép mảng C vào mảng F trước sau đó sẽ đến lượt ghép mảng D vào mảng F -> Thế là xong (câu này khó vaiilonn, thật đấy)!

Câu 6 : Đầu tiên ta tách ra các phần tử chẵn và số lượng các phần tử chẵn trong mảng A và lưu vào 1 mảng mới (trong bài này là mảng G),tiếp đó ta tách ra các phần tử lẻ và số lượng các phần tử lẻ trong mảng A và lưu vào 1 mảng mới (trong bài này là mảng H) . Sau đó ta làm theo đúng đề bài sắp xếp các phần tử chẵn theo thứ tự tăng dần => tức là sắp xếp mảng G tăng dần,sắp xếp các phần tử lẻ theo thứ tự giảm dần => tức là sắp xếp mảng H giảm dần . Sau đó ta khởi tạo ra 1 mảng X để ghép 2 mảng G & H lại theo đúng trình tự thì sẽ ghép mảng G vào mảng X trước sau đó sẽ đến lượt ghép mảng H vào mảng X -> Thế là xong bài (thực ra làm được câu trên thì câu này copy rồi sửa tý thôi :vv )! 

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <conio.h>
#include<Windows.h>
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

// Câu 1:
//Sắp mảng tăng dần bằng thuật toán Selection Sort .
void SapTangDan(int a[], int n){
	for (int i = 0; i < n - 1; i++){
		for (int j = i + 1; j < n; j++){
			if (a[i] > a[j]){
				HoanVi(a[i], a[j]);
			}
		}
	}
}

// Câu 2:
// Tìm số lớn thứ 3 .
void TimSoLonThuBa(int a[], int n){
	int vt1 = 0, vt2 = 0, max1, max2, max3, dem = 0;
	for (int i = 0; i < n; i++){
		if (a[i] != a[i + 1]){
			dem++;
		}
	}
	if (dem >= 3){
		for (int i = 0; i < n; i++){
			max1 = a[n - 1];
			if (max1 == a[i]){
				vt1 = i;
				break;
			}
		}
		for (int i = 0; i < vt1; i++){
			max2 = a[vt1 - 1];
			if (max2 == a[i]){
				vt2 = i;
				break;
			}
		}
		max3 = a[vt2 - 1];
		printf("\nPhan tu lon thu 3 trong mang la: %d", max3);
	}
	else
		printf("\nMang nay khong ton tai it nhat 3 phan tu khac nhau nen khong the tinh duoc!");
}

// Câu 3: 
//Đếm số lượng phần tử lớn nhất có trong mảng .
void DemSoLuongPhanTuLonNhat(int a[], int n){
	int max = a[0], dem = 0;
	for (int i = 1; i < n; i++){
		if (a[i] > max){
			max = a[i];
		}
	}
	for (int i = 0; i < n; i++){
		if (a[i] == max){
			dem++;
		}
	}
	printf("\nSo luong phan tu lon nhat trong day la: %d", dem);
}

// Câu 4: 
//Sắp mảng tăng dần theo trị tuyệt đối .
void SapTangDanTriTuyetDoi(int a[], int b[], int n){
	for (int i = 0; i < n; i++){
		b[i] = abs(a[i]);
	}
	for (int i = 0; i < n - 1; i++){
		for (int j = i + 1; j < n; j++){
			if (b[i] > b[j]){
				HoanVi(b[i], b[j]);
			}
		}
	}
}

//Câu 5:
// Tách ra phần tử dương lưu vào mảng C,phần tử âm lưu vào mảng D
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
// Trả về số lượng các phần tử dương trong mảng C .
int SoLuongPhanTuMangC(int a[], int n){
	int dem = 0;
	for (int i = 0; i < n; i++){
		if (a[i] >= 0){
			dem++;
		}
	}
	return dem;
}
// Trả về số lượng các phần tử âm trong mảng D .
int SoLuongPhanTuMangD(int a[], int n){
	int dem1 = 0;
	for (int i = 0; i < n; i++){
		if (a[i] < 0){
			dem1++;
		}
	}
	return dem1;
}
// Sắp mảng C chứa các phần tử dương giảm dần .
void SapMangCGiamDan(int c[], int dem){
	for (int i = 0; i < dem - 1; i++){
		for (int j = i + 1; j < dem; j++){
			if (c[i] < c[j]){
				HoanVi(c[i], c[j]);
			}
		}
	}
}
// Sắp mảng D chứa các phần tử âm tăng dần .
void SapMangDTangDan(int d[], int dem1){
	for (int i = 0; i < dem1 - 1; i++){
		for (int j = i + 1; j < dem1; j++){
			if (d[i] > d[j]){
				HoanVi(d[i], d[j]);
			}
		}
	}
}
// Ghép chung 2 mảng C & D vào chung 1 mảng F theo đúng trình tự thì ghép mảng C vào trước & mảng D vào sau .
void MangF(int f[], int c[], int d[], int dem, int dem1){
	int l = 0;
	for (int j = 0; j < dem; j++){
		f[l++] = c[j];
	}
	for (int k = 0; k < dem1; k++){
		f[l++] = d[k];
	}
}

// Câu 6: 
// Tách ra phần tử chẵn lưu vào mảng G,phần tử lẻ lưu vào mảng H
void TachChanVaLe(int a[], int g[], int h[], int n){
	int j = 0, k = 0;
	for (int i = 0; i < n; i++){
		if (a[i] % 2 == 0){
			g[j++] = a[i];
		}
		else{
			h[k++] = a[i];
		}
	}
}
// Trả về số lượng các phần tử chẵn trong mảng G .
int SoLuongPhanTuMangG(int a[], int n){
	int dem = 0;
	for (int i = 0; i < n; i++){
		if (a[i] % 2 == 0){
			dem++;
		}
	}
	return dem;
}
// Trả về số lượng các phần tử lẻ trong mảng H .
int SoLuongPhanTuMangH(int a[], int n){
	int dem1 = 0;
	for (int i = 0; i < n; i++){
		if (a[i] % 2 != 0){
			dem1++;
		}
	}
	return dem1;
}
// Sắp mảng G chứa các phần tử chẵn tăng dần .
void SapMangGTangDan(int g[], int dem){
	for (int i = 0; i < dem - 1; i++){
		for (int j = i + 1; j < dem; j++){
			if (g[i] > g[j]){
				HoanVi(g[i], g[j]);
			}
		}
	}
}
// Sắp mảng H chứa các phần tử lẻ giảm dần .
void SapMangHGiamDan(int h[], int dem1){
	for (int i = 0; i < dem1 - 1; i++){
		for (int j = i + 1; j < dem1; j++){
			if (h[i] < h[j]){
				HoanVi(h[i], h[j]);
			}
		}
	}
}
// Ghép chung 2 mảng G & H vào chung 1 mảng X theo đúng trình tự thì ghép mảng G vào trước & mảng H vào sau .
void MangX(int x[], int g[], int h[], int dem, int dem1){
	int l = 0;
	for (int j = 0; j < dem; j++){
		x[l++] = g[j];
	}
	for (int k = 0; k < dem1; k++){
		x[l++] = h[k];
	}
}

int main() {
	//int a[15] = { 12,2,15,-3,8,5,1,-8,6,0,4,15 };		// Tạo mảng A theo như đề bài cho trước.
	//int n = 12;		// Khởi tạo mảng A ban đầu có 12 phần tử .
	int a[Max];		// khởi tạo mảng gốc
	int n,b[Max], c[Max], d[Max], f[Max], g[Max], h[Max], x[Max]; // xây dựng các mảng cần thiết để tánh .
hoang:
	NhapDuLieu(n);
	NhapMang(a, n);
	printf("\nMang Ban Dau La: \n");
	XuatMang(a, n);
	printf("\n");
	SapTangDan(a, n);
	printf("\nMang Sau Khi Sap Tang Dan: \n");
	XuatMang(a, n);
	printf("\n");
	TimSoLonThuBa(a, n);
	printf("\n");
	DemSoLuongPhanTuLonNhat(a, n);
	printf("\n");
	SapTangDanTriTuyetDoi(a, b, n);
	printf("\nMang Sau Khi Sap Tang Dan Tri Tuyet Doi: \n");
	XuatMang(b, n);
	printf("\n");
	int s = SoLuongPhanTuMangC(a, n);
	int s1 = SoLuongPhanTuMangD(a, n);
	TachDuongVaAm(a, c, d, n);
	SapMangCGiamDan(c, s);
	SapMangDTangDan(d, s1);
	MangF(f, c, d, s, s1);
	printf("\nMang Sau Khi Sap Xep Cac So Duong O Dau Mang Va Co Thu Tu Giam Dan,Cac So Am O Cuoi Mang Va Co Thu Tu Tang Dan:\n");
	XuatMang(f, n);
	printf("\n");
	int s2 = SoLuongPhanTuMangG(a, n);
	int s3 = SoLuongPhanTuMangH(a, n);
	TachChanVaLe(a, g, h, n);
	SapMangGTangDan(g, s2);
	SapMangHGiamDan(h, s3);
	MangX(x, g, h, s2, s3);
	printf("\nMang Sau Khi Sap Xep Cac So Chan O Dau Mang Va Co Thu Tu Tang Dan,Cac So Le O Cuoi Mang Va Co Thu Tu Giam Dan:\n");
	XuatMang(x, n);
	printf("\n");
	printf("\nBan co muon tiep tuc nua voi chuong trinh khong? Neu co bam c de tiep tuc, bam phim bat ki de thoat!\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		system("cls");
		goto hoang;
	}
	return 0;
}
