Yêu cầu: Tìm giá trị lớn nhất của biểu thức ai + aj - ak (1<=i<j<k<=n)
Dữ liệu:
Dòng đầu tiên chứa hai số nguyên n (0<n<=106)
Dòng thứ 2 là các số nguyên a1, a2, ..., an
Kết quả:
Một dòng duy nhất ghi giá trị lớn nhất của biểu thức.

Test #1
Input:			
7
8 2 4 -5 9 1 -3
-> Output: 20

Test #2
Input			
33
13 -86 -46 -45 -31 -76 -13 -11 15 -26 1 12 -20 -87 33 59 3 -33 -42 3 58 -49 47 -4 -56 -43 18 61 12 -33 52 90 30
-> Output: 173

/*
Dựa trên cái tư tưởng của bài giải tham khảo ở bên trên thì:
3 vị trí i, j, k sao cho ai + aj - ak là lớn nhất. Với ràng buộc i < j < k. Tức là vị trí index k sẽ là lớn nhất. Sau đó là index j. Cuối cùng bé nhất sẽ là index i. Thì nghĩa là tối thiểu mảng phải có ít nhất 3 phần tử.(Đây là bắt buộc)
Giờ giả sử, 3 phần tử đầu tiên là a b c, Thì đáp án chỉ có thể là: a + b - c. Không cách nào khác được đúng không?
Tuy nhiên nếu có nhiều hơn 3 phần tử. Giả sử 4 phần tử, tức là có thêm sự xuất hiện của d -> Dãy là: a b c d. Thì có phải khi tại c, tính được kết quả: Max = a + b - c.
Giờ khi ta xét lên d. Nghĩa là cần phải trừ cho d. Còn trước đó, ta sẽ cần tìm tổng của 2 phân tử trong số 3 phần tử a b c sao cho tổng này lớn nhất, thì lúc này nó đơn giản là tìm ra 2 số lớn nhất trong tất cả những số trước vị trí d đơn giản vậy thôi.

Vậy tóm lại cách giải quyết bài này là thế này: 
Ta có thể tối ưu hơn được nữa cả về độ phức tạp không gian và thời gian bằng cách: chỉ cần dùng 1 vòng for duy nhất vừa kết hợp quá trình đọc dữ liệu vào mảng rồi lấy giá trị đó đi xử lý luôn không cần phải làm thêm vòng lặp nữa làm gì. Thêm cái nữa vì lấy luôn giá trị đó đi xử lý và ta thấy khi xét tiếp tục lên các giá trị a[i] tiếp theo thì a[i] đó chỉ so sánh với 2 biến Min, Max mà cập nhật lại, hoàn toàn không cần so sánh với các a[j] trước đó, vậy nên ta cũng chẳng cần thiết phải lưu trữ các giá trị vào mảng, ta cứ đại diện biến x đọc dữ liệu rồi lấy biến x đó đi xử lý so sánh với Min, Max và cập nhật lại Min, Max thôi.

Bắt đầu thì ta có 2 biến Max1 và Max2 như mình đã nói ở trên đó. Max1 để đi tìm 2 số a,b ban đầu xem (hay theo mảng thì là phần tử a[0], a[1] đó), xem 2 số này số nào lớn nhất, thì ta lưu lại cho Max1. Còn Max2 thì ta sẽ đi tìm giá trị min của a,b. Sau đó, Max chính cần tìm sẽ là: Max = Max1 + Max2 - c (ai + aj - ak). Rồi ta xét từ vị trí i = 3 trở đi đến i = n. Với mỗi vị trí i, Ta sẽ tìm ra 2 số lớn nhất trong các số ở trước vị trí i đó (tức là các index: i - 1, i - 2, … 0). Ta gọi là Max1, Max2 đi nha. Thì như thế, khi xét đến a[i], mình sẽ tìm được Max1, Max2. Tính ra được kết quả: Max1 + Max2 - a[i].

Tức là i = 4 => tính ra Max1, Max2, tính kết quả: Max1 + Max2 - a[4]
Tức là i = 5 => tính ra Max1, Max2, tính kết quả: Max1 + Max2 - a[5]
Tức là i = 6 => tính ra Max1, Max2, tính kết quả: Max1 + Max2 - a[6] …

Thì ở đây, sau khi scanf n xong thì ta scanf a tương ứng là giá trị của phần tử a[0] sẽ lưu vào a, sau đó scanf b tức là giá trị a[1] lưu vào b, và a[2] lưu vào biến c.  Rồi Max1 = max(a, b) tương ứng là: Lúc này a đang là a[0] và b đang là a[1] nên nghĩa là so sánh giữa a[0] và a[1] tìm ra giá trị lớn nhất cập nhật lại cho Max1. Rồi Max2 = min(a, b) tương ứng là: Lúc này a đang là a[0] và b đang là a[1] nên nghĩa là so sánh giữa a[0] và a[1] tìm ra giá trị nhỏ nhất cập nhật lại cho Max2.
	-> Kiểu gì Max2 < Max1 đúng không nào?
Rồi thì vòng for bắt đầu từ phần tử thứ 3 của mảng và đại diện biến c đọc dữ liệu vào, nếu c > Max1 thì ta cập nhật lại Max2 = Max1, Max1 = c (Lúc này c là 1 số lớn hơn cả Max1, có nghĩa c là 1 số khá lớn, chưa biết lớn hơn Max hay không?) rồi tiến hành đi so sánh lại Max với phép tính Max1 + Max2 - c, rồi từ đó ta sẽ thu về được 1 số và số này chính là giá trị lớn nhất biểu thức mà ta cần phải tìm. Còn ngược lại nếu c > Max2, mà Max2 lại nhỏ hơn Max1 rồi, nên là ta chỉ cần đi so sánh luôn Max với phép tính Max1 + Max2 - c rồi kiểm tra lần lượt với các phần tử còn lại rồi đi kết luận luôn.

(Trong tất cả các kết quả tính ra được thì so sánh tìm ra số lớn nhất. Và nếu cài đặt tối ưu cho bài này như cách nói ở trên, không cần dùng mảng lưu trữ gì cả, từng số từ đầu vào đọc vào chương trình xử lý trực tiếp luôn. Và toàn bộ bài chỉ cần 1 vòng lập duy nhất lặp đủ N lần. Đẳng cấp tối ưu là như vậy.)

THANK ANH TRAI NVNS ĐÃ HỖ TRỢ EM VƯỢT QUA BÀI NÀY BẰNG KIẾN THỨC VÔ GIÁ MÀ EM CHƯA TỪNG BIẾT :3

*/
#include <stdio.h>
long long min(long long a, long long b)
{
	return a < b ? a : b;
}
long long max(long a, long long b)
{
	return a > b ? a : b;
}
int main() 
{
    int n;
    scanf("%d", &n); 
    long long a, b, c;
    scanf("%lld %lld %lld", &a,&b,&c); 
    long long Max1 = max(a, b);
    long long Max2 = min(a, b);
    long long Max = Max1 + Max2 - c;
    for(int i = 3;i<n;++i)
    {
        if(c > Max1)
	{
            Max2 = Max1;
            Max1 = c;
        }
        else if(c > Max2)
	{
            Max2 = c;
        }
         scanf("%lld", &c); 
        Max = max(Max, Max1 + Max2 - c);
    }
    printf("%lld",Max);
    return 0;
}
