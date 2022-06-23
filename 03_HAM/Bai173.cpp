Đọc một số tự nhiên giới hạn 10 chữ số.

vd: Nhập số tự nhiên: 1410
Đọc là: mot ngan bon tram muoi.

#include <stdio.h>
#include<conio.h>
#include< math.h>
void DaoSo(int &n){
	int soluongchuso = log10((double)n);
	int tong = 0;
	while(n!= 0){
		tong += n % 10 * pow(10, soluongchuso--);
		n/=10;
	}
	n = tong;
}
void DocChuSo(int chuso){
	if(chuso == 1){
		printf("Mot");	
	} else if(chuso == 2){
		printf("hai");
	}else if(chuso == 3){
		printf("ba");
	}else if(chuso == 4){
		printf("bon");
	}else if(chuso == 5){
		printf("nam");
	}else if(chuso == 6){
		printf("sau");
	}else if(chuso == 7){
		printf("bay");
	}else if(chuso == 8){
		printf("tam");
	}else if(chuso == 9){
		printf("chin");
	}
}
void DocPhuAm(int sochusoconlai){
	if(sochusoconlai == 1){
		printf("Muoi");
	}
	else if(sochusoconlai == 2){
		printf("Tram");
	} else if(sochusoconlai == 3){
		printf("Nghin");
	}else if(sochusoconlai == 4){
		printf("Muoi");
	}
}
void DocSo(int n){
	while(n!= 0){
		DaoSo(n);
		DocChuSo(n % 10);
		n/=10;
		DocPhuAm(log10((double)n)+ 1);
	}
}
int main(){
hoang:
	n = 12345;
	DocSo(n);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim space de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if( lc == 32){
		goto hoang;
	}
	return 0;
}
