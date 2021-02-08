#include <iostream>
using namespace std;
int a, b, c;

long long solve(int a, int b){
    if(b == 1){
        return a;
    } else{
        if(b % 2 == 0)
            return (solve(a, b/2) * solve(a, b/2)) % c;
        else
            return (((solve(a, b/2) * solve(a, b/2)) % c) * a) % c;
    }
}
int main(){
    cin >> a >> b >> c;
    cout << solve(a%c, b) % c << "\n";
}