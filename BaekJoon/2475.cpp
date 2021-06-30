#include <iostream>
using namespace std;
int mul(int x){
    return x * x;
}
int main(){
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e;
    f = mul(a) + mul(b) + mul(c) + mul(d) + mul(e);
    f = f % 10;
    cout << f << '\n';
}