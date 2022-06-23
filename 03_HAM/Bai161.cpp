Bài tập chương câu lệnh điều kiện và rẽ nhánh:
a. Viết hàm đổi một ký tự hoa sang ký tự thường.
#include<stdio.h>
#include<conio.h>
char DoiKyTuHoaThuong(char x){
	if(x >= 'A' && x <= 'Z'){
		x+=32;	
	}
	return x;
}
int main(){
hoang:
	char x;
	printf("Nhap ki tu: ");
	scanf("%c", &x);
	char biendoi = DoiKyTuHoaThuong(x);
	printf("Ki tu sau khi bien doi: %c",biendoi);
	
	// xóa đi bộ nhớ đệm để tránh lỗi.
	fflush(stdin);					
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim space de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if( lc == 32){
		goto hoang;
	}
	return 0;
} 
		---------------

b. Viết thủ tục giải phương trình bậc nhất.
#include<stdio.h>
#include<conio.h>
void GiaiPTBac1(float a, float b){
	if(a == 0){
		if(b==0){
			printf("Phuong trinh co vo so nghiem!");
		} else {
				printf("Phuong trinh vo nghiem!");
			}
	} else {
		float x = -b/a;
		printf("x = %.3f", x);
	}
}
int main(){
hoang:
	float a,b;
	printf("Nhap a= ");
	scanf("%f", &a);
	printf("Nhap b= ");
	scanf("%f", &b);
	GiaiPTBac1(a,b);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim space de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if( lc == 32){
		goto hoang;
	}
	return 0;
}
		---------------

c. Viết thủ tục giải phương trình bậc hai.
#include<stdio.h>
#include<conio.h>
#include<math.h>
void NhapDuLieu(float &x){
	printf("Nhap so = ");
	scanf("%f", &x);
}
void GiaiPTBac1(float a, float b){
	if(a == 0){
		if(b==0){
			printf("Phuong trinh co vo so nghiem!");
		} else {
				printf("Phuong trinh vo nghiem!");
			}
	} else {
		float x = -b/a;
		printf("x = %.3f", x);
	}
}
void GiaiPTBac2(float a, float b, float c){
	if(a == 0){
		GiaiPTBac1(b,c);
	} else {
		float denta = b*b - 4 *a*c;
		if(denta < 0){
			printf("Phuong trinh vo nghiem");
		} else if(denta == 0){
			float x = -b/(2*a);
			printf("Phuong trinh co nghiem kep x = %.3f",x");
		} else {
			float x1 = (-b+sqrt(denta))/(2*a);
			float x2 = (-b-sqrt(denta))/(2*a);
			printf("Phuong trinh co nghiem:\nx1 = %.3f\nx2 = %.3f",x1,x2);
		}
	}
}
int main(){	
hoang:
	float a,b,c;
	NhapDuLieu(a);
	NhapDuLieu(b);
	NhapDuLieu(c);
	GiaiPTBac2(a,b,c);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim space de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if( lc == 32){
		goto hoang;
	}
	return 0;
}
		---------------

d. Viết hàm trả về giá trị nhỏ nhất của 4 số nguyên.
#include<stdio.h>
#include<conio.h>
#include<math.h>
void NhapDuLieu(int &x){
	printf("Nhap so = ");
	scanf("%d", &x);
}
int TimMin(int a, int b){
	return a < b ? min = a:b;
}
int main(){	
hoang:
	float a,b,c;
	NhapDuLieu(a);
	NhapDuLieu(b);
	NhapDuLieu(c);
	NhapDuLieu(d);
	//int tim = TimMin(a,b,c,d);
	//printf("Min = %d", tim);

	/* nhưng giả sử, ông thầy bắt muốn tìm min của 2 số, 3 số hoặc 8 số thì mình làm sao ?
	 không thể viết lắm hàm lặp lại liên tục được, như vậy rất dở à :vv
	 ta chỉ cần viết hàm so sánh 2 số, rồi sau đó ta chỉ việc truyền thêm ở hàm main() là xong.
	 */
	int tim = TimMin(a,b);
	tim = TimMin(tim,c);
	tim = TimMin(tim,d);
	// các trường hợp tiếp tương tự đối với nhiều số...
	printf("Min = %d", tim);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim space de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if( lc == 32){
		goto hoang;
	}
	return 0;
}

		---------------
e. Viết thủ tục hoán vị hai số nguyên.
#include<stdio.h>
#include<conio.h>
#include<math.h>
void NhapDuLieu(int &x){
	printf("Nhap so = ");
	scanf("%d", &x);
}
void HoanVi(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}
int main(){	
hoang:
	int a,b;
	NhapDuLieu(a);
	NhapDuLieu(b);
	printf("Truoc khi thay doi: %d va %d",a,b);
	HoanVi(a,b);
	printf("\nSau khi thay doi: %d va %d", a,b);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim space de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if( lc == 32){
		goto hoang;
	}
	return 0;
}

		---------------
f. Viết thủ tục sắp xếp 4 số nguyên tăng dần.

#include<stdio.h>
#include<conio.h>
void NhapDuLieu(int &x){
	printf("Nhap so = ");
	scanf("%d", &x);
}
void HoanVi(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}
void SapXep(int &a, int &b, int &c, int &d){
	if(a>b){
		HoanVi(a,b);
	}
	if(a>c){
		HoanVi(a,c);
	}
	if(b>c){
		HoanVi(b,c);
	}
	if(b>d){
		HoanVi(b,d);
	}
	if(c>d){
		HoanVi(c,d);
	}
}
int main(){
hoang:
	int a,b,c,d;
	NhapDuLieu(a);
	NhapDuLieu(b);
	NhapDuLieu(c);
	NhapDuLieu(d);
	printf("Day so ban dau la: %d%d%d%d",a,b,c,d);
	SapXep(a,b,c,d);
	printf("\nDay so sau khi sap tang dan: %d%d%d%d",a,b,c,d);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim space de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if( lc == 32){
		goto hoang;
	}
	return 0;
}
