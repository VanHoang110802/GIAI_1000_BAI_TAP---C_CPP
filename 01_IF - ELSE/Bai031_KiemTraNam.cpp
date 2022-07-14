Trái đất của chúng ta cần 365.25 ngày để quay hết một vòng quanh mặt trời. Phần dư 0.25 thực ra đã làm tròn, con số thực tế là 365.2425 ngày để trái đất quay được một 
vòng. Giá trị sai số này 0.0075 ngày (0.25 - 0.2425) khi nhân với 400 chúng ta sẽ có thêm 3 ngày nữa. Do đó, để lịch của ta chính xác, các chu kỳ 100, 200 và 300 chỉ 
có 24 năm nhuận thay vì 25. Riêng chu kỳ thứ 400 sẽ có 25 năm nhuận. Điều đó đảm bảo rằng mỗi chu kỳ 400 năm sẽ có 97 (24 + 24 + 24 + 25) năm nhuận. Như vậy, cứ 400 năm 
chúng ta sẽ có 97 năm nhuận, chứ không phải 100 nhé. Hãy viết chương trình kiểm tra giá trị nguyên year nhập từ bàn phím có phải là năm nhuận không (theo dương lịch).
Lưu ý: Giá trị năm (year) được coi là hợp lệ nếu: 0<year<=100000. Do đó, chương trình của bạn cũng cần kiểm tra giá trị này có hợp lệ hay không!
input: 2020 	->output: YES

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(){
	int year;
	scanf("%d",&year) ;
	if(year <= 0 || year > 100000){
		printf("INVALID") ;
	}else{
		if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0){
			printf("YES");
		}else{
			printf("NO");
		}
	}
	return 0;
}
