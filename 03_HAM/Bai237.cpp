Cho hai số nguyên dương a và b. Hãy vẽ lưu đồ, tìm bội chung nhỏ nhất
của hai giá trị này.
/*
n1 = 5 = 5, 10,15,20,25,30,35,40,45.....
n2 = 8 = 8,16,24,32,40,48,54.....
-> BSCNN = 40.
*/
#include <stdio.h>
#include<conio.h>
void NhapDuLieu(int &n){
	printf("Nhap so: ");
	scanf("%d", &n);
}
float BoiChungNhoNhat(int a, int b){
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
	int tich = a * b;
	float bcnn = (float)tich / ucln;
	return bcnn;
}

int main(){
hoang:
	int a, b;
	do{
	NhapDuLieu(a);
	if(a<= 0){
		printf("a > 0. Xin hay nhap lai!\n");
	}
	}while(a<= 0);
	do{
	NhapDuLieu(b);
	if(b<= a){
		printf("b > 0. Xin hay nhap lai!\n");
	}
	}while(b<= a);
	float bcnn = BoiChungNhoNhat(a,b);
	printf("%f", bcnn);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim space de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if( lc == 32){
		goto hoang;
	}
	return 0;
}
