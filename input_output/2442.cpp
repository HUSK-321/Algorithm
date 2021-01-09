#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    // i 층에 있어야 할 것 i-1만큼의 공백 후 
    // 1층의 경우 공백 4개 후 별 1개 후 공백 4개
    // 2층의 경우 공백 3개 후 별 3개 후 공백 3개
    for(int i = 1; i < n+1; i++){
        for(int j = 0; j < n-i; j++)
            cout << " ";
        for(int j = 0; j < 2*i-1; j++)
            cout << "*";
        cout << endl;
    }
}