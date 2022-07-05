/*
Hãy khai báo kiểu dữ liệu biểu diễn khái niệm đơn thức 𝑃(𝑥) = 𝑎𝑥𝑛 trong toán học và định nghĩa hàm
nhập, hàm xuất cho kiểu dữ liệu này.

Đơn thức là biểu thức đại số chỉ gồm một số, hoặc một biến, hoặc một tích giữa các số và các biến.
 VD: P(x) = 5x^4.y^3.z
	 P(x) = 12.x^2.y.z
	 -> Tuy nhiên ta chỉ nên quan tâm cái này: P(x) = 4.z^x
	 mấy cái trên chỉ là để biết thôi
	 (. là nhân nhá, chỉ là viết ra như trên để cho dễ nhìn :vv)
*/

#include"DonThuc.h"

int main()
{
	DONTHUC dt;
	NhapDonThuc(dt);
	XuatDonThuc(dt);
	return 0;
}
