Tìm tất cả các phương án kết hợp 3 loại giấy bạc 100đ, 200đ, 500đ với nhau để cho ra số tiền 10000đ.

Phương án 1: 0 tờ 100đ,  5 tờ 200đ, 18 tờ 500đ
Phương án 2: 0 tờ 100đ, 10 tờ 200đ, 16 tờ 500đ
…
Phương án 537: 98 tờ 100đ,  1 tờ 200đ,  0 tờ 500đ

Gợi ý: trước tiên ta có nhận xét rằng trong mỗi phương án, mỗi tờ bạc mệnh giá a đồng chỉ có thể có số lượng tối 
thiểu là 0 và số lượng tối đa là 10000/a. Từ nhận xét này, ta có cách đơn giản nhất là duyệt tất cả các phương án
có thể bằng cách sử dụng 3 vòng lặp for lồng nhau, mỗi vòng for tương ứng với số tờ của mỗi loại tiền. Với mỗi khả
năng, chỉ đơn giản kiểm tra xem tổng mệnh giá có bằng 10000đ hay không. Nếu bằng thì hiển thị ra màn hình và tiếp
tục kiểm tra các khả năng khác.

#include <stdio.h>
#include<conio.h>
void TinhTien(){
    int tien = 10000;
    for(int i = 1; i <= tien/ 100;i++){
        for(int j =1;j<=tien/ 200;j++){
            for(int k =1;k<=tien/ 500;k++){
                if((i*100) + (j *200) + (k*500) == tien){
                    printf("%d %d %d", i, j, k);
                    return 0;
                }
            }
        }
    }
}
int main(){
    TinhTien();
    return 0;
}
