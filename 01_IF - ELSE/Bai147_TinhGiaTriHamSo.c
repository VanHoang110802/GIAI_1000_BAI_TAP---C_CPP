Viết chương trình nhập giá trị x sau khi tính giá trị của hàm số:
𝑓(𝑥) = { 2x^2 + 5x + 9 khi x>= 5
	-2x^2 + 4x - 9 khi x < 5

#include<stdio.h>
#include<conio.h>
int main(){
hoang:
    float x;
    printf("\nNhap x: ");
    scanf("%f", &x);
    float ketqua;
    if(x >= 5)
        ketqua = 2 * x * x + 5 * x + 9;
    else
        ketqua = -2 * x * x + 4 * x - 9;
    printf("\nKet qua = %f", ketqua);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
    return 0;
}
