Cho hai số nguyên dương a và b. Hãy vẽ lưu đồ, tìm ước chung lớn nhất
của hai giá trị này.
/*
16: 1,2,4,8,16
8: 1,2,4,8
-> UCLN: 8
*/
#include <stdio.h>
#include<conio.h>
void NhapDuLieu(int &n){
	printf("Nhap so: ");
	scanf("%d", &n);
}
int UocChungLonNhat(int a, int b){
	int min = a < b ? a : b;
	int max = a > b ? a : b;
	int ucln;

	if (max % min == 0) {	// mình chỉ xét min thôi còn max chắc chắn không chia hết được rồi.
		ucln = min;
	}
	else {
		for (int i = min / 2; i >= 1; i--) {
			if (max % i == 0 && min%i==0) {
				ucln = i;
				break;
			}
		}
	}
	return ucln;
}

int main(){
hoang:
	int a, b;
	int n;
	do{
	NhapDuLieu(a);
	if(a<= 0){
		printf("a > 0. Xin hay nhap lai!\n");
	}
	}while(a<= 0);
	do{
	NhapDuLieu(b);
	if(b<= a){
		printf("b > a. Xin hay nhap lai!\n");
	}
	}while(b<= a);
	int ucln = UocChungLonNhat(a,b);
	printf("%d", ucln);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim space de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if( lc == 32){
		goto hoang;
	}
	return 0;
}
