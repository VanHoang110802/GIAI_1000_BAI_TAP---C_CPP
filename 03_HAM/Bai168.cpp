Tìm phương án tối ưu (số tờ tiền là ít nhất) kết hợp 3 loại giấy bạc 100đ, 200đ, 500đ với nhau để cho ra số 
tiền 10000đ.

Gợi ý: Phương án tối ưu: 1 tờ 100đ, 2 tờ 200đ, 19 tờ 500đ

#include <stdio.h>
void TinhTien(){
    int tien = 10000;
    for(int i = 1; i <= tien/ 100;i++){
        for(int j =1;j<=tien/ 200;j++){
            for(int k =1;k<=tien/ 500;k++){
                if((i*100) + (j *200) + (k*500) == tien){
                    printf("%d %d %d", i, j, k);
                    return 0;
                }
            }
        }
    }
}
int main(){
hoang:
    TinhTien();
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim space de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if( lc == 32){
		goto hoang;
	}
    return 0;
}
