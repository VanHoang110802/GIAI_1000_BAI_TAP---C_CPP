Hãy đảo ngược thứ tự các số chẵn và các số lẻ trong mảng mà vẫn giữ nguyên vị trí tương đối của chúng .

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#define Max 100
void NhapDuLieu(int &n){
	do{
		printf("Nhap so luong phan tu: ");
		scanf("%d", &n);
		if(n<1||n>Max){
			printf("So luong phan tu nhap khong hop le, xin hay kiem tra lai\n");
		}
	}while(n<1||n>Max);
}
void NhapMang(int a[], int n){
	for(int i=0;i<n;i++){
		printf("a[%d]= ");
		scanf("%d", &a[i]);
	}
}
void XuatMang(int a[], int n){
	for(int i=0;i<n;i++){
		printf("%d ", a[i]);
	}
}
void HoanVi(int &a, int &b){
	int tam = a;
	a = b;
	b = tam;
}
void DaoNguocChanLe(int a[], int n){
	int i, j;
	for(i = 0; i < n; i++){
		for(j = i + 1; j < n; j++){
			if(a[i] % 2 == 0 && a[j] % 2 == 0){
				HoanVi(a[i], a[j]);
			}
			else if(a[i] % 2 != 0 && a[j] % 2 != 0){
				HoanVi(a[i], a[j]);
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
	printf("\n");
	DaoNguocChanLe(a,n);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
