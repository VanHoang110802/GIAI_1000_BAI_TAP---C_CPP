 Nhập vào 2 số nguyên dương a & b với điều kiện là b > a. Hãy thực hiện các yêu cầu sau:
a. Đếm xem trong đoạn [a, b] có bao nhiêu số đối xứng, chính phương, nguyên tố
b. Tính tổng các số đối xứng, chính phương, nguyên tố trong đoạn [a, b]

#include <stdio.h>
#include <conio.h>
#include <math.h>
int main() {
hoang:
	int a, b;

	do {
		printf("a= ");
		scanf("%d", &a);
		if (a <= 0) {
			printf("a phai lon hon 0, xin kiem tra lai!\n");
		}
	} while (a <= 0);
	do {
		printf("b= ");
		scanf("%d", &b);
		if (b <= a) {
			printf("b phai lon hon a, xin kiem tra lai!\n");
		}
	} while (b <= a);

	// số chính phương

	/*Ý tưởng:  Ta cho vòng lặp chạy từ a -> b, sau đó tính căn của từng số đã được duyệt trong vòng lặp.
	Rồi sau đó ta đem đi căn những số có trong vòng lặp, ta được kết quả là 1 số thực, rồi đem đi so
	sánh kết quả số thực với kết quả số đã bị ép kiểu về số nguyên, nếu chúng bằng nhau thì in ra
	số chính phương cần tìm, còn không thì loại bỏ, mỗi lần so sánh tìm được số xong thì đếm số lượng và
	cộng vào biến tổng. */

	int demsochinhphuong = 0, tongcacsochinhphuong = 0;
	int demsonguyento = 0, tongsonguyento = 0;
	int demdoixung = 0, tongdoixung = 0;
	
	for (int i = a; i <= b; i++) {
		float kq = sqrt(float(i));
		if (kq == (int)kq) {
			demsochinhphuong++;
			tongcacsochinhphuong += i;
		}
	

	// số nguyên tố

	/*Ý tưởng: Số nguyên tố là số chia hết cho chính nó và 1. Vì vậy ta chỉ xét các số từ 2 đổ lên,
	và xét các số lẻ, nếu số lẻ nào mà chia hết cho 1 số bất kì trong đoạn ( hay trong vòng lặp đã
	được duyệt từ đoạn đó), thì lập tức loại bỏ luôn không cần xét đến, sau khi đã tìm được số nguyên
	tố thì đếm các số vừa tìm được rồi đem cộng vô biến tổng, ta hoàn thành được bài toán cần giải.*/


	// cách 1: cách này nếu xét trong đoạn [3 , n] thì đúng, nhưng không xét được cho 2!
	
	/*for (int i = a; i <= b; i++) {
		int  check = 1;
		if (i < 2) {
			check = 0;
		}
		else {
			if (i % 2 == 0) {
				check = 0;
			}
			else {
				for (int j = 2; j <= sqrt((double)i); j++) {
					if (i % j == 0) {
						check = 0;
						break;
					}
				}

			}
			if (check == 1) {
				demsonguyento++;
			}
		}
		
	}*/

	// cách 2: xét được cả cho 2 , xét được tất cả các số
	
		int check = 1;
		for (int j = 2; j * j <= i; j++) {
			if (i % j == 0) {
				check = 0;
				break;
			}
		}
		if (check == 1 && i >= 2) {
			demsonguyento++;
			tongsonguyento += i;
		}
	}

	
	// số đối xứng

	/*
	- số đối xứng là số đảo lại mà vẫn bằng chính nó không thay đổi: 121, 12021,151...
 - ý tưởng: 
giả sử ta có n= 12345, làm sao để đảo số này được đây? 
ta sẽ đi lấy từng số một bằng cách chia dư cho 10 -> n %=10
rồi sau đó loại chữ số cuối đi: n/=10
rồi lại chia tiếp.
Để đảo ngược số, ta lấy từng chữ số vừa tách ra được nhân với số mũ của 10.
lấy được chữ số :
 5*10^4 + 4*10^3 + 3*10^2 + 2*10^1 + 1*10^0 = 54321 -> số đảo ngược cần tìm
mà ta thấy số đảo ngược này thì không giống với số n ban đầu nên không thể là số đối xứng được. 
Vậy mũ, số mũ lấy đâu ra?
 ta thấy , số mũ chính là số lượng các chữ số của số n - 1( tại sao lại trừ đi 1, tại vì số
 đầu tiên ta lấy chia 10 rồi, để tách các chữ số ra rồi đảo lại, nên chỉ còn lại 4, 3 ... 
 chữ số thôi mà thôi), chẳng hạn mũ 4 chính là số lượng các chữ số nằm sau số 5, số mà chúng 
 ta đã vừa tách riêng ra để lấy từng chữ số để đảo lại đó, chia hết cho 10 ấy. Tương tự, mũ 3
 chính là số chữ số đằng sau, mũ 2, mũ 1 cũng như vậy. 
Mà lại câu hỏi nữa, số lượng chữ số, ta làm thế nào. Có hai cách, nếu không biết công thức log
trong toán học thì mình dùng vòng lặp, lại tách từng số 1, mỗi lần tách ta cho biến đếm vào 
tăng lên 1 đơn vị khi ta chia tiếp cho 10. Còn nếu dùng log thì sẽ nhanh hơn nếu như bạn biết 
công thức toán học: Log10(n) = X -> n = 10^X.
	*/

	for (int i = a; i <= b; i++) {
		int temp = i;
		int sodaonguoc = 0;
		int demchuso = log10((double)temp);	// không cần +1 vì 1-1 thì cũng như nhau không khác gì cả
		while (temp != 0) {
			int chuso = temp % 10;
			temp /= 10;
			sodaonguoc += chuso * pow(10.0, demchuso--);
		}
		if (i == sodaonguoc) {
			printf(" %d ", i);
			demdoixung++;
			tongdoixung += i;
		}
	}

	printf("\nCo %d so chinh phuong co trong doan [%d, %d]!", demsochinhphuong,a,b);
	printf("\nTong cac so chinh phuong co trong doan [%d, %d] la: %d ",a,b, tongcacsochinhphuong);
	printf("\nCo %d so nguyen to co trong doan [%d, %d] !", demsonguyento, a, b);
	printf("\nTong cac so nguyen to co trong doan [%d, %d] la: %d", a, b, tongsonguyento);
	printf("\nCo %d so doi xung trong doan [%d,%d]!", demdoixung,a,b);
	printf("\nTong cac so doi xung co trong doan [%d,%d]: %d",a,b, tongdoixung);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
