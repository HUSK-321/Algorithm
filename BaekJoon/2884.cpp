#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int H, M;
    cin >> H >> M;
    // 45분 앞서야 한다
    if(M >= 45){
        M -= 45;
        printf("%d %d", H, M);
    } else{
        H -= 1;
        int m = abs(M-45);
        M = 60 - m;
        if(H < 0)
            H = 23;
        printf("%d %d", H, M);
    }
}