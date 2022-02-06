#include <iostream>
using namespace std;

int x1, y1;
int x2, y2;
int x3, y3;
int x4, y4;


long long CCW(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3) {
    long long temp = x1*y2 + x2*y3 + x3*y1;
    temp -= y1*x2 + y2*x3 + y3*x1;
    if (temp > 0) 
        return 1;
    else
        return -1;
}

int main(){
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;

    long long L13 = CCW(x1, y1, x2, y2, x3, y3);
    long long L14 = CCW(x1, y1, x2, y2, x4, y4);
    long long L21 = CCW(x3, y3, x4, y4, x1, y1);
    long long L22 = CCW(x3, y3, x4, y4, x2, y2);

    if(L13*L14 <= 0 && L21*L22 <= 0)
        cout << 1 << '\n';
    else
        cout << 0 << '\n';
}