Trả lời câu hỏi sau bằng cách duyệt tất cả các cách có thể để tìm kết quả:
Yêu nhau cau sáu bổ ba 
Ghét nhau cau sáu bổ ra làm mười 
Mỗi người một miếng trăm người 
Có mười bảy quả hỏi người ghét yêu.

Đáp án: có .. người thương và .. người ghét

Thông tin: mỗi quả cau, thông thường các cụ bổ sáu, nghĩa là chia làm sáu phần bằng nhau. Chừng này là đủ để nhóm 
nhém một buổi. Tuy nhiên, khi yêu thì thường muốn ưu tiên cho người mình yêu nhiều hơn 1 tí nên bổ làm ba thôi. Còn
khi ghét thì chỉ cho một phần mười :)
Gợi ý: có thể giải bài này bằng hệ phương trình bậc nhất với 2 ẩn là g (số người ghét), và y (số người yêu). Tuy 
nhiên, để tập cách sử dụng vòng lặp khi lập trình thì ta có thể làm bằng cách duyệt tất cả các khả năng có thể, 
phương án nào đúng thì hiển thị ra màn hình. Ví dụ, khả năng (x=0, y=0) không đúng, khả năng (x=0, y=1) không đúng,
khả năng (x=0, y=2) không đúng, cứ thử như vậy, đến một ngày đẹp trời sẽ tìm thấy!


#include <stdio.h>
#include<conio.h>
void NhapDuLieu(float &a){
	printf("Nhap so = ");
	scanf("%f",&a);
}
void GiaiHePTBac1( float a, float b, float c,float d,float e,float f){
	float D = (a*e) - (d*b);
	float Dx = (c * e) - (f * b);
	float Dy = (a * f) - (d * c);
	if (D == 0) {
		if (Dx + Dy == 0) {
			printf("Phuong trinh co vo so nghiem");
		}
		else {
			printf("Phuong trinh vo nghiem");
		}
	} else{
		float x = Dx / D;
		float y = Dy / D;
		printf("Co %.2f nguoi thuong va %.2f nguoi ghet",x,y);
	}
}
int main(){
hoang:
	float a, b,c,d,e,f;
	NhapDuLieu(a);
	NhapDuLieu(b);
	NhapDuLieu(c);
	NhapDuLieu(d);
	NhapDuLieu(e);
	NhapDuLieu(f);
	GiaiHePTBac1(a,b,c,d,e,f);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim space de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if( lc == 32){
		goto hoang;
	}
	return 0;
}
