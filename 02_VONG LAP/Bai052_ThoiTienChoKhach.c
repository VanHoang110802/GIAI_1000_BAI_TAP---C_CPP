Hệ thống tiền Việt Nam có các mệnh giá sau:
500 đ
1000 đ
2000 đ
5000 đ
10000 đ
20000 đ
50000 đ
100000 đ
200000 đ
500000 đ
Người mua hàng phải trả tiền cho sản phẩm mà họ đã mua. Hãy nhập vào giá tiền của món đồ và tiền khách
hàng trả, viết chương trình hỗ trợ nhân viên cửa hàng thối tiền lại cho khách hàng sao cho số tờ tiền phải
thối lại là ít nhất.

/*
Ý tưởng: 
Ta thấy mệnh hía hiện tại của tờ tiền Việt Nam có giá như đề bài cho. Đầu tiên chắc chắn là phải nhập giá
 của sản phầm với số tiền khách hàng đưa trả cho sản phẩm rồi. Để ý thấy được rằng mỗi mệnh giá tiền hơn 
nhau gấp 2 lần, để xét qua từng mệnh giá này sang mệnh giá khác ( hoặc xét xuống mệnh giá thấp hơn), thì
 sẽ chia cho 2. Tuy nhiên sẽ có ra mệnh giá 25k, 250k, mà trong đề không cho mệnh giá như vậy, ta sẽ phải 
chấp nhận xét 1 trường hợp khác đó là trừ đi cái đơn vị để cho ra mệnh giá đúng với mệnh giá yêu cầu của 
đề bài . Sau đó ta dùng phép chia hết để lấy số lần đếm, mỗi lần lấy được ta lại xét đến trường hợp giá
 trị thấp hơn, cho đến khi nó bằng 0 thì ngừng lại. -> Ra được số tờ tiền cần tìm.

*/

#include <stdio.h>
#include <conio.h>
int main() {
hoang:
		int giatiencuasanpham, tiencuakhach, tien;
		do {
			printf("Nhap gia san pham: ");
			scanf_s("%d", &giatiencuasanpham);
			if (giatiencuasanpham < 500) {
				printf("Gia nhap cho san pham khong hop le! Xin kiem tra lai");
			}
		} while (giatiencuasanpham < 500);
	
		do {
			printf("Nhap tien khach dua: ");
			scanf_s("%d", &tiencuakhach);
			if (tiencuakhach < giatiencuasanpham) {
				printf("Xin loi so tien cua khach khong du de thuc hien !");
			}
		} while (tiencuakhach < giatiencuasanpham);
		
		tien = tiencuakhach - giatiencuasanpham;
		printf("So tien phai thoi lai cho khach la: %d\n", tien);

		int X = 500000;		// mệnh giá mặc định cho là mệnh giá lớn nhất.
		int dem;

		while (tien != 0) {
			// nếu số tiền là 25, thì quy đổi thành 10,20,50 cho đúng mệnh giá. 

			if (X == 250000) {
				X -= 50000;
			}
			else if (X == 25000) {
				X -= 5000;
			}
			else if (X == 2500) {
				X -= 500;
			}

			if (tien > X) {
				dem = tien / X;
				tien %= X;
				printf("So to menh gia %d co %d to!\n", X, dem);
			}
			X/=2; 	// mỗi mệnh giá tiền trước đó sẽ bằng 1 nửa so với mệnh giá tiền đằng sau
		}
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
