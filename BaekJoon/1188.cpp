#include <iostream>
using namespace std;
int N = 0,M = 0; // 소시지 수, 평론가 수
// 소시지를 일자로 늘린 최소공배수? 느낌
int function(int a, int b){
    if(a%b == 0)
        return b;

    return function(b, a%b);
}
int main(){
    cin >> N >> M;
    cout << M - function(N, M) << '\n';
}