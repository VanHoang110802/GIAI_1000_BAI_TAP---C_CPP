Viết chương trình dùng dấu , để ngăn cách ra mệnh giá tiền
vd: 
nhập n = 1000000
=> xuất ra: 1,000,000
nhập n = 1234
=> xuất ra: 1,234

/*
Ý tưởng: giả sử ta nhập vào số 12345678

Nhìn ra quy tắc xem số nguyên bất kì sẽ có bao nhiêu dấu phấy? 
số dấu phẩy = (số lượng chữ số - 1) /3
số cụm = 3

n = 12,345,678 -> có 8 chữ số 
số dấu phẩy = (số chữ số -1)/3 = 7 / 3 = 2.
số cụm = số dấu phẩy +1 = 2 +1 = 3.

*/

/*
	Sau khi kết thúc vòng while để đếm xem có bao nhiêu chữ số. Ta phải nhớ cập nhật lại temp = n chứ
	nếu không, lúc này temp luôn bằng 0 rồi, vì trước đó temp liên tục chia 10.
	Cụ thể nếu nhập 1234567 nó in ra 1 234 567
	Nhưng nếu nhập 1000000 thì nó chỉ in ra 1 0 0
	Vậy nên ta có thể xét riêng trường hợp chữ số đầu tiên. Rồi các cụm 3 phía sau thì cứ mặc định xuất đủ 3 chữ số

*/

#include <stdio.h>
#include <conio.h>
#include <math.h>
int main() {
hoang:
	int n;
	printf("Nhap n= ");
	scanf("%d", &n);

	int dem = 0;
	int temp = n;
	while (temp > 0) {
		temp /= 10;
		dem++;
	}
	temp = n;
	int sodauphay = (dem - 1) / 3;
	int luythua = pow(10.0, (3 * sodauphay));
	int a = temp / luythua;
	printf("-> %d", a);
	temp %= luythua;
	while (--sodauphay >= 0) {
		luythua = pow(10.0, (3 * sodauphay));
		a = temp / luythua;
		printf(",%03d", a);
		temp %= luythua;
	}
	/*
	 giảm sodauphay đi 1 đơn vị.Rồi sau đó kiểm tra xem sodauphay có khác 0 không ?
	 Nếu khác thì thoả -> đi vào vòng lặp. Không thỏa thì dừng vòng lặp
	*/
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
