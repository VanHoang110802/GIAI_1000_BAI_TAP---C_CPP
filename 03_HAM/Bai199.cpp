Viết chương trình tìm số lớn nhất trong ba số thực a, b, c.

#include<stdio.h>
#include<conio.h>
void NhapDuLieu(float &n){
	printf("Nhap so: ");
	scanf("%f", &n);
}
void TimMax(){
	max = a;
    if(max < b)
        max = b;
    if(max < c)
        max = c;
}
int main(){
hoang:
    	float a, b, c;
    	NhapDuLieu(a);
	NhapDuLieu(b);
	NhapDuLieu(c);
	float max = TimMax(a,b,c);
    	printf("So lon nhat trong 3 so %.3f, %.3f, %.3f, la: %.3f", a, b, c, max);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim space de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if( lc == 32){
		goto hoang;
	}
    return 0;
}
