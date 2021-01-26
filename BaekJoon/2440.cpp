#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    // i 층에 있어야 할 것 n-i+1만큼의 별
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-i; j++)
            cout << "*";
        cout << endl;
    }
}