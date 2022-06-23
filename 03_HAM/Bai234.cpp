Hãy kiểm tra các chữ số của số nguyên dương n có tăng dần từ trái
sang phải hay không?
/*
n= 13572 -> các chữ số không tăng dần
n= 13578 -> các chữ số tăng dần.
*/

#include <stdio.h>
#include<conio.h>
void NhapDuLieu(int &n){
	printf("Nhap so: ");
	scanf("%d", &n);
}
int KiemTraSoTangDan(int n){
	int temp = n;
    	int check =1;
    	int cs1 = temp %10; // gán mặc định cho 1 chữ số cuối
    	temp /=10;
    	while(temp !=0){
        	int cs2 = temp %10;
        	temp /=10;
        	if(cs2 >= cs1){
           	 	check = 0;
           	 	break;
        	}
        	cs1 = cs2;
    	}
	if(check ==1){
       		return 1;
    	} 
	return 0;
}
int main() {
hoang:
	int n;
	do{
	NhapDuLieu(n);
	if(n<= 0){
		printf("n > 0. Xin hay nhap lai!\n");
	}
	}while(n<= 0);
	int kiemtra = KiemTraSoTangDan(n);
	if(kiemtra == 1){
		printf("\nDay so tang dan tu trai sang phai!");
	} else {
		printf("\nDay so khong tang dan tu trai sang phai!");
	}	
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim space de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if( lc == 32){
		goto hoang;
	}
	return 0;
}
