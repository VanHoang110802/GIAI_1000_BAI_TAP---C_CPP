sắp xếp các số dương tăng dần hoặc giảm dần, chữ số âm thì k thay đổi giữ nguyên vị trí
#include<stdio.h>
#include<conio.h>
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
void HoanVi(int &a, int &b){
    int tenp = a;
    a = b;
    b = tenp;
}
/*void SapXepDuongTang(int a[],int n){
    for(int i=0;i<n-1 && a[i] >=0;++i){
        for(int j= i+1;j<n && a[j] >= 0;j++){
            if(a[i] > a[j]){
                HoanVi(a[i],a[j]);
                
            }
        }
    }
}*/

void SapXep(int a[], int n, char phanbiet){
	for(int i = 0;i<n;i++){
		if(a[i] >= 0){
			for(int j = i + 1; j<n;j++){
				if(a[j] >= 0){
					if(phanbiet == 't'|| phanbiet == 'T'){
						if(a[i] > a[j]){
							HoanVi(a[i], a[j]);
						}
					} else if(phanbiet == 'g'|| phanbiet == 'G'){
						if(a[i] < a[j]){
							HoanVi(a[i], a[j]);
						}
					}
				}
			}
		}
	}
}
int main(){
	int a[Max],n;
hoang:
	NhapDuLieu(n);
	NhapMang(a,n);
	printf("\n");
	XuatMang(a,n);
	printf("\nBan muon sap xep day so duong trong mang tang dan hay giam dan?\n(nhan t de xep tang dan, nhan g de xep giam dan, nhan phim bat ki de thoat).");
	char phanbiet = getch();
	if(phanbiet == 't'|| phanbiet == 'T'){
		SapXep(a,n,phanbiet);
		printf("\n\nSap xep lai ->");
		XuatMang(a,n);
		return 0;
	}
	else if(phanbiet == 'g' || phanbiet == 'G'){
		SapXep(a,n,phanbiet);
		printf("\n\nSap xep lai ->");
		XuatMang(a,n);
		return 0;
	}
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
