Viết chương trình nhập vào ngày, tháng, năm. Tính xem ngày đó là ngày thứ bao nhiêu trong năm.

#include<stdio.h>
#include<conio.h>
int main(){
hoang:
    int ngay, thang, nam;
    do{
  		printf("Nhap ngay: ");
    	scanf("%d", &ngay);
    	if(ngay < 1 || ngay > 31){
    		printf("So ngay nhap khong hop le, xin kiem tra lai!\n");
		}
	}while(ngay <1);
   	do{
  		printf("Nhap thang: ");
    	scanf("%d", &thang);
    	if(thang < 1 || thang > 12){
    		printf("So thang nhap khong hop le, xin kiem tra lai!\n");
		}
	}while(thang <1 || thang > 12);
	do{
  		printf("Nhap nam: ");
    	scanf("%d", &nam);
    	if(nam < 1 ){
    		printf("So nam nhap khong hop le, xin kiem tra lai!\n");
		}
	}while(nam <1);
	printf("Ngay thang nam: %d/%d/%d\n", ngay, thang, nam);
    int s = ngay;
    for(int i = 1; i < thang; i++){
		if(i==4 ||i == 6 || i == 9 || i == 11 ){
			s+= 30;
		} else if(i == 2){
			if(nam % 4 == 0 && nam % 100 != 0 || nam % 400 == 0){
				s+= 29;
			} 
			else s+=28;
		} else {
			s+=31;
		}
    }
    printf("Ngay thu %d trong nam.", s);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
    return 0;
}
