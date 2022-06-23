Một ngày nọ, Tí đến nhà sách trung tâm để mua sắm sách vở và các dụng cụ học tập cần thiết, chuẩn bị cho năm học mới. Tí cần mua thêm A quyển vở và B cây bút. Tại nhà sách trung tâm, giá của mỗi quyển vở là X và giá của mỗi cây bút là Y . Hãy giúp Tí xác định số tiền ít nhất cần mang theo nhé.
input: 2 3 4 1		-> output: 11
input: 1 0 3 5		-> output: 3

#include <iostream>
using namespace std;
int main(){
	int a, b, x, y, z;
	cin >> a >> b >> x >> y;
	z = (a*x)+(b*y);
	cout << z;
	return 0;
}
