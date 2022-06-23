Viết chương trình lặp lại nhiều lần công việc nhập một ký tự và in ra mã ASCII của ký tự đó, khi nào nhập số 0 thì dừng.
	
#include <stdio.h>
#include<conio.h>
void NhapKiTu(char &kt){
    printf("Hay nhap ki tu: ");
    scanf("%c", &kt);
    printf("Ma ASCII cua ki tu la: %d", kt);
}
int main(){
hoang:
    char kt;
    NhapKiTu(kt);
	fflush(stdin);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim space de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if( lc == 32){
		goto hoang;
	}
    return 0;
}
