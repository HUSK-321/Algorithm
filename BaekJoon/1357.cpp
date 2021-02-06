#include <iostream>
using namespace std;
int Rev(int n){
    int result = 0;
    while(n){
        result = result*10 + n%10;
        n /= 10;
    }
    return result;
}
int main(){
    int x, y;
    cin >> x >> y;
    cout << Rev(Rev(x) + Rev(y));
}