Liệt kê các số hoàn hảo nhỏ hơn 9000. Số hoàn hảo là số có tổng các ước số của nó (không kể nó) bằng chính 
nó. Ví dụ: số 6 là số hoàn hảo vì tổng các ước số là 1+2+3=6.

#include<stdio.h>
#include<conio.h>
#include<math.h>
int KiemTraSoHoanHao(int n){
	int s = 0;
	for(int i = 1;i<= n/2;i++){
		if(n % i == 0){
			s+=i;
		}
	}
	if(n == s){
		return 1;
	} 
	return 0;
}
void LietKeSoHoanHao(int n){
	for(int i= 1;i<n;i++){
		if(KiemTraSoHoanHao(i) == 1){
			printf("%d ", i);
		}
	}
}
int main(){
hoang:
	int n = 9000;
	LietKeSoHoanHao(n);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim space de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if( lc == 32){
		goto hoang;
	}
	return 0;
}
