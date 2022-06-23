Hãy viết chương trình liệt kê tất cả các số Amstrong nằm trong đoạn [1,1000000] .
Định nghĩa:Số Amstrong là số mà từng chữ số của nó mũ theo số lượng các chữ số rồi cộng lại = chính số ban đầu =?số 
Amstrong. 
vd:số 153 có 3 chữ số và 153=1^3+5^3+3^3 => 153 là số Amstrong .

#include<stdio.h>
#include<conio.h>
#include<math.h>

void NhapDuLieu(int &n){
    printf("Nhap so: ");
    scanf("%d",&n);
}

int DemSoChuSo(int n){
    int temp = n;  
    int dem =0;
    while(temp !=0){
        int sochuso = temp % 10;
        temp/=10;
        dem++;
    }
    return dem;
}

int KiemTraSoArmstrong(int n){
    int soluongchuso = DemSoChuSo(n);
    int temp = n, s = 0;
    float chuso;
    while (temp != 0)
    {
        chuso = temp % 10; 
        temp /= 10;       
        s+= pow(chuso, soluongchuso);
    }
    if (s == n){
        return 1;
    }
    return 0;
}

void TimCacSoArmstrong(int n){
    for(int i = 1;i <= n;i++){
        if(KiemTraSoArmstrong(i)){
            printf("%d ", i);
        }
    } 
}

int main(){
hoang:
    int n;
    NhapDuLieu(n);
    TimCacSoArmstrong(n);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim space de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if( lc == 32){
		goto hoang;
	}
    return 0;
}
