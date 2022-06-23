Tính trung bình cộng các giá trị lớn hơn giá trị x trong mảng một chiều các số thực .

#include<stdio.h>
#include<conio.h>
#define Max 100
void NhapDuLieu(int &n){
    do{
        printf("Nhap so luong phan tu: ");
        scanf("%d",&n);
        if(n<1||n>Max){
            printf("So luong phan tu nhap khong hop le, xin hay kiem tra lai!\n");
        }
    }while(n<1||n>Max);
}
void NhapMang(float a[], int n){
    for(int i=0;i<n;++i){
        printf("a[%d]= ",i);
        scanf("%f",&a[i]);
    }
}
void XuatMang(float a[], int n){
    for(int i=0;i<n;i++){
        printf("%.3f  ", a[i]);
    }
}
float TinhTBC(float a[], int n, float z){
    float s = 0,s1;
    int dem = 0;
    for(int i=0;i<n;i++){
        if(a[i] > z){
        	dem++;
            s+=a[i];
            
        }
    }
    return s1 = s/dem;
}
int main(){
    float a[Max];
    int n,x;
hoang:
    NhapDuLieu(n);
    NhapMang(a,n );
    XuatMang(a,n);
    printf("\n");
    printf("Nhap gia tri x= ");
    scanf("%d", &x);
    float Tinh = TinhTBC(a,n,x);
    printf("\nTrung binh cong cac gia tri lon gia tri %d la %.3f",x, Tinh);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
    return 0;
}
