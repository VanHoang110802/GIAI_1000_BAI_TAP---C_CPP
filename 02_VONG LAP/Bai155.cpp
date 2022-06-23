Viết chương trình in ra tam giác cân có độ cao h.
a. Tam giác cân đặc nằm giữa màn hình.
Ví dụ với h = 4

		*
	      * * *
	    * * * * *
          * * * * * * *

#include <stdio.h>
#include <conio.h>
int main(){
hoang:
	int h;
	do{
		printf("Nhap chieu cao = ");
		scanf("%d", &h);
		if(h <= 3){
			printf("Chieu cao de ve nhap khong hop le, phai > 3, xin hay kiem tra lai!\n");
		}
	} while(h <= 3);
	printf("\n");
	// cách 1: 
	/*for(int i = 1; i <= h; i++){
    		printf("\t");
        	for(int j = 1; j <= h + i - 1; j++){
			if((j <= h - i + 1)){
				printf("* ");
			}else printf(" ");
        	}
        	printf("\n");
    	} */
	
	// cách 2: 
	for (int i = 1; i <= h; i++)
	{
		printf("\t");
		//in khoang trang
		for (int j = 1; j <= h - i; j++)
		{
			printf(" ");
		}
		//in *
		for (int k = 1; k <= i; k++)
		{
			printf("* ");
		}
		printf("\n");
	}
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
---------------------------------------------------------------------------------
b. Tam giác cân rỗng nằm giữa màn hình.
Ví dụ với h = 4

		*
 	      *   *
	    *       *
	  * * * * * * *
	
#include <stdio.h>
#include <conio.h>
int main(){
hoang:
	int h;
	do{
		printf("Nhap chieu cao = ");
		scanf("%d", &h);
		if(h <= 3){
			printf("Chieu cao de ve nhap khong hop le, phai > 3, xin hay kiem tra lai!\n");
		}
	} while(h <= 3);
	printf("\n");
	for(int i = 1; i <= h; i++){
    		printf("\t");
        	for(int j = 1; j <= h + i - 1; j++){
            		printf((j == h - i + 1|| j == h + i -1 || i == h)  ? "*" : " ");
        		}
        	printf("\n");
    	}
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
---------------------------------------------------------------------------------
c. Tam giác vuông cân đặc
Ví dụ với h = 4

	* 
	* *
	* * *
	* * * *

#include <stdio.h>
#include <conio.h>
int main(){
hoang:
	int h;
	do{
		printf("Nhap chieu cao = ");
		scanf("%d", &h);
		if(h <= 3){
			printf("Chieu cao de ve nhap khong hop le, phai > 3, xin hay kiem tra lai!\n");
		}
	} while(h <= 3);
	printf("\n");
	for(int i =1;i<=h ;i++){
		printf("\t");
		for(int j = 1; j<= i;j++){
			printf("*");
		}
		printf("\n");
	}
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}

---------------------------------------------------------------------------------------------------

d. Tam giác vuông cân rỗng
Ví dụ với h = 5

	* 
	* *
	*   *
	*     *
	* * * * *

#include <stdio.h>
#include <conio.h>
int main(){
hoang:
	int h;
	do{
		printf("Nhap chieu cao = ");
		scanf("%d", &h);
		if(h <= 3){
			printf("Chieu cao de ve nhap khong hop le, phai > 3, xin hay kiem tra lai!\n");
		}
	} while(h <= 3);
	printf("\n");
	for(int i = 1; i <= h; ++i) {
		printf("\t");
        	for(int j = 1; j <= h; ++j){
			if((j == i || j == 1 || i == h)){
				printf("*");
			} else printf(" ");
        	}
        	printf("\n");
    	}
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
