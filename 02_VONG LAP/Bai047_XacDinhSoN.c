Nhập một số nguyên dương n (n > 0). Hãy cho biết:

a. Có phải là số đối xứng? Ví dụ: 121, 12021, …
/*
Thuật toán: Ta nhập n là số bất kì, rồi sau đó đi tìm, tính ra được số đảo ngược của chính số vừa nhập đó, nếu số đảo ngược 
vừa tính được đó mà bằng với số n ban đầu -> nó là số đối xứng, còn không bằng nhau thì không là số đối xứng
Gỉa sử n = 123456
-> số nghịch đảo của nó : 654321. Vậy ta làm như thế nào? 
- Ta thấy để đảo ngược được số 6, ta phải nhân với 10^5 ( hay có nghĩa là 6 * 100000)
- Để đảo được số 5, ta đem nhân với 10^4, số 4 thì nhân 10^3
- Để ý kĩ, số mũ ngày càng giảm dần -> mũ--
- Mũ thì tìm như nào ? dù dốt toán, ta vẫn phải cần đến công thức log của 1 số, ta sẽ dùng công thức log để tìm ra được số 
chữ số, tìm được log chữ số thì đó chính là số mũ ta cần tìm.
- Cuối cùng, nếu số đảo đó bằng với chính số ban đầu(số n vừa nhập), ta có được số đối xứng.
*/

#include <stdio.h>
#include <conio.h>
#include <math.h>
int main() {
hoang:
	int n;
	do {
		printf("Nhap so n= ");
		scanf("%d", &n);
		if (n <= 0) {
			printf("Vui long nhap lai! n > 0");
		}
	} while (n <= 0);
	int temp = n;
	int dem = log10((double)temp);
	int sodaonguoc = 0;
	printf("Cac chu so bi tach la: ");
	while (temp !=0)
	{
		int chuso = temp % 10;
		temp /= 10;
		printf("%d ", chuso);
		sodaonguoc += chuso * pow(10.0, dem--);
		
	}
	printf("\nSo dao nguoc: %d", sodaonguoc);
	if (n == sodaonguoc) {
		printf("\nDay la so doi xung!");
	}
	else {
		printf("\nDay khong la so doi xung!");
	}
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}

			------------------

b. Có phải là số chính phương? Ví dụ: 0, 1, 4, 9, 16, 25 …
/*
Bài này đơn giản không cần xét vòng lặp cho nặng đầu, ta nhập 1 số n bất kì, rồi dùng sqrt kiểm tra căn của số n đó, rồi
 dùng câu lệnh if- else so sánh, ta so sánh: nếu số kết quả khai căn mà bằng chính kết quả khai căn mà ta sẽ ép kiểu thì 
đó chính là số chính phương.
VD: kết quả của số n = 5 khi khai căn là 2.236
	-> đem ép kiểu là 2.000 -> không giống nhau -> không là số chính phương. 
*/

#include <stdio.h>
#include <conio.h>
#include <math.h>
int main() {
hoang:
	int n;
	do {
		printf("Nhap n= ");
		scanf("%d", &n);
		if (n <= 0) {
			printf("Vui long nhap lai n, n > 0 !\n");
		}
	} while (n <= 0);
	double kq = sqrt((double)n);
	int check = 0;
	if (kq == (int)kq) {
		check = 1;
		}
	if (check == 1) {
		printf("Day la so chinh phuong!");
	}
	else {
		printf("Day khong la so chinh phuong!");
	}
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
			------------------

c. Có phải là số nguyên tố? Ví dụ: 2, 3, 5, 7, 11, 13 …
/*
Số nguyên tố là số chia hết cho chính nó và 1. Ta sẽ chỉ xét số 2 và các số lẻ mà thôi ( vì 2 chỉ chia hết cho 1 và 
chính nó, còn tất cả các số chẵn sao mình không xét? Vì nó đã có thể chia hết cho cùng với 1 số chẵn khác rồi nên 
ta không cần xét thêm làm gì nữa cho mệt).
*/

#include <stdio.h>
#include <conio.h>
#include <math.h>
int main(){
hoang:
	int n;
	do {
		printf("Nhap n= ");
		scanf("%d", &n);
		if (n <= 0) {
			printf("Vui long nhap lai n, n >0 !\n");
		}
	} while (n <= 0);

	int temp = n, check = 1;
	for (int i = 2; i * i <= temp; i++) {
		if (temp % i == 0) {
			check = 0;
			break;
		}
	}

	if (check == 1 && temp >= 2) {
		printf("Day la so nguyen to!");
	}
	else {
		printf("Day khong la so nguyen to!");
	}
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}

			------------------

d. Các chữ số có tăng dần hay giảm dần không ? Lưu ý ở chỗ này cần phải phân biệt rõ ràng giữa tăng dần “nghiêm 
ngặt” và “không nghiêm ngặt”.
Tăng dần nghiêm ngặt: Chữ số đằng sau bắt buộc phải lớn hơn đằng trước. Vd: 123456
Tăng dần không nghiêm ngặt: Chữ số đằng sau có thể >= chữ số đằng trước. Vd: 1122334566

tăng dần: b>a && c>b && d>c && e >d
 - Nên nhớ, không có ai đi chứng minh nó đúng hết, vì nếu chứng minh như thế rất lâu, tốn thời gian, thay vào 
đó người ta sẽ chứng minh ngược lại, chứng minh ngược lại như thế sẽ nhanh hơn, đỡ tốn thời gian với công sức
 của mình hơn. 
 - Đk ngược lại: b <= a || c <= b || d<=c || d<=e -> chứng minh 1 trong các điều kiện sau thì kết luận sẽ 
không tăng dần.
- Nhưng, ta sẽ thấy, nó sẽ rơi vào 1 trong hai điều kiện sau: giảm dần hoặc không tăng không giảm. 
- Mình lại đi xét thêm, nếu nó không giảm thì nó k tăng k giảm.
- Ta lấy từng cặp: 
e-d
d-c
c-b
b-a

ta đem chúng % 10, rồi sau đó /10 để loại đi chữ số cuối.
- Lưu ý: vì ta có thay đổi số vừa nhập, vì vậy không thể để nguyên số đó trong vòng lặp của chương trình được, 
ta sẽ phải lưu thêm vào 1 biến phụ, biến phụ đó sẽ thay thế biến chính để đi chạy thuật toán chương tình.

- Gỉa sử n = 12345
- chuso1 = 5 
- temp = 12345 /10 = 1234
- chuso2 = 4
- Vì temp khác 0, nên vòng lặp sẽ lặp lại, chuso còn =3, =2 , =1. Vì vậy ta nên để điều kiện lặp là 
chuso > 9 (temp >9) - nếu chữ số mà lớn hơn 9, ví dụ là 10 thì vòng lặp sẽ tiếp tục chạy, còn nếu
 nó nhỏ hơn 10 thì vòng lặp sẽ dừng lại.

#include <stdio.h>
#include <conio.h>
int main() {
hoang:
	int n;
	do {
		printf("Nhap n= ");
		scanf("%d", &n);
		if (n <= 0) {
			printf("n bat buoc phai lon hon 0, xin kiem tra lai!\n");
		}
	} while (n <= 0);
	
	int temp = n;	// lưu hết các chữ số vừa nhập của n sang biến phụ
	int checktang = 1;	// khai báo biến tăng đúng tạm thời
	int checkgiam = 1;	// khai báo biến giảm đúng tạm thời
	// đi kiểm tra chữ số xem
	if (temp < 10) {
		printf("So khong tang khong giam");
		return 0;
	}
	else {
		while (temp > 10)
		{

			int chuso1 = temp % 10;

			temp /= 10;
			int chuso2 = temp % 10;
			if (chuso1 <= chuso2) {
				checktang = 0;

			}
			if (chuso1 >= chuso2) {
				checkgiam = 0;

			}
		}
	}
	// đi kiểm tra lại
	if (checktang == 1) {
		printf("So tang dan!");
	}
	if (checkgiam == 1) {
		printf("So giam dan!");
	}
	if( checkgiam == 0 && checktang == 0) {
		printf("So khong tang khong giam!");
	}
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
