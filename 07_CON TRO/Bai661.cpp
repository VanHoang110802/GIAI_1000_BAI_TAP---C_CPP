/* -------------------------------- Khai báo & khởi tạo -------------------------------- */

#pragma warning(disable : 4996)
#include<stdio.h>
#include<stdlib.h>
int main() {
	int a = 10;
	int* b;	// nên nhớ: con trỏ chứa 1 số nguyên địa chỉ
	// nguyên tắc sử dụng con trỏ: 
	// hai bên phải cùng khớp với nhau: giá trị với giá trị, địa chỉ với địa chỉ
	b = &a;	// con trỏ b -> biến bình thường a
	printf("\nGia tri cua a la: %d",a);
	printf("\nDia chi cua a la: %p", &a);

	printf("\nGia tri cua con tro b la: %d", *b);
	printf("\nMien gia tri cua con tro b la: %p", b);
	printf("\nDia chi that su ban dau cua con tro: %p", &b);

	// địa chỉ là 1 dãy 8 con số trong hệ 16, nên không lấy làm lạ gì khi có 8 con số đều là 0 hết.
	// cái nguy hiểm nhất ở đây, khi con trỏ b trỏ đến a
	(*b) += 5;	// lấy giá trị con trỏ tăng lên 5 lần, nhưng mà ở trên á, con trỏ b đang trỏ đến a rồi ( b = &a), vì vậy là:
	printf("\na = %d", a);	// a = 15 chứ không là 10 như trước.

	// con trỏ trỏ tới con trỏ khác:
	int* c;
	// bản chất c là 1 địa chỉ
	c = b;	// con trỏ c trỏ tới con trỏ b, mà b -> a, thành ra, nếu 1 trong 3 cái bị thay đổi, thì lập tức cả ba sẽ bị ảnh hưởng

	(*c) = 1108; // ta sẽ thay đổi con trỏ 1 chút để chứng minh câu trên là đúng
	printf("\n\nGia tri cua con tro c la: %d", *c);
	printf("\nMien gia tri cua con tro c la: %p", c);
	printf("\nDia chi that su ban dau cua con tro: %p", &c);

	printf("\n\na = %d", a);
	printf("\n(*b) = %d", *b);

	/*
	ta thấy được: 
	Con trỏ thành ra nó cũng là 1 đặc ân và cũng là 1 nỗi sợ hãi khi mà trỏ tới 1 vùng nhớ có thể thay đổi lại.
	Thành ra những cái game ấy, chỉ cần mình biết được địa chỉ biến nó nằm ở đâu, mình cho con trỏ trỏ tới, là chết chắc, là cập nhật lại được, nếu mà cái điểm của nó lưu trên sever, thì mỗi cái sever sẽ có 1 cái địa chỉ, và địa chỉ này là 1 dãy rất là dài,giả sử nếu bạn biết được hết cả cái dãy đó, bạn có thể truy xuất đến nó, và sửa lại được, và chắc chắn rằng, sẽ chẳng ai biết được cái địa chỉ này đâu. 
	-> Khi mà truy xuất được đến đây rồi, thì chỉnh sửa 1 phát thôi -> hack, mod game được ra đời.
	-> Mã code nhận quà thưởng cũng bắt nguồn từ đây mà ra.
	(Nói cho dễ gần gũi thì địa chỉ nó chính là cái ID ấy, ID phòng, ID nhân vật ...)
	-> Nỗi đặc ân của các game thủ và nỗi sợ hãi của nhà phát hành :)
	*/

	// nên nhớ 1 điều, muốn thay đổi hay gán 1 giá trị cho con trỏ, thì con trỏ đó, nó phải có bộ nhớ chứa được nó.
	//int* d; // nằm bơ vơ giữa ngã tư
	//*d = 5;	// nhưng hiện tại đây d mới chỉ được khai báo, chưa được cấp phát, chưa được trỏ đến 1 vùng nhớ nào cả, hoặc chưa có bộ nhớ cấp phát-> erorr.
	// thành ra, ta sẽ có 2 dạng cấp phát cho con trỏ: trực tiếp hoặc gián tiếp cho tới 1 địa chỉ nào đó.

	return 0;
}

/* -------------------------------- Kích thước chuẩn  -------------------------------- */
#include <stdio.h>
#include<stdlib.h>
int main()
{
	printf("sizeof(char*) = %d\n",sizeof(char*));         //4
	printf("sizeof(short*) = %d\n",sizeof(short*));       //4
	printf("sizeof(int*) = %d\n",sizeof(int*));           //4
	printf("sizeof(long double*) = %d\n",sizeof(long double*)); //4 
	return 0;
}

/* -------------------------------- Cấp phát -------------------------------- */

#include<stdio.h>
#include<stdlib.h>
int main() {
	int* b;	// khai báo con trỏ
	// cấp phát bộ nhớ cho con trỏ:
	b = (int*)malloc(sizeof(int));
	
/*
	Hàm malloc là hàm thuộc thư viện stdlib.h, có chức năng đảm nhiệm tạo ra 1 vùng nhớ nào đó bất kì mà mình không thể biết được rồi trả địa chỉ vùng nhớ đó về ,sau khi nó làm xong rồi, thì con trỏ b sẽ trỏ tới vị trí vùng nhớ mà thằng malloc đã tạo cấp phát sẵn.
	Bản chất malloc là 1 con trỏ vô kiểu, mà con trỏ b mình đang để kiểu int, nên mình sẽ phải ép nó về cùng kiểu để con trỏ có thể nhảy tới vùng nhớ đó (quy tắc đã được nhắc từ trước: giá trị với giá trị, địa chỉ với địa chỉ) - nói cách khác, chúng phải giống nhau, đồng bộ  với nhau.
	Tuy nhiên, nên dùng realloc để cấp phát, vì:
	malloc nếu như không nhập vào mà xuất luôn thì các phần tử sẽ là giá trị rác.
	calloc nếu như không nhập vào mà xuất luôn thì các phần tử sẽ là giá trị 0.
	realloc (bao trùm cả 2 thằng trên, và còn nhiều chức năng khác nữa).
*/
	(*b) = 11082002;
	printf("\n(*b) = %d", *b);
	free(b); 
	/*
	Giải phóng nó đi(do biến con trỏ này có địa chỉ thuộc về vùng nhớ heap nên có thể giải phóng được, không phải thuộc về stack, thường thì sẽ bắt buộc phải giải phóng),nếu không thì nó mãi vẫn nằm đó, mà biến con trỏ này thuộc vùng nhớ HEAP, do người lập trình quản lí cứ nằm đó rồi lại có thêm biến nữa, biến nữa, mà thanh RAM có giới hạn, sẽ 1 lúc nào đó tràn bộ nhớ -> đứng, treo máy. 
	 */
	/*
	Sau khi giải phóng nó đi rồi, mà xuất thêm con trỏ b nữa, vậy nó có sẽ như nào ? không biết được, vì, nó phụ thuộc vào xem có chương trình nào lấy nó để dùng hay không? Nếu không có tiến trình nào lấy nó vẫn nằm đó chưa mất được đâu, còn nếu có tiến trình nào lấy thì nó mới thật sự biến mất. Thực chất giải phóng, mang hàm ý là vấn đề bây giờ tao không còn sử dụng biến này nữa, có thằng nào có lấy dùng không, cứ lấy đi.? Nhưng mà chẳng ai lấy hết, thì nó vẫn còn đấy.
	*/
	return 0;
}

/* -------------------------------- Toán tử con trỏ   -------------------------------- */

#include <iostream>
#include<stdlib.h>
using namespace std;
int main()
{
	   
	int* pointer = NULL; // Khai báo con trỏ pointer có thể trỏ đến ô nhớ kiểu int. Con trỏ này chưa được khởi tạo vì pointer chưa trỏ đi đâu cả

	int x = 1;
	int* a = NULL; // a là con trỏ NULL. Cách làm việc với con trỏ an toàn là tốt nhất khai báo và cho con trỏ trỏ đến NULL

	// Cho con trỏ a trỏ đến biến x
	a = &x;

	// Toán tử * là toán tử lấy ra giá trị mà con trỏ đang trỏ đến
	int y = 2;
	a = &y;
	cout<< *a;

	pointer = a;
	
	cout<<"Gia tri ma con tro pointer dang tro den la "<<*pointer<<endl;
	cout<<"Dia chi cua bien y la "<<&y<<endl;
	cout<<"Dia chi ma con tro pointer dang tro den la "<<pointer<<endl; 
	cout<<"Dia chi cua chinh con tro la "<<&pointer;
	return 0;
}

/* -------------------------------- Tham số con trỏ  -------------------------------- */

/*
#include <iostream>
using namespace std;

void HoanVi(int* x, int* y) // int* x = &a;  int* y = &b;
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

int main()
{
	int a = 1;
	int b = 2;
	HoanVi(&a, &b);
	cout << "a = " << a <<" ,b = " << b;
	system("pause");
}
*/

#pragma warning(disable : 4996)
#include<stdio.h>

void HoanVi( int &a ,int &b) {
	int temp = a;
	a = b;
	b = temp;
}
void HoanViCach2(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
int main() {
	int a = 1, b = 2;
	int* c, * d;
	c = &a;
	d = &b;
	// ta có được rút ra ở trên: giá trị sẽ đi cùng với giá trị, địa chỉ sẽ đi cùng với địa chỉ
	// vậy nên, ở trên hàm mình có truyền tham chiếu dấu &, thì ở dưới hàm main, nếu là biên bình thường thì truyền vào tên biến như bình thường
	// nếu ở dưới hàm main nó là 1 con trỏ, thì lấy giá trị của con trỏ trước, rồi truyền vào thì phải có dấu * 
	// nếu ở hàm trên truyền vào là con trỏ, dưới hàm main là biến bình thường, thì phải có dấu & đằng trước để lấy địa chỉ
	// nếu ở hàm trên truyền vào là con trỏ, dưới hàm main cũng là con trỏ, thì chúng đã có tham chiếu sẵn rồi, có địa chỉ rồi, chỉ cần truyền tên thôi
	
	/*
	HoanVi(a, b);
	HoanVi(*c, *d);
	HoanViCach2(&a, &b);
	*/
	HoanViCach2(c, d);
	printf("Hoan vi a, b: \n%d %d", a, b);

	return 0;
}
