Cho một dãy n số nguyên a1, a2, ..., an. Hãy tìm hai chỉ số i, j sao cho i < j và hiệu aj - ai là lớn nhất.
Dữ liệu vào: gồm 2 dòng
-  Dòng 1: là số nguyên n (2 ≤ n ≤ 105)       
-  Dòng 2: gồm n số nguyên a1, a2, ..., an (0 ≤ ai ≤ 109)
Dữ liệu xuất:
- Là giá trị lớn nhất của hiệu aj - ai.

input: 3
       1 2 3
-> output: 2

input: 4
       2 5 1 3
-> output: 3

/*
Thực ra ta có thể tối ưu hơn được nữa cả về độ phức tạp không gian và thời gian. Bởi vì vòng lặp for đầu tiên đọc dữ liệu từ input cũng là duyệt từ đầu đến cuối đọc dữ liệu vào mảng, rồi vòng lặp for thứ 2 cũng là duyệt lại các giá trị của mảng từ đầu đến cuối. Vậy ta có thể chỉ cần dùng 1 vòng for duy nhất vừa kết hợp quá trình đọc dữ liệu vào mảng rồi lấy giá trị đó đi xử lý luôn không cần phải làm thêm vòng lặp nữa làm gì, thêm cái nữa vì lấy luôn giá trị đó đi xử lý và ta thấy khi xét tiếp tục lên các giá trị a[j] tiếp theo thì a[j] đó chỉ so sánh với 2 biến Min, Max mà cập nhật lại, hoàn toàn không cần so sánh với các a[j] trước đó, vậy nên ta cũng chẳng cần thiết phải lưu trữ các giá trị vào mảng, ta cứ đại diện biến x đọc dữ liệu rồi lấy biến x đó đi xử lý so sánh với Min, Max và cập nhật lại Min, Max thôi.

Thì ở đây cũng tương tự như vậy thôi sau khi scanf n xong thì ta scanf Min tương ứng là giá trị của phần tử a[0] sẽ lưu vào Min, sau đó scanf x tức là giá trị a[1] lưu vào x. Rồi Max = x - Min tương ứng x lúc này đang là a[1] và Min đang là a[0] nên nghĩa là Max = a[1] - a[0] tương tự như code trước đó, rồi Min = min(Min, x) lúc này Min đang là giá trị a[0], x đang là a[1] nên nghĩa là so sánh giữa a[0] và a[1] tìm ra giá trị nhỏ nhất cập nhật lại cho Min. Rồi thì vòng for bắt đầu từ phần tử thứ 3 của mảng và đại diện biến x đọc dữ liệu vào, biến x lúc này đây tương tự code trước đó chính là giá trị a[j].
Thì code ở trên sẽ tối ưu hơn code trước đó về mặt không gian khi ta không cần dùng mảng lưu trữ, tức là độ phức tạp không gian lúc này chỉ là O(1). Và tuy độ phức tạp thời gian vẫn là O(N) về mặt lý thuyết nhưng về mặt thực tế nó được tối ưu hơn khi chỉ cần 1 vòng lặp duyệt qua N phần tử còn code trước đó cần đến 2 vòng lặp như vậy, tức là code trước đó xét đúng thực tế là O(2 * N) còn code này chỉ là O(N) thôi. Nhưng về mặt tổng quát thì cả 2 code vẫn đều kết luận chung là O(N).
Đến đây các bạn đã thấy cái hay của giải thuật rồi chứ? Từ độ phức tạp thời gian là O(N^2) rút xuống chỉ còn O(N), từ độ phức tạp không gian O(N) rút xuống chỉ còn O(1) hehe
*/
#include <stdio.h>
int min(int a, int b)
{
	return a < b ? a : b;
}
int max(int a, int b)
{
	return a > b ? a : b;
}
int main()
{
    int n, x, Min, Max,i;
    scanf("%d%d%d", &n,&Min,&x);
    Max = x - Min;
    Min = min(Min, x);
    for(i = 2; i < n; ++i)
    {
        scanf("%d",&x);
        Max = max(Max, x - Min);
        Min = min(Min, x);
    }
    printf("%d",Max);
    return 0;
}
