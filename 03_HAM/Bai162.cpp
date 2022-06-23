Bài tập chương câu lệnh lặp. Hàm nhận vào một
số nguyên dương n và thực hiện:

a. Trả về số đảo của số đó.
#include<stdio.h>
#include<conio.h>
#include<math.h>
void NhapDuLieu(int &x){
	printf("Nhap so = ");
	scanf("%d", &x);
}
int TraVeSoDao(int n){
	int soluongchuso = log10((double)n);
	int s = 0;
	while(n!=0){
		s += n % 10 * pow(10,soluongchuso--);
		n/=10;
	}
	return s;
}
int main(){
hoang:
	int n;
	NhapDuLieu(n);
	int Sodao = TraVeSoDao(n);
	printf("So dao la: %d", Sodao);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim space de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if( lc == 32){
		goto hoang;
	}
	return 0;
}
 
		---------------
b. Có phải là số đối xứng (Trả về True/False)

#include<stdio.h>
#include<conio.h>
#include<math.h>
void NhapDuLieu(int &x){
	printf("Nhap so = ");
	scanf("%d", &x);
}
int TraVeSoDao(int n){
	int soluongchuso = log10((double)n);
	int s = 0;
	while(n!=0){
		s += n % 10 * pow(10,soluongchuso--);
		n/=10;
	}
	return s;
}
int KiemTraDoiXung(int n){
	if(n == TraVeSoDao(n)){
		return 1;
	}
	return 0;
}
int main(){
hoang:
	int n;
	NhapDuLieu(n);
	int kiemtra = KiemTraDoiXung(n);
	if(kiemtra == 1){
		printf("Day la so doi xung");
	} else {
		printf("Day khong la so doi xung");
	}
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim space de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if( lc == 32){
		goto hoang;
	}
	return 0;
}

 		---------------
c. Có phải là số chính phương.

#include<stdio.h>
#include<conio.h>
#include<math.h>
void NhapDuLieu(int &x){
	printf("Nhap so = ");
	scanf("%d", &x);
}
int KiemTraChinhPhuong(int n){
	float ketqua = sqrt((float)n);
	if(ketqua == (int)ketqua){
		return 1;
	}
	return 0;
}
int main(){
hoang:
	int n;
	NhapDuLieu(n);
	int kiemtra = KiemTraChinhPhuong(n);
	if(kiemtra == 1){
		printf("Day la so chinh phuong");
	} else {
		printf("Day khong la so chinh phuong");
	}
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim space de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if( lc == 32){
		goto hoang;
	}
	return 0;
}

		---------------
d. Có phải là số nguyên tố.

#include<stdio.h>
#include<conio.h>
#include<math.h>
void NhapDuLieu(int &x){
	printf("Nhap so = ");
	scanf("%d", &x);
}
int KiemTraNguyenTo(int n){
	if(n < 2){
		return 0;
	}
	else {
		if(n!= 2 && n % 2 == 0){
			return 0;
		}
		for(int i =3;i<= (int)sqrt((double)n);i+=2){
			if(n%i == 0){
				return 0;
			}
		}
	}
	return 1;
}
int main(){
hoang:
	int n;
	NhapDuLieu(n);
	int kiemtra = KiemTraNguyenTo(n);
	if(kiemtra == 1 ){
		printf("Day la so nguyen to");
	} else {
		printf("Day khong la so nguyen to");
	}
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim space de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if( lc == 32){
		goto hoang;
	}
	return 0;
}

		---------------
e. Tổng các chữ số lẻ.

#include<stdio.h>
#include<conio.h>
#include<math.h>
void NhapDuLieu(int &x){
	printf("Nhap so = ");
	scanf("%d", &x);
}
int TongCacChuSoLe(int n){
	int chuso, s = 0;
	while(n!= 0){
		chuso = n % 10;
		n/=10;
		if(chuso % 2 !=0){
			s+=chuso;
		}
	}
	return s;
}
int main(){
hoang:
	int n;
	NhapDuLieu(n);
	int tong = TongCacChuSoLe(n);
	printf("Tong = %d", tong);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim space de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if( lc == 32){
		goto hoang;
	}
	return 0;
}

		---------------
f. Tổng các chữ số nguyên tố.

#include<stdio.h>
#include<conio.h>
#include<math.h>
void NhapDuLieu(int &x){
	printf("Nhap so = ");
	scanf("%d", &x);
}
int KiemTraNguyenTo(int n){
	if(n < 2){
		return 0;
	}
	else {
		if(n!= 2 && n % 2 == 0){
			return 0;
		}
		for(int i =3;i<= (int)sqrt((double)n);i+=2){
			if(n%i == 0){
				return 0;
			}
		}
	}
	return 1;
}
int TongCacChuSoNguyenTo(int n){
	int chuso, s = 0;
	while(n!= 0){
		chuso = n % 10;
		n/=10;
		if(KiemTraNguyenTo(chuso) == 1){
			s+=chuso;
		}
	}
	return s;
}
int main(){
hoang:
	int n;
	NhapDuLieu(n);
	int tong = TongCacChuSoNguyenTo(n);
	printf("Tong = %d", tong);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim space de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if( lc == 32){
		goto hoang;
	}
	return 0;
}

		---------------
g. Tổng các chữ số chính phương.

#include<stdio.h>
#include<conio.h>
#include<math.h>
void NhapDuLieu(int &x){
	printf("Nhap so = ");
	scanf("%d", &x);
}
int KiemTraChinhPhuong(int n){
	float ketqua = sqrt((float)n);
	if(ketqua == (int)ketqua){
		return 1;
	}
	return 0;
}
int TongCacChuSoChinhPhuong(int n){
	int chuso, s = 0;
	while(n!= 0){
		chuso = n % 10;
		n/=10;
		if(KiemTraChinhPhuong(chuso) == 1){
			s+=chuso;
		}
	}
	return s;
}
int main(){
hoang:
	int n;
	NhapDuLieu(n);
	int tong = TongCacChuSoChinhPhuong(n);
	printf("Tong = %d", tong);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim space de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if( lc == 32){
		goto hoang;
	}
	return 0;
}
