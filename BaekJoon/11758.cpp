#include <iostream>
using namespace std;
int main(){
    int x1, x2, x3, y1, y2, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    // 벡터 외적 = a*b*sin
    int result = x1*y2 - x2*y1 + x2*y3 - x3*y2 + x3*y1 - x1*y3;
    if(result / 2 > 0)
        cout << "1" << '\n';
    else if(result / 2 < 0)
        cout << "-1" << '\n';
    else
        cout << "0" << '\n';
}