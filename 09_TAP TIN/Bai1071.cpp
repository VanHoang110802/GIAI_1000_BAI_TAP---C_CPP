/*
Cho input:4/2/1/5/8
hãy tìm max và ghi ra file output.txt
*/
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
	ifstream FileIn("input.txt");

	if (!FileIn)
	{
		cout << "\nKhong tim thay tap tin input.txt";
		
		return 0; // Kết thúc.
	}

	vector<int> arr;

	/*
	vector có 2 cơ chế:
	Cơ chế 1: Nếu biết trước số lượng phần tử sẽ cấp phát thì dùng resize(<Số lượng>)

	Cơ chế 2: Nếu không biết trước số lượng phần tử sẽ cấp phát thì dùng push_back(<Phần tử>)

	Lời khuyên: Dùng cơ chế 2 nhé

	*/

	while (!FileIn.eof()) // Vòng lặp để duyệt hết file.
	{
		int x; // Khởi tạo 1 đồi tượng x.
		FileIn >> x; // Đọc dữ liệu từ file vào x.

		
		// Dịch chuyển con trỏ chỉ vị trên file.

		/*
		seekg(x, y);
		x là số byte cần dịch chuyển
		y là vị trí bắt đầu dịch, có 3 thông số:
			+ y = 0: Đầu file.
			+ y = 1: Hiện tại.
			+ y = 2: Cuối file.
		*/

		// Kiểm tra nếu chưa đến cuối file thì mới được phép dịch.
		if (!FileIn.eof())
		{
			FileIn.seekg(1, 1); // Dịch 1 byte từ vị trí y hiện tại.
		}

		arr.push_back(x); // Đưa x vào trong vector.
	}

	FileIn.close();


	ofstream FileOut("output.txt");

	int Max = arr[0];

	for (int i = 1; i < arr.size(); i++)
	{
		if (arr[i] > Max)
		{
			Max = arr[i];
		}
	}

	FileOut << Max;

	FileOut.close();
	return 0;
}
