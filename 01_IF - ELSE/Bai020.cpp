Viết chương trình :
  Nhập số báo danh (số bd mình cho ngẫu nhiên được không?)
  Nhập điểm văn , toán , ngoại ngữ
  In ra màn hình dưới dạng :
    _ Phiếu điểm :
    _ Số báo danh :
    _ Điểm văn : 
    _ Điểm toán :
    _ Điểm ngoại ngữ :
    _ Tổng số điểm :
  Bạn đã trúng tuyển ( hoặc Bạn đã không trúng tuyển ) với điều kiện Tổng số điểm >= 15 hay ngược lại .

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <stdlib.h>
int main() {
    int phieudiem, sobaodanh;
    float diemtoan, diemvan, diemngoaingu, tongdiem;
    srand(time(0));
    printf("\nNhap so diem toan: ");
    scanf("%f", &diemtoan);
    printf("\nNhap so diem van: ");
    scanf("%f", &diemvan);
    printf("\nNhap so diem ngoai ngu: ");
    scanf("%f", &diemngoaingu);
    tongdiem = (diemtoan + diemngoaingu + diemvan);

    phieudiem = rand() % 20;
    printf("\nPhieu diem so: %d", phieudiem);
    sobaodanh = 100 + rand()% 999;
    printf("\n_So bao danh: %d", sobaodanh);
    printf("\nDiem toan cua ban: %.3f", diemtoan);
    printf("\nDiem van cua ban: %.3f", diemvan);
    printf("\nDiem ngoai ngu cua ban: %.3f", diemngoaingu);
    printf("\nTong diem cua ban la: %f", tongdiem);
    if (tongdiem >=15) {
        printf("\n\nXin chuc mung ban da trung tuyen!");
        return 0;
    }
    else {
        printf("\nXin chia buon ban da khong du dieu kien de trung tuyen, chuc ban may man voi hien tai!");
        return  0;
    }
    return 0;
}
