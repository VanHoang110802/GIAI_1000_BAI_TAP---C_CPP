Hãy "dịch trái xoay vòng" các phần tử trong mảng.
/*
Ta sẽ giả sử: Mảng ban đầu là: 1 2 3 4 5 -> giờ dịch chuyển cách phần tử ra sao?
Dịch trái xoay vòng 1 lần -> 2 3 4 5 1 (1)
Dịch trái xoay vòng 2 lần -> 3 4 5 1 2
Dịch trái xoay vòng 3 lần -> 4 5 1 2 3
Dịch trái xoay vòng 4 lần -> 5 1 2 3 4 
Dịch trái xoay vòng 5 lần -> 1 2 3 4 5
Dịch trái xoay vòng 6 lần -> quay trở về (1)
... cứ như thế xoay vòng theo số lần k đã nhập, và xoay phải như vậy.

Chẳng qua, đây chỉ là bài nâng cấp hơn của dạng hoán vị của 2 số, thay vì hoán vị 2 số thì ở đây ta sẽ hoán vị nhiều số trong mảng( thường thì nó sẽ lớn hơn 2 là cái chắc :vv), ta dùng vòng lặp lồng vào trong hàm tìm hoán vị (hàm hoán vị thì quá đơn giản rồi, gán a qua biến phụ, rồi cho b = a, rồi gán b lại qua biến phụ là xong) của nhiều số, có 1 biến char, biến char này sẽ biểu thị cho việc nhấn 1 phím bát kì thì sẽ xoay trái hoặc xoay phải các phần tử trong mảng. Bài này khá hay, có ứng dụng thực tế khá thú vị là những game hay ứng dụng có trò bấm để xoay nhận quà, nhận xu ... các thứ đều có dạng na ná giống bài tập này :D
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#define Max 100
void NhapDuLieu(int& n) {
	do{
	printf("nhap so luong:");
	scanf("%d", &n);
	if(n<1||n>Max){
		printf("So luong phan tu nhap khong hop le,xin hay kiem tra lai!\n");
	}
	while(n<1||n>Max);
}
void NhapMang(int a[], int n) {
	for (int i = 0; i < n; ++i) {
		printf("a[%d]= ", i);
		scanf("%d", &a[i]);
	}
}
void XuatMang(int a[], int n) {
	for (int i = 0; i < n; ++i) {
		printf("%d ", a[i]);
	}
}

void DichTrai(int a[], int n, int k){
	while (k--){
		int temp = a[0];
		for (int i = 0; i < n - 1; i++){
			a[i] = a[i + 1];
		}
		a[n - 1] = temp;
	}
}
int main(){
	int n, k, a[Max];
hoang:
	NhapDuLieu(n);
	NhapMang(a, n);
	XuatMang(a, n);
	printf("\nNhap K= ");
	scanf("%d", &k);
	DichTrai(a, n, k);
	printf("\nDich trai mang %d phan tu: ", k);
	XuatMang(a, n);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
