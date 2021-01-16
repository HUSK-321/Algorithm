#include <iostream>
using namespace std;
// 1, 3
// SK : 1,3,5
// CY : 2,4,
int main(){
    long long n;
    cin >> n;
    if(n%2 == 0)
        cout << "CY" << '\n';
    else
        cout << "SK" << '\n';
    return 0;
}
