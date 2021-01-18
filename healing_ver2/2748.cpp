#include <iostream>
using namespace std;
long long number[92];


int main(){
    long long result = 0;
    int n;
    number[0] = 0;
    number[1] = 1;
    cin >> n;
    for(int i = 2; i <= n; i++){
        number[i] = number[i-1] + number[i-2];
    }
    cout << number[n] << '\n';
}