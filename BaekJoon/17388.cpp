#include <iostream>
#include <algorithm>
using namespace std;

pair<long long, long long> a, b, c, d;

int CCW(pair<long long, long long> A, pair<long long, long long> B, pair<long long, long long> C){
    long long ans = A.first*B.second + B.first*C.second + C.first*A.second;
    ans -= B.first*A.second + C.first*B.second + A.first*C.second;

    if(ans > 0)
        return 1;
    else if (ans == 0)
        return 0;
    else
        return -1;
}


int main(){
    cin >> a.first >> a.second >> b.first >> b.second;
    cin >> c.first >> c.second >> d.first >> d.second;

    int ab_c = CCW(a, b, c);
    int ab_d = CCW(a, b, d);
    int cd_a = CCW(c, d, a);
    int cd_b = CCW(c, d, b);

    if(ab_c*ab_d == 0 && cd_a*cd_b == 0){
        // 포함 관계 확인
        if(a > b)
            swap(a, b);
        if(c > d)
            swap(c, d);
        
        if(a <= d && c <= b)
            cout << 1 << '\n';
        else 
            cout << 0 << '\n';
        
        return 0;
    }

    if(ab_c*ab_d <= 0 && cd_a*cd_b <= 0)
        cout << 1 << '\n';
    else 
        cout << 0 << '\n';
}