Long và Linh là một đôi bạn thân, vào những lúc rảnh rỗi, họ thường bày ra những trò để chơi cùng nhau. Trong đó, trò chơi mà họ ưa thích nhất đó là Pokémon Trading Card
Game (Pokémon TCG).
Về cơ bản, luật của trò chơi đó là mỗi người chơi sẽ có một lá bài, và lá bài nào có "chỉ số sức mạnh" lớn hơn sẽ thắng. Biết rằng lá bài của Long có chỉ số sức mạnh khác
lá bài của Linh.
Bạn được cho biết "chỉ số sức mạnh" của lá bài mỗi người chơi có, hãy cho biết ai sẽ là người thắng cuộc.
Ở lần chơi trước, Long hí hửng vì có được 1 con Vulpix, nhưng Linh lại có được tận 1 con Charizard, vì thế nên Long thua.
Nếu Long là người thắng cuộc, in ra 1. Còn nếu Linh là người thắng cuộc, in ra 0.
input:1 2	->output: 0
intput: 5 3	-> output: 1

#include <iostream>
using namespace std;
int main()
{
    int a, b;
    cin >> a >> b;
    if (a < b)
    {
        cout<<"0";
    }
    else if (a > b)
    {

        cout<<"1";
    }

    return 0;
}
