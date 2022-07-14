Cho một hình chữ nhật có các cạnh song song với các trục tọa độ và một điểm. Kiểm tra xem điểm đã cho có nằm trong hình chữ nhật đã cho không 
(nằm trên cạnh không được tính là nằm trong)?
Một dòng duy nhất chứa 66 số nguyên cách nhau bởi một khoảng trắng, mỗi cặp hai số liên tiếp trong 6 số là tọa độ của hai đỉnh đối của hình chữ nhật và của điểm.
input: 0 0 3 3 2 2	->output: YES
input: 0 1 3 3 3 2	-> output:NO

/*
TH1: x < toadogoc < x2 va y < toadogoc < y2
TH2: x > toadogoc > x2 va y > toadogoc > y2
TH3: x < toadogoc < x2 va y > toadogoc > y2
TH4: x > toadogoc > x2 va y < toadogoc < y2
*/

#include<iostream>
using namespace std;
int main() {
    int x1, y1, x2, y2, x, y;
    cin >> x1 >> y1 >> x2 >> y2 >> x >> y;
    if (x1 < x2 && y1 < y2) {
        if ((x1 < x && x < x2) && (y1 < y && y < y2)) {
            cout << "YES";
        }
        else cout << "NO";
    }
    else if (x1 > x2 && y1 > y2) {
        if ((x2 < x && x < x1) && (y2 < y && y < y1)) {
            cout << "YES";
        }
        else cout << "NO";
    }
    else if (x1<x2 && y1>y2) {
        if ((x1 < x && x < x2) && (y2 < y && y < y1)) {
            cout << "YES";
        }
        else cout << "NO";
    }
    else if (x1 > x2 && y1 < y2) {
        if ((x2 < x && x < x1) && (y1 < y && y < y2)) {
            cout << "YES";
        }
        else cout << "NO";
    }
    return 0;
}
