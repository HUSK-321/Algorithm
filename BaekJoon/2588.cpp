#include <iostream>
using namespace std;
int main(){
    int a, b;
    cin >> a >> b;


    cout << (b%10)*a << '\n';
    cout << ((b/10)%10)*a<< '\n';
    cout << (b/100)*a << '\n';
    cout << a*b << '\n';
}