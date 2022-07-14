Hãy kiểm tra các chữ số của số nguyên dương n có tăng dần từ trái
sang phải hay không?
/*
n= 13572 -> các chữ số không tăng dần
n= 13578 -> các chữ số tăng dần.
*/

#include <stdio.h>
#include<conio.h>
int main(){
hoang:
    int n;
    do{
        printf("nhap n= ");
        scanf("%d",&n); 
        if(n<=0){
            printf("n>0, xin hay kiem tra lai\n");
        }
    }while(n<=0);
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
        printf("Chu so tang dan");
    } else{
        printf("Chu so khong tang dan");
    }
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
    return 0; 
}
