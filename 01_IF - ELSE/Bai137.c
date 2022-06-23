Nhập vào tháng của một năm. Cho biết tháng thuộc quí mấy trong năm.
/*
1 năm có 4 quý, mỗi quý có 3 tháng.
*/
#include <stdio.h>
#include <conio.h>
int main(){
hoang:
	int thang;
	do{
		printf("Nhap vao thang: ");
		scanf("%d", &thang);
		if(thang < 1 || thang > 12){
			printf("Thang nhap khong hop le, xin kiem tra lai!\n");
		}
	}while(thang < 1 || thang > 12);
	if(thang == 1 || thang == 2 || thang == 3){
		printf("Thang thuoc quy I trong nam");
	} else if(thang == 4 || thang == 5 || thang == 6){
		printf("Thang thuoc quy II trong nam");
	} else if(thang == 7 || thang == 8 || thang == 9){
		printf("Thang thuoc quy III trong nam");
	} else  {
		printf("Thang thuoc quy IV trong nam");
	}
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
