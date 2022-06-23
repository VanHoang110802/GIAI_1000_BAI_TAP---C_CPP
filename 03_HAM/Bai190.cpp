Cần có tổng 200.000đ từ 3 loại giấy bạc 1000đ, 2000đ, và 5000đ. Lập
chương tình để tìm tất cả các phương án có thể.

#include <stdio.h>
#include<conio.h>
void NhapDuLieu(int &tiencanquydoi){
	do {
		printf("Nhap so tien can quy doi: ");
		scanf("%d", &tiencanquydoi);
		if (tiencanquydoi < 500) {
			printf("Gia tien can quy doi khong hop le! Xin kiem tra lai\n");
		}
	} while (tiencanquydoi < 500);
}
void QuyDoiTien(){
	int menhgiatienmax = 500000;		// mệnh giá mặc định cho là mệnh giá lớn nhất.
		int dem;

		while (tiencanquydoi != 0) {
			// nếu số tiền là 25, thì quy đổi thành 10,20,50 cho đúng mệnh giá. 

			if (menhgiatienmax == 250000) {
				menhgiatienmax -= 50000;
			}
			else if (menhgiatienmax == 25000) {
				menhgiatienmax -= 5000;
			}
			else if (menhgiatienmax == 2500) {
				menhgiatienmax -= 500;
			}

			if (tiencanquydoi > menhgiatienmax) {
				dem = tiencanquydoi / menhgiatienmax;
				tiencanquydoi %= menhgiatienmax;
				printf("So to menh gia %d co %d to!\n", menhgiatienmax, dem);
			}
			menhgiatienmax/=2; 	// mỗi mệnh giá tiền trước đó sẽ bằng 1 nửa so với mệnh giá tiền đằng sau
		}
}
int main() {
hoang:
	int tiencanquydoi;
	do{
	NhapDuLieu(tiencanquydoi);
	if(tiencanquydoi<= 0){
		printf("Khong hop le, xin hay nhap lai!\n");
	}
	}while(tiencanquydoi<= 0);
	QuyDoiTien(tiencanquydoi);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim space de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if( lc == 32){
		goto hoang;
	}
	return 0;
}
