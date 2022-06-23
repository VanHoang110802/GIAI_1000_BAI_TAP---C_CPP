Các thao tác xử lý
a. Tách các số nguyên tố có trong mảng a đưa vào mảng b.

#include<stdio.h>
#include<conio.h>
#define Max 100
void NhapDuLieu(int &n){
	do{
		printf("Nhap so luong phan tu: ");
		scanf("%d", &n);
		if(n< 1 || n > Max){
			printf("So luong phan tu khong hop le!\n");
		}
	}while(n< 1 || n > Max);
}
void NhapMang(int a[], int n){
	for(int i =0;i<n;i++){
		printf("a[%d]= ",i);
		scanf("%d", &a[i]);
	}
}
void XuatMang(int a[], int n){
	for(int i=0;i<n;i++){
		printf("%d ", a[i]);
	}
}
int KiemTraSoNT(int n){
	int check = 1, temp = n;
	if(temp < 2){
		check = 0;
	} else {
		if(temp > 2 && temp % 2 == 0){
			check = 0;
		} else {
			for(int i =2;i*i<=temp;i++){
				if(temp % i == 0){
					check = 0;
					break;
				}
			}
		}
	}
	if(check == 1 ) {
		return 1;
	}
	return 0;
}
void TachSoNT(int a[], int n, int b[], int &m){
	m =0;
	for(int i =0;i<n;i++){
		if(KiemTraSoNT(a[i])){
			b[m++] = a[i];	// b[m] = a[i]; m++;
		}
	}
}
int main(){
	int n,m, a[Max],b[Max];
hoang:
	NhapDuLieu(n);
	NhapMang(a,n);
	XuatMang(a,n);
	TachSoNT(a,n,b,m);
	printf("\nMang toan so nguyen to: ");
	XuatMang(b,m);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}

b. Tách mảng a thành 2 mảng b (chứa các số
nguyên dương) và c (chứa các số còn lại)

#include<stdio.h>
#include<conio.h>
#define Max 100
void NhapDuLieu(int &n){
	do{
		printf("Nhap so luong phan tu: ");
		scanf("%d", &n);
		if(n< 1 || n > Max){
			printf("So luong phan tu khong hop le!\n");
		}
	}while(n< 1 || n > Max);
}
void NhapMang(int a[], int n){
	for(int i =0;i<n;i++){
		printf("a[%d]= ",i);
		scanf("%d", &a[i]);
	}
}
void XuatMang(int a[], int n){
	for(int i=0;i<n;i++){
		printf("%d ", a[i]);
	}
}
void TachThanh2Mang(int a[], int n, int b[], int &m, int c[], int &k){
	m =k = 0;
	for(int i =0;i<n;i++){
		if(a[i] >= 0){
			b[m++] = a[i];
		}  else {
			c[k++] = a[i];
		}
	}
}
int main(){
	int n,m,k, a[Max],b[Max],c[Max];
hoang:
	NhapDuLieu(n);
	NhapMang(a,n);
	XuatMang(a,n);
	TachThanh2Mang(a,n,b,m,c,k);
	printf("\nMang toan so duong: ");
	XuatMang(b,m);
	printf("\nMang toan so am: ");
	XuatMang(c,k);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}

c. Sắp xếp mảng giảm dần
#include<stdio.h>
#include<conio.h>
#define Max 100
void NhapDuLieu(int &n){
	do{
		printf("Nhap so luong phan tu: ");
		scanf("%d", &n);
		if(n< 1 || n > Max){
			printf("So luong phan tu khong hop le!\n");
		}
	}while(n< 1 || n > Max);
}
void NhapMang(int a[], int n){
	for(int i =0;i<n;i++){
		printf("a[%d]= ",i);
		scanf("%d", &a[i]);
	}
}
void XuatMang(int a[], int n){
	for(int i=0;i<n;i++){
		printf("%d ", a[i]);
	}
}
void HoanVi(int &a, int &b){
	int temp = a;
	a= b;
	b = temp;
}

void SapXep(int a[], int n, char phanbiet){
	for(int i = 0;i<n;i++){
		for(int j = i + 1; j<n;j++){
			 if(phanbiet == 'g'){
				if(a[i] < a[j]){
					HoanVi(a[i], a[j]);
				}
			}
		}
	}
}
int main(){
	int n, a[Max];
hoang:
	NhapDuLieu(n);
	NhapMang(a,n);
	XuatMang(a,n);
	SapXep(a,n,'g');
	printf("\nMang giam dan: ");
	XuatMang(a,n);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}

d. Sắp xếp mảng sao cho các số dương đứng đầu mảng giảm dần, kế đến là các số âm tăng dần, cuối cùng là các số 0.

void SapXepAmDuong(int a[], int &n, int b[], int m, int c[], int k){
	//int dem = 0;
	//for(int i =0;i<n;i++){
	//	if(a[i] == 0){
	//		dem++;
	//	}
	//}
	// vì không tính 0 nên ta sẽ bỏ 0 ở mảng b đi.
	SapXep(b,m,'g');
	// mảng âm tăng dần (có số 0).
	SapXep(c,k,'t');
	// trộn hết các phần tử của 2 mảng vào thành 1 mảng
	int i;
	for(i =0;i<m;i++){
		a[i] = b[i];
	}
	for(int j =0;j<k;j++){
		a[i++] = c[j];
	}
}
