Hãy liệt kê các giá trị trong mảng mà thoả điều kiện lớn hơn giá trị tuyệt đối đứng sau nó
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<math.h>
#define Max 100
void NhapDuLieu(int &n){
	do{
		printf("Nhap so luong phan tu: ");
		scanf("%d", &n);
		if(n<1||n>Max){
			printf("Xin hay kiem tra lai!\n");
		}
	}while(n<1||n>Max);
}
void NhapMang(int a[], int n){
	for(int i=0;i<n;i++){
		printf("a[%d]= ", i);
		scanf("%d", &a[i]);
	}
}
void XuatMang(int a[], int n){
	for(int i =0;i<n;i++){
		printf("%d ", a[i]);
	}
}
void LietKe(int a[],int n){
	printf("\nCac gia tri thoa man: ");
    for(int i =0;i<n-1;i++){
        if(a[i] > fabs(a[i+1])){
            printf("%d ", a[i]);
        }
    }
}

int main(){
	int a[Max],n;
hoang:
	NhapDuLieu(n);
	NhapMang(a,n);
	XuatMang(a,n);
	LietKe(a,n);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
