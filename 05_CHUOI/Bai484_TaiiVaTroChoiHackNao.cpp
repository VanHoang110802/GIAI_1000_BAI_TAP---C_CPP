Taii tham gia một trò chơi hách não. Để bắt đầu anh ta phải chọn được chính xác ô cửa bắt đầu của mình.

Để chọn chính xác ô cửa bắt đầu, trọng tài phát cho mỗi người một mảnh giấy trong đó có ghi mật mã chính là số của ô cửa mà anh ta phải bắt đầu. Tuy nhiên, có vẻ ngay câu hỏi đầu của trò chơi khá khó với Taii do anh ta rất lú lẫn. Taii đã chọn quyền trợ giúp của người thân.

Bạn hãy giúp Taii vượt qua câu hỏi đầu tiên này để tiến tới các câu hỏi khác nhé <3. Nếu bạn giải ra được, mật mã của mảnh giấy chính là điểm xuất phát của bạn.

Luật lệ như sau: Bạn chỉ có thể chọn ra một số chữ cái của mật mã ghi trong mảnh giấy và ghép chúng lại, đó chính là số của ô cửa mà anh ta bắt đầu (Tuyệt đối không được đảo vị trí các chữ)

Mật mã là một trong các dãy: ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE.

Tuy nhiên, trong số các tờ giấy mà Taii nhận được có 1 tờ giấy mà bạn không thể tìm ra mật mã được. Và đó cũng chính là kết thúc của bạn, tức là ô cửa ra về!

input: KJNKJDHSHDSDTSNJSDWJOKJSHKDSKPW	-> ouput: TWO
input: FSDFABDUIOCS			-> output: CHIA BUON, PHAI VE ROI, HEN NAM SAU NHE!!

/*
Ví dụ giờ cần tìm chuỗi con “ZERO” đi thì rất đơn giản chỉ cần duyệt chuỗi đầu vào, xét tìm thấy ký tự ‘Z’ đầu tiên thì tăng biến đếm lên 1, sau đó tiếp tục duyệt xét thấy ký tự ‘E’ thì tăng biến đếm lên 1, sau đó tiếp tục duyệt xét thấy ký tự ‘R’ thì tăng biến đếm lên 1, sau đó tiếp tục duyệt xét thấy ký tự ‘O’ thì tăng biến đếm lên 1 nữa. Cứ mỗi lần biến đếm được tăng lên 1 thì ta kiểm tra nếu thấy biến đếm là 4 (tức là bằng độ dài chuỗi “ZERO”) thì nghĩa là chuỗi “ZERO” đã xuất hiện đủ trong chuỗi ban đầu theo thứ tự, lúc này ta có thể dừng việc tìm kiếm và kết luận. Còn nếu xét hết chuỗi ban đầu rồi mà biến đếm vẫn chưa bằng được với độ dài chuỗi con mà ta đang tìm kiếm thì nghĩa là chuỗi con đó không tồn tại, ta xét qua chuỗi con tiếp theo (“ONE”) và lặp lại quy trình như trên.

Vậy cách xử lý tổng quát là thế này: Đầu tiên ta tạo luôn mảng chuỗi a (string a[]) có 10 phần tử, với mỗi phần tử trong chuỗi sẽ là từ tiếng Anh từ 0 đến 9. Cụ thể lúc này a[0] = “ZERO”, a[1] = “ONE”, cứ thế đến a[9] = “NINE”. Rồi thì duyệt xét tìm chuỗi con a[i] với i lần lượt từ 0 đến 9 trong chuỗi gốc s ban đầu. Khởi tạo biến số nguyên idx = 0 để ta duyệt lần lượt từng ký tự trong chuỗi con a[i] (tức là xét từng ký tự a[i][idx] với idx từ 0 đến a[i].length() - 1. Ta duyệt xét lần lượt từng ký tự s[j] trong chuỗi s, so sánh nếu nó bằng với ký tự a[i][idx] của chuỗi con a[i] thì ta sẽ tăng biến idx lên 1 (idx++) để lần xét ký tự s[j] tiếp theo nó sẽ xét tìm ký tự tiếp theo của chuỗi con a[i]. Cứ mỗi lần tìm thấy ký tự trùng khớp (s[j] == a[i][idx]) thì ta kiểm tra xem giá trị idx có bằng với độ dài của chuỗi con a[i] đang xét không? Nếu bằng nghĩa là toàn bộ chuỗi con a[i] đã được tìm thấy, ta lưu giá trị index i (index chuỗi con đang xét trong mảng chuỗi a) vào biến temp và kết thúc cả 2 vòng lặp rồi sau cùng in ra đáp án chuỗi con nhỏ nhất tìm thấy là a[temp]. Biến temp lúc này đang ý nghĩa lưu lại index của chuỗi con đầu tiên tìm thấy, ban đầu ta nên khởi tạo biến temp = -1 để sau cùng ta kiểm tra nếu temp vẫn là -1 thì ta in ra chia buồn, biến temp đóng vai trò như cờ hiệu bởi làm gì có index nào là -1 đúng không? còn nếu index khác -1 nghĩa là ta hiểu đã tìm ra được chuỗi con.
*/

#include<iostream>
#include <string>
using namespace std;
int main() {
    string a[] = { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };
    string s ="SJNKJDRIARSNJEBRZOKCVDEXKPW";
    //getline(cin, s);
    int temp = -1;
    for (int i = 0; i < 10; ++i) {
        int idx = 0;
        for (int j = 0; j < (int)s.length(); ++j) {
            if (s[j] == a[i][idx]) {	//mỗi lần tìm thấy ký tự trùng khớp
                idx++;
                if (idx == (int)a[i].length()) {
                    temp = i;
                    i = 10;
                    break;
                }
            }
        }
    }
    if (temp == -1) {
        cout << "CHIA BUON, PHAI VE ROI, HEN NAM SAU NHE!!";
    }
    else {
        cout << a[temp];
    }
    return 0;
}
