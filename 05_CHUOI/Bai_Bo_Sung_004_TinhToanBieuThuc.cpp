/*
Tính kết quả của biểu thức toán học gồm các phép toán tử cộng (+), trừ (-), nhân (*), chia (/) và các toán
hạng là các số thực. Thứ tự ưu tiên tính toán bắt buộc xử lý các biểu thức con trong các dấu ngoặc đơn trước 
theo thứ tự từ dấu ngoặc trong cùng trở ra, sau đó trong cùng 1 biểu thức con mới xét đến ưu tiên thứ tự nhân
chia trước cộng trừ sau theo trình tự từ trái qua phải.

Đầu vào: 1 dãy biểu thức toán học với từng phần tử (toán hạng, toán tử, dấu ngoặc) được ngăn cách với nhau bởi
đúng 1 khoảng trắng

Đầu ra: 1 số duy nhất là kết quả của biểu thức toán học

Input: 1 + 2 * 3 – 4 / 5
-> Output: 6.2

Input: 1 – 2 + 3 / 4 * 5 – 6 * 7 / 2 + 9 – 1 * 8 + 5
-> Output: -12.25

Input: 90 - ( 5 * 8 / ( 4 + 6 ) – 3 / ( 2 + 1 ) * 23 ) / 100
-> Output: 90.19

*/

/*
CÁCH ĐỂ DẠY CHO MÁY TÍNH TƯ DUY GIẢI QUYẾT NHƯ CON NGƯỜI VỚI BÀI TẬP TÍNH KẾT QUẢ BIỂU THỨC TOÁN HỌC:

Biểu thức toán học có 2 dạng
1/ Không có ngoặc
2/ Có ngoặc

Dạng 1 sẽ là dạng con của dạng 2 -> vì bên trong mỗi dấu ngoặc thì biểu thức đó chính là dạng 1

Cách làm dạng 1: Không có dấu ngoặc, chỉ có các toán hạng và toán tử (toán tử nằm giữa 2 toán hạng)
"1 + 2 * 3 – 4 / 5"
Chúng ta sẽ có 1 mảng 1 chiều mà mỗi phần tử trong mảng chứa kiểu dữ liệu CHUỖI

a[0] = "1"
a[1] = "+"
a[2] = "2"
a[3] = "*"
a[4] = "3"
a[5] = "-"
a[6] = "4"
a[7] = "/"
a[8] = "5"

a[0] = "1"
a[1] = "+"
a[2] = "6"
a[3] = "-"
a[4] = "4"
a[5] = "/"
a[6] = "5"

Bước 1: Tách các giá trị trong chuỗi biểu thức toán học lưu vào trong mảng 1 chiều chuỗi (mỗi phần tử trong mảng là 1 chuỗi)
chuỗi => mảng 1 chiều các ký tự
mảng 1 chiều chuỗi => mảng 2 chiều các ký tự
gợi ý: Có thể dùng vector bên C++ cho đơn giản (vector<string> a)

Bước 2: Quá trình duyệt mảng 1 chiều bắt đầu từ đây
    Bước 2.1: Duyệt để phá đi các phép toán nhân, chia

    Bước 2.2: Duyệt để phá đi các phép toán cộng, trừ

Trong mỗi bước 2.1, 2.2 thì:
Xét các vị trí index lẻ (1, 3, 5, 7 ...) vì đó chính là các index chứa các toán tử (vd: index là x), khi gặp 1 toán tử thì sẽ lấy phần tử index trước nó (x - 1) và sau nó (x + 1) (2 toán hạng) đổi ra số thực rồi tính toán đúng theo nguyên tắc toán tử như vậy để ra được kết quả là 1 con số thực => đổi kết quả số đó sang chuỗi rồi cập nhật vô vị trí phần tử ở index toán hạng đầu tiên (x - 1), sau đó xóa 2 phần tử là toán tử (x) và toán hạng thứ 2 (x + 1). Sau đó bắt đầu xét tiếp từ vị trí vừa cập nhật kết quả vô trở đi tiếp theo xét tiếp các giá trị lẻ và cứ thế quy trình lặp lại giống như trên cho đến khi mảng còn đúng duy nhất 1 phần tử thì đó chính là giá trị của biểu thức toán học

Cách làm dạng 2: Có dấu ngoặc tham gia vào biểu thức toán học
( 1 + 2 * ( ( 3 – 4 ) / 5 ) )

Chủ động thêm vào dấu mở ngoặc ở đầu và đóng ngoặc ở cuối biểu thức toán học - Duyệt chuỗi biểu thức toán học, khi gặp ký tự đóng ngoặc ')' thì xét lùi về mở ngoặc đầu tiên '(' lấy đoạn nội dung bên trong (tức là biểu thức không có ngoặc) gọi lại về hàm xử lý dạng 1 để trả ra kết quả là 1 con số sau đó xóa đoạn ngoặc đi và thay vào đó là kết quả được trả về từ dạng 1 và rồi tiếp tục xét tiếp lên và cứ thế phá hết tất cả dấu ngoặc đi. Quá trình sẽ lặp lại liên tục đến khi không còn duyệt xét dấu ngoặc được nữa (tức là tất cả dấu ngoặc đều đã được phá bỏ hết kể cả dấu ngoặc mình chủ động thêm) => kết thúc và có được giá trị cuối cùng của biểu thức

how to convert string to float in c++
how to convert float to string in c++

s = "(1 + 2 * ((3 – 4) / 5))"
s[0] = '('
s[1] = '1'
s[2] = ' '
s[3] = '+'
s[4] = ' '
s[5] = '2'
s[6] = ' '
s[7] = '*'
s[8] = ' '
s[9] = '('
s[10] = '('
s[11] = '3'
s[12] = ' '
s[13] = '-'
s[14] = ' '
s[15] = '4'
s[16] = ')'
s[17] = ' '
s[18] = '/'
s[19] = ' '
s[20] = '5'
s[21] = ')'
s[22] = ')'

vector<int> a; // chứa các index của dấu mở ngoặc
a[0] = 0
a[1] = 9
a[2] = 10

*/

#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
using namespace std;

void XuatVector(vector<string> a)
{
    cout << endl;

    for (int i = 0; i < a.size() - 1; ++i)
        cout << a[i] << " ";

    cout << a[a.size() - 1];
}

string TinhKetQuaBieuThucKhongNgoac(string s)
{
    // Bước 1: Tách chuỗi lưu vào mảng vector
    vector<string> a;

    char *p = strtok((char *)s.c_str(), " ");

    while (p != NULL)
    {
        a.push_back(p);
        p = strtok(NULL, " ");
    }

    // Bước 2: Xử lý tính toán trên mảng

    int dem = 1;
    // Thực hiện nhân chia trước
    for (int i = 1; i < a.size(); i += 2)
    {
        if (a[i] == "*" || a[i] == "/")
        {
            float x = stof(a[i - 1]);
            float y = stof(a[i + 1]);

            float ketqua;

            if (a[i] == "*")
                ketqua = x * y;
            else if (a[i] == "/")
                ketqua = x / y;

            a[i - 1] = to_string(ketqua);

            // xóa a[i] và a[i + 1] đi
            a.erase(a.begin() + i);
            a.erase(a.begin() + i); // do sau lần xóa vị trí i đầu tiên thì vị trí i + 1 đã bị lùi xuống thành i nên không được xóa i + 1 mà phải xóa i
          
            i -= 2; // Phải lùi về 2 cho biến i bởi sau khi xóa thì index đã bị thay đổi cho nên nếu không lùi thì sẽ bị bỏ qua 1 số phép toán
        }
    }

    // Thực hiện cộng trừ sau
    for (int i = 1; i < a.size(); i += 2)
    {
        if (a[i] == "+" || a[i] == "-")
        {

            float x = stof(a[i - 1]);
            float y = stof(a[i + 1]);

            float ketqua;

            if (a[i] == "+")
                ketqua = x + y;
            else if (a[i] == "-")
                ketqua = x - y;

            a[i - 1] = to_string(ketqua);

            // xóa a[i] và a[i + 1] đi
            a.erase(a.begin() + i);
            a.erase(a.begin() + i); // do sau lần xóa vị trí i đầu tiên thì vị trí i + 1 đã bị lùi xuống thành i nên không được xóa i + 1 mà phải xóa i

            i -= 2; // Phải lùi về 2 cho biến i bởi sau khi xóa thì index đã bị thay đổi cho nên nếu không lùi thì sẽ bị bỏ qua 1 số phép toán
        }
    }
    return a[0];
}

// có ngoặc hay không ngoặc đều tính được hết
string TinhKetQuaBieuThucToanHoc(string s)
{
    // Chủ động thêm vào dấu mở ngoặc ở đầu và đóng ngoặc ở cuối biểu thức toán học
    s.insert(0, "(");
    s.insert(s.length(), ")"); // hay có thể viết là: s += ")";

    vector<int> a; // Chứa các index của dấu mở ngoặc

    int dem = 1;
    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] == '(')
            a.push_back(i);
        else if (s[i] == ')')
        {
            int end = i;
            int start = a[a.size() - 1];

            string bieuthuctrongngoac = s.substr(start + 1, end - 1 - start);

            string ketqua = TinhKetQuaBieuThucKhongNgoac(bieuthuctrongngoac);

            s.erase(start, end - start + 1); // Xóa đoạn biểu thức có ngoặc đã tính ra kết quả
            s.insert(start, ketqua);         // Chèn chuỗi kết quả vào chuỗi s tại vị trí start

            i = start + ketqua.length() - 1;
            a.erase(a.begin() + a.size() - 1);
            
        }
    }
    return s;
}

int main()
{
    string s; //ví dụ: 90 - (5 * 8 / (4 + 6) - 3 / (2 + 1) * 23) / 100 = 90.19
    cout << "Nhap bieu thuc can tinh \n(Moi phep tinh cach nhau boi 1 khoang trang, so am thi co the viet lien):\n";
    getline(cin, s);
    string kq = TinhKetQuaBieuThucToanHoc(s);
    cout << "\nBieu thuc can tinh s = " << s << " = " << kq;
    return 0;
}
