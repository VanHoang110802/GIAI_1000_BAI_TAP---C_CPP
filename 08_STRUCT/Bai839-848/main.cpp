/*

Tính tổng, hiệu, tích, thương hai đa thức.
Tính đa thức dư của phép chia đa thức thứ nhất cho đa thức thứ hai.
Tính đạo hàm cấp 1 của đa thức.
Tính đạo hàm cấp k của đa thức.
Tính giá trị của đa thức tại vị trí x = xo.
Định nghĩa toán tử cộng (operator +) cho hai đa thức.
Định nghĩa toán tử hiệu (operator –) cho hai đa thức.
Định nghĩa toán tử tích (operator *) cho hai đa thức.
Định nghĩa toán tử thương (operator /) cho hai đa thức.
Tính nghiệm của đa thức trong đoạn [a, b] cho trước.
*/
/*
* Tính tổng 2 đa thức: 

Đối vói toán học:
Phép cộng các đa thức bao gồm việc sắp xếp các số hạng tương tự với nhau và tính tổng chúng lại.
Có thể thực hiện thao tác bằng cách sắp xếp các đa thức theo chiều dọc hoặc chiều ngang. Cho sẽ sử dụng phương pháp nào,
câu trả lời cuối cùng sẽ không đổi.
* Ví dụ hình dung: 7xy + 6y + 6xy
- là một đa thức có các số hạng giống như 7xy và 6xy. Do đó, đa thức này có thể được đơn giản hóa bằng cách
kết hợp các số hạng như 7xy + 6xy + 6y = 13xy + y. Khi kết hợp các số hạng giống nhau, chúng ta chỉ cộng các
hệ số của các biến giống nhau.

Còn đối với tin: 
Ta sẽ nhìn ví dụ trên 1 chút. Vậy sẽ phải đi tìm min, max của số bậc (n) được nhập vào của mỗi đa thức. Rồi 
cấp phát mảng động theo max + 1. Tạo 1 struct mới lưu lại đối số bậc (n) vào struct đó. Đi duyệt từ phần tử 
trong mảng đến = min. Vì min là số lượng hệ số tối thiểu mà 2 đa thức chắc chắn đều sẽ có. Lấy từng phần tử
trong mỗi 2 đa thức cộng dồn lại. Sau đó đi xét xem có phần tử nào thừa hay không, nếu có thì cho thêm vòng
lặp duyệt từ min + 1 trở đi rồi cho gán phần tử đó vào cuối đa thức mới là xong.
*/
/*
* Tính hiệu 2 đa thức:

Đa thức có thể được trừ bằng một trong hai phương pháp. Cũng giống như cộng, có thể trừ bằng cách sắp xếp các
đa thức theo dạng ngang hoặc dọc. Và thuật toán y như vậy chỉ việc đổi mỗi dấu thôi là xong.
*/
/*
Tính tích 2 đa thức: Đa thức có thể được tính như sau:
phép nhân đơn giản chỉ là 2 cái vòng for nhân các đơn thức với nhau nhau, rồi nhớ chỉnh bậc cho đúng:
2 đơn thức nhân với nhau tạo ra đơn thức mới, hệ số bằng tích 2 hệ số cũ, bậc bằng tổng 2 bậc cũ.

*/
/*
* Tính thương 2 đa thức:
phép chia thì tính từ từ: lấy hệ số của đơn thức bậc cao nhất trong vế trái chia cho hệ số của đơn thức bậc cao nhất
bên vế phải, ra được hệ số của 1 đơn thức trong thương (quotient), rồi phải lấy đa thức bị chia (dividend) trừ đi 
tích của đơn thức này với đa thức chia (divisor). Lập lại tới khi nào đa thức bị chia có bậc bé hơn đa thức chia là
được. Lúc này đa thức bị chia chính là phần dư (remainder) của phép chia đa thức.

*/
/*
1 số test chia đa thức ...
-----------------------------------------------------------------------
Test: (2x4 – 3x3 – 3x2 – 2 + 6x) : (x2 – 2) = 2x2 – 3x + 1

-----------------------------------------------------------------------
Test: (-2x5 + 3x2 – 4x3) : 2x2 = -x3 + 3/2 – 2x. 

-----------------------------------------------------------------------
Test: (x3 – 7x + 3 – x2) : (x – 3) = x2  + 2x  – 1

-----------------------------------------------------------------------
Test: (-1 + x3) : (1 + x + x2) = -1 + x

-----------------------------------------------------------------------
Test: (7x3 - 7x + 42 ):(x2 - 2x + 3) = 7x + 14

-----------------------------------------------------------------------
Test: (10x2 – 7x - 12): (2x – 3) = 5x + 4

-----------------------------------------------------------------------
*/
