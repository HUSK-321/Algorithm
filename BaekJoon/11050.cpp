#include <iostream>
using namespace std;

int function(int a){
    if(a==0) return 1;

    int fac = 1;
    for(int i = a; i >=1; i--){
        fac *= i;
    }
    return fac;
}

int main(){
    int n, k;
    cin >> n >> k;
    //cout << function(n) << function(k) << function(n-k);
    cout << function(n) / (function(k)*function(n-k)) << '\n';
    
}