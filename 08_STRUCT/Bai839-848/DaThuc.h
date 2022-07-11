#ifndef _dathuc_
#define _dathuc_

#include <iostream>
using namespace std;

struct DaThuc
{
	float* heso;
	int sobac;
};
typedef struct DaThuc DATHUC;

typedef float* Poly;
/* Còn toán tử operator thì quá dễ rồi, mỗi hàm tính toán, các thứ thêm vào operator là xong */
void NhapDaThuc(DATHUC*);
void XuatDaThuc(DATHUC*);
void* TinhTong2DT(DATHUC*, DATHUC*);
void* TinhHieu2DT(DATHUC*, DATHUC*);
void* TinhTich2DT(DATHUC*, DATHUC*);
void* TinhThuong2DT(DATHUC*, DATHUC*);
//void* TinhDaoHamCap1(DATHUC*);  // nếu chỉ tính 1 cấp đạo hàm cho đa thức thì dùng cái này
DATHUC* TinhDaoHamCap1(DATHUC*);	// nếu tính cấp n đạo hàm thì tính ở đây
void* TinhDaoHamCapk(DATHUC* , int);
//void* TinhTichPhanCapKDaThuc(DATHUC*, int);
float TinhGiaTriX(DATHUC*, float );

#endif
