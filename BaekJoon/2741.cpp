#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    if (n <= 100000){
        for (int i = 0; i < n; i++)
            cout << i+1 << '\n';
    }
    return 0;
}