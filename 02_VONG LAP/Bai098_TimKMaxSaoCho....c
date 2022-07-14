Cho n là số nguyên dương. Hãy tìm giá trị nguyên dương k lớn nhất sao
cho S(k) < n. Trong đó chuỗi S(k) được định nghĩa như sau : S(k) = 1 +
2 + 3 + … + k.

#include<stdio.h>
#include<conio.h>

int main(){
hoang:
    	int n;
   	 do{
    	 	printf("\nNhap n= ");
    	 	scanf("%d", &n);
	 	if(n<0){
			printf("n >= 0, xin hay kiem tra lai!\n");
	 	}
	}while(n < 0);
   	int i = 0;
    	float S = 0;
    	while(S + i < n){
        	 i++;         //
       		 S = S + i;  // tuong duong 1 dòng S += ++i;
    	}
    	printf("Gia tri k lon nhat de S(k) = 1 + 2 + ... + k < n la: %d", i);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
   	return 0;
}
