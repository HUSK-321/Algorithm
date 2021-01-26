#include <iostream>
using namespace std;
int main(){
    int a, b, c;
    cin >> a >> b >> c;
    if(b>=c){
        cout << -1 << '\n';
        return 0;
    }
    cout << a/(c-b) +1 << '\n';
    return 0;
}