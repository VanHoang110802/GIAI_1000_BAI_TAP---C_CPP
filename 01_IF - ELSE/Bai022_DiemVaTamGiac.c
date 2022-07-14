Cho biết thông tin của tam giác gồm có 3 điểm A, B, C. Biết mỗi điểm sẽ có thông tin là hoành độ & tung độ. Viết chương trình nhập vào thông tin của 1 tam giác 
(nhập hoành độ, tung độ của lần lượt 3 điểm). Xuất tam giác ra màn hình, tính chu vi & diện tích của tam giác
/*
gợi ý: 
- chuvi = 3 cạnh cộng lại
- diện tích: áp dụng công thức Heron: 
S = sqrt(p * (p - canh1) * (p - canh2) * (p - canh3))
với p là nửa chu vi
muốn tính độ dài cạnh thì đó chính là khoảng cách giữa 2 điểm 
vd: 
AB = khoảng cách giữa điểm A & điểm B
AC  = khoảng cách giữa điểm A & điểm C
BC = khoảng cách giữa điểm B & điểm C
Câu nâng cao (*):
Không dùng công thức heron để tính diện tích mà hãy dùng công thức: S = (đáy * chiều cao) / 2
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <math.h>
int main() {
	float xA, yA, xB, yB, xC, yC;
	// -------- nhập tọa độ của 3 điểm ----------

	printf("Hoanh do cua diem A: ");
	scanf_s("%f", &xA);
	printf("Tung do cua diem A: ");
	scanf_s("%f", &yA);
	printf("Hoanh do cua diem B: ");
	scanf_s("%f", &xB);
	printf("Tung do cua diem B: ");
	scanf_s("%f", &yB);
	printf("Hoanh do cua diem C: ");
	scanf_s("%f", &xC);
	printf("Tung do x cua diem C: ");
	scanf_s("%f", &yC);
	printf("\nToa do diem A(%.2f,%.2f)", xA, yA);
	printf("\nToa do diem B(%.2f,%.2f)", xB, yB);
	printf("\nToa do diem C(%.2f,%.2f)", xC, yC);

	// ----- tính khoảng cách 2 cạnh ---------
	// d = căn ((x2-x1)^2 + (y2-y1)^2) 
	float AB,AC,BC, chuvi, p;
	AB = sqrt((xB - xA) * (xB - xA) + (yB - yA) * (yB - yA));
	AC = sqrt((xC - xA) * (xC - xA) + (yC - yA) * (yC - yA));
	BC = sqrt((xC - xB) * (xC - xB) + (yC - yB) * (yC - yB));

	printf("\nAB = %.3f", AB);
	printf("\nAC = %.3f", AC);
	printf("\nBC = %.3f", BC);

	chuvi = AB + AC + BC;
	p = chuvi / (float)2;
	double dientich = sqrt(p * (p - AB) * (p - AC) * (p - BC));
	
	printf("\nChu vi cua tam giac: %.3f", chuvi);
	printf("\nNua chu vi cua tam giac: %.3f", p);
	printf("\nDien tich cua tam giac: %.3f", dientich);

	// ------------------------------ phần nâng cao ------------------------------

	float xBA, yBA, xBC, yBC, t, xH, yH,xAH,yAH ,AH, dientich2;
	 xBA = xA - xB;
	 yBA = yA - yB;
	 xBC = xB - xC;
	 yBC = yB - yC;

	//------------- biến đổi biểu thức trên giấy, rút gọn tìm tọa độ H ------------- 

	float t = (xBC*xBA + yBC*yBA) / (xBC*xBC + yBC*yBC);
	 xH = t*xBC + xB;
	 yH = t*yBC + yB;

	//----------------------- tính độ dài (khoảng cách) AH -----------------------

	 xAH = xH - xA;
	 yAH = yH - yA;
	 AH = sqrt(xAH*xAH + (yAH*yAH));

	//----------------------- Diện tích theo hệ thức lượng -----------------------
	dientich2 = (AH * BC) / 2;
	printf("\nTheo he thuc luong trong tam giac, dien tich la: %.3f", dientich2);
	return 0;
}
