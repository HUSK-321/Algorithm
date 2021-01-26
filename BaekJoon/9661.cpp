#include <iostream>
using namespace std;
// 1, 4, 16, 64
// SK : 1,3,4,6,8
// CY : 2,5,7
int main(){
    long long n;
    cin >> n;
    if(n%5 == 2 || n%5 == 0)
        cout << "CY" << '\n';
    else
        cout << "SK" << '\n';
}