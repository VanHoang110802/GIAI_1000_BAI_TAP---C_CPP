/*
Nhập vào 1 số nguyên dương, sau đó sắp xếp các chữ số ở trong số nguyên dương đó tăng dần. Kết quả là 
được 1 số nguyên dương mới.

vd: Nhập vào 316851274
=> Số mới sẽ là: 112345678

Yêu cầu: Không dùng mảng, chỉ dùng các kiến thức về if else, vòng lặp & hàm.
*/

/* 
Ý TƯỞNG: 
Tách các chữ số trong số ban đầu ra. Tìm Min trong các chữ số đó.
Sau khi tìm được Min ta đề phòng có nhiều biến Min giống nhau cho nên ta đặt 1 biến đếm để duyệt hết Min.
Sau đó bắt đầu tìm sang Biến MIn tiếp theo nhưng thỏa là phải lớn hơn biến Min ban đầu.
Cứ thế nhân biến Min tìm được lần lượt cho 10^(Số lượng chữ số - 1) và cộng dồn lại.

Điều kiện dừng sẽ là khi biến Min tìm được nó chính là chữ số lớn nhất của số ban đầu.

31685127

Đầu tiên ra được Min = 1
Sau đó lấy 1 * 10^7 lưu vào S

Sau đó đếm xem số 1 vừa tìm được có mấy số 1 ? 
=> đếm ra đc có 2 số 1.
=> mình còn thiếu 1 số 1 chưa làm.
S += 1 * 10^6

Tiếp tục tìm 1 biến Min tiếp theo nhưng phải lớn hơn biến Min ban đầu.
=> Min = 2
S += 2 * 10^5

Đếm xem có tồn tại bao nhiêu chữ số 2 ?
=> chỉ có 1 (chính là số ban đầu).

Tiếp tục tìm 1 biến Min tiếp theo nhưng phải lớn hơn biến Min vừa tìm được.
=> Min = 3
S += 3 * 10^4

Đếm xem có tồn tại bao nhiêu chữ số 3 ?
=> chỉ số 1 chữ số (chính là số ban đầu).

Tiếp tục tìm biến Min tiếp theo ... và cứ thế cộng dồn lại sẽ ra kết quả.
*/


#include <stdio.h>
#include <conio.h>
#include <math.h>

int DemSoChuSo(int n){
	int dem =0;
	while(n!= 0){
		n/=10;
		dem++;
	}
	return dem;
}
int DemSoLuongChuSoPhanBiet(int n){
	int dem =0;
	while(n!= 0){
		n/=10;
		dem++;
	}
	return dem;
}
int chusolonnhat(int n){
	int max = 0;
	while(n!=0){
		int chuso = n % 10;
		n/=10;
		if(chuso > max){
			max = chuso;
		}
	}
	return max;
}
int SoSauKhiDuocSapXep(int n){
	int sum = 0;
	int dem = DemSoChuSo(n);
	int dem1 = dem;
	int min1 = -1;	// d? b?o d?m m?i ch? s? d?u l?n hon 1
	int chusomax = chusolonnhat(n);
	while(true){
		/* ta s? ph?i d?t bi?n min ph?i là 1 ch? s? c?c kì l?n d? d?m b?o
		 các s? bên trong d?m b?o luôn luôn bé d? so sánh */
		
		int min = 10;
		int temp = n;
		while(temp != 0){
			int chuso = temp %10;
			temp /= 10;
			if(chuso < min && chuso > min1){
				min = chuso;
			}
		}
		sum += min * pow(10.0,dem1 - 1);
		dem1--;
		// ki?m tra ti?p xem có bao nhiêu ch? s? trùng v?i bi?n min
		temp = n; 	// c?p nh?t l?i temp tránh temp = 0.
		int dem2 = 0;
		while(temp != 0){
			int chuso = temp %10;
			temp /= 10;
			if(chuso == min){
				dem2++ ;
			}
		}
		for(int i=2;i<=dem2;i++){
			sum+= min * pow(10.0, dem1 - 1);
		}
		min1 = min;
		if(min1 == chusomax ){
			break;
		}
	}
	return sum;
}
int main(){
hoang:
	int n = 31685127;
	int ketqua = SoSauKhiDuocSapXep(n);
	printf("%d", ketqua);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim space de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if( lc == 32){
		goto hoang;
	}
	return 0;
}
